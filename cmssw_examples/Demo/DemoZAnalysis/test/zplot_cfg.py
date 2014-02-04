import FWCore.ParameterSet.Config as cms

process = cms.Process("ZPLOTS")

# message logger (logorithmic printout)
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.limit = cms.untracked.int32(10)

# options
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:ntuples/dy.root')
)

# load ZTreeAnalyzer
process.load("Demo.DemoZAnalysis.ZTreeAnalyzer_cfi")
process.ZTreeAnalyzer.hist_filename = cms.untracked.string("plots/dy_plots.root")

# paths
process.p = cms.Path(process.ZTreeAnalyzer)
