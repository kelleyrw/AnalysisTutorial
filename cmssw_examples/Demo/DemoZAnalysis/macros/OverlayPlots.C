#include "RootTools.h"
#include <string>

void PrintBasicPlots
(
    const std::string& input_file_name  = "plots/dy_plots.root",
    const std::string& output_path = "plots/basic",
    const std::string& suffix = "eps"
)
{
    // load the histograms
    rt::TH1Container hc(input_file_name);
    hc.List();

    // write
    hc.Print(output_path, suffix);

    // done
    return;
}

void OverlayPlots
(
    const std::string& input_file_name  = "plots/dy_plots.root",
    const std::string& output_path = "plots/overlays",
    const std::string& suffix = "eps"
)
{
    // load the histograms
    rt::TH1Container hc(input_file_name);

    // mass plots 
    std::map<std::string, rt::TH1Overlay> p;
    p["p_z_mass"] = rt::TH1Overlay("Z-boson Invariant Mass;mass (GeV/c^2);a.u.", "sb::off lg::top_right");
    p["p_z_mass"].Add(hc["h_gen_mz" ], "m_{Z}" , kBlack, 2); 
    p["p_z_mass"].Add(hc["h_gen_mll"], "m_{ll}", kRed ,  2); 
/*     p["p_z_mass"].SetOption("hist"); */
    
    p["p_mll_mass"] = rt::TH1Overlay("Dilepton Invariant Mass;m_{ll} (GeV/c^2);a.u.", "sb::off lg::top_right dt::norm");
    p["p_mll_mass"].Add(hc["h_gen_mll" ], "gen" , kBlack, 2); 
    p["p_mll_mass"].Add(hc["h_reco_mll"], "reco", kRed ,  2); 
/*     p["p_mll_mass"].SetOption("hist"); */

    p["p_mee_mass"] = rt::TH1Overlay("Dielectron Invariant Mass;m_{ee} (GeV/c^2);a.u.", "sb::off lg::top_right dt::norm");
    p["p_mee_mass"].Add(hc["h_gen_mee" ], "gen" , kBlack, 2); 
    p["p_mee_mass"].Add(hc["h_reco_mee"], "reco", kRed ,  2); 
/*     p["p_mee_mass"].SetOption("hist"); */
    
    p["p_mmm_mass"] = rt::TH1Overlay("Dimuon Invariant Mass;m_{#mu#mu} (GeV/c^2);a.u.", "sb::off lg::top_right dt::norm");
    p["p_mmm_mass"].Add(hc["h_gen_mmm" ], "gen" , kBlack, 2); 
    p["p_mmm_mass"].Add(hc["h_reco_mmm"], "reco", kRed ,  2); 
/*     p["p_mmm_mass"].SetOption("hist"); */

    // gen leptons
    p["p_gen_l1_eta"] = rt::TH1Overlay("l_{1} #eta;#eta;a.u.", "sb::top_right lg::top_left");
    p["p_gen_l1_eta"].Add(hc["h_gen_e1_eta" ], "electron", kBlue, 2); 
    p["p_gen_l1_eta"].Add(hc["h_gen_mu1_eta"], "muon"    , kRed , 2); 

    p["p_gen_l2_eta"] = rt::TH1Overlay("l_{2} #eta;#eta;a.u.", "sb::top_right lg::top_left");
    p["p_gen_l2_eta"].Add(hc["h_gen_e2_eta" ], "electron", kBlue, 2); 
    p["p_gen_l2_eta"].Add(hc["h_gen_mu2_eta"], "muon"    , kRed , 2); 

    p["p_gen_l1_pt"] = rt::TH1Overlay("l_{1} p_{T};p_{T} (GeV);a.u.", "sb::top_right lg::right");
    p["p_gen_l1_pt"].Add(hc["h_gen_e1_pt" ], "electron", kBlue, 2); 
    p["p_gen_l1_pt"].Add(hc["h_gen_mu1_pt"], "muon"    , kRed , 2); 

    p["p_gen_l2_pt"] = rt::TH1Overlay("l_{2} p_{T};p_{T} (GeV);a.u.", "sb::top_right lg::right");
    p["p_gen_l2_pt"].Add(hc["h_gen_e2_pt" ], "electron", kBlue, 2); 
    p["p_gen_l2_pt"].Add(hc["h_gen_mu2_pt"], "muon"    , kRed , 2); 

    // matched leptons
    p["p_reco_e1_pt"] = rt::TH1Overlay("e_{1} p_{T};p_{T} (GeV)", "sb::top_right lg::top_left dt::norm");
    p["p_reco_e1_pt"].Add(hc["h_gen_e1_pt" ], "gen" , kBlue, 2); 
    p["p_reco_e1_pt"].Add(hc["h_reco_e1_pt"], "reco", kRed , 2); 

    p["p_reco_e2_pt"] = rt::TH1Overlay("e_{2} p_{T};p_{T} (GeV)", "sb::top_right lg::top_left dt::norm");
    p["p_reco_e2_pt"].Add(hc["h_gen_e2_pt" ], "gen" , kBlue, 2); 
    p["p_reco_e2_pt"].Add(hc["h_reco_e2_pt"], "reco", kRed , 2); 

    p["p_reco_mu1_pt"] = rt::TH1Overlay("#mu_{1} p_{T};p_{T} (GeV)", "sb::top_right lg::top_left dt::norm");
    p["p_reco_mu1_pt"].Add(hc["h_gen_mu1_pt" ], "gen" , kBlue, 2); 
    p["p_reco_mu1_pt"].Add(hc["h_reco_mu1_pt"], "reco", kRed , 2); 

    p["p_reco_mu2_pt"] = rt::TH1Overlay("#mu_{2} p_{T};p_{T} (GeV)", "sb::top_right lg::top_left dt::norm");
    p["p_reco_mu2_pt"].Add(hc["h_gen_mu2_pt" ], "gen" , kBlue, 2); 
    p["p_reco_mu2_pt"].Add(hc["h_reco_mu2_pt"], "reco", kRed , 2); 

    // matched leptons
    p["p_reco_e_eff_vs_pt"] = rt::TH1Overlay("electron efficiency vs p_{T};p_{T} (GeV);#epsilon", "sb::off lg::top_left");
    p["p_reco_e_eff_vs_pt"].Add(hc["h_e1_eff_vs_pt"], "higher p_{T} electron", kBlue, 2); 
    p["p_reco_e_eff_vs_pt"].Add(hc["h_e2_eff_vs_pt"], "lower p_{T} electron" , kRed , 2); 
    p["p_reco_e_eff_vs_pt"].SetYAxisRange(0.3, 1.2);

    p["p_reco_mu_eff_vs_pt"] = rt::TH1Overlay("muon efficiency vs p_{T};p_{T} (GeV);#epsilon", "sb::off lg::top_left");
    p["p_reco_mu_eff_vs_pt"].Add(hc["h_mu1_eff_vs_pt"], "higher p_{T} muon", kBlue, 2); 
    p["p_reco_mu_eff_vs_pt"].Add(hc["h_mu2_eff_vs_pt"], "lower p_{T} muon" , kRed , 2); 
    p["p_reco_mu_eff_vs_pt"].SetYAxisRange(0.3, 1.2);

    p["p_reco_sigma_vs_pt"] = rt::TH1Overlay("lepton resolution vs p_{T};p_{T} (GeV);#sigma(residual) (GeV)", "sb::off lg::top_left");
    p["p_reco_sigma_vs_pt"].Add(hc["h_sigma_e1_vs_pt" ], "higher p_{T} electron", kBlack   , 2);
    p["p_reco_sigma_vs_pt"].Add(hc["h_sigma_e2_vs_pt" ], "lower p_{T} electron" , kBlue    , 2);
    p["p_reco_sigma_vs_pt"].Add(hc["h_sigma_mu1_vs_pt"], "higher p_{T} muon"    , kRed     , 2);
    p["p_reco_sigma_vs_pt"].Add(hc["h_sigma_mu2_vs_pt"], "lower p_{T} muon"     , kGreen+2 , 2);

    // z-mass resolution
    p["p_reco_sigma_vs_mz"] = rt::TH1Overlay("Invariant Mass Resolution;mass (GeV/c^2);a.u.", "sb::off lg::top_right");
    p["p_reco_sigma_vs_mz"].Add(hc["h_sigma_mee"], "m_{ee}"    , kBlack, 2); 
    p["p_reco_sigma_vs_mz"].Add(hc["h_sigma_mmm"], "m_{#mu#mu}", kRed ,  2); 

    // print
    rt::Print(p, output_path, suffix);

    // done
    return;
}
