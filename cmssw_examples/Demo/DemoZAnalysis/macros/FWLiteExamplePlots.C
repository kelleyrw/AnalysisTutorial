#include <iostream>
#include <limits>
#include <limits>
#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"

void FWLiteExamplePlots(const std::string& ntuple_path, const std::string& output_filename, long long num_events=-1)
{
    // get the data
    TChain e("Events");
    e.Add(ntuple_path.c_str());

    // set aliases
    e.SetAlias("gp"       , "recoGenParticles_genParticles__SIM.obj"   ); 
    e.SetAlias("is_z"     , "gp.status()==3 && gp.pdgId()==23"         ); 
    e.SetAlias("d1"       , "gp.daughterRef(0).get()"                  ); 
    e.SetAlias("d2"       , "gp.daughterRef(1).get()"                  ); 
    e.SetAlias("is_tautau", "abs(d1.pdgId())*abs(d2.pdgId())!=(-15*15)"); 

    // book hists
    TH1F h_zmass("h_zmass", "Invariant mass of Z boson;m_{Z} (GeV)" , 60, 60, 120);
    TH1F h_d1_pt("h_d1_pt", "Z higher daughter's p_{T};p_{T} (GeV)" ,100,  0, 100);
    TH1F h_d2_pt("h_d2_pt", "Z lower daughter's p_{T};p_{T} (GeV)"  ,100,  0, 100);
     
    // num_events < -1 means run on all the events
    if (num_events < 0)
    {
        num_events = std::min(e.GetEntries(), std::numeric_limits<long long>::max());
    }

    // fill the hists
    e.Draw("gp.mass()>>h_zmass", "is_z && !is_tautau", "goff", num_events);
    e.Draw("d1.pt()>>h_d1_pt"  , "is_z && !is_tautau", "goff", num_events);
    e.Draw("d2.pt()>>h_d2_pt"  , "is_z && !is_tautau", "goff", num_events);

    // output
    TFile output_file(output_filename.c_str(), "RECREATE");
    h_zmass.Write();
    h_d1_pt.Write();
    h_d2_pt.Write();
    output_file.Close();

    // done
    return;
}
