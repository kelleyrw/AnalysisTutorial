#include <iostream>
#include <string>
#include <map>
#include "TCanvas.h"
#include "TChain.h"
#include "TH1D.h"
#include "TCut.h"
#include "TDirectory.h"
#include "TSystem.h"
#include "TLegend.h"
#include "THStack.h"
#include "HistTools.h"

// simple type to hold selection info
struct Selection
{
    std::string name;
    std::string title;
    TCut cut;
};

// a list of selections that are applied cumulatively
const std::vector<Selection>& GetElectronSelections()
{
    static std::vector<Selection> selections
    {
        {"base", "Base selections", "is_el"         },
        {"fid" , "Passes Fiducial", "el_is_fiducial"},
        {"pt20", "p_{T} > 20 GeV" , "p4.pt() > 20"  }
    };
    return selections;
}

// convenenice typedef for a simple histogram container
typedef std::map<std::string, TH1*> TH1Map;

// book the histograms
void BookHists(TH1Map& hm)
{
    TH1::SetDefaultSumw2(true);

    // electron plots
    for (const auto& s : GetElectronSelections())
    {
        AddHist(hm, new TH1D(Form("h_el_pt_%s" , s.name.c_str()), Form("Electron p_{T} (%s);p_{T} (GeV)", s.title.c_str()), 100,  0, 100));
        AddHist(hm, new TH1D(Form("h_el_eta_%s", s.name.c_str()), Form("Electron #eta (%s);#eta"        , s.title.c_str()), 100, -5,   5));
    }
}

// use TTree::Draw to create all the hists for each selection
void CreateElectronHists
(
    const std::string& sample,
    const bool require_prompt,
    const std::string& label
)
{
    // ntuple
    // ----------------------------- // 

    TChain chain("tree");
    chain.Add(Form("babies/%s_baby.root", sample.c_str()));
    const double num_entries = chain.GetEntries();

    // hists
    // ----------------------------- // 

    TH1Map hm;
    BookHists(hm);

    // Fill hists
    // ----------------------------- // 

    SetDirectory(hm, gDirectory);
    TCut selection = (require_prompt ? "is_prompt" : "!is_prompt");
    for (const auto& s : GetElectronSelections())
    {
        // cumulative selection
        selection = selection && s.cut;
        // normalizing to 100%
/*         selection = Form("%1.5e*(%s)", 100.0/num_entries, (selection && s.cut).GetTitle()); */
/*         std::cout << selection << std::endl; */

        // fill the hists
        chain.Draw(Form("p4.pt()>>h_el_pt_%s"  , s.name.c_str()), selection, "goff");
        chain.Draw(Form("p4.eta()>>h_el_eta_%s", s.name.c_str()), selection, "goff");
    }
    SetDirectory(hm, NULL);

    // write plots
    // ----------------------------- // 

    gSystem->Exec(Form("mkdir -p plots/%s", label.c_str()));
    SaveHists(hm, Form("plots/%s/%s_plots.root", label.c_str(), sample.c_str()));

    // cleanup
    ClearHists(hm);
}
    
// simple overlaying routine
void PrintOverlays
(
    const std::string label,
    const std::vector<Selection>& selections,
    TH1Map& hm_sig, 
    TH1Map& hm_bkg, 
    const std::string hist_stem,
    const std::string hist_title,
    const bool log_plot = false,
    const std::string suffix = "png"
)
{
    for (const auto& s : selections)
    {
        // formatting
        TH1& h_sig = *hm_sig[hist_stem + "_" + s.name];
        h_sig.SetLineWidth(2);

        TH1& h_bkg = *hm_bkg[hist_stem + "_" + s.name];
        h_bkg.SetLineWidth(2);

        const std::string plot_name = Form("p_%s_%s", hist_stem.substr(2, std::string::npos).c_str(), s.name.c_str());

        // create stack
        THStack hs(plot_name.c_str(), hist_title.c_str());
        hs.Add(&h_sig);
        hs.Add(&h_bkg);

        // legend
        TLegend legend(0.7, 0.9, 0.9, 0.75);
        legend.AddEntry(&h_sig, "Drell-Yan", "L");
        legend.AddEntry(&h_bkg, "QCD"      , "L");
        legend.SetFillColor(0);  // 0 makes it the background clear on the pad
        legend.SetFillStyle(0);
        legend.SetBorderSize(0);

        // write
        TCanvas c1;
        hs.Draw("nostack");
        legend.Draw();
        c1.SetLogy(log_plot);
        c1.Print(Form("plots/%s/overlays/%s/%s.%s", label.c_str(), suffix.c_str(), plot_name.c_str(), suffix.c_str()));
    }    
}

// create the overlays for dyll and QCD samples
void CreateOverlays(const std::string& label, const std::string& suffix = "png")
{
    std::cout << "[CreatePlots] creating overlays plots" << std::endl;

    // get prompt plots
    TH1Map hm_sig;
    LoadHists(hm_sig, Form("plots/%s/dyll_plots.root", label.c_str()));
    SetLineColor(hm_sig, kBlue);
    NormalizeHists(hm_sig);

    // get none prompt plots
    TH1Map hm_bkg;
    LoadHists(hm_bkg, Form("plots/%s/qcd_plots.root", label.c_str()));
    SetLineColor(hm_bkg, kRed);
    NormalizeHists(hm_bkg);

    // create overlay
    gSystem->Exec(Form("mkdir -p plots/%s/overlays/%s", label.c_str(), suffix.c_str()));
    PrintOverlays(label, GetElectronSelections(), hm_sig, hm_bkg, "h_el_pt" , "Electron p_{T}; p_{T} (GeV)", /*log_plot=*/false, suffix);
    PrintOverlays(label, GetElectronSelections(), hm_sig, hm_bkg, "h_el_eta", "Electron #eta; #eta"        , /*log_plot=*/false, suffix);
}

// Do all the plots
void CreatePlots(const std::string& label = "test", const std::string& suffix = "png")
{
    std::cout << "[CreatePlots] creating dyll plots" << std::endl;
    CreateElectronHists("dyll", /*prompt=*/true , label);

    std::cout << "[CreatePlots] creating QCD plots" << std::endl;
    CreateElectronHists("qcd" , /*prompt=*/false, label);

    CreateOverlays(label, suffix);
}
