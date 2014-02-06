#include "TChain.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TROOT.h"

#include "interface/ScanChain.h"

int runSample()
{

  std::cout<<__LINE__<<std::endl;
  gSystem->Load("libcms2_looper.so");

  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain * ch1 = new TChain("Events");
  // ch1->Add("/hadoop/cms/store/user/cwelke/CMS2_V05-03-18/DYToMuMu_M-20_CT10_TuneZ2star_v2_8TeV-powheg-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/ntuple_191_1_zZL.root");
  // ch1->Add("/hadoop/cms/store/user/cwelke/CMS2_V05-03-18/DYToMuMu_M-20_CT10_TuneZ2star_v2_8TeV-powheg-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1/ntuple_1910_1_rOc.root");
  ch1->Add("/hadoop/cms/store/group/snt/papers2012/Summer12_53X_MC/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1/V05-03-23/merged_ntuple_1.root");
  // ch1->Add("~/MCNtupling/CMSSW/CMSSW_5_3_2_patch4_V05-03-23/crab/makecms2ntuple/post_processed_ntuple.root");

  cms2Looper looper();
  std::cout<<"running cms2 looper."<<std::endl;

  looper.ScanChain(ch1, true, -1);

  return 0;
}
