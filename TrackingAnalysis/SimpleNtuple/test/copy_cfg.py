import FWCore.ParameterSet.Config as cms

# Give the process a name
process = cms.Process("CopyEvents")

# Tell the process which files to use as the sourdce
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source("PoolSource", fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_100_2_MGV.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_10_1_8am.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_11_1_dYa.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_12_1_zZA.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_13_2_9ZC.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_14_2_M0W.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_15_2_WkT.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_16_2_VhR.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_17_2_jXo.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_18_2_e7j.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_19_1_SJq.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_1_1_7sz.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_20_2_KSk.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_21_1_NBr.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_22_2_JDr.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_23_1_6ty.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_24_2_K6Z.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_25_1_Byc.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_26_1_VfA.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_27_1_QI5.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_28_1_hn5.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_29_2_Z5q.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_2_3_kuy.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_30_3_7cQ.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_31_1_34f.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_32_1_1FR.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_33_1_ApV.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_34_1_vy3.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_35_1_hlS.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_36_1_gCQ.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_37_2_3Z3.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_38_2_PFq.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_39_1_6IO.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_3_2_ObY.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_40_1_mA3.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_41_1_CQb.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_42_1_1Eg.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_43_1_m3m.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_44_1_5Od.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_45_1_NK2.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_46_3_Igh.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_47_1_QCW.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_48_2_RDg.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_49_2_tBX.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_4_1_sQE.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_50_1_Xcd.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_51_2_fRD.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_52_1_mt8.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_53_1_tYy.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_54_2_Dur.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_55_1_8yu.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_56_1_U9a.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_57_2_fsh.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_58_1_w8e.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_59_1_wye.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_5_1_1v5.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_60_1_SN1.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_61_1_dVp.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_62_1_LsW.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_63_1_Y6q.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_64_1_J4a.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_65_1_RRF.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_66_2_6Bd.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_67_4_kbn.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_68_1_DUU.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_69_2_WXt.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_6_1_QMC.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_70_1_0KW.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_71_2_OKM.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_72_1_CGc.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_73_2_z4Z.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_74_1_Sj0.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_75_1_Mxu.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_76_1_eyH.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_77_1_0iA.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_78_1_oV0.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_79_1_Xvk.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_7_1_5eN.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_80_1_utc.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_81_2_aUE.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_82_1_c9U.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_83_1_P0B.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_84_1_kBo.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_85_1_jJM.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_86_1_ab6.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_87_2_1mj.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_88_1_wQD.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_89_2_aNa.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_8_2_q2q.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_90_2_4FZ.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_91_1_245.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_92_1_aGH.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_93_1_PCC.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_94_1_uOH.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_95_1_6En.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_96_1_BJJ.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_97_1_TnS.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_98_2_sBW.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_99_1_LO4.root',
    'file:/hadoop/cms/store/user/kelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_9_1_Pq2.root',
#     'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-RECO/v1/0000/D80E86FF-7EC7-E111-BB09-003048678DD6.root',
#     'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-RECO/v1/0000/8C41444F-62C7-E111-9FE7-002618943833.root',
#     'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-RECO/v1/0000/64542608-69C7-E111-AFC8-002618943953.root',
] );
# secFiles.extend([
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/FE8F9CCB-4AC7-E111-8490-002618943864.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/F4873C7E-5AC7-E111-BBAF-00248C0BE014.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/D2D451C6-4AC7-E111-929F-002618943865.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/96510AD2-4AC7-E111-B0D3-003048678B0E.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/946E11BF-4AC7-E111-83CA-002618943970.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/7ADD2ADD-4AC7-E111-9FE2-003048678EE2.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/72FE5FDF-4AC7-E111-976D-003048FFCB84.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/623CBBC4-4AC7-E111-8953-00304867BFB0.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/4CA69FBE-4AC7-E111-A5F8-0026189438BA.root',
# 	'root://xrootd.unl.edu//store/relval/CMSSW_5_3_2_patch1-START53_V7A/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG/v1/0000/165D92FA-4AC7-E111-AA80-00261894395F.root',
# ] )
process.source = source

# reduce output
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

# number of events (-1 == all) 
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

# Tell the process what filename to use to save the output
process.Out = cms.OutputModule("PoolOutputModule",
	fileName = cms.untracked.string ("/nfs-7/userdata/rwkelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_1k.root")
# 	fileName = cms.untracked.string ("merged_ntuple.root")
)

# make sure everything is hooked up
process.end = cms.EndPath(process.Out)