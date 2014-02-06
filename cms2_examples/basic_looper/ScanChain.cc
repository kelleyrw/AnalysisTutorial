// Usage:

// > ./setup.sh
// > root -b runSample.C

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "Math/VectorUtil.h"
#include "TDatabasePDG.h"

// CMS2
#include "interface/CMS2.h"
#include "interface/goodrun.h"

// CORE
#include "CORE/mcSelections.h"

//stuff from looper tools
#include "looperTools/eventFilter.h"

#include "ScanChain.h"

using namespace std;
using namespace tas;

cms2Looper::cms2Looper()
{
}

int cms2Looper::ScanChain( TChain* chain, bool fast, int nEvents ) 
{

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  //~-~-~-~-~-~-~-~-~-~-//
  //Book Histograms Here//
  //~-~-~-~-~-~-~-~-~-~-//
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  TH1F *samplehisto = new TH1F("samplehisto", "Example histogram", 200,0,200);
  samplehisto->SetDirectory(rootdir);

  //~-~-~-~-~-~-~-~-~-~-~-//
  //Set json here for data//
  //~-~-~-~-~-~-~-~-~-~-~-//
  //json for moriond
  set_goodrun_file("json/Merged_190456-208686_8TeV_PromptReReco_Collisions12_goodruns.txt");

  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
  // Loop over events to Analyze//
  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

	if( !currentFile || currentFile->IsZombie() ) {
	  cout << "Skipping bad input file: " << currentFile->GetTitle() << endl;
	  continue; //exit(1);                                                                                             
	}

	// Get File Content
	TFile *file = new TFile( currentFile->GetTitle() );
	TTree *tree = (TTree*)file->Get("Events");
	if(fast) TTreeCache::SetLearnEntries(10);
	if(fast) tree->SetCacheSize(128*1024*1024);
	cms2.Init(tree);
    
	// Loop over Events in current file
	if( nEventsTotal >= nEventsChain ) continue;
	unsigned int nEventsTree = tree->GetEntriesFast();
	for( unsigned int event = 0; event < nEventsTree; ++event) {
    
	  // Get Event Content
	  if( nEventsTotal >= nEventsChain ) continue;
	  if(fast) tree->LoadTree(event);
	  cms2.GetEntry(event);
	  ++nEventsTotal;
    
	  //parse events from json
	  if( cms2.evt_isRealData() ){
		if( !goodrun_json( cms2.evt_run(), cms2.evt_lumiBlock() ) ){continue;}
		DorkyEventIdentifier id = { cms2.evt_run(), cms2.evt_event(), cms2.evt_lumiBlock() };
		if ( is_duplicate( id ) ){
		  // cout << "\t! ERROR: found duplicate." << endl;
		  // nDuplicates++;
		  continue;
		}
	  }

	  // Progress
	  CMS2::progress( nEventsTotal, nEventsChain );

	  //~-~-~-~-~-~-~-//
	  // Analysis Code//
	  //~-~-~-~-~-~-~-//

	  Bool_t foundwz = false;
	  Int_t nwzpartons = 0;

	  for( size_t ind = 0; ind < genps_id().size(); ind++ ){

	  	Int_t pid = abs(genps_id().at(ind));
		
	  	if ( pid == 23 ) {
	  	  // ptzgen_ = genps_p4().at(igen).pt();
	  	  foundwz = true;
	  	  // nwzpartons_  = 0;
	  	}
		
	  	if (foundwz && ( pid == 1 || pid == 2 || pid == 3 || pid == 4 || pid == 5 || pid == 6 || pid == 21 ) ) {  
	  	  nwzpartons++;
	  	}
	  }

	  if( nwzpartons > 3 ){
	  	dumpDocLines();
	  }

	  // samplehisto->Fill(cms2.evt_scale1fb());
	  // samplehisto->Fill(cms2.evt_nEvts());
	  // if(!cleaning_standardApril2011()) continue;
	  
	  //   vector <LorentzVector> goodmus;

	  //   for (size_t mui = 0; mui < mus_p4().size(); mui++)
	  // 	{
	  // 	  if (!muonId( mui, ZMet2012_v1)) continue;

	  // 	  goodmus.push_back(mus_p4().at(mui));
	  // 	  samplehisto->Fill(mus_p4().at(mui).pt());
	  // 	}

	}
  
	// Clean Up
	delete tree;
	file->Close();
	delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
	cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Histograms
  samplehisto->Draw();
  
  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}

cms2Looper::~cms2Looper()
{
}

