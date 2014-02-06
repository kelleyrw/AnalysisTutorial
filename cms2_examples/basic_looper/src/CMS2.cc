#include "../interface/CMS2.h"
CMS2 cms2;
namespace tas {
	TBits &hlt_bits() { return cms2.hlt_bits(); }
	vector<TString> &evt_CMS2tag() { return cms2.evt_CMS2tag(); }
	vector<TString> &evt_dataset() { return cms2.evt_dataset(); }
	vector<TString> &hlt_trigNames() { return cms2.hlt_trigNames(); }
	vector<TString> &evt_errCategory() { return cms2.evt_errCategory(); }
	vector<TString> &evt_errModule() { return cms2.evt_errModule(); }
	vector<TString> &evt_errSeverity() { return cms2.evt_errSeverity(); }
	bool &evt_eventHasHalo() { return cms2.evt_eventHasHalo(); }
	bool &hcalnoise_HasBadRBXTS4TS5() { return cms2.hcalnoise_HasBadRBXTS4TS5(); }
	bool &ls_isValid() { return cms2.ls_isValid(); }
	bool &filt_ecalBE() { return cms2.filt_ecalBE(); }
	bool &filt_ecalDR() { return cms2.filt_ecalDR(); }
	bool &filt_ecalLaser() { return cms2.filt_ecalLaser(); }
	bool &filt_ecalTP() { return cms2.filt_ecalTP(); }
	bool &filt_eeBadSc() { return cms2.filt_eeBadSc(); }
	bool &filt_greedyMuon() { return cms2.filt_greedyMuon(); }
	bool &filt_hcalLaser() { return cms2.filt_hcalLaser(); }
	bool &filt_inconsistentMuon() { return cms2.filt_inconsistentMuon(); }
	bool &filt_jetIDFailure() { return cms2.filt_jetIDFailure(); }
	bool &filt_multiEvent() { return cms2.filt_multiEvent(); }
	bool &filt_trackingFailure() { return cms2.filt_trackingFailure(); }
	bool &evt_hbheFilter() { return cms2.evt_hbheFilter(); }
	vector<bool> &els_conv_vtx_flag() { return cms2.els_conv_vtx_flag(); }
	vector<bool> &els_passingMvaPreselection() { return cms2.els_passingMvaPreselection(); }
	vector<bool> &els_passingPflowPreselection() { return cms2.els_passingPflowPreselection(); }
	vector<bool> &mus_isRPCMuon() { return cms2.mus_isRPCMuon(); }
	vector<bool> &mus_tightMatch() { return cms2.mus_tightMatch(); }
	vector<bool> &mus_updatedSta() { return cms2.mus_updatedSta(); }
	vector<bool> &photons_haspixelSeed() { return cms2.photons_haspixelSeed(); }
	float &evt_bs_Xwidth() { return cms2.evt_bs_Xwidth(); }
	float &evt_bs_XwidthErr() { return cms2.evt_bs_XwidthErr(); }
	float &evt_bs_Ywidth() { return cms2.evt_bs_Ywidth(); }
	float &evt_bs_YwidthErr() { return cms2.evt_bs_YwidthErr(); }
	float &evt_bs_dxdz() { return cms2.evt_bs_dxdz(); }
	float &evt_bs_dxdzErr() { return cms2.evt_bs_dxdzErr(); }
	float &evt_bs_dydz() { return cms2.evt_bs_dydz(); }
	float &evt_bs_dydzErr() { return cms2.evt_bs_dydzErr(); }
	float &evt_bs_sigmaZ() { return cms2.evt_bs_sigmaZ(); }
	float &evt_bs_sigmaZErr() { return cms2.evt_bs_sigmaZErr(); }
	float &evt_bs_xErr() { return cms2.evt_bs_xErr(); }
	float &evt_bs_yErr() { return cms2.evt_bs_yErr(); }
	float &evt_bs_zErr() { return cms2.evt_bs_zErr(); }
	float &evt_bField() { return cms2.evt_bField(); }
	float &evt_rho() { return cms2.evt_rho(); }
	float &evt_rhoJEC() { return cms2.evt_rhoJEC(); }
	float &evt_fixgrid_all_rho() { return cms2.evt_fixgrid_all_rho(); }
	float &evt_fixgridfastjet_all_rho() { return cms2.evt_fixgridfastjet_all_rho(); }
	float &evt_kfactor() { return cms2.evt_kfactor(); }
	float &evt_scale1fb() { return cms2.evt_scale1fb(); }
	float &evt_xsec_excl() { return cms2.evt_xsec_excl(); }
	float &evt_xsec_incl() { return cms2.evt_xsec_incl(); }
	float &gen_met() { return cms2.gen_met(); }
	float &gen_metPhi() { return cms2.gen_metPhi(); }
	float &genps_alphaQCD() { return cms2.genps_alphaQCD(); }
	float &genps_pthat() { return cms2.genps_pthat(); }
	float &genps_qScale() { return cms2.genps_qScale(); }
	float &genps_weight() { return cms2.genps_weight(); }
	float &gen_sumEt() { return cms2.gen_sumEt(); }
	float &hcalnoise_GetRecHitEnergy() { return cms2.hcalnoise_GetRecHitEnergy(); }
	float &hcalnoise_GetRecHitEnergy15() { return cms2.hcalnoise_GetRecHitEnergy15(); }
	float &hcalnoise_GetTotalCalibCharge() { return cms2.hcalnoise_GetTotalCalibCharge(); }
	float &hcalnoise_TS4TS5NoiseSumE() { return cms2.hcalnoise_TS4TS5NoiseSumE(); }
	float &hcalnoise_TS4TS5NoiseSumEt() { return cms2.hcalnoise_TS4TS5NoiseSumEt(); }
	float &hcalnoise_eventChargeFraction() { return cms2.hcalnoise_eventChargeFraction(); }
	float &hcalnoise_eventEMEnergy() { return cms2.hcalnoise_eventEMEnergy(); }
	float &hcalnoise_eventEMFraction() { return cms2.hcalnoise_eventEMFraction(); }
	float &hcalnoise_eventHadEnergy() { return cms2.hcalnoise_eventHadEnergy(); }
	float &hcalnoise_eventTrackEnergy() { return cms2.hcalnoise_eventTrackEnergy(); }
	float &hcalnoise_flatNoiseSumE() { return cms2.hcalnoise_flatNoiseSumE(); }
	float &hcalnoise_flatNoiseSumEt() { return cms2.hcalnoise_flatNoiseSumEt(); }
	float &hcalnoise_isolatedNoiseSumE() { return cms2.hcalnoise_isolatedNoiseSumE(); }
	float &hcalnoise_isolatedNoiseSumEt() { return cms2.hcalnoise_isolatedNoiseSumEt(); }
	float &hcalnoise_max10GeVHitTime() { return cms2.hcalnoise_max10GeVHitTime(); }
	float &hcalnoise_max25GeVHitTime() { return cms2.hcalnoise_max25GeVHitTime(); }
	float &hcalnoise_maxE10TS() { return cms2.hcalnoise_maxE10TS(); }
	float &hcalnoise_maxE2Over10TS() { return cms2.hcalnoise_maxE2Over10TS(); }
	float &hcalnoise_maxE2TS() { return cms2.hcalnoise_maxE2TS(); }
	float &hcalnoise_min10GeVHitTime() { return cms2.hcalnoise_min10GeVHitTime(); }
	float &hcalnoise_min25GeVHitTime() { return cms2.hcalnoise_min25GeVHitTime(); }
	float &hcalnoise_minE10TS() { return cms2.hcalnoise_minE10TS(); }
	float &hcalnoise_minE2Over10TS() { return cms2.hcalnoise_minE2Over10TS(); }
	float &hcalnoise_minE2TS() { return cms2.hcalnoise_minE2TS(); }
	float &hcalnoise_minHPDEMF() { return cms2.hcalnoise_minHPDEMF(); }
	float &hcalnoise_minRBXEMF() { return cms2.hcalnoise_minRBXEMF(); }
	float &hcalnoise_rms10GeVHitTime() { return cms2.hcalnoise_rms10GeVHitTime(); }
	float &hcalnoise_rms25GeVHitTime() { return cms2.hcalnoise_rms25GeVHitTime(); }
	float &hcalnoise_spikeNoiseSumE() { return cms2.hcalnoise_spikeNoiseSumE(); }
	float &hcalnoise_spikeNoiseSumEt() { return cms2.hcalnoise_spikeNoiseSumEt(); }
	float &hcalnoise_triangleNoiseSumE() { return cms2.hcalnoise_triangleNoiseSumE(); }
	float &hcalnoise_triangleNoiseSumEt() { return cms2.hcalnoise_triangleNoiseSumEt(); }
	float &evt_kt6calo_central_rho() { return cms2.evt_kt6calo_central_rho(); }
	float &evt_kt6calo_muhlt_rho() { return cms2.evt_kt6calo_muhlt_rho(); }
	float &evt_kt6calo_rho() { return cms2.evt_kt6calo_rho(); }
	float &evt_kt6pf_ctrChargedPU_rho() { return cms2.evt_kt6pf_ctrChargedPU_rho(); }
	float &evt_kt6pf_ctrNeutral_rho() { return cms2.evt_kt6pf_ctrNeutral_rho(); }
	float &evt_kt6pf_ctrNeutralTight_rho() { return cms2.evt_kt6pf_ctrNeutralTight_rho(); }
	float &evt_kt6pf_foregiso_rho() { return cms2.evt_kt6pf_foregiso_rho(); }
	float &ls_avgInsDelLumi() { return cms2.ls_avgInsDelLumi(); }
	float &ls_avgInsDelLumiErr() { return cms2.ls_avgInsDelLumiErr(); }
	float &ls_avgInsRecLumi() { return cms2.ls_avgInsRecLumi(); }
	float &ls_avgInsRecLumiErr() { return cms2.ls_avgInsRecLumiErr(); }
	float &ls_deadFrac() { return cms2.ls_deadFrac(); }
	float &ls_intgDelLumi() { return cms2.ls_intgDelLumi(); }
	float &ls_intgRecLumi() { return cms2.ls_intgRecLumi(); }
	float &ls_lumiSectionLength() { return cms2.ls_lumiSectionLength(); }
	float &evt_ecalendcapm_met() { return cms2.evt_ecalendcapm_met(); }
	float &evt_ecalendcapm_metPhi() { return cms2.evt_ecalendcapm_metPhi(); }
	float &evt_ecalendcapp_met() { return cms2.evt_ecalendcapp_met(); }
	float &evt_ecalendcapp_metPhi() { return cms2.evt_ecalendcapp_metPhi(); }
	float &evt_ecalmet() { return cms2.evt_ecalmet(); }
	float &evt_ecalmetPhi() { return cms2.evt_ecalmetPhi(); }
	float &evt_endcapm_met() { return cms2.evt_endcapm_met(); }
	float &evt_endcapm_metPhi() { return cms2.evt_endcapm_metPhi(); }
	float &evt_endcapp_met() { return cms2.evt_endcapp_met(); }
	float &evt_endcapp_metPhi() { return cms2.evt_endcapp_metPhi(); }
	float &evt_hcalendcapm_met() { return cms2.evt_hcalendcapm_met(); }
	float &evt_hcalendcapm_metPhi() { return cms2.evt_hcalendcapm_metPhi(); }
	float &evt_hcalendcapp_met() { return cms2.evt_hcalendcapp_met(); }
	float &evt_hcalendcapp_metPhi() { return cms2.evt_hcalendcapp_metPhi(); }
	float &evt_hcalmet() { return cms2.evt_hcalmet(); }
	float &evt_hcalmetPhi() { return cms2.evt_hcalmetPhi(); }
	float &evt_met() { return cms2.evt_met(); }
	float &evt_met_EtGt3() { return cms2.evt_met_EtGt3(); }
	float &evt_metHO() { return cms2.evt_metHO(); }
	float &evt_metHOPhi() { return cms2.evt_metHOPhi(); }
	float &evt_metHOSig() { return cms2.evt_metHOSig(); }
	float &evt_metMuonCorr() { return cms2.evt_metMuonCorr(); }
	float &evt_metMuonCorrPhi() { return cms2.evt_metMuonCorrPhi(); }
	float &evt_metMuonCorrSig() { return cms2.evt_metMuonCorrSig(); }
	float &evt_metMuonJESCorr() { return cms2.evt_metMuonJESCorr(); }
	float &evt_metMuonJESCorrPhi() { return cms2.evt_metMuonJESCorrPhi(); }
	float &evt_metMuonJESCorrSig() { return cms2.evt_metMuonJESCorrSig(); }
	float &evt_metNoHF() { return cms2.evt_metNoHF(); }
	float &evt_metNoHFHO() { return cms2.evt_metNoHFHO(); }
	float &evt_metNoHFHOPhi() { return cms2.evt_metNoHFHOPhi(); }
	float &evt_metNoHFHOSig() { return cms2.evt_metNoHFHOSig(); }
	float &evt_metNoHFPhi() { return cms2.evt_metNoHFPhi(); }
	float &evt_metNoHFSig() { return cms2.evt_metNoHFSig(); }
	float &evt_metOpt() { return cms2.evt_metOpt(); }
	float &evt_metOptHO() { return cms2.evt_metOptHO(); }
	float &evt_metOptHOPhi() { return cms2.evt_metOptHOPhi(); }
	float &evt_metOptHOSig() { return cms2.evt_metOptHOSig(); }
	float &evt_metOptNoHF() { return cms2.evt_metOptNoHF(); }
	float &evt_metOptNoHFHO() { return cms2.evt_metOptNoHFHO(); }
	float &evt_metOptNoHFHOPhi() { return cms2.evt_metOptNoHFHOPhi(); }
	float &evt_metOptNoHFHOSig() { return cms2.evt_metOptNoHFHOSig(); }
	float &evt_metOptNoHFPhi() { return cms2.evt_metOptNoHFPhi(); }
	float &evt_metOptNoHFSig() { return cms2.evt_metOptNoHFSig(); }
	float &evt_metOptPhi() { return cms2.evt_metOptPhi(); }
	float &evt_metOptSig() { return cms2.evt_metOptSig(); }
	float &evt_metPhi() { return cms2.evt_metPhi(); }
	float &evt_metPhi_EtGt3() { return cms2.evt_metPhi_EtGt3(); }
	float &evt_metSig() { return cms2.evt_metSig(); }
	float &evt_sumet() { return cms2.evt_sumet(); }
	float &evt_sumet_EtGt3() { return cms2.evt_sumet_EtGt3(); }
	float &evt_sumetHO() { return cms2.evt_sumetHO(); }
	float &evt_sumetMuonCorr() { return cms2.evt_sumetMuonCorr(); }
	float &evt_sumetMuonJESCorr() { return cms2.evt_sumetMuonJESCorr(); }
	float &evt_sumetNoHF() { return cms2.evt_sumetNoHF(); }
	float &evt_sumetNoHFHO() { return cms2.evt_sumetNoHFHO(); }
	float &evt_sumetOpt() { return cms2.evt_sumetOpt(); }
	float &evt_sumetOptHO() { return cms2.evt_sumetOptHO(); }
	float &evt_sumetOptNoHF() { return cms2.evt_sumetOptNoHF(); }
	float &evt_sumetOptNoHFHO() { return cms2.evt_sumetOptNoHFHO(); }
	float &pdfinfo_pdf1() { return cms2.pdfinfo_pdf1(); }
	float &pdfinfo_pdf2() { return cms2.pdfinfo_pdf2(); }
	float &pdfinfo_scale() { return cms2.pdfinfo_scale(); }
	float &pdfinfo_x1() { return cms2.pdfinfo_x1(); }
	float &pdfinfo_x2() { return cms2.pdfinfo_x2(); }
	float &evt_fixgrid_rho_all() { return cms2.evt_fixgrid_rho_all(); }
	float &evt_fixgrid_rho_ctr() { return cms2.evt_fixgrid_rho_ctr(); }
	float &evt_fixgrid_rho_fwd() { return cms2.evt_fixgrid_rho_fwd(); }
	float &evt_pfmet() { return cms2.evt_pfmet(); }
	float &evt_pfmetPhi() { return cms2.evt_pfmetPhi(); }
	float &evt_pfmetPhi_type1cor() { return cms2.evt_pfmetPhi_type1cor(); }
	float &evt_pfmetSig() { return cms2.evt_pfmetSig(); }
	float &evt_pfmetSignificance() { return cms2.evt_pfmetSignificance(); }
	float &evt_pfmet_type1cor() { return cms2.evt_pfmet_type1cor(); }
	float &evt_pfsumet() { return cms2.evt_pfsumet(); }
	float &evt_pf_tcmet() { return cms2.evt_pf_tcmet(); }
	float &evt_pf_tcmetPhi() { return cms2.evt_pf_tcmetPhi(); }
	float &evt_pf_tcmetSig() { return cms2.evt_pf_tcmetSig(); }
	float &evt_pf_tcsumet() { return cms2.evt_pf_tcsumet(); }
	float &evt_tcmet() { return cms2.evt_tcmet(); }
	float &evt_tcmetPhi() { return cms2.evt_tcmetPhi(); }
	float &evt_tcmetSig() { return cms2.evt_tcmetSig(); }
	float &evt_tcsumet() { return cms2.evt_tcsumet(); }
	float &evt_ww_rho_act() { return cms2.evt_ww_rho_act(); }
	float &evt_ww_rho() { return cms2.evt_ww_rho(); }
	float &evt_ww_rho_rnd() { return cms2.evt_ww_rho_rnd(); }
	float &evt_ww_rho_vor() { return cms2.evt_ww_rho_vor(); }
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &evt_bsp4() { return cms2.evt_bsp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_motherp4() { return cms2.els_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_p4() { return cms2.els_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_motherp4() { return cms2.mus_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_p4() { return cms2.mus_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_gp_p4() { return cms2.pfjets_mc_gp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_motherp4() { return cms2.pfjets_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_p4() { return cms2.pfjets_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_motherp4() { return cms2.photons_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_p4() { return cms2.photons_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_conv_pos_p4() { return cms2.els_conv_pos_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_inner_position() { return cms2.els_inner_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_outer_position() { return cms2.els_outer_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4() { return cms2.els_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4In() { return cms2.els_p4In(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4Out() { return cms2.els_p4Out(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_p4() { return cms2.els_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_vertex_p4() { return cms2.els_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4NoMuNoNu() { return cms2.genjets_p4NoMuNoNu(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms2.genps_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_prod_vtx() { return cms2.genps_prod_vtx(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4() { return cms2.genjets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gsftrks_p4() { return cms2.gsftrks_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_p4() { return cms2.hyp_ll_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_p4() { return cms2.hyp_lt_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_p4() { return cms2.hyp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_mc_p4() { return cms2.hyp_ll_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_mc_p4() { return cms2.hyp_lt_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_fittev_p4() { return cms2.mus_fittev_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_fittpfms_p4() { return cms2.mus_fittpfms_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_p4() { return cms2.mus_gfit_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_vertex_p4() { return cms2.mus_gfit_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_p4() { return cms2.mus_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfp4() { return cms2.mus_pfp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfposAtEcal_p4() { return cms2.mus_pfposAtEcal_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_p4() { return cms2.mus_sta_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_vertex_p4() { return cms2.mus_sta_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_trk_p4() { return cms2.mus_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_vertex_p4() { return cms2.mus_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_p4() { return cms2.pfcands_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfels_p4() { return cms2.pfels_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms2.pfjets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfmus_p4() { return cms2.pfmus_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfmus_posAtEcal_p4() { return cms2.pfmus_posAtEcal_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_p4() { return cms2.taus_pf_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_p4() { return cms2.photons_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &scs_p4() { return cms2.scs_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &scs_pos_p4() { return cms2.scs_pos_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &trks_trk_p4() { return cms2.trks_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &vtxs_position() { return cms2.vtxs_position(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &genps_lepdaughter_p4() { return cms2.genps_lepdaughter_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hlt_trigObjs_p4() { return cms2.hlt_trigObjs_p4(); }
	vector<float> &pfjets_combinedSecondaryVertexBJetTag() { return cms2.pfjets_combinedSecondaryVertexBJetTag(); }
	vector<float> &pfjets_combinedSecondaryVertexMVABJetTag() { return cms2.pfjets_combinedSecondaryVertexMVABJetTag(); }
	vector<float> &pfjets_jetBProbabilityBJetTag() { return cms2.pfjets_jetBProbabilityBJetTag(); }
	vector<float> &pfjets_jetProbabilityBJetTag() { return cms2.pfjets_jetProbabilityBJetTag(); }
	vector<float> &pfjets_simpleSecondaryVertexBJetTag() { return cms2.pfjets_simpleSecondaryVertexBJetTag(); }
	vector<float> &pfjets_simpleSecondaryVertexHighEffBJetTag() { return cms2.pfjets_simpleSecondaryVertexHighEffBJetTag(); }
	vector<float> &pfjets_simpleSecondaryVertexHighPurBJetTags() { return cms2.pfjets_simpleSecondaryVertexHighPurBJetTags(); }
	vector<float> &pfjets_trackCountingHighEffBJetTag() { return cms2.pfjets_trackCountingHighEffBJetTag(); }
	vector<float> &pfjets_trackCountingHighPurBJetTag() { return cms2.pfjets_trackCountingHighPurBJetTag(); }
	vector<float> &evt_bs_covMatrix() { return cms2.evt_bs_covMatrix(); }
	vector<float> &els_mc3dr() { return cms2.els_mc3dr(); }
	vector<float> &els_mcdr() { return cms2.els_mcdr(); }
	vector<float> &mus_mc3dr() { return cms2.mus_mc3dr(); }
	vector<float> &mus_mcdr() { return cms2.mus_mcdr(); }
	vector<float> &pfjets_mc3dr() { return cms2.pfjets_mc3dr(); }
	vector<float> &pfjets_mcdr() { return cms2.pfjets_mcdr(); }
	vector<float> &pfjets_mc_emEnergy() { return cms2.pfjets_mc_emEnergy(); }
	vector<float> &pfjets_mc_gpdr() { return cms2.pfjets_mc_gpdr(); }
	vector<float> &pfjets_mc_hadEnergy() { return cms2.pfjets_mc_hadEnergy(); }
	vector<float> &pfjets_mc_invEnergy() { return cms2.pfjets_mc_invEnergy(); }
	vector<float> &pfjets_mc_otherEnergy() { return cms2.pfjets_mc_otherEnergy(); }
	vector<float> &photons_mc3dr() { return cms2.photons_mc3dr(); }
	vector<float> &photons_mcdr() { return cms2.photons_mcdr(); }
	vector<float> &els_ecalJuraIso() { return cms2.els_ecalJuraIso(); }
	vector<float> &els_ecalJuraTowerIso() { return cms2.els_ecalJuraTowerIso(); }
	vector<float> &els_hcalConeIso() { return cms2.els_hcalConeIso(); }
	vector<float> &els_tkJuraIso() { return cms2.els_tkJuraIso(); }
	vector<float> &els_jetdr() { return cms2.els_jetdr(); }
	vector<float> &els_musdr() { return cms2.els_musdr(); }
	vector<float> &els_isoR03_chpf_radial() { return cms2.els_isoR03_chpf_radial(); }
	vector<float> &els_isoR03_chpf_radialTight() { return cms2.els_isoR03_chpf_radialTight(); }
	vector<float> &els_isoR03_chpf_radialTight_bv() { return cms2.els_isoR03_chpf_radialTight_bv(); }
	vector<float> &els_isoR03_chpf_radial_bv() { return cms2.els_isoR03_chpf_radial_bv(); }
	vector<float> &els_isoR03_empf_radial() { return cms2.els_isoR03_empf_radial(); }
	vector<float> &els_isoR03_empf_radialTight() { return cms2.els_isoR03_empf_radialTight(); }
	vector<float> &els_isoR03_empf_radialTight_bv() { return cms2.els_isoR03_empf_radialTight_bv(); }
	vector<float> &els_isoR03_empf_radial_bv() { return cms2.els_isoR03_empf_radial_bv(); }
	vector<float> &els_isoR03_nhpf_radial() { return cms2.els_isoR03_nhpf_radial(); }
	vector<float> &els_isoR03_nhpf_radialTight() { return cms2.els_isoR03_nhpf_radialTight(); }
	vector<float> &els_isoR03_nhpf_radialTight_bv() { return cms2.els_isoR03_nhpf_radialTight_bv(); }
	vector<float> &els_isoR03_nhpf_radial_bv() { return cms2.els_isoR03_nhpf_radial_bv(); }
	vector<float> &els_isoR03_pf2012n0p5_ch() { return cms2.els_isoR03_pf2012n0p5_ch(); }
	vector<float> &els_isoR03_pf2012n0p5_em() { return cms2.els_isoR03_pf2012n0p5_em(); }
	vector<float> &els_isoR03_pf2012n0p5_nh() { return cms2.els_isoR03_pf2012n0p5_nh(); }
	vector<float> &els_isoR03_pf_radial() { return cms2.els_isoR03_pf_radial(); }
	vector<float> &els_isoR03_pf_radialTight() { return cms2.els_isoR03_pf_radialTight(); }
	vector<float> &els_isoR03_pf_radialTight_bv() { return cms2.els_isoR03_pf_radialTight_bv(); }
	vector<float> &els_isoR03_pf_radial_bv() { return cms2.els_isoR03_pf_radial_bv(); }
	vector<float> &els_chi2() { return cms2.els_chi2(); }
	vector<float> &els_ckf_chi2() { return cms2.els_ckf_chi2(); }
	vector<float> &els_ckf_ndof() { return cms2.els_ckf_ndof(); }
	vector<float> &els_conv_dcot() { return cms2.els_conv_dcot(); }
	vector<float> &els_conv_dist() { return cms2.els_conv_dist(); }
	vector<float> &els_conv_old_dcot() { return cms2.els_conv_old_dcot(); }
	vector<float> &els_conv_old_dist() { return cms2.els_conv_old_dist(); }
	vector<float> &els_conv_old_radius() { return cms2.els_conv_old_radius(); }
	vector<float> &els_conv_radius() { return cms2.els_conv_radius(); }
	vector<float> &els_d0() { return cms2.els_d0(); }
	vector<float> &els_d0Err() { return cms2.els_d0Err(); }
	vector<float> &els_d0corr() { return cms2.els_d0corr(); }
	vector<float> &els_dEtaIn() { return cms2.els_dEtaIn(); }
	vector<float> &els_dEtaOut() { return cms2.els_dEtaOut(); }
	vector<float> &els_dPhiIn() { return cms2.els_dPhiIn(); }
	vector<float> &els_dPhiInPhiOut() { return cms2.els_dPhiInPhiOut(); }
	vector<float> &els_dPhiOut() { return cms2.els_dPhiOut(); }
	vector<float> &els_deltaEtaEleClusterTrackAtCalo() { return cms2.els_deltaEtaEleClusterTrackAtCalo(); }
	vector<float> &els_deltaPhiEleClusterTrackAtCalo() { return cms2.els_deltaPhiEleClusterTrackAtCalo(); }
	vector<float> &els_e1x5() { return cms2.els_e1x5(); }
	vector<float> &els_e2x5Max() { return cms2.els_e2x5Max(); }
	vector<float> &els_e3x3() { return cms2.els_e3x3(); }
	vector<float> &els_e5x5() { return cms2.els_e5x5(); }
	vector<float> &els_eMax() { return cms2.els_eMax(); }
	vector<float> &els_eOverPIn() { return cms2.els_eOverPIn(); }
	vector<float> &els_eOverPOut() { return cms2.els_eOverPOut(); }
	vector<float> &els_eSC() { return cms2.els_eSC(); }
	vector<float> &els_eSCPresh() { return cms2.els_eSCPresh(); }
	vector<float> &els_eSCRaw() { return cms2.els_eSCRaw(); }
	vector<float> &els_eSeed() { return cms2.els_eSeed(); }
	vector<float> &els_eSeedOverPIn() { return cms2.els_eSeedOverPIn(); }
	vector<float> &els_eSeedOverPOut() { return cms2.els_eSeedOverPOut(); }
	vector<float> &els_ecalEnergy() { return cms2.els_ecalEnergy(); }
	vector<float> &els_ecalEnergyError() { return cms2.els_ecalEnergyError(); }
	vector<float> &els_ecalIso() { return cms2.els_ecalIso(); }
	vector<float> &els_ecalIso04() { return cms2.els_ecalIso04(); }
	vector<float> &els_etaErr() { return cms2.els_etaErr(); }
	vector<float> &els_etaSC() { return cms2.els_etaSC(); }
	vector<float> &els_etaSCwidth() { return cms2.els_etaSCwidth(); }
	vector<float> &els_fbrem() { return cms2.els_fbrem(); }
	vector<float> &els_hOverE() { return cms2.els_hOverE(); }
	vector<float> &els_hcalDepth1OverEcal() { return cms2.els_hcalDepth1OverEcal(); }
	vector<float> &els_hcalDepth1TowerSumEt() { return cms2.els_hcalDepth1TowerSumEt(); }
	vector<float> &els_hcalDepth1TowerSumEt04() { return cms2.els_hcalDepth1TowerSumEt04(); }
	vector<float> &els_hcalDepth2OverEcal() { return cms2.els_hcalDepth2OverEcal(); }
	vector<float> &els_hcalDepth2TowerSumEt() { return cms2.els_hcalDepth2TowerSumEt(); }
	vector<float> &els_hcalDepth2TowerSumEt04() { return cms2.els_hcalDepth2TowerSumEt04(); }
	vector<float> &els_hcalIso() { return cms2.els_hcalIso(); }
	vector<float> &els_hcalIso04() { return cms2.els_hcalIso04(); }
	vector<float> &els_ip3d() { return cms2.els_ip3d(); }
	vector<float> &els_ip3derr() { return cms2.els_ip3derr(); }
	vector<float> &els_iso03_pf() { return cms2.els_iso03_pf(); }
	vector<float> &els_iso03_pf2012_ch() { return cms2.els_iso03_pf2012_ch(); }
	vector<float> &els_iso03_pf2012_em() { return cms2.els_iso03_pf2012_em(); }
	vector<float> &els_iso03_pf2012ext_ch() { return cms2.els_iso03_pf2012ext_ch(); }
	vector<float> &els_iso03_pf2012ext_em() { return cms2.els_iso03_pf2012ext_em(); }
	vector<float> &els_iso03_pf2012ext_nh() { return cms2.els_iso03_pf2012ext_nh(); }
	vector<float> &els_iso03_pf2012_nh() { return cms2.els_iso03_pf2012_nh(); }
	vector<float> &els_iso03_pf_ch() { return cms2.els_iso03_pf_ch(); }
	vector<float> &els_iso03_pf_gamma05() { return cms2.els_iso03_pf_gamma05(); }
	vector<float> &els_iso03_pf_nhad05() { return cms2.els_iso03_pf_nhad05(); }
	vector<float> &els_iso04_pf() { return cms2.els_iso04_pf(); }
	vector<float> &els_iso04_pf2012_ch() { return cms2.els_iso04_pf2012_ch(); }
	vector<float> &els_iso04_pf2012_em() { return cms2.els_iso04_pf2012_em(); }
	vector<float> &els_iso04_pf2012ext_ch() { return cms2.els_iso04_pf2012ext_ch(); }
	vector<float> &els_iso04_pf2012ext_em() { return cms2.els_iso04_pf2012ext_em(); }
	vector<float> &els_iso04_pf2012ext_nh() { return cms2.els_iso04_pf2012ext_nh(); }
	vector<float> &els_iso04_pf2012_nh() { return cms2.els_iso04_pf2012_nh(); }
	vector<float> &els_iso04_pf_ch() { return cms2.els_iso04_pf_ch(); }
	vector<float> &els_iso04_pf_gamma05() { return cms2.els_iso04_pf_gamma05(); }
	vector<float> &els_iso04_pf_nhad05() { return cms2.els_iso04_pf_nhad05(); }
	vector<float> &els_layer1_charge() { return cms2.els_layer1_charge(); }
	vector<float> &els_lh() { return cms2.els_lh(); }
	vector<float> &els_mva() { return cms2.els_mva(); }
	vector<float> &els_ndof() { return cms2.els_ndof(); }
	vector<float> &els_pfChargedHadronIso() { return cms2.els_pfChargedHadronIso(); }
	vector<float> &els_pfNeutralHadronIso() { return cms2.els_pfNeutralHadronIso(); }
	vector<float> &els_pfPhotonIso() { return cms2.els_pfPhotonIso(); }
	vector<float> &els_phiErr() { return cms2.els_phiErr(); }
	vector<float> &els_phiSC() { return cms2.els_phiSC(); }
	vector<float> &els_phiSCwidth() { return cms2.els_phiSCwidth(); }
	vector<float> &els_ptErr() { return cms2.els_ptErr(); }
	vector<float> &els_r9() { return cms2.els_r9(); }
	vector<float> &els_sigmaEtaEta() { return cms2.els_sigmaEtaEta(); }
	vector<float> &els_sigmaIEtaIEta() { return cms2.els_sigmaIEtaIEta(); }
	vector<float> &els_sigmaIEtaIEtaSC() { return cms2.els_sigmaIEtaIEtaSC(); }
	vector<float> &els_sigmaIEtaIPhi() { return cms2.els_sigmaIEtaIPhi(); }
	vector<float> &els_sigmaIPhiIPhi() { return cms2.els_sigmaIPhiIPhi(); }
	vector<float> &els_sigmaIPhiIPhiSC() { return cms2.els_sigmaIPhiIPhiSC(); }
	vector<float> &els_sigmaIphiIphi() { return cms2.els_sigmaIphiIphi(); }
	vector<float> &els_sigmaPhiPhi() { return cms2.els_sigmaPhiPhi(); }
	vector<float> &els_tkIso() { return cms2.els_tkIso(); }
	vector<float> &els_tkIso04() { return cms2.els_tkIso04(); }
	vector<float> &els_trackMomentumError() { return cms2.els_trackMomentumError(); }
	vector<float> &els_trkdr() { return cms2.els_trkdr(); }
	vector<float> &els_trkshFrac() { return cms2.els_trkshFrac(); }
	vector<float> &els_z0() { return cms2.els_z0(); }
	vector<float> &els_z0Err() { return cms2.els_z0Err(); }
	vector<float> &els_z0corr() { return cms2.els_z0corr(); }
	vector<float> &gsftrks_chi2() { return cms2.gsftrks_chi2(); }
	vector<float> &gsftrks_d0() { return cms2.gsftrks_d0(); }
	vector<float> &gsftrks_d0Err() { return cms2.gsftrks_d0Err(); }
	vector<float> &gsftrks_d0corr() { return cms2.gsftrks_d0corr(); }
	vector<float> &gsftrks_d0phiCov() { return cms2.gsftrks_d0phiCov(); }
	vector<float> &gsftrks_etaErr() { return cms2.gsftrks_etaErr(); }
	vector<float> &gsftrks_ndof() { return cms2.gsftrks_ndof(); }
	vector<float> &gsftrks_phiErr() { return cms2.gsftrks_phiErr(); }
	vector<float> &gsftrks_ptErr() { return cms2.gsftrks_ptErr(); }
	vector<float> &gsftrks_z0() { return cms2.gsftrks_z0(); }
	vector<float> &gsftrks_z0Err() { return cms2.gsftrks_z0Err(); }
	vector<float> &gsftrks_z0corr() { return cms2.gsftrks_z0corr(); }
	vector<float> &hyp_Ht() { return cms2.hyp_Ht(); }
	vector<float> &hyp_sumJetPt() { return cms2.hyp_sumJetPt(); }
	vector<float> &mus_met_deltax() { return cms2.mus_met_deltax(); }
	vector<float> &mus_met_deltay() { return cms2.mus_met_deltay(); }
	vector<float> &mus_eledr() { return cms2.mus_eledr(); }
	vector<float> &mus_jetdr() { return cms2.mus_jetdr(); }
	vector<float> &mus_isoR03_chpf_radial() { return cms2.mus_isoR03_chpf_radial(); }
	vector<float> &mus_isoR03_chpf_radialTight() { return cms2.mus_isoR03_chpf_radialTight(); }
	vector<float> &mus_isoR03_empf_radial() { return cms2.mus_isoR03_empf_radial(); }
	vector<float> &mus_isoR03_empf_radialTight() { return cms2.mus_isoR03_empf_radialTight(); }
	vector<float> &mus_isoR03_nhpf_radial() { return cms2.mus_isoR03_nhpf_radial(); }
	vector<float> &mus_isoR03_nhpf_radialTight() { return cms2.mus_isoR03_nhpf_radialTight(); }
	vector<float> &mus_isoR03_pf_radial() { return cms2.mus_isoR03_pf_radial(); }
	vector<float> &mus_isoR03_pf_radialTight() { return cms2.mus_isoR03_pf_radialTight(); }
	vector<float> &mus_backToBackCompat() { return cms2.mus_backToBackCompat(); }
	vector<float> &mus_caloCompatibility() { return cms2.mus_caloCompatibility(); }
	vector<float> &mus_chi2() { return cms2.mus_chi2(); }
	vector<float> &mus_chi2LocalMomentum() { return cms2.mus_chi2LocalMomentum(); }
	vector<float> &mus_chi2LocalPosition() { return cms2.mus_chi2LocalPosition(); }
	vector<float> &mus_cosmicCompat() { return cms2.mus_cosmicCompat(); }
	vector<float> &mus_d0() { return cms2.mus_d0(); }
	vector<float> &mus_d0Err() { return cms2.mus_d0Err(); }
	vector<float> &mus_d0corr() { return cms2.mus_d0corr(); }
	vector<float> &mus_e_em() { return cms2.mus_e_em(); }
	vector<float> &mus_e_emS9() { return cms2.mus_e_emS9(); }
	vector<float> &mus_e_had() { return cms2.mus_e_had(); }
	vector<float> &mus_e_hadS9() { return cms2.mus_e_hadS9(); }
	vector<float> &mus_e_ho() { return cms2.mus_e_ho(); }
	vector<float> &mus_e_hoS9() { return cms2.mus_e_hoS9(); }
	vector<float> &mus_etaErr() { return cms2.mus_etaErr(); }
	vector<float> &mus_gfit_chi2() { return cms2.mus_gfit_chi2(); }
	vector<float> &mus_gfit_d0() { return cms2.mus_gfit_d0(); }
	vector<float> &mus_gfit_d0Err() { return cms2.mus_gfit_d0Err(); }
	vector<float> &mus_gfit_d0corr() { return cms2.mus_gfit_d0corr(); }
	vector<float> &mus_gfit_ndof() { return cms2.mus_gfit_ndof(); }
	vector<float> &mus_gfit_qoverp() { return cms2.mus_gfit_qoverp(); }
	vector<float> &mus_gfit_qoverpError() { return cms2.mus_gfit_qoverpError(); }
	vector<float> &mus_gfit_z0() { return cms2.mus_gfit_z0(); }
	vector<float> &mus_gfit_z0Err() { return cms2.mus_gfit_z0Err(); }
	vector<float> &mus_gfit_z0corr() { return cms2.mus_gfit_z0corr(); }
	vector<float> &mus_glbKink() { return cms2.mus_glbKink(); }
	vector<float> &mus_glbTrackProbability() { return cms2.mus_glbTrackProbability(); }
	vector<float> &mus_globalDeltaEtaPhi() { return cms2.mus_globalDeltaEtaPhi(); }
	vector<float> &mus_ip3d() { return cms2.mus_ip3d(); }
	vector<float> &mus_ip3derr() { return cms2.mus_ip3derr(); }
	vector<float> &mus_iso03_emEt() { return cms2.mus_iso03_emEt(); }
	vector<float> &mus_iso03_hadEt() { return cms2.mus_iso03_hadEt(); }
	vector<float> &mus_iso03_hoEt() { return cms2.mus_iso03_hoEt(); }
	vector<float> &mus_iso03_pf() { return cms2.mus_iso03_pf(); }
	vector<float> &mus_iso03_sumPt() { return cms2.mus_iso03_sumPt(); }
	vector<float> &mus_iso04_pf() { return cms2.mus_iso04_pf(); }
	vector<float> &mus_iso05_emEt() { return cms2.mus_iso05_emEt(); }
	vector<float> &mus_iso05_hadEt() { return cms2.mus_iso05_hadEt(); }
	vector<float> &mus_iso05_hoEt() { return cms2.mus_iso05_hoEt(); }
	vector<float> &mus_iso05_sumPt() { return cms2.mus_iso05_sumPt(); }
	vector<float> &mus_isoR03_pf_ChargedHadronPt() { return cms2.mus_isoR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR03_pf_ChargedParticlePt() { return cms2.mus_isoR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEt() { return cms2.mus_isoR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR03_pf_PUPt() { return cms2.mus_isoR03_pf_PUPt(); }
	vector<float> &mus_isoR03_pf_PhotonEt() { return cms2.mus_isoR03_pf_PhotonEt(); }
	vector<float> &mus_isoR03_pf_PhotonEtHighThreshold() { return cms2.mus_isoR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_ChargedHadronPt() { return cms2.mus_isoR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR04_pf_ChargedParticlePt() { return cms2.mus_isoR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEt() { return cms2.mus_isoR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_PUPt() { return cms2.mus_isoR04_pf_PUPt(); }
	vector<float> &mus_isoR04_pf_PhotonEt() { return cms2.mus_isoR04_pf_PhotonEt(); }
	vector<float> &mus_isoR04_pf_PhotonEtHighThreshold() { return cms2.mus_isoR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_iso_ecalvetoDep() { return cms2.mus_iso_ecalvetoDep(); }
	vector<float> &mus_iso_hcalvetoDep() { return cms2.mus_iso_hcalvetoDep(); }
	vector<float> &mus_iso_hovetoDep() { return cms2.mus_iso_hovetoDep(); }
	vector<float> &mus_iso_trckvetoDep() { return cms2.mus_iso_trckvetoDep(); }
	vector<float> &mus_localDistance() { return cms2.mus_localDistance(); }
	vector<float> &mus_ndof() { return cms2.mus_ndof(); }
	vector<float> &mus_overlapCompat() { return cms2.mus_overlapCompat(); }
	vector<float> &mus_pfdeltaP() { return cms2.mus_pfdeltaP(); }
	vector<float> &mus_pfecalE() { return cms2.mus_pfecalE(); }
	vector<float> &mus_pfhcalE() { return cms2.mus_pfhcalE(); }
	vector<float> &mus_pfmva_emu() { return cms2.mus_pfmva_emu(); }
	vector<float> &mus_pfmva_epi() { return cms2.mus_pfmva_epi(); }
	vector<float> &mus_pfmva_nothing_gamma() { return cms2.mus_pfmva_nothing_gamma(); }
	vector<float> &mus_pfmva_nothing_nh() { return cms2.mus_pfmva_nothing_nh(); }
	vector<float> &mus_pfmva_pimu() { return cms2.mus_pfmva_pimu(); }
	vector<float> &mus_pfpS1E() { return cms2.mus_pfpS1E(); }
	vector<float> &mus_pfpS2E() { return cms2.mus_pfpS2E(); }
	vector<float> &mus_pfrawEcalE() { return cms2.mus_pfrawEcalE(); }
	vector<float> &mus_pfrawHcalE() { return cms2.mus_pfrawHcalE(); }
	vector<float> &mus_phiErr() { return cms2.mus_phiErr(); }
	vector<float> &mus_ptErr() { return cms2.mus_ptErr(); }
	vector<float> &mus_qoverp() { return cms2.mus_qoverp(); }
	vector<float> &mus_qoverpError() { return cms2.mus_qoverpError(); }
	vector<float> &mus_segmCompatibility() { return cms2.mus_segmCompatibility(); }
	vector<float> &mus_staRelChi2() { return cms2.mus_staRelChi2(); }
	vector<float> &mus_sta_chi2() { return cms2.mus_sta_chi2(); }
	vector<float> &mus_sta_d0() { return cms2.mus_sta_d0(); }
	vector<float> &mus_sta_d0Err() { return cms2.mus_sta_d0Err(); }
	vector<float> &mus_sta_d0corr() { return cms2.mus_sta_d0corr(); }
	vector<float> &mus_sta_ndof() { return cms2.mus_sta_ndof(); }
	vector<float> &mus_sta_qoverp() { return cms2.mus_sta_qoverp(); }
	vector<float> &mus_sta_qoverpError() { return cms2.mus_sta_qoverpError(); }
	vector<float> &mus_sta_z0() { return cms2.mus_sta_z0(); }
	vector<float> &mus_sta_z0Err() { return cms2.mus_sta_z0Err(); }
	vector<float> &mus_sta_z0corr() { return cms2.mus_sta_z0corr(); }
	vector<float> &mus_timeAtIpInOut() { return cms2.mus_timeAtIpInOut(); }
	vector<float> &mus_timeAtIpInOutErr() { return cms2.mus_timeAtIpInOutErr(); }
	vector<float> &mus_timeAtIpOutIn() { return cms2.mus_timeAtIpOutIn(); }
	vector<float> &mus_timeAtIpOutInErr() { return cms2.mus_timeAtIpOutInErr(); }
	vector<float> &mus_timeCompat() { return cms2.mus_timeCompat(); }
	vector<float> &mus_trkKink() { return cms2.mus_trkKink(); }
	vector<float> &mus_trkRelChi2() { return cms2.mus_trkRelChi2(); }
	vector<float> &mus_vertexCompat() { return cms2.mus_vertexCompat(); }
	vector<float> &mus_vertexphi() { return cms2.mus_vertexphi(); }
	vector<float> &mus_z0() { return cms2.mus_z0(); }
	vector<float> &mus_z0Err() { return cms2.mus_z0Err(); }
	vector<float> &mus_z0corr() { return cms2.mus_z0corr(); }
	vector<float> &pfjets_mvavalue() { return cms2.pfjets_mvavalue(); }
	vector<float> &pfjets_full53xmva_beta() { return cms2.pfjets_full53xmva_beta(); }
	vector<float> &pfjets_full53xmva_betaStar() { return cms2.pfjets_full53xmva_betaStar(); }
	vector<float> &pfjets_full53xmva_d0() { return cms2.pfjets_full53xmva_d0(); }
	vector<float> &pfjets_full53xmva_dRMean() { return cms2.pfjets_full53xmva_dRMean(); }
	vector<float> &pfjets_full53xmva_dZ() { return cms2.pfjets_full53xmva_dZ(); }
	vector<float> &pfjets_full53xmva_frac01() { return cms2.pfjets_full53xmva_frac01(); }
	vector<float> &pfjets_full53xmva_frac02() { return cms2.pfjets_full53xmva_frac02(); }
	vector<float> &pfjets_full53xmva_frac03() { return cms2.pfjets_full53xmva_frac03(); }
	vector<float> &pfjets_full53xmva_frac04() { return cms2.pfjets_full53xmva_frac04(); }
	vector<float> &pfjets_full53xmva_frac05() { return cms2.pfjets_full53xmva_frac05(); }
	vector<float> &pfjets_full53xmva_nCharged() { return cms2.pfjets_full53xmva_nCharged(); }
	vector<float> &pfjets_full53xmva_nNeutrals() { return cms2.pfjets_full53xmva_nNeutrals(); }
	vector<float> &pfjets_full53xmva_nvtx() { return cms2.pfjets_full53xmva_nvtx(); }
	vector<float> &pfjets_full53xmvavalue() { return cms2.pfjets_full53xmvavalue(); }
	vector<float> &pfjets_full5xmvavalue() { return cms2.pfjets_full5xmvavalue(); }
	vector<float> &trk_met() { return cms2.trk_met(); }
	vector<float> &trk_metPhi() { return cms2.trk_metPhi(); }
	vector<float> &trk_sumet() { return cms2.trk_sumet(); }
	vector<float> &pfels_deltaP() { return cms2.pfels_deltaP(); }
	vector<float> &pfels_ecalE() { return cms2.pfels_ecalE(); }
	vector<float> &pfels_hcalE() { return cms2.pfels_hcalE(); }
	vector<float> &pfels_iso04ChargedHadrons() { return cms2.pfels_iso04ChargedHadrons(); }
	vector<float> &pfels_iso04NeutralHadrons() { return cms2.pfels_iso04NeutralHadrons(); }
	vector<float> &pfels_iso04Photons() { return cms2.pfels_iso04Photons(); }
	vector<float> &pfels_isoChargedHadrons() { return cms2.pfels_isoChargedHadrons(); }
	vector<float> &pfels_isoNeutralHadrons() { return cms2.pfels_isoNeutralHadrons(); }
	vector<float> &pfels_isoPhotons() { return cms2.pfels_isoPhotons(); }
	vector<float> &pfels_mva_emu() { return cms2.pfels_mva_emu(); }
	vector<float> &pfels_mva_epi() { return cms2.pfels_mva_epi(); }
	vector<float> &pfels_mva_nothing_gamma() { return cms2.pfels_mva_nothing_gamma(); }
	vector<float> &pfels_mva_nothing_nh() { return cms2.pfels_mva_nothing_nh(); }
	vector<float> &pfels_mva_pimu() { return cms2.pfels_mva_pimu(); }
	vector<float> &pfels_pS1E() { return cms2.pfels_pS1E(); }
	vector<float> &pfels_pS2E() { return cms2.pfels_pS2E(); }
	vector<float> &pfels_rawEcalE() { return cms2.pfels_rawEcalE(); }
	vector<float> &pfels_rawHcalE() { return cms2.pfels_rawHcalE(); }
	vector<float> &pfjets_area() { return cms2.pfjets_area(); }
	vector<float> &pfjets_chargedEmE() { return cms2.pfjets_chargedEmE(); }
	vector<float> &pfjets_chargedHadronE() { return cms2.pfjets_chargedHadronE(); }
	vector<float> &pfjets_cor() { return cms2.pfjets_cor(); }
	vector<float> &pfjets_corL1Fast() { return cms2.pfjets_corL1Fast(); }
	vector<float> &pfjets_corL1FastL2L3() { return cms2.pfjets_corL1FastL2L3(); }
	vector<float> &pfjets_corL1FastL2L3residual() { return cms2.pfjets_corL1FastL2L3residual(); }
	vector<float> &pfjets_corL1L2L3() { return cms2.pfjets_corL1L2L3(); }
	vector<float> &pfjets_electronE() { return cms2.pfjets_electronE(); }
	vector<float> &pfjets_hfEmE() { return cms2.pfjets_hfEmE(); }
	vector<float> &pfjets_hfHadronE() { return cms2.pfjets_hfHadronE(); }
	vector<float> &pfjets_muonE() { return cms2.pfjets_muonE(); }
	vector<float> &pfjets_neutralEmE() { return cms2.pfjets_neutralEmE(); }
	vector<float> &pfjets_neutralHadronE() { return cms2.pfjets_neutralHadronE(); }
	vector<float> &pfjets_photonE() { return cms2.pfjets_photonE(); }
	vector<float> &pfmus_deltaP() { return cms2.pfmus_deltaP(); }
	vector<float> &pfmus_ecalE() { return cms2.pfmus_ecalE(); }
	vector<float> &pfmus_hcalE() { return cms2.pfmus_hcalE(); }
	vector<float> &pfmus_iso04ChargedHadrons() { return cms2.pfmus_iso04ChargedHadrons(); }
	vector<float> &pfmus_iso04NeutralHadrons() { return cms2.pfmus_iso04NeutralHadrons(); }
	vector<float> &pfmus_iso04Photons() { return cms2.pfmus_iso04Photons(); }
	vector<float> &pfmus_isoChargedHadrons() { return cms2.pfmus_isoChargedHadrons(); }
	vector<float> &pfmus_isoNeutralHadrons() { return cms2.pfmus_isoNeutralHadrons(); }
	vector<float> &pfmus_isoPhotons() { return cms2.pfmus_isoPhotons(); }
	vector<float> &pfmus_mva_emu() { return cms2.pfmus_mva_emu(); }
	vector<float> &pfmus_mva_epi() { return cms2.pfmus_mva_epi(); }
	vector<float> &pfmus_mva_nothing_gamma() { return cms2.pfmus_mva_nothing_gamma(); }
	vector<float> &pfmus_mva_nothing_nh() { return cms2.pfmus_mva_nothing_nh(); }
	vector<float> &pfmus_mva_pimu() { return cms2.pfmus_mva_pimu(); }
	vector<float> &pfmus_pS1E() { return cms2.pfmus_pS1E(); }
	vector<float> &pfmus_pS2E() { return cms2.pfmus_pS2E(); }
	vector<float> &pfmus_rawEcalE() { return cms2.pfmus_rawEcalE(); }
	vector<float> &pfmus_rawHcalE() { return cms2.pfmus_rawHcalE(); }
	vector<float> &taus_pf_againstElectronDeadECAL() { return cms2.taus_pf_againstElectronDeadECAL(); }
	vector<float> &taus_pf_againstElectronLoose() { return cms2.taus_pf_againstElectronLoose(); }
	vector<float> &taus_pf_againstElectronLooseMVA2() { return cms2.taus_pf_againstElectronLooseMVA2(); }
	vector<float> &taus_pf_againstElectronLooseMVA3() { return cms2.taus_pf_againstElectronLooseMVA3(); }
	vector<float> &taus_pf_againstElectronMVA() { return cms2.taus_pf_againstElectronMVA(); }
	vector<float> &taus_pf_againstElectronMVA2category() { return cms2.taus_pf_againstElectronMVA2category(); }
	vector<float> &taus_pf_againstElectronMVA2raw() { return cms2.taus_pf_againstElectronMVA2raw(); }
	vector<float> &taus_pf_againstElectronMVA3category() { return cms2.taus_pf_againstElectronMVA3category(); }
	vector<float> &taus_pf_againstElectronMVA3raw() { return cms2.taus_pf_againstElectronMVA3raw(); }
	vector<float> &taus_pf_againstElectronMedium() { return cms2.taus_pf_againstElectronMedium(); }
	vector<float> &taus_pf_againstElectronMediumMVA2() { return cms2.taus_pf_againstElectronMediumMVA2(); }
	vector<float> &taus_pf_againstElectronMediumMVA3() { return cms2.taus_pf_againstElectronMediumMVA3(); }
	vector<float> &taus_pf_againstElectronTight() { return cms2.taus_pf_againstElectronTight(); }
	vector<float> &taus_pf_againstElectronTightMVA2() { return cms2.taus_pf_againstElectronTightMVA2(); }
	vector<float> &taus_pf_againstElectronTightMVA3() { return cms2.taus_pf_againstElectronTightMVA3(); }
	vector<float> &taus_pf_againstElectronVLooseMVA2() { return cms2.taus_pf_againstElectronVLooseMVA2(); }
	vector<float> &taus_pf_againstElectronVTightMVA3() { return cms2.taus_pf_againstElectronVTightMVA3(); }
	vector<float> &taus_pf_againstMuonLoose() { return cms2.taus_pf_againstMuonLoose(); }
	vector<float> &taus_pf_againstMuonLoose2() { return cms2.taus_pf_againstMuonLoose2(); }
	vector<float> &taus_pf_againstMuonMedium() { return cms2.taus_pf_againstMuonMedium(); }
	vector<float> &taus_pf_againstMuonMedium2() { return cms2.taus_pf_againstMuonMedium2(); }
	vector<float> &taus_pf_againstMuonTight() { return cms2.taus_pf_againstMuonTight(); }
	vector<float> &taus_pf_againstMuonTight2() { return cms2.taus_pf_againstMuonTight2(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits(); }
	vector<float> &taus_pf_byDecayModeFinding() { return cms2.taus_pf_byDecayModeFinding(); }
	vector<float> &taus_pf_byIsolationMVA2raw() { return cms2.taus_pf_byIsolationMVA2raw(); }
	vector<float> &taus_pf_byIsolationMVAraw() { return cms2.taus_pf_byIsolationMVAraw(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byLooseIsolationMVA() { return cms2.taus_pf_byLooseIsolationMVA(); }
	vector<float> &taus_pf_byLooseIsolationMVA2() { return cms2.taus_pf_byLooseIsolationMVA2(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byMediumIsolationMVA() { return cms2.taus_pf_byMediumIsolationMVA(); }
	vector<float> &taus_pf_byMediumIsolationMVA2() { return cms2.taus_pf_byMediumIsolationMVA2(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byTightIsolationMVA() { return cms2.taus_pf_byTightIsolationMVA(); }
	vector<float> &taus_pf_byTightIsolationMVA2() { return cms2.taus_pf_byTightIsolationMVA2(); }
	vector<float> &taus_pf_byVLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byVLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &photons_e1x5() { return cms2.photons_e1x5(); }
	vector<float> &photons_e2x5Max() { return cms2.photons_e2x5Max(); }
	vector<float> &photons_e3x3() { return cms2.photons_e3x3(); }
	vector<float> &photons_e5x5() { return cms2.photons_e5x5(); }
	vector<float> &photons_ecalIso03() { return cms2.photons_ecalIso03(); }
	vector<float> &photons_ecalIso04() { return cms2.photons_ecalIso04(); }
	vector<float> &photons_hOverE() { return cms2.photons_hOverE(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalIso03() { return cms2.photons_hcalIso03(); }
	vector<float> &photons_hcalIso04() { return cms2.photons_hcalIso04(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR03() { return cms2.photons_hcalTowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR04() { return cms2.photons_hcalTowerSumEtBcConeDR04(); }
	vector<float> &photons_ntkIsoHollow03() { return cms2.photons_ntkIsoHollow03(); }
	vector<float> &photons_ntkIsoHollow04() { return cms2.photons_ntkIsoHollow04(); }
	vector<float> &photons_ntkIsoSolid03() { return cms2.photons_ntkIsoSolid03(); }
	vector<float> &photons_ntkIsoSolid04() { return cms2.photons_ntkIsoSolid04(); }
	vector<float> &photons_sigmaEtaEta() { return cms2.photons_sigmaEtaEta(); }
	vector<float> &photons_sigmaIEtaIEta() { return cms2.photons_sigmaIEtaIEta(); }
	vector<float> &photons_swissSeed() { return cms2.photons_swissSeed(); }
	vector<float> &photons_tkIsoHollow03() { return cms2.photons_tkIsoHollow03(); }
	vector<float> &photons_tkIsoHollow04() { return cms2.photons_tkIsoHollow04(); }
	vector<float> &photons_tkIsoSolid03() { return cms2.photons_tkIsoSolid03(); }
	vector<float> &photons_tkIsoSolid04() { return cms2.photons_tkIsoSolid04(); }
	vector<float> &puInfo_trueNumInteractions() { return cms2.puInfo_trueNumInteractions(); }
	vector<float> &convs_chi2() { return cms2.convs_chi2(); }
	vector<float> &convs_dl() { return cms2.convs_dl(); }
	vector<float> &convs_ndof() { return cms2.convs_ndof(); }
	vector<float> &scs_clustersSize() { return cms2.scs_clustersSize(); }
	vector<float> &scs_crystalsSize() { return cms2.scs_crystalsSize(); }
	vector<float> &scs_e1x3() { return cms2.scs_e1x3(); }
	vector<float> &scs_e1x5() { return cms2.scs_e1x5(); }
	vector<float> &scs_e2nd() { return cms2.scs_e2nd(); }
	vector<float> &scs_e2x2() { return cms2.scs_e2x2(); }
	vector<float> &scs_e2x5Max() { return cms2.scs_e2x5Max(); }
	vector<float> &scs_e3x1() { return cms2.scs_e3x1(); }
	vector<float> &scs_e3x2() { return cms2.scs_e3x2(); }
	vector<float> &scs_e3x3() { return cms2.scs_e3x3(); }
	vector<float> &scs_e4x4() { return cms2.scs_e4x4(); }
	vector<float> &scs_e5x5() { return cms2.scs_e5x5(); }
	vector<float> &scs_eMax() { return cms2.scs_eMax(); }
	vector<float> &scs_eSeed() { return cms2.scs_eSeed(); }
	vector<float> &scs_energy() { return cms2.scs_energy(); }
	vector<float> &scs_eta() { return cms2.scs_eta(); }
	vector<float> &scs_hoe() { return cms2.scs_hoe(); }
	vector<float> &scs_laserCorMax() { return cms2.scs_laserCorMax(); }
	vector<float> &scs_laserCorMean() { return cms2.scs_laserCorMean(); }
	vector<float> &scs_laserCorSeed() { return cms2.scs_laserCorSeed(); }
	vector<float> &scs_phi() { return cms2.scs_phi(); }
	vector<float> &scs_preshowerEnergy() { return cms2.scs_preshowerEnergy(); }
	vector<float> &scs_rawEnergy() { return cms2.scs_rawEnergy(); }
	vector<float> &scs_sigmaEtaEta() { return cms2.scs_sigmaEtaEta(); }
	vector<float> &scs_sigmaEtaPhi() { return cms2.scs_sigmaEtaPhi(); }
	vector<float> &scs_sigmaIEtaIEta() { return cms2.scs_sigmaIEtaIEta(); }
	vector<float> &scs_sigmaIEtaIEtaSC() { return cms2.scs_sigmaIEtaIEtaSC(); }
	vector<float> &scs_sigmaIEtaIPhi() { return cms2.scs_sigmaIEtaIPhi(); }
	vector<float> &scs_sigmaIEtaIPhiSC() { return cms2.scs_sigmaIEtaIPhiSC(); }
	vector<float> &scs_sigmaIPhiIPhi() { return cms2.scs_sigmaIPhiIPhi(); }
	vector<float> &scs_sigmaIPhiIPhiSC() { return cms2.scs_sigmaIPhiIPhiSC(); }
	vector<float> &scs_sigmaPhiPhi() { return cms2.scs_sigmaPhiPhi(); }
	vector<float> &scs_timeSeed() { return cms2.scs_timeSeed(); }
	vector<float> &mus_tcmet_deltax() { return cms2.mus_tcmet_deltax(); }
	vector<float> &mus_tcmet_deltay() { return cms2.mus_tcmet_deltay(); }
	vector<float> &pfcands_dzpv() { return cms2.pfcands_dzpv(); }
	vector<float> &pfcands_trkiso() { return cms2.pfcands_trkiso(); }
	vector<float> &trks_chi2() { return cms2.trks_chi2(); }
	vector<float> &trks_d0() { return cms2.trks_d0(); }
	vector<float> &trks_d0Err() { return cms2.trks_d0Err(); }
	vector<float> &trks_d0corr() { return cms2.trks_d0corr(); }
	vector<float> &trks_d0phiCov() { return cms2.trks_d0phiCov(); }
	vector<float> &trks_etaErr() { return cms2.trks_etaErr(); }
	vector<float> &trks_ndof() { return cms2.trks_ndof(); }
	vector<float> &trks_phiErr() { return cms2.trks_phiErr(); }
	vector<float> &trks_ptErr() { return cms2.trks_ptErr(); }
	vector<float> &trks_validFraction() { return cms2.trks_validFraction(); }
	vector<float> &trks_z0() { return cms2.trks_z0(); }
	vector<float> &trks_z0Err() { return cms2.trks_z0Err(); }
	vector<float> &trks_z0corr() { return cms2.trks_z0corr(); }
	vector<float> &vtxs_chi2() { return cms2.vtxs_chi2(); }
	vector<float> &vtxs_ndof() { return cms2.vtxs_ndof(); }
	vector<float> &vtxs_sumpt() { return cms2.vtxs_sumpt(); }
	vector<float> &vtxs_xError() { return cms2.vtxs_xError(); }
	vector<float> &vtxs_yError() { return cms2.vtxs_yError(); }
	vector<float> &vtxs_zError() { return cms2.vtxs_zError(); }
	vector<vector<float> > &els_convs_dcot() { return cms2.els_convs_dcot(); }
	vector<vector<float> > &els_convs_dist() { return cms2.els_convs_dist(); }
	vector<vector<float> > &els_convs_radius() { return cms2.els_convs_radius(); }
	vector<vector<float> > &mus_stationShowerDeltaR() { return cms2.mus_stationShowerDeltaR(); }
	vector<vector<float> > &mus_stationShowerSizeT() { return cms2.mus_stationShowerSizeT(); }
	vector<vector<float> > &puInfo_instLumi() { return cms2.puInfo_instLumi(); }
	vector<vector<float> > &vtxs_covMatrix() { return cms2.vtxs_covMatrix(); }
	int &evt_cscLooseHaloId() { return cms2.evt_cscLooseHaloId(); }
	int &evt_cscTightHaloId() { return cms2.evt_cscTightHaloId(); }
	int &evt_ecalLooseHaloId() { return cms2.evt_ecalLooseHaloId(); }
	int &evt_ecalTightHaloId() { return cms2.evt_ecalTightHaloId(); }
	int &evt_extremeTightHaloId() { return cms2.evt_extremeTightHaloId(); }
	int &evt_globalLooseHaloId() { return cms2.evt_globalLooseHaloId(); }
	int &evt_globalTightHaloId() { return cms2.evt_globalTightHaloId(); }
	int &evt_hcalLooseHaloId() { return cms2.evt_hcalLooseHaloId(); }
	int &evt_hcalTightHaloId() { return cms2.evt_hcalTightHaloId(); }
	int &evt_looseHaloId() { return cms2.evt_looseHaloId(); }
	int &evt_nHaloLikeTracks() { return cms2.evt_nHaloLikeTracks(); }
	int &evt_nHaloTriggerCandidates() { return cms2.evt_nHaloTriggerCandidates(); }
	int &evt_tightHaloId() { return cms2.evt_tightHaloId(); }
	int &evt_bsType() { return cms2.evt_bsType(); }
	int &evt_bunchCrossing() { return cms2.evt_bunchCrossing(); }
	int &evt_experimentType() { return cms2.evt_experimentType(); }
	int &evt_isRealData() { return cms2.evt_isRealData(); }
	int &evt_orbitNumber() { return cms2.evt_orbitNumber(); }
	int &evt_storeNumber() { return cms2.evt_storeNumber(); }
	int &hcalnoise_GetRecHitCount() { return cms2.hcalnoise_GetRecHitCount(); }
	int &hcalnoise_GetRecHitCount15() { return cms2.hcalnoise_GetRecHitCount15(); }
	int &hcalnoise_maxHPDHits() { return cms2.hcalnoise_maxHPDHits(); }
	int &hcalnoise_maxHPDNoOtherHits() { return cms2.hcalnoise_maxHPDNoOtherHits(); }
	int &hcalnoise_maxRBXHits() { return cms2.hcalnoise_maxRBXHits(); }
	int &hcalnoise_maxZeros() { return cms2.hcalnoise_maxZeros(); }
	int &hcalnoise_noiseFilterStatus() { return cms2.hcalnoise_noiseFilterStatus(); }
	int &hcalnoise_noiseType() { return cms2.hcalnoise_noiseType(); }
	int &hcalnoise_num10GeVHits() { return cms2.hcalnoise_num10GeVHits(); }
	int &hcalnoise_num25GeVHits() { return cms2.hcalnoise_num25GeVHits(); }
	int &hcalnoise_numFlatNoiseChannels() { return cms2.hcalnoise_numFlatNoiseChannels(); }
	int &hcalnoise_numIsolatedNoiseChannels() { return cms2.hcalnoise_numIsolatedNoiseChannels(); }
	int &hcalnoise_numProblematicRBXs() { return cms2.hcalnoise_numProblematicRBXs(); }
	int &hcalnoise_numSpikeNoiseChannels() { return cms2.hcalnoise_numSpikeNoiseChannels(); }
	int &hcalnoise_numTS4TS5NoiseChannels() { return cms2.hcalnoise_numTS4TS5NoiseChannels(); }
	int &hcalnoise_numTriangleNoiseChannels() { return cms2.hcalnoise_numTriangleNoiseChannels(); }
	int &hcalnoise_passHighLevelNoiseFilter() { return cms2.hcalnoise_passHighLevelNoiseFilter(); }
	int &hcalnoise_passLooseNoiseFilter() { return cms2.hcalnoise_passLooseNoiseFilter(); }
	int &hcalnoise_passTightNoiseFilter() { return cms2.hcalnoise_passTightNoiseFilter(); }
	int &ls_lumiSecQual() { return cms2.ls_lumiSecQual(); }
	int &pdfinfo_id1() { return cms2.pdfinfo_id1(); }
	int &pdfinfo_id2() { return cms2.pdfinfo_id2(); }
	vector<int> &evt_ecaliPhiSuspects() { return cms2.evt_ecaliPhiSuspects(); }
	vector<int> &evt_globaliPhiSuspects() { return cms2.evt_globaliPhiSuspects(); }
	vector<int> &evt_hcaliPhiSuspects() { return cms2.evt_hcaliPhiSuspects(); }
	vector<int> &els_mc3_id() { return cms2.els_mc3_id(); }
	vector<int> &els_mc3idx() { return cms2.els_mc3idx(); }
	vector<int> &els_mc3_motherid() { return cms2.els_mc3_motherid(); }
	vector<int> &els_mc3_motheridx() { return cms2.els_mc3_motheridx(); }
	vector<int> &els_mc_id() { return cms2.els_mc_id(); }
	vector<int> &els_mcidx() { return cms2.els_mcidx(); }
	vector<int> &els_mc_motherid() { return cms2.els_mc_motherid(); }
	vector<int> &mus_mc3_id() { return cms2.mus_mc3_id(); }
	vector<int> &mus_mc3idx() { return cms2.mus_mc3idx(); }
	vector<int> &mus_mc3_motherid() { return cms2.mus_mc3_motherid(); }
	vector<int> &mus_mc3_motheridx() { return cms2.mus_mc3_motheridx(); }
	vector<int> &mus_mc_id() { return cms2.mus_mc_id(); }
	vector<int> &mus_mcidx() { return cms2.mus_mcidx(); }
	vector<int> &mus_mc_motherid() { return cms2.mus_mc_motherid(); }
	vector<int> &pfjets_mc3_id() { return cms2.pfjets_mc3_id(); }
	vector<int> &pfjets_mc3idx() { return cms2.pfjets_mc3idx(); }
	vector<int> &pfjets_mc_gpidx() { return cms2.pfjets_mc_gpidx(); }
	vector<int> &pfjets_mc_id() { return cms2.pfjets_mc_id(); }
	vector<int> &pfjets_mcidx() { return cms2.pfjets_mcidx(); }
	vector<int> &pfjets_mc_motherid() { return cms2.pfjets_mc_motherid(); }
	vector<int> &photons_mc3_id() { return cms2.photons_mc3_id(); }
	vector<int> &photons_mc3idx() { return cms2.photons_mc3idx(); }
	vector<int> &photons_mc3_motherid() { return cms2.photons_mc3_motherid(); }
	vector<int> &photons_mc3_motheridx() { return cms2.photons_mc3_motheridx(); }
	vector<int> &photons_mc_id() { return cms2.photons_mc_id(); }
	vector<int> &photons_mcidx() { return cms2.photons_mcidx(); }
	vector<int> &photons_mc_motherid() { return cms2.photons_mc_motherid(); }
	vector<int> &els_closestJet() { return cms2.els_closestJet(); }
	vector<int> &els_closestMuon() { return cms2.els_closestMuon(); }
	vector<int> &els_pfelsidx() { return cms2.els_pfelsidx(); }
	vector<int> &els_category() { return cms2.els_category(); }
	vector<int> &els_charge() { return cms2.els_charge(); }
	vector<int> &els_ckf_laywithmeas() { return cms2.els_ckf_laywithmeas(); }
	vector<int> &els_class() { return cms2.els_class(); }
	vector<int> &els_conv_delMissHits() { return cms2.els_conv_delMissHits(); }
	vector<int> &els_conv_flag() { return cms2.els_conv_flag(); }
	vector<int> &els_conv_gsftkidx() { return cms2.els_conv_gsftkidx(); }
	vector<int> &els_conv_old_delMissHits() { return cms2.els_conv_old_delMissHits(); }
	vector<int> &els_conv_old_flag() { return cms2.els_conv_old_flag(); }
	vector<int> &els_conv_old_gsftkidx() { return cms2.els_conv_old_gsftkidx(); }
	vector<int> &els_conv_old_tkidx() { return cms2.els_conv_old_tkidx(); }
	vector<int> &els_conv_tkidx() { return cms2.els_conv_tkidx(); }
	vector<int> &els_exp_innerlayers() { return cms2.els_exp_innerlayers(); }
	vector<int> &els_exp_outerlayers() { return cms2.els_exp_outerlayers(); }
	vector<int> &els_fiduciality() { return cms2.els_fiduciality(); }
	vector<int> &els_gsftrkidx() { return cms2.els_gsftrkidx(); }
	vector<int> &els_layer1_det() { return cms2.els_layer1_det(); }
	vector<int> &els_layer1_layer() { return cms2.els_layer1_layer(); }
	vector<int> &els_layer1_sizerphi() { return cms2.els_layer1_sizerphi(); }
	vector<int> &els_layer1_sizerz() { return cms2.els_layer1_sizerz(); }
	vector<int> &els_lostHits() { return cms2.els_lostHits(); }
	vector<int> &els_lost_pixelhits() { return cms2.els_lost_pixelhits(); }
	vector<int> &els_nSeed() { return cms2.els_nSeed(); }
	vector<int> &els_sccharge() { return cms2.els_sccharge(); }
	vector<int> &els_scindex() { return cms2.els_scindex(); }
	vector<int> &els_trk_charge() { return cms2.els_trk_charge(); }
	vector<int> &els_trkidx() { return cms2.els_trkidx(); }
	vector<int> &els_type() { return cms2.els_type(); }
	vector<int> &els_validHits() { return cms2.els_validHits(); }
	vector<int> &els_valid_pixelhits() { return cms2.els_valid_pixelhits(); }
	vector<int> &genps_id() { return cms2.genps_id(); }
	vector<int> &genps_id_mother() { return cms2.genps_id_mother(); }
	vector<int> &genps_status() { return cms2.genps_status(); }
	vector<int> &gsftrks_charge() { return cms2.gsftrks_charge(); }
	vector<int> &gsftrks_exp_innerlayers() { return cms2.gsftrks_exp_innerlayers(); }
	vector<int> &gsftrks_exp_outerlayers() { return cms2.gsftrks_exp_outerlayers(); }
	vector<int> &gsftrks_lostHits() { return cms2.gsftrks_lostHits(); }
	vector<int> &gsftrks_nlayers() { return cms2.gsftrks_nlayers(); }
	vector<int> &gsftrks_validHits() { return cms2.gsftrks_validHits(); }
	vector<int> &gsftrks_valid_pixelhits() { return cms2.gsftrks_valid_pixelhits(); }
	vector<int> &hyp_ll_charge() { return cms2.hyp_ll_charge(); }
	vector<int> &hyp_ll_id() { return cms2.hyp_ll_id(); }
	vector<int> &hyp_ll_index() { return cms2.hyp_ll_index(); }
	vector<int> &hyp_lt_charge() { return cms2.hyp_lt_charge(); }
	vector<int> &hyp_lt_id() { return cms2.hyp_lt_id(); }
	vector<int> &hyp_lt_index() { return cms2.hyp_lt_index(); }
	vector<int> &hyp_type() { return cms2.hyp_type(); }
	vector<int> &hyp_ll_mc_id() { return cms2.hyp_ll_mc_id(); }
	vector<int> &hyp_ll_mc_motherid() { return cms2.hyp_ll_mc_motherid(); }
	vector<int> &hyp_lt_mc_id() { return cms2.hyp_lt_mc_id(); }
	vector<int> &hyp_lt_mc_motherid() { return cms2.hyp_lt_mc_motherid(); }
	vector<int> &pfjets_mcflavorAlgo() { return cms2.pfjets_mcflavorAlgo(); }
	vector<int> &pfjets_mcflavorPhys() { return cms2.pfjets_mcflavorPhys(); }
	vector<int> &jets_closestElectron() { return cms2.jets_closestElectron(); }
	vector<int> &jets_closestMuon() { return cms2.jets_closestMuon(); }
	vector<int> &mus_met_flag() { return cms2.mus_met_flag(); }
	vector<int> &mus_closestEle() { return cms2.mus_closestEle(); }
	vector<int> &mus_closestJet() { return cms2.mus_closestJet(); }
	vector<int> &mus_pfmusidx() { return cms2.mus_pfmusidx(); }
	vector<int> &mus_charge() { return cms2.mus_charge(); }
	vector<int> &mus_gfit_validHits() { return cms2.mus_gfit_validHits(); }
	vector<int> &mus_gfit_validSTAHits() { return cms2.mus_gfit_validSTAHits(); }
	vector<int> &mus_gfit_validSiHits() { return cms2.mus_gfit_validSiHits(); }
	vector<int> &mus_goodmask() { return cms2.mus_goodmask(); }
	vector<int> &mus_iso03_ntrk() { return cms2.mus_iso03_ntrk(); }
	vector<int> &mus_iso05_ntrk() { return cms2.mus_iso05_ntrk(); }
	vector<int> &mus_lostHits() { return cms2.mus_lostHits(); }
	vector<int> &mus_muonBestTrackType() { return cms2.mus_muonBestTrackType(); }
	vector<int> &mus_nOverlaps() { return cms2.mus_nOverlaps(); }
	vector<int> &mus_nmatches() { return cms2.mus_nmatches(); }
	vector<int> &mus_numberOfMatchedStations() { return cms2.mus_numberOfMatchedStations(); }
	vector<int> &mus_overlap0() { return cms2.mus_overlap0(); }
	vector<int> &mus_overlap1() { return cms2.mus_overlap1(); }
	vector<int> &mus_pfcharge() { return cms2.mus_pfcharge(); }
	vector<int> &mus_pfflag() { return cms2.mus_pfflag(); }
	vector<int> &mus_pfparticleId() { return cms2.mus_pfparticleId(); }
	vector<int> &mus_pid_PFMuon() { return cms2.mus_pid_PFMuon(); }
	vector<int> &mus_pid_TM2DCompatibilityLoose() { return cms2.mus_pid_TM2DCompatibilityLoose(); }
	vector<int> &mus_pid_TM2DCompatibilityTight() { return cms2.mus_pid_TM2DCompatibilityTight(); }
	vector<int> &mus_pid_TMLastStationLoose() { return cms2.mus_pid_TMLastStationLoose(); }
	vector<int> &mus_pid_TMLastStationTight() { return cms2.mus_pid_TMLastStationTight(); }
	vector<int> &mus_sta_validHits() { return cms2.mus_sta_validHits(); }
	vector<int> &mus_timeDirection() { return cms2.mus_timeDirection(); }
	vector<int> &mus_timeNumStationsUsed() { return cms2.mus_timeNumStationsUsed(); }
	vector<int> &mus_trk_charge() { return cms2.mus_trk_charge(); }
	vector<int> &mus_trkidx() { return cms2.mus_trkidx(); }
	vector<int> &mus_type() { return cms2.mus_type(); }
	vector<int> &mus_validHits() { return cms2.mus_validHits(); }
	vector<int> &pfcands_charge() { return cms2.pfcands_charge(); }
	vector<int> &pfcands_particleId() { return cms2.pfcands_particleId(); }
	vector<int> &pfcands_pfelsidx() { return cms2.pfcands_pfelsidx(); }
	vector<int> &pfcands_pfmusidx() { return cms2.pfcands_pfmusidx(); }
	vector<int> &pfcands_trkidx() { return cms2.pfcands_trkidx(); }
	vector<int> &pfcands_vtxidx() { return cms2.pfcands_vtxidx(); }
	vector<int> &pfels_elsidx() { return cms2.pfels_elsidx(); }
	vector<int> &pfels_charge() { return cms2.pfels_charge(); }
	vector<int> &pfels_flag() { return cms2.pfels_flag(); }
	vector<int> &pfels_particleId() { return cms2.pfels_particleId(); }
	vector<int> &pfjets_chargedHadronMultiplicity() { return cms2.pfjets_chargedHadronMultiplicity(); }
	vector<int> &pfjets_chargedMultiplicity() { return cms2.pfjets_chargedMultiplicity(); }
	vector<int> &pfjets_electronMultiplicity() { return cms2.pfjets_electronMultiplicity(); }
	vector<int> &pfjets_hfEmMultiplicity() { return cms2.pfjets_hfEmMultiplicity(); }
	vector<int> &pfjets_hfHadronMultiplicity() { return cms2.pfjets_hfHadronMultiplicity(); }
	vector<int> &pfjets_muonMultiplicity() { return cms2.pfjets_muonMultiplicity(); }
	vector<int> &pfjets_neutralHadronMultiplicity() { return cms2.pfjets_neutralHadronMultiplicity(); }
	vector<int> &pfjets_neutralMultiplicity() { return cms2.pfjets_neutralMultiplicity(); }
	vector<int> &pfjets_photonMultiplicity() { return cms2.pfjets_photonMultiplicity(); }
	vector<int> &pfmus_musidx() { return cms2.pfmus_musidx(); }
	vector<int> &pfmus_charge() { return cms2.pfmus_charge(); }
	vector<int> &pfmus_flag() { return cms2.pfmus_flag(); }
	vector<int> &pfmus_particleId() { return cms2.pfmus_particleId(); }
	vector<int> &taus_pf_charge() { return cms2.taus_pf_charge(); }
	vector<int> &taus_pf_pfjetIndex() { return cms2.taus_pf_pfjetIndex(); }
	vector<int> &photons_fiduciality() { return cms2.photons_fiduciality(); }
	vector<int> &photons_scindex() { return cms2.photons_scindex(); }
	vector<int> &puInfo_bunchCrossing() { return cms2.puInfo_bunchCrossing(); }
	vector<int> &puInfo_nPUvertices() { return cms2.puInfo_nPUvertices(); }
	vector<int> &convs_algo() { return cms2.convs_algo(); }
	vector<int> &convs_isConverted() { return cms2.convs_isConverted(); }
	vector<int> &convs_quality() { return cms2.convs_quality(); }
	vector<int> &scs_detIdSeed() { return cms2.scs_detIdSeed(); }
	vector<int> &scs_elsidx() { return cms2.scs_elsidx(); }
	vector<int> &scs_severitySeed() { return cms2.scs_severitySeed(); }
	vector<int> &mus_tcmet_flag() { return cms2.mus_tcmet_flag(); }
	vector<int> &trks_algo() { return cms2.trks_algo(); }
	vector<int> &trks_charge() { return cms2.trks_charge(); }
	vector<int> &trks_exp_innerlayers() { return cms2.trks_exp_innerlayers(); }
	vector<int> &trks_exp_outerlayers() { return cms2.trks_exp_outerlayers(); }
	vector<int> &trks_lostHits() { return cms2.trks_lostHits(); }
	vector<int> &trks_nLoops() { return cms2.trks_nLoops(); }
	vector<int> &trks_nlayers() { return cms2.trks_nlayers(); }
	vector<int> &trks_pvidx0() { return cms2.trks_pvidx0(); }
	vector<int> &trks_pvidx1() { return cms2.trks_pvidx1(); }
	vector<int> &trks_qualityMask() { return cms2.trks_qualityMask(); }
	vector<int> &trks_validHits() { return cms2.trks_validHits(); }
	vector<int> &trks_valid_pixelhits() { return cms2.trks_valid_pixelhits(); }
	vector<int> &trks_elsidx() { return cms2.trks_elsidx(); }
	vector<int> &trk_musidx() { return cms2.trk_musidx(); }
	vector<int> &vtxs_isFake() { return cms2.vtxs_isFake(); }
	vector<int> &vtxs_isValid() { return cms2.vtxs_isValid(); }
	vector<int> &vtxs_tracksSize() { return cms2.vtxs_tracksSize(); }
	vector<vector<int> > &els_convs_delMissHits() { return cms2.els_convs_delMissHits(); }
	vector<vector<int> > &els_convs_flag() { return cms2.els_convs_flag(); }
	vector<vector<int> > &els_convs_gsftkidx() { return cms2.els_convs_gsftkidx(); }
	vector<vector<int> > &els_convs_tkidx() { return cms2.els_convs_tkidx(); }
	vector<vector<int> > &genps_lepdaughter_id() { return cms2.genps_lepdaughter_id(); }
	vector<vector<int> > &genps_lepdaughter_idx() { return cms2.genps_lepdaughter_idx(); }
	vector<vector<int> > &hlt_trigObjs_id() { return cms2.hlt_trigObjs_id(); }
	vector<vector<int> > &mus_nStationCorrelatedHits() { return cms2.mus_nStationCorrelatedHits(); }
	vector<vector<int> > &mus_nStationHits() { return cms2.mus_nStationHits(); }
	vector<vector<int> > &pfjets_pfcandIndicies() { return cms2.pfjets_pfcandIndicies(); }
	vector<vector<int> > &taus_pf_pfcandIndicies() { return cms2.taus_pf_pfcandIndicies(); }
	vector<vector<int> > &convs_nHitsBeforeVtx() { return cms2.convs_nHitsBeforeVtx(); }
	vector<vector<int> > &convs_tkalgo() { return cms2.convs_tkalgo(); }
	vector<vector<int> > &convs_tkidx() { return cms2.convs_tkidx(); }
	unsigned int &els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version(); }
	unsigned int &els_HLT_Ele17_Ele8_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_version() { return cms2.els_HLT_Ele17_Ele8_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version(); }
	unsigned int &els_HLT_Ele27_WP80_version() { return cms2.els_HLT_Ele27_WP80_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_version() { return cms2.els_HLT_Mu17_Ele8_version(); }
	unsigned int &els_HLT_Mu8_Ele17_version() { return cms2.els_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nels() { return cms2.evt_nels(); }
	unsigned int &evt_detectorStatus() { return cms2.evt_detectorStatus(); }
	unsigned int &evt_event() { return cms2.evt_event(); }
	unsigned int &evt_lumiBlock() { return cms2.evt_lumiBlock(); }
	unsigned int &evt_run() { return cms2.evt_run(); }
	unsigned int &genps_flavorHistoryFilterResult() { return cms2.genps_flavorHistoryFilterResult(); }
	unsigned int &evt_ngenjetsNoMuNoNu() { return cms2.evt_ngenjetsNoMuNoNu(); }
	unsigned int &genps_signalProcessID() { return cms2.genps_signalProcessID(); }
	unsigned int &evt_ngenjets() { return cms2.evt_ngenjets(); }
	unsigned int &ls_lsNumber() { return cms2.ls_lsNumber(); }
	unsigned int &ls_numOrbit() { return cms2.ls_numOrbit(); }
	unsigned int &ls_startOrbit() { return cms2.ls_startOrbit(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_version() { return cms2.mus_HLT_Mu17_Ele8_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_version() { return cms2.mus_HLT_Mu17_Mu8_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_version() { return cms2.mus_HLT_Mu17_TkMu8_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_TrailingLeg_version() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_version() { return cms2.mus_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nphotons() { return cms2.evt_nphotons(); }
	unsigned int &evt_ecalRecoStatus() { return cms2.evt_ecalRecoStatus(); }
	unsigned int &evt_nscs() { return cms2.evt_nscs(); }
	unsigned int &evt_nvtxs() { return cms2.evt_nvtxs(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8() { return cms2.els_HLT_Ele17_Ele8(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_L1sL1DoubleEG137() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_LeadingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_TrailingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele27_WP80() { return cms2.els_HLT_Ele27_WP80(); }
	vector<unsigned int> &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_LeadingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_TrailingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8() { return cms2.els_HLT_Mu17_Ele8(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8_TrailingLeg() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu8_Ele17() { return cms2.els_HLT_Mu8_Ele17(); }
	vector<unsigned int> &els_id2012ext_loose() { return cms2.els_id2012ext_loose(); }
	vector<unsigned int> &els_id2012ext_medium() { return cms2.els_id2012ext_medium(); }
	vector<unsigned int> &els_id2012ext_tight() { return cms2.els_id2012ext_tight(); }
	vector<unsigned int> &els_id2012ext_veto() { return cms2.els_id2012ext_veto(); }
	vector<unsigned int> &els_id2012_loose() { return cms2.els_id2012_loose(); }
	vector<unsigned int> &els_id2012_medium() { return cms2.els_id2012_medium(); }
	vector<unsigned int> &els_id2012_tight() { return cms2.els_id2012_tight(); }
	vector<unsigned int> &els_id2012_veto() { return cms2.els_id2012_veto(); }
	vector<unsigned int> &hlt_prescales() { return cms2.hlt_prescales(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8() { return cms2.mus_HLT_Mu17_Ele8(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8_LeadingLeg() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8() { return cms2.mus_HLT_Mu17_Mu8(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_LeadingLeg() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_TrailingLeg() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8() { return cms2.mus_HLT_Mu17_TkMu8(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_LeadingLeg() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLeg() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17() { return cms2.mus_HLT_Mu8_Ele17(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17_TrailingLeg() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg(); }
	int &evt_nEvts() { return cms2.evt_nEvts(); }
	float &evt_filt_eff() { return cms2.evt_filt_eff(); }
	bool passHLTTrigger(TString trigName) { return cms2.passHLTTrigger(trigName); }
}
