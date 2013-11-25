import FWCore.ParameterSet.Config as cms

process = cms.Process("SimpleNtuple")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/nfs-7/userdata/rwkelley/edm/TTbar_Tauola_8TeV_cfi_py_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_VALIDATION_1k.root')
)

# load the associator
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("SimTracker.TrackAssociation.TrackAssociatorByHits_cfi")

# for the d0/dz calculation
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START53_V7A::All'

process.simple = cms.EDAnalyzer('SimpleNtuple'
    , output_file_name = cms.untracked.string('output/tracking_ntuple.root')
    , reco_tracks_label = cms.untracked.InputTag('generalTracks')
    , primary_vertex_label = cms.untracked.InputTag("offlinePrimaryVertices")
)


process.p = cms.Path(process.simple)
