#!/bin/bash

lumi=0.082
nevts=-1
json="json/Merged_190456-208686_8TeV_PromptReReco_Collisions12_goodruns.txt"
verbose=0

function run_create_baby
{
	local sample=$1
	local input=$2
	local output="babies/${sample}.root"
	local log="logs/${sample}.log"
	cmd="root -b -q -l \"macros/create_baby_osx.C(\\\"$sample\\\", \\\"$input\\\", \\\"$output\\\", \\\"$json\\\", $nevts, $lumi, $verbose)\""
	mkdir -p babies 
	mkdir -p logs 
	echo $cmd
	eval $cmd >& $log & 
}

run_create_baby "data"     "/nfs-7/userdata/rwkelley/cms2/SingleMu_Run2012A-recover-06Aug2012-v1_AOD.root,/nfs-7/userdata/rwkelley/cms2/SingleElectron_Run2012A-recover-06Aug2012-v1_AOD.root"
run_create_baby "dyll"     "/nfs-7/userdata/rwkelley/cms2/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "wjets"    "/nfs-7/userdata/rwkelley/cms2/WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "ttdil"    "/nfs-7/userdata/rwkelley/cms2/TTJets_FullLeptMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v2.root"
run_create_baby "ttslq"    "/nfs-7/userdata/rwkelley/cms2/TTJets_SemiLeptMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A_ext-v1.root"
run_create_baby "tthad"    "/nfs-7/userdata/rwkelley/cms2/TTJets_HadronicMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A_ext-v1.root"
run_create_baby "qcdmu15"  "/nfs-7/userdata/rwkelley/cms2/QCD_Pt_20_MuEnrichedPt_15_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v3.root"
run_create_baby "ww2l2nu"  "/nfs-7/userdata/rwkelley/cms2/WWJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "wz2l2q"   "/nfs-7/userdata/rwkelley/cms2/WZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "wz3lnu"   "/nfs-7/userdata/rwkelley/cms2/WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "zz2l2nu"  "/nfs-7/userdata/rwkelley/cms2/ZZJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v3.root"
run_create_baby "zz2l2q"   "/nfs-7/userdata/rwkelley/cms2/ZZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
run_create_baby "zz4l"     "/nfs-7/userdata/rwkelley/cms2/ZZJetsTo4L_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1.root"
