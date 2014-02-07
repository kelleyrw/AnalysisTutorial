import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# message logger (logorithmic printout)
process.load("FWCore.MessageLogger.MessageLogger_cfi")
# process.MessageLogger.cerr.FwkReport.limit = cms.untracked.int32(10)

# input source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10))
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/nfs-7/userdata/rwkelley/cms2/ttjets_with_status1.root'
    )
)

# output file name
process.TFileService = cms.Service("TFileService",
	fileName = cms.string('plots/cms2testanalyzer.root')
)

# my demo analyzer
process.load("CMS2.CMS2Test.CMS2TestAnalyzer_cfi")
process.demo.minTracks=1000

# path
process.p = cms.Path(process.demo)

