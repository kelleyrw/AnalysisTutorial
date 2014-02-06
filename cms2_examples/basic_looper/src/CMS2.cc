#include "CMS2.h"
CMS2 cms2;
namespace tas {
	const TBits &hlt_bits() { return cms2.hlt_bits(); }
	const vector<TString> &evt_CMS2tag() { return cms2.evt_CMS2tag(); }
	const vector<TString> &evt_dataset() { return cms2.evt_dataset(); }
	const vector<TString> &hlt_trigNames() { return cms2.hlt_trigNames(); }
	const vector<TString> &l1_techtrigNames() { return cms2.l1_techtrigNames(); }
	const vector<TString> &l1_trigNames() { return cms2.l1_trigNames(); }
	const vector<TString> &evt_errCategory() { return cms2.evt_errCategory(); }
	const vector<TString> &evt_errModule() { return cms2.evt_errModule(); }
	const vector<TString> &evt_errSeverity() { return cms2.evt_errSeverity(); }
	const vector<TString> &sparm_comment() { return cms2.sparm_comment(); }
	const vector<TString> &sparm_names() { return cms2.sparm_names(); }
	const bool &evt_eventHasHalo() { return cms2.evt_eventHasHalo(); }
	const bool &hcalnoise_HasBadRBXTS4TS5() { return cms2.hcalnoise_HasBadRBXTS4TS5(); }
	const bool &ls_isValid() { return cms2.ls_isValid(); }
	const bool &filt_ecalBE() { return cms2.filt_ecalBE(); }
	const bool &filt_ecalDR() { return cms2.filt_ecalDR(); }
	const bool &filt_ecalLaser() { return cms2.filt_ecalLaser(); }
	const bool &filt_ecalTP() { return cms2.filt_ecalTP(); }
	const bool &filt_eeBadSc() { return cms2.filt_eeBadSc(); }
	const bool &filt_greedyMuon() { return cms2.filt_greedyMuon(); }
	const bool &filt_hcalLaser() { return cms2.filt_hcalLaser(); }
	const bool &filt_inconsistentMuon() { return cms2.filt_inconsistentMuon(); }
	const bool &filt_jetIDFailure() { return cms2.filt_jetIDFailure(); }
	const bool &filt_multiEvent() { return cms2.filt_multiEvent(); }
	const bool &filt_trackingFailure() { return cms2.filt_trackingFailure(); }
	const bool &evt_hbheFilter() { return cms2.evt_hbheFilter(); }
	const vector<bool> &els_conv_vtx_flag() { return cms2.els_conv_vtx_flag(); }
	const vector<bool> &els_passingMvaPreselection() { return cms2.els_passingMvaPreselection(); }
	const vector<bool> &els_passingPflowPreselection() { return cms2.els_passingPflowPreselection(); }
	const vector<bool> &mus_isRPCMuon() { return cms2.mus_isRPCMuon(); }
	const vector<bool> &mus_tightMatch() { return cms2.mus_tightMatch(); }
	const vector<bool> &mus_updatedSta() { return cms2.mus_updatedSta(); }
	const vector<bool> &pfcands_isMuIso() { return cms2.pfcands_isMuIso(); }
	const vector<bool> &photons_haspixelSeed() { return cms2.photons_haspixelSeed(); }
	const vector<double> &jets_closestElectron_DR() { return cms2.jets_closestElectron_DR(); }
	const vector<double> &jets_closestMuon_DR() { return cms2.jets_closestMuon_DR(); }
	const float &evt_bs_Xwidth() { return cms2.evt_bs_Xwidth(); }
	const float &evt_bs_XwidthErr() { return cms2.evt_bs_XwidthErr(); }
	const float &evt_bs_Ywidth() { return cms2.evt_bs_Ywidth(); }
	const float &evt_bs_YwidthErr() { return cms2.evt_bs_YwidthErr(); }
	const float &evt_bs_dxdz() { return cms2.evt_bs_dxdz(); }
	const float &evt_bs_dxdzErr() { return cms2.evt_bs_dxdzErr(); }
	const float &evt_bs_dydz() { return cms2.evt_bs_dydz(); }
	const float &evt_bs_dydzErr() { return cms2.evt_bs_dydzErr(); }
	const float &evt_bs_sigmaZ() { return cms2.evt_bs_sigmaZ(); }
	const float &evt_bs_sigmaZErr() { return cms2.evt_bs_sigmaZErr(); }
	const float &evt_bs_xErr() { return cms2.evt_bs_xErr(); }
	const float &evt_bs_yErr() { return cms2.evt_bs_yErr(); }
	const float &evt_bs_zErr() { return cms2.evt_bs_zErr(); }
	const float &evt_bField() { return cms2.evt_bField(); }
	const float &evt_rho() { return cms2.evt_rho(); }
	const float &evt_rhoJEC() { return cms2.evt_rhoJEC(); }
	const float &evt_fixgrid_all_rho() { return cms2.evt_fixgrid_all_rho(); }
	const float &evt_fixgridfastjet_all_rho() { return cms2.evt_fixgridfastjet_all_rho(); }
	const float &evt_kfactor() { return cms2.evt_kfactor(); }
	const float &evt_scale1fb() { return cms2.evt_scale1fb(); }
	const float &evt_xsec_excl() { return cms2.evt_xsec_excl(); }
	const float &evt_xsec_incl() { return cms2.evt_xsec_incl(); }
	const float &gen_met() { return cms2.gen_met(); }
	const float &gen_metPhi() { return cms2.gen_metPhi(); }
	const float &genps_alphaQCD() { return cms2.genps_alphaQCD(); }
	const float &genps_pthat() { return cms2.genps_pthat(); }
	const float &genps_qScale() { return cms2.genps_qScale(); }
	const float &genps_weight() { return cms2.genps_weight(); }
	const float &gen_sumEt() { return cms2.gen_sumEt(); }
	const float &hcalnoise_GetRecHitEnergy() { return cms2.hcalnoise_GetRecHitEnergy(); }
	const float &hcalnoise_GetRecHitEnergy15() { return cms2.hcalnoise_GetRecHitEnergy15(); }
	const float &hcalnoise_GetTotalCalibCharge() { return cms2.hcalnoise_GetTotalCalibCharge(); }
	const float &hcalnoise_TS4TS5NoiseSumE() { return cms2.hcalnoise_TS4TS5NoiseSumE(); }
	const float &hcalnoise_TS4TS5NoiseSumEt() { return cms2.hcalnoise_TS4TS5NoiseSumEt(); }
	const float &hcalnoise_eventChargeFraction() { return cms2.hcalnoise_eventChargeFraction(); }
	const float &hcalnoise_eventEMEnergy() { return cms2.hcalnoise_eventEMEnergy(); }
	const float &hcalnoise_eventEMFraction() { return cms2.hcalnoise_eventEMFraction(); }
	const float &hcalnoise_eventHadEnergy() { return cms2.hcalnoise_eventHadEnergy(); }
	const float &hcalnoise_eventTrackEnergy() { return cms2.hcalnoise_eventTrackEnergy(); }
	const float &hcalnoise_flatNoiseSumE() { return cms2.hcalnoise_flatNoiseSumE(); }
	const float &hcalnoise_flatNoiseSumEt() { return cms2.hcalnoise_flatNoiseSumEt(); }
	const float &hcalnoise_isolatedNoiseSumE() { return cms2.hcalnoise_isolatedNoiseSumE(); }
	const float &hcalnoise_isolatedNoiseSumEt() { return cms2.hcalnoise_isolatedNoiseSumEt(); }
	const float &hcalnoise_max10GeVHitTime() { return cms2.hcalnoise_max10GeVHitTime(); }
	const float &hcalnoise_max25GeVHitTime() { return cms2.hcalnoise_max25GeVHitTime(); }
	const float &hcalnoise_maxE10TS() { return cms2.hcalnoise_maxE10TS(); }
	const float &hcalnoise_maxE2Over10TS() { return cms2.hcalnoise_maxE2Over10TS(); }
	const float &hcalnoise_maxE2TS() { return cms2.hcalnoise_maxE2TS(); }
	const float &hcalnoise_min10GeVHitTime() { return cms2.hcalnoise_min10GeVHitTime(); }
	const float &hcalnoise_min25GeVHitTime() { return cms2.hcalnoise_min25GeVHitTime(); }
	const float &hcalnoise_minE10TS() { return cms2.hcalnoise_minE10TS(); }
	const float &hcalnoise_minE2Over10TS() { return cms2.hcalnoise_minE2Over10TS(); }
	const float &hcalnoise_minE2TS() { return cms2.hcalnoise_minE2TS(); }
	const float &hcalnoise_minHPDEMF() { return cms2.hcalnoise_minHPDEMF(); }
	const float &hcalnoise_minRBXEMF() { return cms2.hcalnoise_minRBXEMF(); }
	const float &hcalnoise_rms10GeVHitTime() { return cms2.hcalnoise_rms10GeVHitTime(); }
	const float &hcalnoise_rms25GeVHitTime() { return cms2.hcalnoise_rms25GeVHitTime(); }
	const float &hcalnoise_spikeNoiseSumE() { return cms2.hcalnoise_spikeNoiseSumE(); }
	const float &hcalnoise_spikeNoiseSumEt() { return cms2.hcalnoise_spikeNoiseSumEt(); }
	const float &hcalnoise_triangleNoiseSumE() { return cms2.hcalnoise_triangleNoiseSumE(); }
	const float &hcalnoise_triangleNoiseSumEt() { return cms2.hcalnoise_triangleNoiseSumEt(); }
	const float &evt_kt6calo_central_rho() { return cms2.evt_kt6calo_central_rho(); }
	const float &evt_kt6calo_muhlt_rho() { return cms2.evt_kt6calo_muhlt_rho(); }
	const float &evt_kt6calo_rho() { return cms2.evt_kt6calo_rho(); }
	const float &evt_kt6pf_ctrChargedPU_rho() { return cms2.evt_kt6pf_ctrChargedPU_rho(); }
	const float &evt_kt6pf_ctrNeutral_rho() { return cms2.evt_kt6pf_ctrNeutral_rho(); }
	const float &evt_kt6pf_ctrNeutralTight_rho() { return cms2.evt_kt6pf_ctrNeutralTight_rho(); }
	const float &evt_kt6pf_foregiso_rho() { return cms2.evt_kt6pf_foregiso_rho(); }
	const float &l1_met_etTot() { return cms2.l1_met_etTot(); }
	const float &l1_met_met() { return cms2.l1_met_met(); }
	const float &l1_mht_htTot() { return cms2.l1_mht_htTot(); }
	const float &l1_mht_mht() { return cms2.l1_mht_mht(); }
	const float &ls_avgInsDelLumi() { return cms2.ls_avgInsDelLumi(); }
	const float &ls_avgInsDelLumiErr() { return cms2.ls_avgInsDelLumiErr(); }
	const float &ls_avgInsRecLumi() { return cms2.ls_avgInsRecLumi(); }
	const float &ls_avgInsRecLumiErr() { return cms2.ls_avgInsRecLumiErr(); }
	const float &ls_deadFrac() { return cms2.ls_deadFrac(); }
	const float &ls_intgDelLumi() { return cms2.ls_intgDelLumi(); }
	const float &ls_intgRecLumi() { return cms2.ls_intgRecLumi(); }
	const float &ls_lumiSectionLength() { return cms2.ls_lumiSectionLength(); }
	const float &evt_ecalendcapm_met() { return cms2.evt_ecalendcapm_met(); }
	const float &evt_ecalendcapm_metPhi() { return cms2.evt_ecalendcapm_metPhi(); }
	const float &evt_ecalendcapp_met() { return cms2.evt_ecalendcapp_met(); }
	const float &evt_ecalendcapp_metPhi() { return cms2.evt_ecalendcapp_metPhi(); }
	const float &evt_ecalmet() { return cms2.evt_ecalmet(); }
	const float &evt_ecalmetPhi() { return cms2.evt_ecalmetPhi(); }
	const float &evt_endcapm_met() { return cms2.evt_endcapm_met(); }
	const float &evt_endcapm_metPhi() { return cms2.evt_endcapm_metPhi(); }
	const float &evt_endcapp_met() { return cms2.evt_endcapp_met(); }
	const float &evt_endcapp_metPhi() { return cms2.evt_endcapp_metPhi(); }
	const float &evt_hcalendcapm_met() { return cms2.evt_hcalendcapm_met(); }
	const float &evt_hcalendcapm_metPhi() { return cms2.evt_hcalendcapm_metPhi(); }
	const float &evt_hcalendcapp_met() { return cms2.evt_hcalendcapp_met(); }
	const float &evt_hcalendcapp_metPhi() { return cms2.evt_hcalendcapp_metPhi(); }
	const float &evt_hcalmet() { return cms2.evt_hcalmet(); }
	const float &evt_hcalmetPhi() { return cms2.evt_hcalmetPhi(); }
	const float &evt_met() { return cms2.evt_met(); }
	const float &evt_met_EtGt3() { return cms2.evt_met_EtGt3(); }
	const float &evt_metHO() { return cms2.evt_metHO(); }
	const float &evt_metHOPhi() { return cms2.evt_metHOPhi(); }
	const float &evt_metHOSig() { return cms2.evt_metHOSig(); }
	const float &evt_metMuonCorr() { return cms2.evt_metMuonCorr(); }
	const float &evt_metMuonCorrPhi() { return cms2.evt_metMuonCorrPhi(); }
	const float &evt_metMuonCorrSig() { return cms2.evt_metMuonCorrSig(); }
	const float &evt_metMuonJESCorr() { return cms2.evt_metMuonJESCorr(); }
	const float &evt_metMuonJESCorrPhi() { return cms2.evt_metMuonJESCorrPhi(); }
	const float &evt_metMuonJESCorrSig() { return cms2.evt_metMuonJESCorrSig(); }
	const float &evt_metNoHF() { return cms2.evt_metNoHF(); }
	const float &evt_metNoHFHO() { return cms2.evt_metNoHFHO(); }
	const float &evt_metNoHFHOPhi() { return cms2.evt_metNoHFHOPhi(); }
	const float &evt_metNoHFHOSig() { return cms2.evt_metNoHFHOSig(); }
	const float &evt_metNoHFPhi() { return cms2.evt_metNoHFPhi(); }
	const float &evt_metNoHFSig() { return cms2.evt_metNoHFSig(); }
	const float &evt_metOpt() { return cms2.evt_metOpt(); }
	const float &evt_metOptHO() { return cms2.evt_metOptHO(); }
	const float &evt_metOptHOPhi() { return cms2.evt_metOptHOPhi(); }
	const float &evt_metOptHOSig() { return cms2.evt_metOptHOSig(); }
	const float &evt_metOptNoHF() { return cms2.evt_metOptNoHF(); }
	const float &evt_metOptNoHFHO() { return cms2.evt_metOptNoHFHO(); }
	const float &evt_metOptNoHFHOPhi() { return cms2.evt_metOptNoHFHOPhi(); }
	const float &evt_metOptNoHFHOSig() { return cms2.evt_metOptNoHFHOSig(); }
	const float &evt_metOptNoHFPhi() { return cms2.evt_metOptNoHFPhi(); }
	const float &evt_metOptNoHFSig() { return cms2.evt_metOptNoHFSig(); }
	const float &evt_metOptPhi() { return cms2.evt_metOptPhi(); }
	const float &evt_metOptSig() { return cms2.evt_metOptSig(); }
	const float &evt_metPhi() { return cms2.evt_metPhi(); }
	const float &evt_metPhi_EtGt3() { return cms2.evt_metPhi_EtGt3(); }
	const float &evt_metSig() { return cms2.evt_metSig(); }
	const float &evt_sumet() { return cms2.evt_sumet(); }
	const float &evt_sumet_EtGt3() { return cms2.evt_sumet_EtGt3(); }
	const float &evt_sumetHO() { return cms2.evt_sumetHO(); }
	const float &evt_sumetMuonCorr() { return cms2.evt_sumetMuonCorr(); }
	const float &evt_sumetMuonJESCorr() { return cms2.evt_sumetMuonJESCorr(); }
	const float &evt_sumetNoHF() { return cms2.evt_sumetNoHF(); }
	const float &evt_sumetNoHFHO() { return cms2.evt_sumetNoHFHO(); }
	const float &evt_sumetOpt() { return cms2.evt_sumetOpt(); }
	const float &evt_sumetOptHO() { return cms2.evt_sumetOptHO(); }
	const float &evt_sumetOptNoHF() { return cms2.evt_sumetOptNoHF(); }
	const float &evt_sumetOptNoHFHO() { return cms2.evt_sumetOptNoHFHO(); }
	const float &pdfinfo_pdf1() { return cms2.pdfinfo_pdf1(); }
	const float &pdfinfo_pdf2() { return cms2.pdfinfo_pdf2(); }
	const float &pdfinfo_scale() { return cms2.pdfinfo_scale(); }
	const float &pdfinfo_x1() { return cms2.pdfinfo_x1(); }
	const float &pdfinfo_x2() { return cms2.pdfinfo_x2(); }
	const float &evt_fixgrid_rho_all() { return cms2.evt_fixgrid_rho_all(); }
	const float &evt_fixgrid_rho_ctr() { return cms2.evt_fixgrid_rho_ctr(); }
	const float &evt_fixgrid_rho_fwd() { return cms2.evt_fixgrid_rho_fwd(); }
	const float &evt_pfmet() { return cms2.evt_pfmet(); }
	const float &evt_pfmetPhi() { return cms2.evt_pfmetPhi(); }
	const float &evt_pfmetPhi_type1cor() { return cms2.evt_pfmetPhi_type1cor(); }
	const float &evt_pfmetSig() { return cms2.evt_pfmetSig(); }
	const float &evt_pfmetSignificance() { return cms2.evt_pfmetSignificance(); }
	const float &evt_pfmet_type1cor() { return cms2.evt_pfmet_type1cor(); }
	const float &evt_pfsumet() { return cms2.evt_pfsumet(); }
	const float &sparm_filterEfficiency() { return cms2.sparm_filterEfficiency(); }
	const float &sparm_pdfScale() { return cms2.sparm_pdfScale(); }
	const float &sparm_pdfWeight1() { return cms2.sparm_pdfWeight1(); }
	const float &sparm_pdfWeight2() { return cms2.sparm_pdfWeight2(); }
	const float &sparm_weight() { return cms2.sparm_weight(); }
	const float &sparm_xsec() { return cms2.sparm_xsec(); }
	const float &evt_pf_tcmet() { return cms2.evt_pf_tcmet(); }
	const float &evt_pf_tcmetPhi() { return cms2.evt_pf_tcmetPhi(); }
	const float &evt_pf_tcmetSig() { return cms2.evt_pf_tcmetSig(); }
	const float &evt_pf_tcsumet() { return cms2.evt_pf_tcsumet(); }
	const float &evt_tcmet() { return cms2.evt_tcmet(); }
	const float &evt_tcmetPhi() { return cms2.evt_tcmetPhi(); }
	const float &evt_tcmetSig() { return cms2.evt_tcmetSig(); }
	const float &evt_tcsumet() { return cms2.evt_tcsumet(); }
	const float &evt_ww_rho_act() { return cms2.evt_ww_rho_act(); }
	const float &evt_ww_rho() { return cms2.evt_ww_rho(); }
	const float &evt_ww_rho_rnd() { return cms2.evt_ww_rho_rnd(); }
	const float &evt_ww_rho_vor() { return cms2.evt_ww_rho_vor(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &evt_bsp4() { return cms2.evt_bsp4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &l1_met_p4() { return cms2.l1_met_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &l1_mht_p4() { return cms2.l1_mht_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_motherp4() { return cms2.els_mc_motherp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_p4() { return cms2.els_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_mc_gp_p4() { return cms2.jets_mc_gp_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_mc_motherp4() { return cms2.jets_mc_motherp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_mc_p4() { return cms2.jets_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_motherp4() { return cms2.mus_mc_motherp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_p4() { return cms2.mus_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_gp_p4() { return cms2.pfjets_mc_gp_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_motherp4() { return cms2.pfjets_mc_motherp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_p4() { return cms2.pfjets_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_motherp4() { return cms2.photons_mc_motherp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_p4() { return cms2.photons_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trk_mcp4() { return cms2.trk_mcp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_conv_pos_p4() { return cms2.els_conv_pos_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_inner_position() { return cms2.els_inner_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_outer_position() { return cms2.els_outer_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4() { return cms2.els_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4In() { return cms2.els_p4In(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4Out() { return cms2.els_p4Out(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_p4() { return cms2.els_trk_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_vertex_p4() { return cms2.els_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4() { return cms2.genjets_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms2.genps_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_prod_vtx() { return cms2.genps_prod_vtx(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_inner_position() { return cms2.gsftrks_inner_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_outer_p4() { return cms2.gsftrks_outer_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_outer_position() { return cms2.gsftrks_outer_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_p4() { return cms2.gsftrks_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_vertex_p4() { return cms2.gsftrks_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_p4() { return cms2.hyp_ll_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_trk_p4() { return cms2.hyp_ll_trk_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_p4() { return cms2.hyp_lt_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_trk_p4() { return cms2.hyp_lt_trk_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_p4() { return cms2.hyp_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_FVFit_p4() { return cms2.hyp_FVFit_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_FVFit_v4() { return cms2.hyp_FVFit_v4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_mc_p4() { return cms2.hyp_ll_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_mc_p4() { return cms2.hyp_lt_mc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4() { return cms2.jets_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_vertex_p4() { return cms2.jets_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_emiso_p4() { return cms2.l1_emiso_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_emnoiso_p4() { return cms2.l1_emnoiso_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_jetsc_p4() { return cms2.l1_jetsc_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_jetsf_p4() { return cms2.l1_jetsf_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_jetst_p4() { return cms2.l1_jetst_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &l1_mus_p4() { return cms2.l1_mus_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_ecalpos_p4() { return cms2.mus_ecalpos_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_fitpicky_p4() { return cms2.mus_fitpicky_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_fittev_p4() { return cms2.mus_fittev_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_fittpfms_p4() { return cms2.mus_fittpfms_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_outerPos_p4() { return cms2.mus_gfit_outerPos_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_p4() { return cms2.mus_gfit_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_vertex_p4() { return cms2.mus_gfit_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_p4() { return cms2.mus_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfp4() { return cms2.mus_pfp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfposAtEcal_p4() { return cms2.mus_pfposAtEcal_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_p4() { return cms2.mus_sta_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_vertex_p4() { return cms2.mus_sta_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_trk_p4() { return cms2.mus_trk_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_vertex_p4() { return cms2.mus_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_p4() { return cms2.pfcands_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_posAtEcal_p4() { return cms2.pfcands_posAtEcal_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfels_p4() { return cms2.pfels_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfels_posAtEcal_p4() { return cms2.pfels_posAtEcal_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms2.pfjets_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfmus_p4() { return cms2.pfmus_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfmus_posAtEcal_p4() { return cms2.pfmus_posAtEcal_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_p4() { return cms2.taus_pf_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_p4() { return cms2.photons_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &convs_refitPairMom_p4() { return cms2.convs_refitPairMom_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &convs_vtxpos() { return cms2.convs_vtxpos(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &scs_p4() { return cms2.scs_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &scs_pos_p4() { return cms2.scs_pos_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &scs_vtx_p4() { return cms2.scs_vtx_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_flight() { return cms2.svs_flight(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_mc3_p4() { return cms2.svs_mc3_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_p4() { return cms2.svs_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_position() { return cms2.svs_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_refitp4() { return cms2.svs_refitp4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_inner_position() { return cms2.trks_inner_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_outer_p4() { return cms2.trks_outer_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_outer_position() { return cms2.trks_outer_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_trk_p4() { return cms2.trks_trk_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_vertex_p4() { return cms2.trks_vertex_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trkjets_p4() { return cms2.trkjets_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &vtxs_position() { return cms2.vtxs_position(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &bsvtxs_position() { return cms2.bsvtxs_position(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &els_convs_pos_p4() { return cms2.els_convs_pos_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &genps_lepdaughter_p4() { return cms2.genps_lepdaughter_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hlt_trigObjs_p4() { return cms2.hlt_trigObjs_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hyp_jets_p4() { return cms2.hyp_jets_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hyp_other_jets_p4() { return cms2.hyp_other_jets_p4(); }
	const vector<float> &jpts_combinedSecondaryVertexBJetTag() { return cms2.jpts_combinedSecondaryVertexBJetTag(); }
	const vector<float> &jpts_combinedSecondaryVertexMVABJetTag() { return cms2.jpts_combinedSecondaryVertexMVABJetTag(); }
	const vector<float> &jpts_jetBProbabilityBJetTag() { return cms2.jpts_jetBProbabilityBJetTag(); }
	const vector<float> &jpts_jetProbabilityBJetTag() { return cms2.jpts_jetProbabilityBJetTag(); }
	const vector<float> &jpts_simpleSecondaryVertexBJetTag() { return cms2.jpts_simpleSecondaryVertexBJetTag(); }
	const vector<float> &jpts_simpleSecondaryVertexHighEffBJetTag() { return cms2.jpts_simpleSecondaryVertexHighEffBJetTag(); }
	const vector<float> &jpts_simpleSecondaryVertexHighPurBJetTags() { return cms2.jpts_simpleSecondaryVertexHighPurBJetTags(); }
	const vector<float> &jpts_softElectronByIP3dBJetTag() { return cms2.jpts_softElectronByIP3dBJetTag(); }
	const vector<float> &jpts_softElectronByPtBJetTag() { return cms2.jpts_softElectronByPtBJetTag(); }
	const vector<float> &jpts_softElectronTag() { return cms2.jpts_softElectronTag(); }
	const vector<float> &jpts_softMuonBJetTag() { return cms2.jpts_softMuonBJetTag(); }
	const vector<float> &jpts_softMuonByIP3dBJetTag() { return cms2.jpts_softMuonByIP3dBJetTag(); }
	const vector<float> &jpts_softMuonByPtBJetTag() { return cms2.jpts_softMuonByPtBJetTag(); }
	const vector<float> &jpts_trackCountingHighEffBJetTag() { return cms2.jpts_trackCountingHighEffBJetTag(); }
	const vector<float> &jpts_trackCountingHighPurBJetTag() { return cms2.jpts_trackCountingHighPurBJetTag(); }
	const vector<float> &jets_combinedSecondaryVertexBJetTag() { return cms2.jets_combinedSecondaryVertexBJetTag(); }
	const vector<float> &jets_combinedSecondaryVertexMVABJetTag() { return cms2.jets_combinedSecondaryVertexMVABJetTag(); }
	const vector<float> &jets_jetBProbabilityBJetTag() { return cms2.jets_jetBProbabilityBJetTag(); }
	const vector<float> &jets_jetProbabilityBJetTag() { return cms2.jets_jetProbabilityBJetTag(); }
	const vector<float> &jets_simpleSecondaryVertexBJetTag() { return cms2.jets_simpleSecondaryVertexBJetTag(); }
	const vector<float> &jets_simpleSecondaryVertexHighEffBJetTag() { return cms2.jets_simpleSecondaryVertexHighEffBJetTag(); }
	const vector<float> &jets_simpleSecondaryVertexHighPurBJetTags() { return cms2.jets_simpleSecondaryVertexHighPurBJetTags(); }
	const vector<float> &jets_softElectronByIP3dBJetTag() { return cms2.jets_softElectronByIP3dBJetTag(); }
	const vector<float> &jets_softElectronByPtBJetTag() { return cms2.jets_softElectronByPtBJetTag(); }
	const vector<float> &jets_softElectronTag() { return cms2.jets_softElectronTag(); }
	const vector<float> &jets_softMuonBJetTag() { return cms2.jets_softMuonBJetTag(); }
	const vector<float> &jets_softMuonByIP3dBJetTag() { return cms2.jets_softMuonByIP3dBJetTag(); }
	const vector<float> &jets_softMuonByPtBJetTag() { return cms2.jets_softMuonByPtBJetTag(); }
	const vector<float> &jets_trackCountingHighEffBJetTag() { return cms2.jets_trackCountingHighEffBJetTag(); }
	const vector<float> &jets_trackCountingHighPurBJetTag() { return cms2.jets_trackCountingHighPurBJetTag(); }
	const vector<float> &pfjets_combinedSecondaryVertexBJetTag() { return cms2.pfjets_combinedSecondaryVertexBJetTag(); }
	const vector<float> &pfjets_combinedSecondaryVertexMVABJetTag() { return cms2.pfjets_combinedSecondaryVertexMVABJetTag(); }
	const vector<float> &pfjets_jetBProbabilityBJetTag() { return cms2.pfjets_jetBProbabilityBJetTag(); }
	const vector<float> &pfjets_jetProbabilityBJetTag() { return cms2.pfjets_jetProbabilityBJetTag(); }
	const vector<float> &pfjets_simpleSecondaryVertexBJetTag() { return cms2.pfjets_simpleSecondaryVertexBJetTag(); }
	const vector<float> &pfjets_simpleSecondaryVertexHighEffBJetTag() { return cms2.pfjets_simpleSecondaryVertexHighEffBJetTag(); }
	const vector<float> &pfjets_simpleSecondaryVertexHighPurBJetTags() { return cms2.pfjets_simpleSecondaryVertexHighPurBJetTags(); }
	const vector<float> &pfjets_softElectronByIP3dBJetTag() { return cms2.pfjets_softElectronByIP3dBJetTag(); }
	const vector<float> &pfjets_softElectronByPtBJetTag() { return cms2.pfjets_softElectronByPtBJetTag(); }
	const vector<float> &pfjets_softElectronTag() { return cms2.pfjets_softElectronTag(); }
	const vector<float> &pfjets_softMuonBJetTag() { return cms2.pfjets_softMuonBJetTag(); }
	const vector<float> &pfjets_softMuonByIP3dBJetTag() { return cms2.pfjets_softMuonByIP3dBJetTag(); }
	const vector<float> &pfjets_softMuonByPtBJetTag() { return cms2.pfjets_softMuonByPtBJetTag(); }
	const vector<float> &pfjets_trackCountingHighEffBJetTag() { return cms2.pfjets_trackCountingHighEffBJetTag(); }
	const vector<float> &pfjets_trackCountingHighPurBJetTag() { return cms2.pfjets_trackCountingHighPurBJetTag(); }
	const vector<float> &trkjets_combinedSecondaryVertexBJetTag() { return cms2.trkjets_combinedSecondaryVertexBJetTag(); }
	const vector<float> &trkjets_combinedSecondaryVertexMVABJetTag() { return cms2.trkjets_combinedSecondaryVertexMVABJetTag(); }
	const vector<float> &trkjets_jetBProbabilityBJetTag() { return cms2.trkjets_jetBProbabilityBJetTag(); }
	const vector<float> &trkjets_jetProbabilityBJetTag() { return cms2.trkjets_jetProbabilityBJetTag(); }
	const vector<float> &trkjets_simpleSecondaryVertexBJetTag() { return cms2.trkjets_simpleSecondaryVertexBJetTag(); }
	const vector<float> &trkjets_simpleSecondaryVertexHighEffBJetTag() { return cms2.trkjets_simpleSecondaryVertexHighEffBJetTag(); }
	const vector<float> &trkjets_simpleSecondaryVertexHighPurBJetTags() { return cms2.trkjets_simpleSecondaryVertexHighPurBJetTags(); }
	const vector<float> &trkjets_softElectronByIP3dBJetTag() { return cms2.trkjets_softElectronByIP3dBJetTag(); }
	const vector<float> &trkjets_softElectronByPtBJetTag() { return cms2.trkjets_softElectronByPtBJetTag(); }
	const vector<float> &trkjets_softElectronTag() { return cms2.trkjets_softElectronTag(); }
	const vector<float> &trkjets_softMuonBJetTag() { return cms2.trkjets_softMuonBJetTag(); }
	const vector<float> &trkjets_softMuonByIP3dBJetTag() { return cms2.trkjets_softMuonByIP3dBJetTag(); }
	const vector<float> &trkjets_softMuonByPtBJetTag() { return cms2.trkjets_softMuonByPtBJetTag(); }
	const vector<float> &trkjets_trackCountingHighEffBJetTag() { return cms2.trkjets_trackCountingHighEffBJetTag(); }
	const vector<float> &trkjets_trackCountingHighPurBJetTag() { return cms2.trkjets_trackCountingHighPurBJetTag(); }
	const vector<float> &evt_bs_covMatrix() { return cms2.evt_bs_covMatrix(); }
	const vector<float> &els_mc3dr() { return cms2.els_mc3dr(); }
	const vector<float> &els_mcdr() { return cms2.els_mcdr(); }
	const vector<float> &jets_mc3dr() { return cms2.jets_mc3dr(); }
	const vector<float> &jets_mcdr() { return cms2.jets_mcdr(); }
	const vector<float> &jets_mc_emEnergy() { return cms2.jets_mc_emEnergy(); }
	const vector<float> &jets_mc_gpdr() { return cms2.jets_mc_gpdr(); }
	const vector<float> &jets_mc_hadEnergy() { return cms2.jets_mc_hadEnergy(); }
	const vector<float> &jets_mc_invEnergy() { return cms2.jets_mc_invEnergy(); }
	const vector<float> &jets_mc_otherEnergy() { return cms2.jets_mc_otherEnergy(); }
	const vector<float> &mus_mc3dr() { return cms2.mus_mc3dr(); }
	const vector<float> &mus_mcdr() { return cms2.mus_mcdr(); }
	const vector<float> &pfjets_mc3dr() { return cms2.pfjets_mc3dr(); }
	const vector<float> &pfjets_mcdr() { return cms2.pfjets_mcdr(); }
	const vector<float> &pfjets_mc_emEnergy() { return cms2.pfjets_mc_emEnergy(); }
	const vector<float> &pfjets_mc_gpdr() { return cms2.pfjets_mc_gpdr(); }
	const vector<float> &pfjets_mc_hadEnergy() { return cms2.pfjets_mc_hadEnergy(); }
	const vector<float> &pfjets_mc_invEnergy() { return cms2.pfjets_mc_invEnergy(); }
	const vector<float> &pfjets_mc_otherEnergy() { return cms2.pfjets_mc_otherEnergy(); }
	const vector<float> &photons_mc3dr() { return cms2.photons_mc3dr(); }
	const vector<float> &photons_mcdr() { return cms2.photons_mcdr(); }
	const vector<float> &trk_mc3dr() { return cms2.trk_mc3dr(); }
	const vector<float> &trk_mcdr() { return cms2.trk_mcdr(); }
	const vector<float> &els_ecalJuraIso() { return cms2.els_ecalJuraIso(); }
	const vector<float> &els_ecalJuraTowerIso() { return cms2.els_ecalJuraTowerIso(); }
	const vector<float> &els_hcalConeIso() { return cms2.els_hcalConeIso(); }
	const vector<float> &els_tkJuraIso() { return cms2.els_tkJuraIso(); }
	const vector<float> &els_jetdr() { return cms2.els_jetdr(); }
	const vector<float> &els_musdr() { return cms2.els_musdr(); }
	const vector<float> &els_isoR03_chpf_radial() { return cms2.els_isoR03_chpf_radial(); }
	const vector<float> &els_isoR03_chpf_radialTight() { return cms2.els_isoR03_chpf_radialTight(); }
	const vector<float> &els_isoR03_chpf_radialTight_bv() { return cms2.els_isoR03_chpf_radialTight_bv(); }
	const vector<float> &els_isoR03_chpf_radial_bv() { return cms2.els_isoR03_chpf_radial_bv(); }
	const vector<float> &els_isoR03_empf_radial() { return cms2.els_isoR03_empf_radial(); }
	const vector<float> &els_isoR03_empf_radialTight() { return cms2.els_isoR03_empf_radialTight(); }
	const vector<float> &els_isoR03_empf_radialTight_bv() { return cms2.els_isoR03_empf_radialTight_bv(); }
	const vector<float> &els_isoR03_empf_radial_bv() { return cms2.els_isoR03_empf_radial_bv(); }
	const vector<float> &els_isoR03_nhpf_radial() { return cms2.els_isoR03_nhpf_radial(); }
	const vector<float> &els_isoR03_nhpf_radialTight() { return cms2.els_isoR03_nhpf_radialTight(); }
	const vector<float> &els_isoR03_nhpf_radialTight_bv() { return cms2.els_isoR03_nhpf_radialTight_bv(); }
	const vector<float> &els_isoR03_nhpf_radial_bv() { return cms2.els_isoR03_nhpf_radial_bv(); }
	const vector<float> &els_isoR03_pf2012n0p5_ch() { return cms2.els_isoR03_pf2012n0p5_ch(); }
	const vector<float> &els_isoR03_pf2012n0p5_em() { return cms2.els_isoR03_pf2012n0p5_em(); }
	const vector<float> &els_isoR03_pf2012n0p5_nh() { return cms2.els_isoR03_pf2012n0p5_nh(); }
	const vector<float> &els_isoR03_pf_radial() { return cms2.els_isoR03_pf_radial(); }
	const vector<float> &els_isoR03_pf_radialTight() { return cms2.els_isoR03_pf_radialTight(); }
	const vector<float> &els_isoR03_pf_radialTight_bv() { return cms2.els_isoR03_pf_radialTight_bv(); }
	const vector<float> &els_isoR03_pf_radial_bv() { return cms2.els_isoR03_pf_radial_bv(); }
	const vector<float> &els_chi2() { return cms2.els_chi2(); }
	const vector<float> &els_ckf_chi2() { return cms2.els_ckf_chi2(); }
	const vector<float> &els_ckf_ndof() { return cms2.els_ckf_ndof(); }
	const vector<float> &els_conv_dcot() { return cms2.els_conv_dcot(); }
	const vector<float> &els_conv_dist() { return cms2.els_conv_dist(); }
	const vector<float> &els_conv_old_dcot() { return cms2.els_conv_old_dcot(); }
	const vector<float> &els_conv_old_dist() { return cms2.els_conv_old_dist(); }
	const vector<float> &els_conv_old_radius() { return cms2.els_conv_old_radius(); }
	const vector<float> &els_conv_radius() { return cms2.els_conv_radius(); }
	const vector<float> &els_d0() { return cms2.els_d0(); }
	const vector<float> &els_d0Err() { return cms2.els_d0Err(); }
	const vector<float> &els_d0corr() { return cms2.els_d0corr(); }
	const vector<float> &els_dEtaIn() { return cms2.els_dEtaIn(); }
	const vector<float> &els_dEtaOut() { return cms2.els_dEtaOut(); }
	const vector<float> &els_dPhiIn() { return cms2.els_dPhiIn(); }
	const vector<float> &els_dPhiInPhiOut() { return cms2.els_dPhiInPhiOut(); }
	const vector<float> &els_dPhiOut() { return cms2.els_dPhiOut(); }
	const vector<float> &els_deltaEtaEleClusterTrackAtCalo() { return cms2.els_deltaEtaEleClusterTrackAtCalo(); }
	const vector<float> &els_deltaPhiEleClusterTrackAtCalo() { return cms2.els_deltaPhiEleClusterTrackAtCalo(); }
	const vector<float> &els_e1x5() { return cms2.els_e1x5(); }
	const vector<float> &els_e2x5Max() { return cms2.els_e2x5Max(); }
	const vector<float> &els_e3x3() { return cms2.els_e3x3(); }
	const vector<float> &els_e5x5() { return cms2.els_e5x5(); }
	const vector<float> &els_eMax() { return cms2.els_eMax(); }
	const vector<float> &els_eOverPIn() { return cms2.els_eOverPIn(); }
	const vector<float> &els_eOverPOut() { return cms2.els_eOverPOut(); }
	const vector<float> &els_eSC() { return cms2.els_eSC(); }
	const vector<float> &els_eSCPresh() { return cms2.els_eSCPresh(); }
	const vector<float> &els_eSCRaw() { return cms2.els_eSCRaw(); }
	const vector<float> &els_eSeed() { return cms2.els_eSeed(); }
	const vector<float> &els_eSeedOverPIn() { return cms2.els_eSeedOverPIn(); }
	const vector<float> &els_eSeedOverPOut() { return cms2.els_eSeedOverPOut(); }
	const vector<float> &els_ecalEnergy() { return cms2.els_ecalEnergy(); }
	const vector<float> &els_ecalEnergyError() { return cms2.els_ecalEnergyError(); }
	const vector<float> &els_ecalIso() { return cms2.els_ecalIso(); }
	const vector<float> &els_ecalIso04() { return cms2.els_ecalIso04(); }
	const vector<float> &els_etaErr() { return cms2.els_etaErr(); }
	const vector<float> &els_etaSC() { return cms2.els_etaSC(); }
	const vector<float> &els_etaSCwidth() { return cms2.els_etaSCwidth(); }
	const vector<float> &els_fbrem() { return cms2.els_fbrem(); }
	const vector<float> &els_hOverE() { return cms2.els_hOverE(); }
	const vector<float> &els_hcalDepth1OverEcal() { return cms2.els_hcalDepth1OverEcal(); }
	const vector<float> &els_hcalDepth1TowerSumEt() { return cms2.els_hcalDepth1TowerSumEt(); }
	const vector<float> &els_hcalDepth1TowerSumEt04() { return cms2.els_hcalDepth1TowerSumEt04(); }
	const vector<float> &els_hcalDepth2OverEcal() { return cms2.els_hcalDepth2OverEcal(); }
	const vector<float> &els_hcalDepth2TowerSumEt() { return cms2.els_hcalDepth2TowerSumEt(); }
	const vector<float> &els_hcalDepth2TowerSumEt04() { return cms2.els_hcalDepth2TowerSumEt04(); }
	const vector<float> &els_hcalIso() { return cms2.els_hcalIso(); }
	const vector<float> &els_hcalIso04() { return cms2.els_hcalIso04(); }
	const vector<float> &els_ip3d() { return cms2.els_ip3d(); }
	const vector<float> &els_ip3derr() { return cms2.els_ip3derr(); }
	const vector<float> &els_iso03_pf() { return cms2.els_iso03_pf(); }
	const vector<float> &els_iso03_pf2012_ch() { return cms2.els_iso03_pf2012_ch(); }
	const vector<float> &els_iso03_pf2012_em() { return cms2.els_iso03_pf2012_em(); }
	const vector<float> &els_iso03_pf2012ext_ch() { return cms2.els_iso03_pf2012ext_ch(); }
	const vector<float> &els_iso03_pf2012ext_em() { return cms2.els_iso03_pf2012ext_em(); }
	const vector<float> &els_iso03_pf2012ext_nh() { return cms2.els_iso03_pf2012ext_nh(); }
	const vector<float> &els_iso03_pf2012_nh() { return cms2.els_iso03_pf2012_nh(); }
	const vector<float> &els_iso03_pf_ch() { return cms2.els_iso03_pf_ch(); }
	const vector<float> &els_iso03_pf_gamma05() { return cms2.els_iso03_pf_gamma05(); }
	const vector<float> &els_iso03_pf_nhad05() { return cms2.els_iso03_pf_nhad05(); }
	const vector<float> &els_iso04_pf() { return cms2.els_iso04_pf(); }
	const vector<float> &els_iso04_pf2012_ch() { return cms2.els_iso04_pf2012_ch(); }
	const vector<float> &els_iso04_pf2012_em() { return cms2.els_iso04_pf2012_em(); }
	const vector<float> &els_iso04_pf2012ext_ch() { return cms2.els_iso04_pf2012ext_ch(); }
	const vector<float> &els_iso04_pf2012ext_em() { return cms2.els_iso04_pf2012ext_em(); }
	const vector<float> &els_iso04_pf2012ext_nh() { return cms2.els_iso04_pf2012ext_nh(); }
	const vector<float> &els_iso04_pf2012_nh() { return cms2.els_iso04_pf2012_nh(); }
	const vector<float> &els_iso04_pf_ch() { return cms2.els_iso04_pf_ch(); }
	const vector<float> &els_iso04_pf_gamma05() { return cms2.els_iso04_pf_gamma05(); }
	const vector<float> &els_iso04_pf_nhad05() { return cms2.els_iso04_pf_nhad05(); }
	const vector<float> &els_layer1_charge() { return cms2.els_layer1_charge(); }
	const vector<float> &els_lh() { return cms2.els_lh(); }
	const vector<float> &els_mva() { return cms2.els_mva(); }
	const vector<float> &els_ndof() { return cms2.els_ndof(); }
	const vector<float> &els_pfChargedHadronIso() { return cms2.els_pfChargedHadronIso(); }
	const vector<float> &els_pfNeutralHadronIso() { return cms2.els_pfNeutralHadronIso(); }
	const vector<float> &els_pfPhotonIso() { return cms2.els_pfPhotonIso(); }
	const vector<float> &els_phiErr() { return cms2.els_phiErr(); }
	const vector<float> &els_phiSC() { return cms2.els_phiSC(); }
	const vector<float> &els_phiSCwidth() { return cms2.els_phiSCwidth(); }
	const vector<float> &els_ptErr() { return cms2.els_ptErr(); }
	const vector<float> &els_r9() { return cms2.els_r9(); }
	const vector<float> &els_sigmaEtaEta() { return cms2.els_sigmaEtaEta(); }
	const vector<float> &els_sigmaIEtaIEta() { return cms2.els_sigmaIEtaIEta(); }
	const vector<float> &els_sigmaIEtaIEtaSC() { return cms2.els_sigmaIEtaIEtaSC(); }
	const vector<float> &els_sigmaIEtaIPhi() { return cms2.els_sigmaIEtaIPhi(); }
	const vector<float> &els_sigmaIPhiIPhi() { return cms2.els_sigmaIPhiIPhi(); }
	const vector<float> &els_sigmaIPhiIPhiSC() { return cms2.els_sigmaIPhiIPhiSC(); }
	const vector<float> &els_sigmaIphiIphi() { return cms2.els_sigmaIphiIphi(); }
	const vector<float> &els_sigmaPhiPhi() { return cms2.els_sigmaPhiPhi(); }
	const vector<float> &els_tkIso() { return cms2.els_tkIso(); }
	const vector<float> &els_tkIso04() { return cms2.els_tkIso04(); }
	const vector<float> &els_trackMomentumError() { return cms2.els_trackMomentumError(); }
	const vector<float> &els_trkdr() { return cms2.els_trkdr(); }
	const vector<float> &els_trkshFrac() { return cms2.els_trkshFrac(); }
	const vector<float> &els_z0() { return cms2.els_z0(); }
	const vector<float> &els_z0Err() { return cms2.els_z0Err(); }
	const vector<float> &els_z0corr() { return cms2.els_z0corr(); }
	const vector<float> &gsftrks_chi2() { return cms2.gsftrks_chi2(); }
	const vector<float> &gsftrks_d0() { return cms2.gsftrks_d0(); }
	const vector<float> &gsftrks_d0Err() { return cms2.gsftrks_d0Err(); }
	const vector<float> &gsftrks_d0corr() { return cms2.gsftrks_d0corr(); }
	const vector<float> &gsftrks_d0corrPhi() { return cms2.gsftrks_d0corrPhi(); }
	const vector<float> &gsftrks_d0phiCov() { return cms2.gsftrks_d0phiCov(); }
	const vector<float> &gsftrks_etaErr() { return cms2.gsftrks_etaErr(); }
	const vector<float> &gsftrks_layer1_charge() { return cms2.gsftrks_layer1_charge(); }
	const vector<float> &gsftrks_ndof() { return cms2.gsftrks_ndof(); }
	const vector<float> &gsftrks_phiErr() { return cms2.gsftrks_phiErr(); }
	const vector<float> &gsftrks_ptErr() { return cms2.gsftrks_ptErr(); }
	const vector<float> &gsftrks_z0() { return cms2.gsftrks_z0(); }
	const vector<float> &gsftrks_z0Err() { return cms2.gsftrks_z0Err(); }
	const vector<float> &gsftrks_z0corr() { return cms2.gsftrks_z0corr(); }
	const vector<float> &hyp_Ht() { return cms2.hyp_Ht(); }
	const vector<float> &hyp_dPhi_nJet_metMuonJESCorr() { return cms2.hyp_dPhi_nJet_metMuonJESCorr(); }
	const vector<float> &hyp_dPhi_nJet_muCorrMet() { return cms2.hyp_dPhi_nJet_muCorrMet(); }
	const vector<float> &hyp_dPhi_nJet_tcMet() { return cms2.hyp_dPhi_nJet_tcMet(); }
	const vector<float> &hyp_dPhi_nJet_unCorrMet() { return cms2.hyp_dPhi_nJet_unCorrMet(); }
	const vector<float> &hyp_ll_chi2() { return cms2.hyp_ll_chi2(); }
	const vector<float> &hyp_ll_d0() { return cms2.hyp_ll_d0(); }
	const vector<float> &hyp_ll_d0Err() { return cms2.hyp_ll_d0Err(); }
	const vector<float> &hyp_ll_d0corr() { return cms2.hyp_ll_d0corr(); }
	const vector<float> &hyp_ll_dPhi_metMuonJESCorr() { return cms2.hyp_ll_dPhi_metMuonJESCorr(); }
	const vector<float> &hyp_ll_dPhi_muCorrMet() { return cms2.hyp_ll_dPhi_muCorrMet(); }
	const vector<float> &hyp_ll_dPhi_tcMet() { return cms2.hyp_ll_dPhi_tcMet(); }
	const vector<float> &hyp_ll_dPhi_unCorrMet() { return cms2.hyp_ll_dPhi_unCorrMet(); }
	const vector<float> &hyp_ll_etaErr() { return cms2.hyp_ll_etaErr(); }
	const vector<float> &hyp_ll_ndof() { return cms2.hyp_ll_ndof(); }
	const vector<float> &hyp_ll_phiErr() { return cms2.hyp_ll_phiErr(); }
	const vector<float> &hyp_ll_ptErr() { return cms2.hyp_ll_ptErr(); }
	const vector<float> &hyp_ll_z0() { return cms2.hyp_ll_z0(); }
	const vector<float> &hyp_ll_z0Err() { return cms2.hyp_ll_z0Err(); }
	const vector<float> &hyp_ll_z0corr() { return cms2.hyp_ll_z0corr(); }
	const vector<float> &hyp_lt_chi2() { return cms2.hyp_lt_chi2(); }
	const vector<float> &hyp_lt_d0() { return cms2.hyp_lt_d0(); }
	const vector<float> &hyp_lt_d0Err() { return cms2.hyp_lt_d0Err(); }
	const vector<float> &hyp_lt_d0corr() { return cms2.hyp_lt_d0corr(); }
	const vector<float> &hyp_lt_dPhi_metMuonJESCorr() { return cms2.hyp_lt_dPhi_metMuonJESCorr(); }
	const vector<float> &hyp_lt_dPhi_muCorrMet() { return cms2.hyp_lt_dPhi_muCorrMet(); }
	const vector<float> &hyp_lt_dPhi_tcMet() { return cms2.hyp_lt_dPhi_tcMet(); }
	const vector<float> &hyp_lt_dPhi_unCorrMet() { return cms2.hyp_lt_dPhi_unCorrMet(); }
	const vector<float> &hyp_lt_etaErr() { return cms2.hyp_lt_etaErr(); }
	const vector<float> &hyp_lt_ndof() { return cms2.hyp_lt_ndof(); }
	const vector<float> &hyp_lt_phiErr() { return cms2.hyp_lt_phiErr(); }
	const vector<float> &hyp_lt_ptErr() { return cms2.hyp_lt_ptErr(); }
	const vector<float> &hyp_lt_z0() { return cms2.hyp_lt_z0(); }
	const vector<float> &hyp_lt_z0Err() { return cms2.hyp_lt_z0Err(); }
	const vector<float> &hyp_lt_z0corr() { return cms2.hyp_lt_z0corr(); }
	const vector<float> &hyp_mt2_metMuonJESCorr() { return cms2.hyp_mt2_metMuonJESCorr(); }
	const vector<float> &hyp_mt2_muCorrMet() { return cms2.hyp_mt2_muCorrMet(); }
	const vector<float> &hyp_mt2_tcMet() { return cms2.hyp_mt2_tcMet(); }
	const vector<float> &hyp_sumJetPt() { return cms2.hyp_sumJetPt(); }
	const vector<float> &hyp_FVFit_chi2ndf() { return cms2.hyp_FVFit_chi2ndf(); }
	const vector<float> &hyp_FVFit_prob() { return cms2.hyp_FVFit_prob(); }
	const vector<float> &hyp_FVFit_v4cxx() { return cms2.hyp_FVFit_v4cxx(); }
	const vector<float> &hyp_FVFit_v4cxy() { return cms2.hyp_FVFit_v4cxy(); }
	const vector<float> &hyp_FVFit_v4cyy() { return cms2.hyp_FVFit_v4cyy(); }
	const vector<float> &hyp_FVFit_v4czx() { return cms2.hyp_FVFit_v4czx(); }
	const vector<float> &hyp_FVFit_v4czy() { return cms2.hyp_FVFit_v4czy(); }
	const vector<float> &hyp_FVFit_v4czz() { return cms2.hyp_FVFit_v4czz(); }
	const vector<float> &jets_approximatefHPD() { return cms2.jets_approximatefHPD(); }
	const vector<float> &jets_approximatefRBX() { return cms2.jets_approximatefRBX(); }
	const vector<float> &jets_cor() { return cms2.jets_cor(); }
	const vector<float> &jets_corL1FastL2L3() { return cms2.jets_corL1FastL2L3(); }
	const vector<float> &jets_corL1L2L3() { return cms2.jets_corL1L2L3(); }
	const vector<float> &jets_emFrac() { return cms2.jets_emFrac(); }
	const vector<float> &jets_fHPD() { return cms2.jets_fHPD(); }
	const vector<float> &jets_fRBX() { return cms2.jets_fRBX(); }
	const vector<float> &jets_fSubDetector1() { return cms2.jets_fSubDetector1(); }
	const vector<float> &jets_fSubDetector2() { return cms2.jets_fSubDetector2(); }
	const vector<float> &jets_fSubDetector3() { return cms2.jets_fSubDetector3(); }
	const vector<float> &jets_fSubDetector4() { return cms2.jets_fSubDetector4(); }
	const vector<float> &jets_hitsInN90() { return cms2.jets_hitsInN90(); }
	const vector<float> &jets_n90Hits() { return cms2.jets_n90Hits(); }
	const vector<float> &jets_nECALTowers() { return cms2.jets_nECALTowers(); }
	const vector<float> &jets_nHCALTowers() { return cms2.jets_nHCALTowers(); }
	const vector<float> &jets_restrictedEMF() { return cms2.jets_restrictedEMF(); }
	const vector<float> &mus_met_deltax() { return cms2.mus_met_deltax(); }
	const vector<float> &mus_met_deltay() { return cms2.mus_met_deltay(); }
	const vector<float> &mus_eledr() { return cms2.mus_eledr(); }
	const vector<float> &mus_jetdr() { return cms2.mus_jetdr(); }
	const vector<float> &mus_isoR03_chpf_radial() { return cms2.mus_isoR03_chpf_radial(); }
	const vector<float> &mus_isoR03_chpf_radialTight() { return cms2.mus_isoR03_chpf_radialTight(); }
	const vector<float> &mus_isoR03_empf_radial() { return cms2.mus_isoR03_empf_radial(); }
	const vector<float> &mus_isoR03_empf_radialTight() { return cms2.mus_isoR03_empf_radialTight(); }
	const vector<float> &mus_isoR03_nhpf_radial() { return cms2.mus_isoR03_nhpf_radial(); }
	const vector<float> &mus_isoR03_nhpf_radialTight() { return cms2.mus_isoR03_nhpf_radialTight(); }
	const vector<float> &mus_isoR03_pf_radial() { return cms2.mus_isoR03_pf_radial(); }
	const vector<float> &mus_isoR03_pf_radialTight() { return cms2.mus_isoR03_pf_radialTight(); }
	const vector<float> &mus_backToBackCompat() { return cms2.mus_backToBackCompat(); }
	const vector<float> &mus_caloCompatibility() { return cms2.mus_caloCompatibility(); }
	const vector<float> &mus_chi2() { return cms2.mus_chi2(); }
	const vector<float> &mus_chi2LocalMomentum() { return cms2.mus_chi2LocalMomentum(); }
	const vector<float> &mus_chi2LocalPosition() { return cms2.mus_chi2LocalPosition(); }
	const vector<float> &mus_cosmicCompat() { return cms2.mus_cosmicCompat(); }
	const vector<float> &mus_d0() { return cms2.mus_d0(); }
	const vector<float> &mus_d0Err() { return cms2.mus_d0Err(); }
	const vector<float> &mus_d0corr() { return cms2.mus_d0corr(); }
	const vector<float> &mus_e_em() { return cms2.mus_e_em(); }
	const vector<float> &mus_e_emS9() { return cms2.mus_e_emS9(); }
	const vector<float> &mus_e_had() { return cms2.mus_e_had(); }
	const vector<float> &mus_e_hadS9() { return cms2.mus_e_hadS9(); }
	const vector<float> &mus_e_ho() { return cms2.mus_e_ho(); }
	const vector<float> &mus_e_hoS9() { return cms2.mus_e_hoS9(); }
	const vector<float> &mus_etaErr() { return cms2.mus_etaErr(); }
	const vector<float> &mus_gfit_chi2() { return cms2.mus_gfit_chi2(); }
	const vector<float> &mus_gfit_d0() { return cms2.mus_gfit_d0(); }
	const vector<float> &mus_gfit_d0Err() { return cms2.mus_gfit_d0Err(); }
	const vector<float> &mus_gfit_d0corr() { return cms2.mus_gfit_d0corr(); }
	const vector<float> &mus_gfit_ndof() { return cms2.mus_gfit_ndof(); }
	const vector<float> &mus_gfit_qoverp() { return cms2.mus_gfit_qoverp(); }
	const vector<float> &mus_gfit_qoverpError() { return cms2.mus_gfit_qoverpError(); }
	const vector<float> &mus_gfit_z0() { return cms2.mus_gfit_z0(); }
	const vector<float> &mus_gfit_z0Err() { return cms2.mus_gfit_z0Err(); }
	const vector<float> &mus_gfit_z0corr() { return cms2.mus_gfit_z0corr(); }
	const vector<float> &mus_glbKink() { return cms2.mus_glbKink(); }
	const vector<float> &mus_glbTrackProbability() { return cms2.mus_glbTrackProbability(); }
	const vector<float> &mus_globalDeltaEtaPhi() { return cms2.mus_globalDeltaEtaPhi(); }
	const vector<float> &mus_ip3d() { return cms2.mus_ip3d(); }
	const vector<float> &mus_ip3derr() { return cms2.mus_ip3derr(); }
	const vector<float> &mus_iso03_emEt() { return cms2.mus_iso03_emEt(); }
	const vector<float> &mus_iso03_hadEt() { return cms2.mus_iso03_hadEt(); }
	const vector<float> &mus_iso03_hoEt() { return cms2.mus_iso03_hoEt(); }
	const vector<float> &mus_iso03_pf() { return cms2.mus_iso03_pf(); }
	const vector<float> &mus_iso03_sumPt() { return cms2.mus_iso03_sumPt(); }
	const vector<float> &mus_iso04_pf() { return cms2.mus_iso04_pf(); }
	const vector<float> &mus_iso05_emEt() { return cms2.mus_iso05_emEt(); }
	const vector<float> &mus_iso05_hadEt() { return cms2.mus_iso05_hadEt(); }
	const vector<float> &mus_iso05_hoEt() { return cms2.mus_iso05_hoEt(); }
	const vector<float> &mus_iso05_sumPt() { return cms2.mus_iso05_sumPt(); }
	const vector<float> &mus_isoR03_pf_ChargedHadronPt() { return cms2.mus_isoR03_pf_ChargedHadronPt(); }
	const vector<float> &mus_isoR03_pf_ChargedParticlePt() { return cms2.mus_isoR03_pf_ChargedParticlePt(); }
	const vector<float> &mus_isoR03_pf_NeutralHadronEt() { return cms2.mus_isoR03_pf_NeutralHadronEt(); }
	const vector<float> &mus_isoR03_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR03_pf_NeutralHadronEtHighThreshold(); }
	const vector<float> &mus_isoR03_pf_PUPt() { return cms2.mus_isoR03_pf_PUPt(); }
	const vector<float> &mus_isoR03_pf_PhotonEt() { return cms2.mus_isoR03_pf_PhotonEt(); }
	const vector<float> &mus_isoR03_pf_PhotonEtHighThreshold() { return cms2.mus_isoR03_pf_PhotonEtHighThreshold(); }
	const vector<float> &mus_isoR04_pf_ChargedHadronPt() { return cms2.mus_isoR04_pf_ChargedHadronPt(); }
	const vector<float> &mus_isoR04_pf_ChargedParticlePt() { return cms2.mus_isoR04_pf_ChargedParticlePt(); }
	const vector<float> &mus_isoR04_pf_NeutralHadronEt() { return cms2.mus_isoR04_pf_NeutralHadronEt(); }
	const vector<float> &mus_isoR04_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR04_pf_NeutralHadronEtHighThreshold(); }
	const vector<float> &mus_isoR04_pf_PUPt() { return cms2.mus_isoR04_pf_PUPt(); }
	const vector<float> &mus_isoR04_pf_PhotonEt() { return cms2.mus_isoR04_pf_PhotonEt(); }
	const vector<float> &mus_isoR04_pf_PhotonEtHighThreshold() { return cms2.mus_isoR04_pf_PhotonEtHighThreshold(); }
	const vector<float> &mus_iso_ecalvetoDep() { return cms2.mus_iso_ecalvetoDep(); }
	const vector<float> &mus_iso_hcalvetoDep() { return cms2.mus_iso_hcalvetoDep(); }
	const vector<float> &mus_iso_hovetoDep() { return cms2.mus_iso_hovetoDep(); }
	const vector<float> &mus_iso_trckvetoDep() { return cms2.mus_iso_trckvetoDep(); }
	const vector<float> &mus_localDistance() { return cms2.mus_localDistance(); }
	const vector<float> &mus_ndof() { return cms2.mus_ndof(); }
	const vector<float> &mus_overlapCompat() { return cms2.mus_overlapCompat(); }
	const vector<float> &mus_pfdeltaP() { return cms2.mus_pfdeltaP(); }
	const vector<float> &mus_pfecalE() { return cms2.mus_pfecalE(); }
	const vector<float> &mus_pfhcalE() { return cms2.mus_pfhcalE(); }
	const vector<float> &mus_pfmva_emu() { return cms2.mus_pfmva_emu(); }
	const vector<float> &mus_pfmva_epi() { return cms2.mus_pfmva_epi(); }
	const vector<float> &mus_pfmva_nothing_gamma() { return cms2.mus_pfmva_nothing_gamma(); }
	const vector<float> &mus_pfmva_nothing_nh() { return cms2.mus_pfmva_nothing_nh(); }
	const vector<float> &mus_pfmva_pimu() { return cms2.mus_pfmva_pimu(); }
	const vector<float> &mus_pfpS1E() { return cms2.mus_pfpS1E(); }
	const vector<float> &mus_pfpS2E() { return cms2.mus_pfpS2E(); }
	const vector<float> &mus_pfrawEcalE() { return cms2.mus_pfrawEcalE(); }
	const vector<float> &mus_pfrawHcalE() { return cms2.mus_pfrawHcalE(); }
	const vector<float> &mus_phiErr() { return cms2.mus_phiErr(); }
	const vector<float> &mus_ptErr() { return cms2.mus_ptErr(); }
	const vector<float> &mus_qoverp() { return cms2.mus_qoverp(); }
	const vector<float> &mus_qoverpError() { return cms2.mus_qoverpError(); }
	const vector<float> &mus_segmCompatibility() { return cms2.mus_segmCompatibility(); }
	const vector<float> &mus_staRelChi2() { return cms2.mus_staRelChi2(); }
	const vector<float> &mus_sta_chi2() { return cms2.mus_sta_chi2(); }
	const vector<float> &mus_sta_d0() { return cms2.mus_sta_d0(); }
	const vector<float> &mus_sta_d0Err() { return cms2.mus_sta_d0Err(); }
	const vector<float> &mus_sta_d0corr() { return cms2.mus_sta_d0corr(); }
	const vector<float> &mus_sta_ndof() { return cms2.mus_sta_ndof(); }
	const vector<float> &mus_sta_qoverp() { return cms2.mus_sta_qoverp(); }
	const vector<float> &mus_sta_qoverpError() { return cms2.mus_sta_qoverpError(); }
	const vector<float> &mus_sta_z0() { return cms2.mus_sta_z0(); }
	const vector<float> &mus_sta_z0Err() { return cms2.mus_sta_z0Err(); }
	const vector<float> &mus_sta_z0corr() { return cms2.mus_sta_z0corr(); }
	const vector<float> &mus_timeAtIpInOut() { return cms2.mus_timeAtIpInOut(); }
	const vector<float> &mus_timeAtIpInOutErr() { return cms2.mus_timeAtIpInOutErr(); }
	const vector<float> &mus_timeAtIpOutIn() { return cms2.mus_timeAtIpOutIn(); }
	const vector<float> &mus_timeAtIpOutInErr() { return cms2.mus_timeAtIpOutInErr(); }
	const vector<float> &mus_timeCompat() { return cms2.mus_timeCompat(); }
	const vector<float> &mus_trkKink() { return cms2.mus_trkKink(); }
	const vector<float> &mus_trkRelChi2() { return cms2.mus_trkRelChi2(); }
	const vector<float> &mus_vertexCompat() { return cms2.mus_vertexCompat(); }
	const vector<float> &mus_vertexphi() { return cms2.mus_vertexphi(); }
	const vector<float> &mus_z0() { return cms2.mus_z0(); }
	const vector<float> &mus_z0Err() { return cms2.mus_z0Err(); }
	const vector<float> &mus_z0corr() { return cms2.mus_z0corr(); }
	const vector<float> &pfjets_mvavalue() { return cms2.pfjets_mvavalue(); }
	const vector<float> &pfjets_full53xmva_beta() { return cms2.pfjets_full53xmva_beta(); }
	const vector<float> &pfjets_full53xmva_betaStar() { return cms2.pfjets_full53xmva_betaStar(); }
	const vector<float> &pfjets_full53xmva_d0() { return cms2.pfjets_full53xmva_d0(); }
	const vector<float> &pfjets_full53xmva_dRMean() { return cms2.pfjets_full53xmva_dRMean(); }
	const vector<float> &pfjets_full53xmva_dZ() { return cms2.pfjets_full53xmva_dZ(); }
	const vector<float> &pfjets_full53xmva_frac01() { return cms2.pfjets_full53xmva_frac01(); }
	const vector<float> &pfjets_full53xmva_frac02() { return cms2.pfjets_full53xmva_frac02(); }
	const vector<float> &pfjets_full53xmva_frac03() { return cms2.pfjets_full53xmva_frac03(); }
	const vector<float> &pfjets_full53xmva_frac04() { return cms2.pfjets_full53xmva_frac04(); }
	const vector<float> &pfjets_full53xmva_frac05() { return cms2.pfjets_full53xmva_frac05(); }
	const vector<float> &pfjets_full53xmva_nCharged() { return cms2.pfjets_full53xmva_nCharged(); }
	const vector<float> &pfjets_full53xmva_nNeutrals() { return cms2.pfjets_full53xmva_nNeutrals(); }
	const vector<float> &pfjets_full53xmva_nvtx() { return cms2.pfjets_full53xmva_nvtx(); }
	const vector<float> &pfjets_full53xmvavalue() { return cms2.pfjets_full53xmvavalue(); }
	const vector<float> &pfjets_full5xmvavalue() { return cms2.pfjets_full5xmvavalue(); }
	const vector<float> &trkjet_met() { return cms2.trkjet_met(); }
	const vector<float> &trkjet_metPhi() { return cms2.trkjet_metPhi(); }
	const vector<float> &trkjet_sumet() { return cms2.trkjet_sumet(); }
	const vector<float> &trk_met() { return cms2.trk_met(); }
	const vector<float> &trk_metPhi() { return cms2.trk_metPhi(); }
	const vector<float> &trk_sumet() { return cms2.trk_sumet(); }
	const vector<float> &pfcands_deltaP() { return cms2.pfcands_deltaP(); }
	const vector<float> &pfcands_ecalE() { return cms2.pfcands_ecalE(); }
	const vector<float> &pfcands_hcalE() { return cms2.pfcands_hcalE(); }
	const vector<float> &pfcands_mva_emu() { return cms2.pfcands_mva_emu(); }
	const vector<float> &pfcands_mva_epi() { return cms2.pfcands_mva_epi(); }
	const vector<float> &pfcands_mva_nothing_gamma() { return cms2.pfcands_mva_nothing_gamma(); }
	const vector<float> &pfcands_mva_nothing_nh() { return cms2.pfcands_mva_nothing_nh(); }
	const vector<float> &pfcands_mva_pimu() { return cms2.pfcands_mva_pimu(); }
	const vector<float> &pfcands_pS1E() { return cms2.pfcands_pS1E(); }
	const vector<float> &pfcands_pS2E() { return cms2.pfcands_pS2E(); }
	const vector<float> &pfcands_rawEcalE() { return cms2.pfcands_rawEcalE(); }
	const vector<float> &pfcands_rawHcalE() { return cms2.pfcands_rawHcalE(); }
	const vector<float> &pfels_deltaP() { return cms2.pfels_deltaP(); }
	const vector<float> &pfels_ecalE() { return cms2.pfels_ecalE(); }
	const vector<float> &pfels_hcalE() { return cms2.pfels_hcalE(); }
	const vector<float> &pfels_iso04ChargedHadrons() { return cms2.pfels_iso04ChargedHadrons(); }
	const vector<float> &pfels_iso04NeutralHadrons() { return cms2.pfels_iso04NeutralHadrons(); }
	const vector<float> &pfels_iso04Photons() { return cms2.pfels_iso04Photons(); }
	const vector<float> &pfels_isoChargedHadrons() { return cms2.pfels_isoChargedHadrons(); }
	const vector<float> &pfels_isoNeutralHadrons() { return cms2.pfels_isoNeutralHadrons(); }
	const vector<float> &pfels_isoPhotons() { return cms2.pfels_isoPhotons(); }
	const vector<float> &pfels_mva_emu() { return cms2.pfels_mva_emu(); }
	const vector<float> &pfels_mva_epi() { return cms2.pfels_mva_epi(); }
	const vector<float> &pfels_mva_nothing_gamma() { return cms2.pfels_mva_nothing_gamma(); }
	const vector<float> &pfels_mva_nothing_nh() { return cms2.pfels_mva_nothing_nh(); }
	const vector<float> &pfels_mva_pimu() { return cms2.pfels_mva_pimu(); }
	const vector<float> &pfels_pS1E() { return cms2.pfels_pS1E(); }
	const vector<float> &pfels_pS2E() { return cms2.pfels_pS2E(); }
	const vector<float> &pfels_rawEcalE() { return cms2.pfels_rawEcalE(); }
	const vector<float> &pfels_rawHcalE() { return cms2.pfels_rawHcalE(); }
	const vector<float> &pfjets_area() { return cms2.pfjets_area(); }
	const vector<float> &pfjets_chargedEmE() { return cms2.pfjets_chargedEmE(); }
	const vector<float> &pfjets_chargedHadronE() { return cms2.pfjets_chargedHadronE(); }
	const vector<float> &pfjets_cor() { return cms2.pfjets_cor(); }
	const vector<float> &pfjets_corL1Fast() { return cms2.pfjets_corL1Fast(); }
	const vector<float> &pfjets_corL1FastL2L3() { return cms2.pfjets_corL1FastL2L3(); }
	const vector<float> &pfjets_corL1FastL2L3residual() { return cms2.pfjets_corL1FastL2L3residual(); }
	const vector<float> &pfjets_corL1L2L3() { return cms2.pfjets_corL1L2L3(); }
	const vector<float> &pfjets_electronE() { return cms2.pfjets_electronE(); }
	const vector<float> &pfjets_hfEmE() { return cms2.pfjets_hfEmE(); }
	const vector<float> &pfjets_hfHadronE() { return cms2.pfjets_hfHadronE(); }
	const vector<float> &pfjets_muonE() { return cms2.pfjets_muonE(); }
	const vector<float> &pfjets_neutralEmE() { return cms2.pfjets_neutralEmE(); }
	const vector<float> &pfjets_neutralHadronE() { return cms2.pfjets_neutralHadronE(); }
	const vector<float> &pfjets_photonE() { return cms2.pfjets_photonE(); }
	const vector<float> &pfmus_deltaP() { return cms2.pfmus_deltaP(); }
	const vector<float> &pfmus_ecalE() { return cms2.pfmus_ecalE(); }
	const vector<float> &pfmus_hcalE() { return cms2.pfmus_hcalE(); }
	const vector<float> &pfmus_iso04ChargedHadrons() { return cms2.pfmus_iso04ChargedHadrons(); }
	const vector<float> &pfmus_iso04NeutralHadrons() { return cms2.pfmus_iso04NeutralHadrons(); }
	const vector<float> &pfmus_iso04Photons() { return cms2.pfmus_iso04Photons(); }
	const vector<float> &pfmus_isoChargedHadrons() { return cms2.pfmus_isoChargedHadrons(); }
	const vector<float> &pfmus_isoNeutralHadrons() { return cms2.pfmus_isoNeutralHadrons(); }
	const vector<float> &pfmus_isoPhotons() { return cms2.pfmus_isoPhotons(); }
	const vector<float> &pfmus_mva_emu() { return cms2.pfmus_mva_emu(); }
	const vector<float> &pfmus_mva_epi() { return cms2.pfmus_mva_epi(); }
	const vector<float> &pfmus_mva_nothing_gamma() { return cms2.pfmus_mva_nothing_gamma(); }
	const vector<float> &pfmus_mva_nothing_nh() { return cms2.pfmus_mva_nothing_nh(); }
	const vector<float> &pfmus_mva_pimu() { return cms2.pfmus_mva_pimu(); }
	const vector<float> &pfmus_pS1E() { return cms2.pfmus_pS1E(); }
	const vector<float> &pfmus_pS2E() { return cms2.pfmus_pS2E(); }
	const vector<float> &pfmus_rawEcalE() { return cms2.pfmus_rawEcalE(); }
	const vector<float> &pfmus_rawHcalE() { return cms2.pfmus_rawHcalE(); }
	const vector<float> &taus_pf_againstElectronDeadECAL() { return cms2.taus_pf_againstElectronDeadECAL(); }
	const vector<float> &taus_pf_againstElectronLoose() { return cms2.taus_pf_againstElectronLoose(); }
	const vector<float> &taus_pf_againstElectronLooseMVA2() { return cms2.taus_pf_againstElectronLooseMVA2(); }
	const vector<float> &taus_pf_againstElectronLooseMVA3() { return cms2.taus_pf_againstElectronLooseMVA3(); }
	const vector<float> &taus_pf_againstElectronMVA() { return cms2.taus_pf_againstElectronMVA(); }
	const vector<float> &taus_pf_againstElectronMVA2category() { return cms2.taus_pf_againstElectronMVA2category(); }
	const vector<float> &taus_pf_againstElectronMVA2raw() { return cms2.taus_pf_againstElectronMVA2raw(); }
	const vector<float> &taus_pf_againstElectronMVA3category() { return cms2.taus_pf_againstElectronMVA3category(); }
	const vector<float> &taus_pf_againstElectronMVA3raw() { return cms2.taus_pf_againstElectronMVA3raw(); }
	const vector<float> &taus_pf_againstElectronMedium() { return cms2.taus_pf_againstElectronMedium(); }
	const vector<float> &taus_pf_againstElectronMediumMVA2() { return cms2.taus_pf_againstElectronMediumMVA2(); }
	const vector<float> &taus_pf_againstElectronMediumMVA3() { return cms2.taus_pf_againstElectronMediumMVA3(); }
	const vector<float> &taus_pf_againstElectronTight() { return cms2.taus_pf_againstElectronTight(); }
	const vector<float> &taus_pf_againstElectronTightMVA2() { return cms2.taus_pf_againstElectronTightMVA2(); }
	const vector<float> &taus_pf_againstElectronTightMVA3() { return cms2.taus_pf_againstElectronTightMVA3(); }
	const vector<float> &taus_pf_againstElectronVLooseMVA2() { return cms2.taus_pf_againstElectronVLooseMVA2(); }
	const vector<float> &taus_pf_againstElectronVTightMVA3() { return cms2.taus_pf_againstElectronVTightMVA3(); }
	const vector<float> &taus_pf_againstMuonLoose() { return cms2.taus_pf_againstMuonLoose(); }
	const vector<float> &taus_pf_againstMuonLoose2() { return cms2.taus_pf_againstMuonLoose2(); }
	const vector<float> &taus_pf_againstMuonMedium() { return cms2.taus_pf_againstMuonMedium(); }
	const vector<float> &taus_pf_againstMuonMedium2() { return cms2.taus_pf_againstMuonMedium2(); }
	const vector<float> &taus_pf_againstMuonTight() { return cms2.taus_pf_againstMuonTight(); }
	const vector<float> &taus_pf_againstMuonTight2() { return cms2.taus_pf_againstMuonTight2(); }
	const vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw(); }
	const vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits(); }
	const vector<float> &taus_pf_byDecayModeFinding() { return cms2.taus_pf_byDecayModeFinding(); }
	const vector<float> &taus_pf_byIsolationMVA2raw() { return cms2.taus_pf_byIsolationMVA2raw(); }
	const vector<float> &taus_pf_byIsolationMVAraw() { return cms2.taus_pf_byIsolationMVAraw(); }
	const vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr(); }
	const vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits(); }
	const vector<float> &taus_pf_byLooseIsolationMVA() { return cms2.taus_pf_byLooseIsolationMVA(); }
	const vector<float> &taus_pf_byLooseIsolationMVA2() { return cms2.taus_pf_byLooseIsolationMVA2(); }
	const vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr(); }
	const vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits(); }
	const vector<float> &taus_pf_byMediumIsolationMVA() { return cms2.taus_pf_byMediumIsolationMVA(); }
	const vector<float> &taus_pf_byMediumIsolationMVA2() { return cms2.taus_pf_byMediumIsolationMVA2(); }
	const vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr(); }
	const vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits(); }
	const vector<float> &taus_pf_byTightIsolationMVA() { return cms2.taus_pf_byTightIsolationMVA(); }
	const vector<float> &taus_pf_byTightIsolationMVA2() { return cms2.taus_pf_byTightIsolationMVA2(); }
	const vector<float> &taus_pf_byVLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byVLooseCombinedIsolationDeltaBetaCorr(); }
	const vector<float> &photons_e1x5() { return cms2.photons_e1x5(); }
	const vector<float> &photons_e2x5Max() { return cms2.photons_e2x5Max(); }
	const vector<float> &photons_e3x3() { return cms2.photons_e3x3(); }
	const vector<float> &photons_e5x5() { return cms2.photons_e5x5(); }
	const vector<float> &photons_ecalIso03() { return cms2.photons_ecalIso03(); }
	const vector<float> &photons_ecalIso04() { return cms2.photons_ecalIso04(); }
	const vector<float> &photons_hOverE() { return cms2.photons_hOverE(); }
	const vector<float> &photons_hcalDepth1TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR03(); }
	const vector<float> &photons_hcalDepth1TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR04(); }
	const vector<float> &photons_hcalDepth2TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR03(); }
	const vector<float> &photons_hcalDepth2TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR04(); }
	const vector<float> &photons_hcalIso03() { return cms2.photons_hcalIso03(); }
	const vector<float> &photons_hcalIso04() { return cms2.photons_hcalIso04(); }
	const vector<float> &photons_hcalTowerSumEtBcConeDR03() { return cms2.photons_hcalTowerSumEtBcConeDR03(); }
	const vector<float> &photons_hcalTowerSumEtBcConeDR04() { return cms2.photons_hcalTowerSumEtBcConeDR04(); }
	const vector<float> &photons_ntkIsoHollow03() { return cms2.photons_ntkIsoHollow03(); }
	const vector<float> &photons_ntkIsoHollow04() { return cms2.photons_ntkIsoHollow04(); }
	const vector<float> &photons_ntkIsoSolid03() { return cms2.photons_ntkIsoSolid03(); }
	const vector<float> &photons_ntkIsoSolid04() { return cms2.photons_ntkIsoSolid04(); }
	const vector<float> &photons_sigmaEtaEta() { return cms2.photons_sigmaEtaEta(); }
	const vector<float> &photons_sigmaIEtaIEta() { return cms2.photons_sigmaIEtaIEta(); }
	const vector<float> &photons_swissSeed() { return cms2.photons_swissSeed(); }
	const vector<float> &photons_tkIsoHollow03() { return cms2.photons_tkIsoHollow03(); }
	const vector<float> &photons_tkIsoHollow04() { return cms2.photons_tkIsoHollow04(); }
	const vector<float> &photons_tkIsoSolid03() { return cms2.photons_tkIsoSolid03(); }
	const vector<float> &photons_tkIsoSolid04() { return cms2.photons_tkIsoSolid04(); }
	const vector<float> &puInfo_trueNumInteractions() { return cms2.puInfo_trueNumInteractions(); }
	const vector<float> &convs_chi2() { return cms2.convs_chi2(); }
	const vector<float> &convs_dl() { return cms2.convs_dl(); }
	const vector<float> &convs_ndof() { return cms2.convs_ndof(); }
	const vector<float> &sparm_values() { return cms2.sparm_values(); }
	const vector<float> &scs_clustersSize() { return cms2.scs_clustersSize(); }
	const vector<float> &scs_crystalsSize() { return cms2.scs_crystalsSize(); }
	const vector<float> &scs_e1x3() { return cms2.scs_e1x3(); }
	const vector<float> &scs_e1x5() { return cms2.scs_e1x5(); }
	const vector<float> &scs_e2nd() { return cms2.scs_e2nd(); }
	const vector<float> &scs_e2x2() { return cms2.scs_e2x2(); }
	const vector<float> &scs_e2x5Max() { return cms2.scs_e2x5Max(); }
	const vector<float> &scs_e3x1() { return cms2.scs_e3x1(); }
	const vector<float> &scs_e3x2() { return cms2.scs_e3x2(); }
	const vector<float> &scs_e3x3() { return cms2.scs_e3x3(); }
	const vector<float> &scs_e4x4() { return cms2.scs_e4x4(); }
	const vector<float> &scs_e5x5() { return cms2.scs_e5x5(); }
	const vector<float> &scs_eMax() { return cms2.scs_eMax(); }
	const vector<float> &scs_eSeed() { return cms2.scs_eSeed(); }
	const vector<float> &scs_energy() { return cms2.scs_energy(); }
	const vector<float> &scs_eta() { return cms2.scs_eta(); }
	const vector<float> &scs_hoe() { return cms2.scs_hoe(); }
	const vector<float> &scs_laserCorMax() { return cms2.scs_laserCorMax(); }
	const vector<float> &scs_laserCorMean() { return cms2.scs_laserCorMean(); }
	const vector<float> &scs_laserCorSeed() { return cms2.scs_laserCorSeed(); }
	const vector<float> &scs_phi() { return cms2.scs_phi(); }
	const vector<float> &scs_preshowerEnergy() { return cms2.scs_preshowerEnergy(); }
	const vector<float> &scs_rawEnergy() { return cms2.scs_rawEnergy(); }
	const vector<float> &scs_sigmaEtaEta() { return cms2.scs_sigmaEtaEta(); }
	const vector<float> &scs_sigmaEtaPhi() { return cms2.scs_sigmaEtaPhi(); }
	const vector<float> &scs_sigmaIEtaIEta() { return cms2.scs_sigmaIEtaIEta(); }
	const vector<float> &scs_sigmaIEtaIEtaSC() { return cms2.scs_sigmaIEtaIEtaSC(); }
	const vector<float> &scs_sigmaIEtaIPhi() { return cms2.scs_sigmaIEtaIPhi(); }
	const vector<float> &scs_sigmaIEtaIPhiSC() { return cms2.scs_sigmaIEtaIPhiSC(); }
	const vector<float> &scs_sigmaIPhiIPhi() { return cms2.scs_sigmaIPhiIPhi(); }
	const vector<float> &scs_sigmaIPhiIPhiSC() { return cms2.scs_sigmaIPhiIPhiSC(); }
	const vector<float> &scs_sigmaPhiPhi() { return cms2.scs_sigmaPhiPhi(); }
	const vector<float> &scs_timeSeed() { return cms2.scs_timeSeed(); }
	const vector<float> &svs_anglePV() { return cms2.svs_anglePV(); }
	const vector<float> &svs_chi2() { return cms2.svs_chi2(); }
	const vector<float> &svs_dist3Dsig() { return cms2.svs_dist3Dsig(); }
	const vector<float> &svs_dist3Dval() { return cms2.svs_dist3Dval(); }
	const vector<float> &svs_distXYsig() { return cms2.svs_distXYsig(); }
	const vector<float> &svs_distXYval() { return cms2.svs_distXYval(); }
	const vector<float> &svs_ndof() { return cms2.svs_ndof(); }
	const vector<float> &svs_prob() { return cms2.svs_prob(); }
	const vector<float> &svs_xError() { return cms2.svs_xError(); }
	const vector<float> &svs_yError() { return cms2.svs_yError(); }
	const vector<float> &svs_zError() { return cms2.svs_zError(); }
	const vector<float> &mus_tcmet_deltax() { return cms2.mus_tcmet_deltax(); }
	const vector<float> &mus_tcmet_deltay() { return cms2.mus_tcmet_deltay(); }
	const vector<float> &pfcands_dzpv() { return cms2.pfcands_dzpv(); }
	const vector<float> &pfcands_trkiso() { return cms2.pfcands_trkiso(); }
	const vector<float> &trks_chi2() { return cms2.trks_chi2(); }
	const vector<float> &trks_d0() { return cms2.trks_d0(); }
	const vector<float> &trks_d0Err() { return cms2.trks_d0Err(); }
	const vector<float> &trks_d0corr() { return cms2.trks_d0corr(); }
	const vector<float> &trks_d0corrPhi() { return cms2.trks_d0corrPhi(); }
	const vector<float> &trks_d0phiCov() { return cms2.trks_d0phiCov(); }
	const vector<float> &trks_etaErr() { return cms2.trks_etaErr(); }
	const vector<float> &trks_layer1_charge() { return cms2.trks_layer1_charge(); }
	const vector<float> &trks_ndof() { return cms2.trks_ndof(); }
	const vector<float> &trks_phiErr() { return cms2.trks_phiErr(); }
	const vector<float> &trks_ptErr() { return cms2.trks_ptErr(); }
	const vector<float> &trks_validFraction() { return cms2.trks_validFraction(); }
	const vector<float> &trks_z0() { return cms2.trks_z0(); }
	const vector<float> &trks_z0Err() { return cms2.trks_z0Err(); }
	const vector<float> &trks_z0corr() { return cms2.trks_z0corr(); }
	const vector<float> &trkjets_cor() { return cms2.trkjets_cor(); }
	const vector<float> &trks_d0Errvtx() { return cms2.trks_d0Errvtx(); }
	const vector<float> &trks_d0vtx() { return cms2.trks_d0vtx(); }
	const vector<float> &vtxs_chi2() { return cms2.vtxs_chi2(); }
	const vector<float> &vtxs_ndof() { return cms2.vtxs_ndof(); }
	const vector<float> &vtxs_sumpt() { return cms2.vtxs_sumpt(); }
	const vector<float> &vtxs_xError() { return cms2.vtxs_xError(); }
	const vector<float> &vtxs_yError() { return cms2.vtxs_yError(); }
	const vector<float> &vtxs_zError() { return cms2.vtxs_zError(); }
	const vector<float> &bsvtxs_chi2() { return cms2.bsvtxs_chi2(); }
	const vector<float> &bsvtxs_ndof() { return cms2.bsvtxs_ndof(); }
	const vector<float> &bsvtxs_sumpt() { return cms2.bsvtxs_sumpt(); }
	const vector<float> &bsvtxs_xError() { return cms2.bsvtxs_xError(); }
	const vector<float> &bsvtxs_yError() { return cms2.bsvtxs_yError(); }
	const vector<float> &bsvtxs_zError() { return cms2.bsvtxs_zError(); }
	const vector<vector<float> > &els_convs_dcot() { return cms2.els_convs_dcot(); }
	const vector<vector<float> > &els_convs_dist() { return cms2.els_convs_dist(); }
	const vector<vector<float> > &els_convs_radius() { return cms2.els_convs_radius(); }
	const vector<vector<float> > &mus_stationShowerDeltaR() { return cms2.mus_stationShowerDeltaR(); }
	const vector<vector<float> > &mus_stationShowerSizeT() { return cms2.mus_stationShowerSizeT(); }
	const vector<vector<float> > &puInfo_instLumi() { return cms2.puInfo_instLumi(); }
	const vector<vector<float> > &puInfo_sump_highpt() { return cms2.puInfo_sump_highpt(); }
	const vector<vector<float> > &puInfo_sumpt_lowpt() { return cms2.puInfo_sumpt_lowpt(); }
	const vector<vector<float> > &puInfo_zpositions() { return cms2.puInfo_zpositions(); }
	const vector<vector<float> > &vtxs_covMatrix() { return cms2.vtxs_covMatrix(); }
	const vector<vector<float> > &bsvtxs_covMatrix() { return cms2.bsvtxs_covMatrix(); }
	const int &evt_cscLooseHaloId() { return cms2.evt_cscLooseHaloId(); }
	const int &evt_cscTightHaloId() { return cms2.evt_cscTightHaloId(); }
	const int &evt_ecalLooseHaloId() { return cms2.evt_ecalLooseHaloId(); }
	const int &evt_ecalTightHaloId() { return cms2.evt_ecalTightHaloId(); }
	const int &evt_extremeTightHaloId() { return cms2.evt_extremeTightHaloId(); }
	const int &evt_globalLooseHaloId() { return cms2.evt_globalLooseHaloId(); }
	const int &evt_globalTightHaloId() { return cms2.evt_globalTightHaloId(); }
	const int &evt_hcalLooseHaloId() { return cms2.evt_hcalLooseHaloId(); }
	const int &evt_hcalTightHaloId() { return cms2.evt_hcalTightHaloId(); }
	const int &evt_looseHaloId() { return cms2.evt_looseHaloId(); }
	const int &evt_nHaloLikeTracks() { return cms2.evt_nHaloLikeTracks(); }
	const int &evt_nHaloTriggerCandidates() { return cms2.evt_nHaloTriggerCandidates(); }
	const int &evt_tightHaloId() { return cms2.evt_tightHaloId(); }
	const int &evt_bsType() { return cms2.evt_bsType(); }
	const int &evt_bunchCrossing() { return cms2.evt_bunchCrossing(); }
	const int &evt_experimentType() { return cms2.evt_experimentType(); }
	const int &evt_isRealData() { return cms2.evt_isRealData(); }
	const int &evt_orbitNumber() { return cms2.evt_orbitNumber(); }
	const int &evt_storeNumber() { return cms2.evt_storeNumber(); }
	const int &hcalnoise_GetRecHitCount() { return cms2.hcalnoise_GetRecHitCount(); }
	const int &hcalnoise_GetRecHitCount15() { return cms2.hcalnoise_GetRecHitCount15(); }
	const int &hcalnoise_maxHPDHits() { return cms2.hcalnoise_maxHPDHits(); }
	const int &hcalnoise_maxHPDNoOtherHits() { return cms2.hcalnoise_maxHPDNoOtherHits(); }
	const int &hcalnoise_maxRBXHits() { return cms2.hcalnoise_maxRBXHits(); }
	const int &hcalnoise_maxZeros() { return cms2.hcalnoise_maxZeros(); }
	const int &hcalnoise_noiseFilterStatus() { return cms2.hcalnoise_noiseFilterStatus(); }
	const int &hcalnoise_noiseType() { return cms2.hcalnoise_noiseType(); }
	const int &hcalnoise_num10GeVHits() { return cms2.hcalnoise_num10GeVHits(); }
	const int &hcalnoise_num25GeVHits() { return cms2.hcalnoise_num25GeVHits(); }
	const int &hcalnoise_numFlatNoiseChannels() { return cms2.hcalnoise_numFlatNoiseChannels(); }
	const int &hcalnoise_numIsolatedNoiseChannels() { return cms2.hcalnoise_numIsolatedNoiseChannels(); }
	const int &hcalnoise_numProblematicRBXs() { return cms2.hcalnoise_numProblematicRBXs(); }
	const int &hcalnoise_numSpikeNoiseChannels() { return cms2.hcalnoise_numSpikeNoiseChannels(); }
	const int &hcalnoise_numTS4TS5NoiseChannels() { return cms2.hcalnoise_numTS4TS5NoiseChannels(); }
	const int &hcalnoise_numTriangleNoiseChannels() { return cms2.hcalnoise_numTriangleNoiseChannels(); }
	const int &hcalnoise_passHighLevelNoiseFilter() { return cms2.hcalnoise_passHighLevelNoiseFilter(); }
	const int &hcalnoise_passLooseNoiseFilter() { return cms2.hcalnoise_passLooseNoiseFilter(); }
	const int &hcalnoise_passTightNoiseFilter() { return cms2.hcalnoise_passTightNoiseFilter(); }
	const int &l1_nemiso() { return cms2.l1_nemiso(); }
	const int &l1_nemnoiso() { return cms2.l1_nemnoiso(); }
	const int &l1_njetsc() { return cms2.l1_njetsc(); }
	const int &l1_njetsf() { return cms2.l1_njetsf(); }
	const int &l1_njetst() { return cms2.l1_njetst(); }
	const int &l1_nmus() { return cms2.l1_nmus(); }
	const int &ls_lumiSecQual() { return cms2.ls_lumiSecQual(); }
	const int &pdfinfo_id1() { return cms2.pdfinfo_id1(); }
	const int &pdfinfo_id2() { return cms2.pdfinfo_id2(); }
	const int &sparm_subProcessId() { return cms2.sparm_subProcessId(); }
	const vector<int> &evt_ecaliPhiSuspects() { return cms2.evt_ecaliPhiSuspects(); }
	const vector<int> &evt_globaliPhiSuspects() { return cms2.evt_globaliPhiSuspects(); }
	const vector<int> &evt_hcaliPhiSuspects() { return cms2.evt_hcaliPhiSuspects(); }
	const vector<int> &els_mc3_id() { return cms2.els_mc3_id(); }
	const vector<int> &els_mc3idx() { return cms2.els_mc3idx(); }
	const vector<int> &els_mc3_motherid() { return cms2.els_mc3_motherid(); }
	const vector<int> &els_mc3_motheridx() { return cms2.els_mc3_motheridx(); }
	const vector<int> &els_mc_id() { return cms2.els_mc_id(); }
	const vector<int> &els_mcidx() { return cms2.els_mcidx(); }
	const vector<int> &els_mc_motherid() { return cms2.els_mc_motherid(); }
	const vector<int> &jets_mc3_id() { return cms2.jets_mc3_id(); }
	const vector<int> &jets_mc3idx() { return cms2.jets_mc3idx(); }
	const vector<int> &jets_mc_gpidx() { return cms2.jets_mc_gpidx(); }
	const vector<int> &jets_mc_id() { return cms2.jets_mc_id(); }
	const vector<int> &jets_mcidx() { return cms2.jets_mcidx(); }
	const vector<int> &jets_mc_motherid() { return cms2.jets_mc_motherid(); }
	const vector<int> &mus_mc3_id() { return cms2.mus_mc3_id(); }
	const vector<int> &mus_mc3idx() { return cms2.mus_mc3idx(); }
	const vector<int> &mus_mc3_motherid() { return cms2.mus_mc3_motherid(); }
	const vector<int> &mus_mc3_motheridx() { return cms2.mus_mc3_motheridx(); }
	const vector<int> &mus_mc_id() { return cms2.mus_mc_id(); }
	const vector<int> &mus_mcidx() { return cms2.mus_mcidx(); }
	const vector<int> &mus_mc_motherid() { return cms2.mus_mc_motherid(); }
	const vector<int> &pfjets_mc3_id() { return cms2.pfjets_mc3_id(); }
	const vector<int> &pfjets_mc3idx() { return cms2.pfjets_mc3idx(); }
	const vector<int> &pfjets_mc_gpidx() { return cms2.pfjets_mc_gpidx(); }
	const vector<int> &pfjets_mc_id() { return cms2.pfjets_mc_id(); }
	const vector<int> &pfjets_mcidx() { return cms2.pfjets_mcidx(); }
	const vector<int> &pfjets_mc_motherid() { return cms2.pfjets_mc_motherid(); }
	const vector<int> &photons_mc3_id() { return cms2.photons_mc3_id(); }
	const vector<int> &photons_mc3idx() { return cms2.photons_mc3idx(); }
	const vector<int> &photons_mc3_motherid() { return cms2.photons_mc3_motherid(); }
	const vector<int> &photons_mc3_motheridx() { return cms2.photons_mc3_motheridx(); }
	const vector<int> &photons_mc_id() { return cms2.photons_mc_id(); }
	const vector<int> &photons_mcidx() { return cms2.photons_mcidx(); }
	const vector<int> &photons_mc_motherid() { return cms2.photons_mc_motherid(); }
	const vector<int> &trk_mc3_id() { return cms2.trk_mc3_id(); }
	const vector<int> &trk_mc3idx() { return cms2.trk_mc3idx(); }
	const vector<int> &trk_mc3_motherid() { return cms2.trk_mc3_motherid(); }
	const vector<int> &trk_mc3_motheridx() { return cms2.trk_mc3_motheridx(); }
	const vector<int> &trk_mc_id() { return cms2.trk_mc_id(); }
	const vector<int> &trk_mcidx() { return cms2.trk_mcidx(); }
	const vector<int> &trk_mc_motherid() { return cms2.trk_mc_motherid(); }
	const vector<int> &els_closestJet() { return cms2.els_closestJet(); }
	const vector<int> &els_closestMuon() { return cms2.els_closestMuon(); }
	const vector<int> &els_pfelsidx() { return cms2.els_pfelsidx(); }
	const vector<int> &els_category() { return cms2.els_category(); }
	const vector<int> &els_charge() { return cms2.els_charge(); }
	const vector<int> &els_ckf_laywithmeas() { return cms2.els_ckf_laywithmeas(); }
	const vector<int> &els_class() { return cms2.els_class(); }
	const vector<int> &els_conv_delMissHits() { return cms2.els_conv_delMissHits(); }
	const vector<int> &els_conv_flag() { return cms2.els_conv_flag(); }
	const vector<int> &els_conv_gsftkidx() { return cms2.els_conv_gsftkidx(); }
	const vector<int> &els_conv_old_delMissHits() { return cms2.els_conv_old_delMissHits(); }
	const vector<int> &els_conv_old_flag() { return cms2.els_conv_old_flag(); }
	const vector<int> &els_conv_old_gsftkidx() { return cms2.els_conv_old_gsftkidx(); }
	const vector<int> &els_conv_old_tkidx() { return cms2.els_conv_old_tkidx(); }
	const vector<int> &els_conv_tkidx() { return cms2.els_conv_tkidx(); }
	const vector<int> &els_exp_innerlayers() { return cms2.els_exp_innerlayers(); }
	const vector<int> &els_exp_outerlayers() { return cms2.els_exp_outerlayers(); }
	const vector<int> &els_fiduciality() { return cms2.els_fiduciality(); }
	const vector<int> &els_gsftrkidx() { return cms2.els_gsftrkidx(); }
	const vector<int> &els_layer1_det() { return cms2.els_layer1_det(); }
	const vector<int> &els_layer1_layer() { return cms2.els_layer1_layer(); }
	const vector<int> &els_layer1_sizerphi() { return cms2.els_layer1_sizerphi(); }
	const vector<int> &els_layer1_sizerz() { return cms2.els_layer1_sizerz(); }
	const vector<int> &els_lostHits() { return cms2.els_lostHits(); }
	const vector<int> &els_lost_pixelhits() { return cms2.els_lost_pixelhits(); }
	const vector<int> &els_nSeed() { return cms2.els_nSeed(); }
	const vector<int> &els_sccharge() { return cms2.els_sccharge(); }
	const vector<int> &els_scindex() { return cms2.els_scindex(); }
	const vector<int> &els_trk_charge() { return cms2.els_trk_charge(); }
	const vector<int> &els_trkidx() { return cms2.els_trkidx(); }
	const vector<int> &els_type() { return cms2.els_type(); }
	const vector<int> &els_validHits() { return cms2.els_validHits(); }
	const vector<int> &els_valid_pixelhits() { return cms2.els_valid_pixelhits(); }
	const vector<int> &genps_id() { return cms2.genps_id(); }
	const vector<int> &genps_id_mother() { return cms2.genps_id_mother(); }
	const vector<int> &genps_status() { return cms2.genps_status(); }
	const vector<int> &gsftrks_charge() { return cms2.gsftrks_charge(); }
	const vector<int> &gsftrks_exp_innerlayers() { return cms2.gsftrks_exp_innerlayers(); }
	const vector<int> &gsftrks_exp_outerlayers() { return cms2.gsftrks_exp_outerlayers(); }
	const vector<int> &gsftrks_layer1_det() { return cms2.gsftrks_layer1_det(); }
	const vector<int> &gsftrks_layer1_layer() { return cms2.gsftrks_layer1_layer(); }
	const vector<int> &gsftrks_layer1_sizerphi() { return cms2.gsftrks_layer1_sizerphi(); }
	const vector<int> &gsftrks_layer1_sizerz() { return cms2.gsftrks_layer1_sizerz(); }
	const vector<int> &gsftrks_lostHits() { return cms2.gsftrks_lostHits(); }
	const vector<int> &gsftrks_lost_pixelhits() { return cms2.gsftrks_lost_pixelhits(); }
	const vector<int> &gsftrks_nlayers() { return cms2.gsftrks_nlayers(); }
	const vector<int> &gsftrks_nlayers3D() { return cms2.gsftrks_nlayers3D(); }
	const vector<int> &gsftrks_nlayersLost() { return cms2.gsftrks_nlayersLost(); }
	const vector<int> &gsftrks_validHits() { return cms2.gsftrks_validHits(); }
	const vector<int> &gsftrks_valid_pixelhits() { return cms2.gsftrks_valid_pixelhits(); }
	const vector<int> &hyp_ll_charge() { return cms2.hyp_ll_charge(); }
	const vector<int> &hyp_ll_id() { return cms2.hyp_ll_id(); }
	const vector<int> &hyp_ll_index() { return cms2.hyp_ll_index(); }
	const vector<int> &hyp_ll_lostHits() { return cms2.hyp_ll_lostHits(); }
	const vector<int> &hyp_ll_validHits() { return cms2.hyp_ll_validHits(); }
	const vector<int> &hyp_lt_charge() { return cms2.hyp_lt_charge(); }
	const vector<int> &hyp_lt_id() { return cms2.hyp_lt_id(); }
	const vector<int> &hyp_lt_index() { return cms2.hyp_lt_index(); }
	const vector<int> &hyp_lt_lostHits() { return cms2.hyp_lt_lostHits(); }
	const vector<int> &hyp_lt_validHits() { return cms2.hyp_lt_validHits(); }
	const vector<int> &hyp_njets() { return cms2.hyp_njets(); }
	const vector<int> &hyp_nojets() { return cms2.hyp_nojets(); }
	const vector<int> &hyp_type() { return cms2.hyp_type(); }
	const vector<int> &hyp_FVFit_ndf() { return cms2.hyp_FVFit_ndf(); }
	const vector<int> &hyp_FVFit_status() { return cms2.hyp_FVFit_status(); }
	const vector<int> &hyp_ll_mc_id() { return cms2.hyp_ll_mc_id(); }
	const vector<int> &hyp_ll_mc_motherid() { return cms2.hyp_ll_mc_motherid(); }
	const vector<int> &hyp_lt_mc_id() { return cms2.hyp_lt_mc_id(); }
	const vector<int> &hyp_lt_mc_motherid() { return cms2.hyp_lt_mc_motherid(); }
	const vector<int> &pfjets_mcflavorAlgo() { return cms2.pfjets_mcflavorAlgo(); }
	const vector<int> &pfjets_mcflavorPhys() { return cms2.pfjets_mcflavorPhys(); }
	const vector<int> &jets_closestElectron() { return cms2.jets_closestElectron(); }
	const vector<int> &jets_closestMuon() { return cms2.jets_closestMuon(); }
	const vector<int> &l1_emiso_ieta() { return cms2.l1_emiso_ieta(); }
	const vector<int> &l1_emiso_iphi() { return cms2.l1_emiso_iphi(); }
	const vector<int> &l1_emiso_rawId() { return cms2.l1_emiso_rawId(); }
	const vector<int> &l1_emiso_type() { return cms2.l1_emiso_type(); }
	const vector<int> &l1_emnoiso_ieta() { return cms2.l1_emnoiso_ieta(); }
	const vector<int> &l1_emnoiso_iphi() { return cms2.l1_emnoiso_iphi(); }
	const vector<int> &l1_emnoiso_rawId() { return cms2.l1_emnoiso_rawId(); }
	const vector<int> &l1_emnoiso_type() { return cms2.l1_emnoiso_type(); }
	const vector<int> &l1_jetsc_ieta() { return cms2.l1_jetsc_ieta(); }
	const vector<int> &l1_jetsc_iphi() { return cms2.l1_jetsc_iphi(); }
	const vector<int> &l1_jetsc_rawId() { return cms2.l1_jetsc_rawId(); }
	const vector<int> &l1_jetsc_type() { return cms2.l1_jetsc_type(); }
	const vector<int> &l1_jetsf_ieta() { return cms2.l1_jetsf_ieta(); }
	const vector<int> &l1_jetsf_iphi() { return cms2.l1_jetsf_iphi(); }
	const vector<int> &l1_jetsf_rawId() { return cms2.l1_jetsf_rawId(); }
	const vector<int> &l1_jetsf_type() { return cms2.l1_jetsf_type(); }
	const vector<int> &l1_jetst_ieta() { return cms2.l1_jetst_ieta(); }
	const vector<int> &l1_jetst_iphi() { return cms2.l1_jetst_iphi(); }
	const vector<int> &l1_jetst_rawId() { return cms2.l1_jetst_rawId(); }
	const vector<int> &l1_jetst_type() { return cms2.l1_jetst_type(); }
	const vector<int> &l1_mus_flags() { return cms2.l1_mus_flags(); }
	const vector<int> &l1_mus_q() { return cms2.l1_mus_q(); }
	const vector<int> &l1_mus_qual() { return cms2.l1_mus_qual(); }
	const vector<int> &l1_mus_qualFlags() { return cms2.l1_mus_qualFlags(); }
	const vector<int> &mus_met_flag() { return cms2.mus_met_flag(); }
	const vector<int> &mus_closestEle() { return cms2.mus_closestEle(); }
	const vector<int> &mus_closestJet() { return cms2.mus_closestJet(); }
	const vector<int> &mus_pfmusidx() { return cms2.mus_pfmusidx(); }
	const vector<int> &mus_charge() { return cms2.mus_charge(); }
	const vector<int> &mus_gfit_validHits() { return cms2.mus_gfit_validHits(); }
	const vector<int> &mus_gfit_validSTAHits() { return cms2.mus_gfit_validSTAHits(); }
	const vector<int> &mus_gfit_validSiHits() { return cms2.mus_gfit_validSiHits(); }
	const vector<int> &mus_goodmask() { return cms2.mus_goodmask(); }
	const vector<int> &mus_iso03_ntrk() { return cms2.mus_iso03_ntrk(); }
	const vector<int> &mus_iso05_ntrk() { return cms2.mus_iso05_ntrk(); }
	const vector<int> &mus_lostHits() { return cms2.mus_lostHits(); }
	const vector<int> &mus_muonBestTrackType() { return cms2.mus_muonBestTrackType(); }
	const vector<int> &mus_nOverlaps() { return cms2.mus_nOverlaps(); }
	const vector<int> &mus_nmatches() { return cms2.mus_nmatches(); }
	const vector<int> &mus_numberOfMatchedStations() { return cms2.mus_numberOfMatchedStations(); }
	const vector<int> &mus_overlap0() { return cms2.mus_overlap0(); }
	const vector<int> &mus_overlap1() { return cms2.mus_overlap1(); }
	const vector<int> &mus_pfcharge() { return cms2.mus_pfcharge(); }
	const vector<int> &mus_pfflag() { return cms2.mus_pfflag(); }
	const vector<int> &mus_pfparticleId() { return cms2.mus_pfparticleId(); }
	const vector<int> &mus_pid_PFMuon() { return cms2.mus_pid_PFMuon(); }
	const vector<int> &mus_pid_TM2DCompatibilityLoose() { return cms2.mus_pid_TM2DCompatibilityLoose(); }
	const vector<int> &mus_pid_TM2DCompatibilityTight() { return cms2.mus_pid_TM2DCompatibilityTight(); }
	const vector<int> &mus_pid_TMLastStationLoose() { return cms2.mus_pid_TMLastStationLoose(); }
	const vector<int> &mus_pid_TMLastStationTight() { return cms2.mus_pid_TMLastStationTight(); }
	const vector<int> &mus_sta_validHits() { return cms2.mus_sta_validHits(); }
	const vector<int> &mus_timeDirection() { return cms2.mus_timeDirection(); }
	const vector<int> &mus_timeNumStationsUsed() { return cms2.mus_timeNumStationsUsed(); }
	const vector<int> &mus_trk_charge() { return cms2.mus_trk_charge(); }
	const vector<int> &mus_trkidx() { return cms2.mus_trkidx(); }
	const vector<int> &mus_type() { return cms2.mus_type(); }
	const vector<int> &mus_validHits() { return cms2.mus_validHits(); }
	const vector<int> &pfcands_charge() { return cms2.pfcands_charge(); }
	const vector<int> &pfcands_flag() { return cms2.pfcands_flag(); }
	const vector<int> &pfcands_particleId() { return cms2.pfcands_particleId(); }
	const vector<int> &pfcands_pfelsidx() { return cms2.pfcands_pfelsidx(); }
	const vector<int> &pfcands_pfmusidx() { return cms2.pfcands_pfmusidx(); }
	const vector<int> &pfcands_trkidx() { return cms2.pfcands_trkidx(); }
	const vector<int> &pfcands_vtxidx() { return cms2.pfcands_vtxidx(); }
	const vector<int> &pfels_elsidx() { return cms2.pfels_elsidx(); }
	const vector<int> &pfels_charge() { return cms2.pfels_charge(); }
	const vector<int> &pfels_flag() { return cms2.pfels_flag(); }
	const vector<int> &pfels_particleId() { return cms2.pfels_particleId(); }
	const vector<int> &pfjets_chargedHadronMultiplicity() { return cms2.pfjets_chargedHadronMultiplicity(); }
	const vector<int> &pfjets_chargedMultiplicity() { return cms2.pfjets_chargedMultiplicity(); }
	const vector<int> &pfjets_electronMultiplicity() { return cms2.pfjets_electronMultiplicity(); }
	const vector<int> &pfjets_hfEmMultiplicity() { return cms2.pfjets_hfEmMultiplicity(); }
	const vector<int> &pfjets_hfHadronMultiplicity() { return cms2.pfjets_hfHadronMultiplicity(); }
	const vector<int> &pfjets_muonMultiplicity() { return cms2.pfjets_muonMultiplicity(); }
	const vector<int> &pfjets_neutralHadronMultiplicity() { return cms2.pfjets_neutralHadronMultiplicity(); }
	const vector<int> &pfjets_neutralMultiplicity() { return cms2.pfjets_neutralMultiplicity(); }
	const vector<int> &pfjets_photonMultiplicity() { return cms2.pfjets_photonMultiplicity(); }
	const vector<int> &pfmus_musidx() { return cms2.pfmus_musidx(); }
	const vector<int> &pfmus_charge() { return cms2.pfmus_charge(); }
	const vector<int> &pfmus_flag() { return cms2.pfmus_flag(); }
	const vector<int> &pfmus_particleId() { return cms2.pfmus_particleId(); }
	const vector<int> &taus_pf_charge() { return cms2.taus_pf_charge(); }
	const vector<int> &taus_pf_pfjetIndex() { return cms2.taus_pf_pfjetIndex(); }
	const vector<int> &photons_fiduciality() { return cms2.photons_fiduciality(); }
	const vector<int> &photons_scindex() { return cms2.photons_scindex(); }
	const vector<int> &puInfo_bunchCrossing() { return cms2.puInfo_bunchCrossing(); }
	const vector<int> &puInfo_nPUvertices() { return cms2.puInfo_nPUvertices(); }
	const vector<int> &convs_algo() { return cms2.convs_algo(); }
	const vector<int> &convs_isConverted() { return cms2.convs_isConverted(); }
	const vector<int> &convs_quality() { return cms2.convs_quality(); }
	const vector<int> &scs_detIdSeed() { return cms2.scs_detIdSeed(); }
	const vector<int> &scs_elsidx() { return cms2.scs_elsidx(); }
	const vector<int> &scs_severitySeed() { return cms2.scs_severitySeed(); }
	const vector<int> &svs_isKs() { return cms2.svs_isKs(); }
	const vector<int> &svs_isLambda() { return cms2.svs_isLambda(); }
	const vector<int> &svs_mc3_id() { return cms2.svs_mc3_id(); }
	const vector<int> &svs_nTrks() { return cms2.svs_nTrks(); }
	const vector<int> &mus_tcmet_flag() { return cms2.mus_tcmet_flag(); }
	const vector<int> &trks_algo() { return cms2.trks_algo(); }
	const vector<int> &trks_charge() { return cms2.trks_charge(); }
	const vector<int> &trks_exp_innerlayers() { return cms2.trks_exp_innerlayers(); }
	const vector<int> &trks_exp_outerlayers() { return cms2.trks_exp_outerlayers(); }
	const vector<int> &trks_layer1_det() { return cms2.trks_layer1_det(); }
	const vector<int> &trks_layer1_layer() { return cms2.trks_layer1_layer(); }
	const vector<int> &trks_layer1_sizerphi() { return cms2.trks_layer1_sizerphi(); }
	const vector<int> &trks_layer1_sizerz() { return cms2.trks_layer1_sizerz(); }
	const vector<int> &trks_lostHits() { return cms2.trks_lostHits(); }
	const vector<int> &trks_lost_pixelhits() { return cms2.trks_lost_pixelhits(); }
	const vector<int> &trks_nLoops() { return cms2.trks_nLoops(); }
	const vector<int> &trks_nlayers() { return cms2.trks_nlayers(); }
	const vector<int> &trks_nlayers3D() { return cms2.trks_nlayers3D(); }
	const vector<int> &trks_nlayersLost() { return cms2.trks_nlayersLost(); }
	const vector<int> &trks_pvidx0() { return cms2.trks_pvidx0(); }
	const vector<int> &trks_pvidx1() { return cms2.trks_pvidx1(); }
	const vector<int> &trks_qualityMask() { return cms2.trks_qualityMask(); }
	const vector<int> &trks_validHits() { return cms2.trks_validHits(); }
	const vector<int> &trks_valid_pixelhits() { return cms2.trks_valid_pixelhits(); }
	const vector<int> &trks_elsidx() { return cms2.trks_elsidx(); }
	const vector<int> &trk_musidx() { return cms2.trk_musidx(); }
	const vector<int> &trkjets_ntrks() { return cms2.trkjets_ntrks(); }
	const vector<int> &trkjets_vtxs_idx() { return cms2.trkjets_vtxs_idx(); }
	const vector<int> &vtxs_isFake() { return cms2.vtxs_isFake(); }
	const vector<int> &vtxs_isValid() { return cms2.vtxs_isValid(); }
	const vector<int> &vtxs_tracksSize() { return cms2.vtxs_tracksSize(); }
	const vector<int> &bsvtxs_isFake() { return cms2.bsvtxs_isFake(); }
	const vector<int> &bsvtxs_isValid() { return cms2.bsvtxs_isValid(); }
	const vector<int> &bsvtxs_tracksSize() { return cms2.bsvtxs_tracksSize(); }
	const vector<vector<int> > &els_convs_delMissHits() { return cms2.els_convs_delMissHits(); }
	const vector<vector<int> > &els_convs_flag() { return cms2.els_convs_flag(); }
	const vector<vector<int> > &els_convs_gsftkidx() { return cms2.els_convs_gsftkidx(); }
	const vector<vector<int> > &els_convs_tkidx() { return cms2.els_convs_tkidx(); }
	const vector<vector<int> > &genps_lepdaughter_id() { return cms2.genps_lepdaughter_id(); }
	const vector<vector<int> > &genps_lepdaughter_idx() { return cms2.genps_lepdaughter_idx(); }
	const vector<vector<int> > &hlt_trigObjs_id() { return cms2.hlt_trigObjs_id(); }
	const vector<vector<int> > &hyp_jets_idx() { return cms2.hyp_jets_idx(); }
	const vector<vector<int> > &hyp_other_jets_idx() { return cms2.hyp_other_jets_idx(); }
	const vector<vector<int> > &mus_nStationCorrelatedHits() { return cms2.mus_nStationCorrelatedHits(); }
	const vector<vector<int> > &mus_nStationHits() { return cms2.mus_nStationHits(); }
	const vector<vector<int> > &pfjets_pfcandIndicies() { return cms2.pfjets_pfcandIndicies(); }
	const vector<vector<int> > &taus_pf_pfcandIndicies() { return cms2.taus_pf_pfcandIndicies(); }
	const vector<vector<int> > &puInfo_ntrks_highpt() { return cms2.puInfo_ntrks_highpt(); }
	const vector<vector<int> > &puInfo_ntrks_lowpt() { return cms2.puInfo_ntrks_lowpt(); }
	const vector<vector<int> > &convs_nHitsBeforeVtx() { return cms2.convs_nHitsBeforeVtx(); }
	const vector<vector<int> > &convs_tkalgo() { return cms2.convs_tkalgo(); }
	const vector<vector<int> > &convs_tkidx() { return cms2.convs_tkidx(); }
	const unsigned int &els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version(); }
	const unsigned int &els_HLT_Ele17_Ele8_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg_version(); }
	const unsigned int &els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version(); }
	const unsigned int &els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version(); }
	const unsigned int &els_HLT_Ele17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg_version(); }
	const unsigned int &els_HLT_Ele17_Ele8_version() { return cms2.els_HLT_Ele17_Ele8_version(); }
	const unsigned int &els_HLT_Ele20_SC4_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg_version(); }
	const unsigned int &els_HLT_Ele20_SC4_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg_version(); }
	const unsigned int &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version(); }
	const unsigned int &els_HLT_Ele27_WP80_version() { return cms2.els_HLT_Ele27_WP80_version(); }
	const unsigned int &els_HLT_Ele32_SC17_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg_version(); }
	const unsigned int &els_HLT_Ele32_SC17_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg_version(); }
	const unsigned int &els_HLT_Mu17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg_version(); }
	const unsigned int &els_HLT_Mu17_Ele8_version() { return cms2.els_HLT_Mu17_Ele8_version(); }
	const unsigned int &els_HLT_Mu8_Ele17_version() { return cms2.els_HLT_Mu8_Ele17_version(); }
	const unsigned int &evt_nels() { return cms2.evt_nels(); }
	const unsigned int &evt_detectorStatus() { return cms2.evt_detectorStatus(); }
	const unsigned int &evt_event() { return cms2.evt_event(); }
	const unsigned int &evt_lumiBlock() { return cms2.evt_lumiBlock(); }
	const unsigned int &evt_run() { return cms2.evt_run(); }
	const unsigned int &genps_flavorHistoryFilterResult() { return cms2.genps_flavorHistoryFilterResult(); }
	const unsigned int &evt_ngenjets() { return cms2.evt_ngenjets(); }
	const unsigned int &genps_signalProcessID() { return cms2.genps_signalProcessID(); }
	const unsigned int &evt_njets() { return cms2.evt_njets(); }
	const unsigned int &l1_bits1() { return cms2.l1_bits1(); }
	const unsigned int &l1_bits2() { return cms2.l1_bits2(); }
	const unsigned int &l1_bits3() { return cms2.l1_bits3(); }
	const unsigned int &l1_bits4() { return cms2.l1_bits4(); }
	const unsigned int &l1_techbits1() { return cms2.l1_techbits1(); }
	const unsigned int &l1_techbits2() { return cms2.l1_techbits2(); }
	const unsigned int &ls_lsNumber() { return cms2.ls_lsNumber(); }
	const unsigned int &ls_numOrbit() { return cms2.ls_numOrbit(); }
	const unsigned int &ls_startOrbit() { return cms2.ls_startOrbit(); }
	const unsigned int &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version(); }
	const unsigned int &mus_HLT_IsoMu24_eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_version(); }
	const unsigned int &mus_HLT_Mu17_Ele8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg_version(); }
	const unsigned int &mus_HLT_Mu17_Ele8_version() { return cms2.mus_HLT_Mu17_Ele8_version(); }
	const unsigned int &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version(); }
	const unsigned int &mus_HLT_Mu17_Mu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg_version(); }
	const unsigned int &mus_HLT_Mu17_Mu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg_version(); }
	const unsigned int &mus_HLT_Mu17_Mu8_version() { return cms2.mus_HLT_Mu17_Mu8_version(); }
	const unsigned int &mus_HLT_Mu17_TkMu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg_version(); }
	const unsigned int &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version(); }
	const unsigned int &mus_HLT_Mu17_TkMu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg_version(); }
	const unsigned int &mus_HLT_Mu17_TkMu8_version() { return cms2.mus_HLT_Mu17_TkMu8_version(); }
	const unsigned int &mus_HLT_Mu8_Ele17_TrailingLeg_version() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg_version(); }
	const unsigned int &mus_HLT_Mu8_Ele17_version() { return cms2.mus_HLT_Mu8_Ele17_version(); }
	const unsigned int &evt_nphotons() { return cms2.evt_nphotons(); }
	const unsigned int &evt_ecalRecoStatus() { return cms2.evt_ecalRecoStatus(); }
	const unsigned int &evt_nscs() { return cms2.evt_nscs(); }
	const unsigned int &evt_ntrkjets() { return cms2.evt_ntrkjets(); }
	const unsigned int &evt_nvtxs() { return cms2.evt_nvtxs(); }
	const unsigned int &evt_nbsvtxs() { return cms2.evt_nbsvtxs(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8() { return cms2.els_HLT_Ele17_Ele8(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8_L1sL1DoubleEG137() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg(); }
	const vector<unsigned int> &els_HLT_Ele17_Ele8_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg(); }
	const vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_LeadingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg(); }
	const vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_TrailingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg(); }
	const vector<unsigned int> &els_HLT_Ele27_WP80() { return cms2.els_HLT_Ele27_WP80(); }
	const vector<unsigned int> &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22(); }
	const vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_LeadingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg(); }
	const vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_TrailingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg(); }
	const vector<unsigned int> &els_HLT_Mu17_Ele8() { return cms2.els_HLT_Mu17_Ele8(); }
	const vector<unsigned int> &els_HLT_Mu17_Ele8_TrailingLeg() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg(); }
	const vector<unsigned int> &els_HLT_Mu8_Ele17() { return cms2.els_HLT_Mu8_Ele17(); }
	const vector<unsigned int> &els_id2012ext_loose() { return cms2.els_id2012ext_loose(); }
	const vector<unsigned int> &els_id2012ext_medium() { return cms2.els_id2012ext_medium(); }
	const vector<unsigned int> &els_id2012ext_tight() { return cms2.els_id2012ext_tight(); }
	const vector<unsigned int> &els_id2012ext_veto() { return cms2.els_id2012ext_veto(); }
	const vector<unsigned int> &els_id2012_loose() { return cms2.els_id2012_loose(); }
	const vector<unsigned int> &els_id2012_medium() { return cms2.els_id2012_medium(); }
	const vector<unsigned int> &els_id2012_tight() { return cms2.els_id2012_tight(); }
	const vector<unsigned int> &els_id2012_veto() { return cms2.els_id2012_veto(); }
	const vector<unsigned int> &hlt_prescales() { return cms2.hlt_prescales(); }
	const vector<unsigned int> &l1_prescales() { return cms2.l1_prescales(); }
	const vector<unsigned int> &l1_techtrigprescales() { return cms2.l1_techtrigprescales(); }
	const vector<unsigned int> &mus_HLT_IsoMu24_eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1(); }
	const vector<unsigned int> &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1(); }
	const vector<unsigned int> &mus_HLT_Mu17_Ele8() { return cms2.mus_HLT_Mu17_Ele8(); }
	const vector<unsigned int> &mus_HLT_Mu17_Ele8_LeadingLeg() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg(); }
	const vector<unsigned int> &mus_HLT_Mu17_Mu8() { return cms2.mus_HLT_Mu17_Mu8(); }
	const vector<unsigned int> &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen(); }
	const vector<unsigned int> &mus_HLT_Mu17_Mu8_LeadingLeg() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg(); }
	const vector<unsigned int> &mus_HLT_Mu17_Mu8_TrailingLeg() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg(); }
	const vector<unsigned int> &mus_HLT_Mu17_TkMu8() { return cms2.mus_HLT_Mu17_TkMu8(); }
	const vector<unsigned int> &mus_HLT_Mu17_TkMu8_LeadingLeg() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg(); }
	const vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLeg() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg(); }
	const vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered(); }
	const vector<unsigned int> &mus_HLT_Mu8_Ele17() { return cms2.mus_HLT_Mu8_Ele17(); }
	const vector<unsigned int> &mus_HLT_Mu8_Ele17_TrailingLeg() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg(); }
	const int &evt_nEvts() { return cms2.evt_nEvts(); }
	const float &evt_filt_eff() { return cms2.evt_filt_eff(); }
	bool passHLTTrigger(TString trigName) { return cms2.passHLTTrigger(trigName); }
	bool passL1Trigger(TString trigName) { return cms2.passL1Trigger(trigName); }
}
