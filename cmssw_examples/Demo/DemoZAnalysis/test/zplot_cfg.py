import FWCore.ParameterSet.Config as cms

process = cms.Process("ZPLOTS")

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring('file:ntuples/dy.root')
)

# load ZTreeAnalyzer
process.load("Demo.DemoZAnalysis.ZTreeAnalyzer_cfi")
process.ZTreeAnalyzer.hist_filename = cms.untracked.string("plots/dy_plots.root")

# paths
process.p = cms.Path(process.ZTreeAnalyzer)

# message logger (logorithmic printout)
# process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger = cms.Service("MessageLogger",
     default = cms.untracked.PSet(limit = cms.untracked.int32(10))
)
