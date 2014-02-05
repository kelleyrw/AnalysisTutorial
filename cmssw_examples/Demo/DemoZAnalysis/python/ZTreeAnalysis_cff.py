import FWCore.ParameterSet.Config as cms

# load ZTreeMaker
from Demo.DemoZAnalysis.ZTreeMaker_cfi import *

# load ZTreeFilter
from Demo.DemoZAnalysis.ZTreeFilter_cfi import *

# load ZTreeAnalyzer
from Demo.DemoZAnalysis.ZTreeAnalyzer_cfi import *

# define the full sequence
ZTreeAnalysis = cms.Sequence(ZTreeMaker * ZTreeFilter * ZTreeAnalyzer)
