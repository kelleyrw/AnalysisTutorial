import FWCore.ParameterSet.Config as cms

# CLUSTER REMOVAL
stripTripletStepClusters = cms.EDProducer("TrackClusterRemover",
    clusterLessSolution = cms.bool(True),
    oldClusterRemovalInfo = cms.InputTag("mixedTripletStepClusters"),
    trajectories = cms.InputTag("mixedTripletStepTracks"),
    overrideTrkQuals = cms.InputTag('mixedTripletStep'),
    TrackQuality = cms.string('highPurity'),
    minNumberOfLayersWithMeasBeforeFiltering = cms.int32(0),
    pixelClusters = cms.InputTag("siPixelClusters"),
    stripClusters = cms.InputTag("siStripClusters"),
    Common = cms.PSet(
        maxChi2 = cms.double(9.0)
    )
)
 
# SEEDING LAYERS
stripTripletStepSeedLayers = cms.ESProducer("SeedingLayersESProducer",
    ComponentName = cms.string('stripTripletStepSeedLayers'),
    layerList = cms.vstring(
    #TIB+TOB: all combinations
    'TIB1+TIB2+TOB1','TIB1+TIB2+TOB2','TIB1+TOB1+TOB2','TIB2+TOB1+TOB2',
    #TIB+TID: TIB1+all TID combinations
    'TIB1+TID1_pos+TID2_pos','TIB1+TID1_pos+TID3_pos','TIB1+TID2_pos+TID3_pos',
    'TIB1+TID1_neg+TID2_neg','TIB1+TID1_neg+TID3_neg','TIB1+TID2_neg+TID3_neg',
    #TID: all combinations
    'TID1_pos+TID2_pos+TID3_pos','TID1_neg+TID2_neg+TID3_neg',
    #TID+TEC: all combinations with TID+TEC1 (plus TID3+TEC12)
    'TID1_pos+TID2_pos+TEC1_pos','TID1_pos+TID3_pos+TEC1_pos','TID2_pos+TID3_pos+TEC1_pos','TID3_pos+TEC1_pos+TEC2_pos',
    'TID1_neg+TID2_neg+TEC1_neg','TID1_neg+TID3_neg+TEC1_neg','TID2_neg+TID3_neg+TEC1_neg','TID3_neg+TEC1_neg+TEC2_neg',
    #TEC: all combinations of 3 consecutive planes up to TEC5
    'TEC1_pos+TEC2_pos+TEC3_pos','TEC2_pos+TEC3_pos+TEC4_pos','TEC3_pos+TEC4_pos+TEC5_pos',
    'TEC1_neg+TEC2_neg+TEC3_neg','TEC2_neg+TEC3_neg+TEC4_neg','TEC3_neg+TEC4_neg+TEC5_neg' 
    ),
    TIB = cms.PSet(
         TTRHBuilder = cms.string('WithTrackAngle'),
         matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
         skipClusters = cms.InputTag('stripTripletStepClusters')
    ),
    TOB = cms.PSet(
         TTRHBuilder = cms.string('WithTrackAngle'),
         matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
         skipClusters = cms.InputTag('stripTripletStepClusters')
    ),
    TID = cms.PSet(
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        skipClusters = cms.InputTag('stripTripletStepClusters'),
        useRingSlector = cms.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        minRing = cms.int32(1),
        maxRing = cms.int32(2)
    ),
    TEC = cms.PSet(
        matchedRecHits = cms.InputTag("siStripMatchedRecHits","matchedRecHit"),
        skipClusters = cms.InputTag('stripTripletStepClusters'),
        useRingSlector = cms.bool(True),
        TTRHBuilder = cms.string('WithTrackAngle'),
        minRing = cms.int32(1),
        maxRing = cms.int32(5)
    )

)

# SEEDS
from RecoPixelVertexing.PixelTriplets.PixelTripletLargeTipGenerator_cfi import *
PixelTripletLargeTipGenerator.extraHitRZtolerance = 0.0
PixelTripletLargeTipGenerator.extraHitRPhitolerance = 0.0
import RecoTracker.TkSeedGenerator.GlobalSeedsFromTriplets_cff
stripTripletStepSeeds = RecoTracker.TkSeedGenerator.GlobalSeedsFromTriplets_cff.globalSeedsFromTriplets.clone()
stripTripletStepSeeds.OrderedHitsFactoryPSet.SeedingLayers = 'stripTripletStepSeedLayers'
stripTripletStepSeeds.OrderedHitsFactoryPSet.GeneratorPSet = cms.PSet(PixelTripletLargeTipGenerator)
stripTripletStepSeeds.SeedCreatorPSet.ComponentName = 'SeedFromConsecutiveHitsTripletOnlyCreator'
stripTripletStepSeeds.RegionFactoryPSet.RegionPSet.ptMin = 0.4
stripTripletStepSeeds.RegionFactoryPSet.RegionPSet.originHalfLength = 15.0
stripTripletStepSeeds.RegionFactoryPSet.RegionPSet.originRadius = 2.5
#stripTripletStepSeeds.SeedCreatorPSet.OriginTransverseErrorMultiplier = 1.0 #2.0 this is not used according to kevin
stripTripletStepSeeds.SeedComparitorPSet = cms.PSet(
        ComponentName = cms.string('PixelClusterShapeSeedComparitor'),
        FilterAtHelixStage = cms.bool(True),
        FilterPixelHits = cms.bool(False),
        FilterStripHits = cms.bool(True),
        ClusterShapeHitFilterName = cms.string('ClusterShapeHitFilter')
)

# QUALITY CUTS DURING TRACK BUILDING
import TrackingTools.TrajectoryFiltering.TrajectoryFilterESProducer_cfi
stripTripletStepTrajectoryFilter = TrackingTools.TrajectoryFiltering.TrajectoryFilterESProducer_cfi.trajectoryFilterESProducer.clone(
    ComponentName = 'stripTripletStepTrajectoryFilter',
    filterPset = TrackingTools.TrajectoryFiltering.TrajectoryFilterESProducer_cfi.trajectoryFilterESProducer.filterPset.clone(
    maxLostHits = 0,
    minimumNumberOfHits = 4,
    minPt = 0.1
    )
    )

import TrackingTools.KalmanUpdators.Chi2MeasurementEstimatorESProducer_cfi
stripTripletStepChi2Est = TrackingTools.KalmanUpdators.Chi2MeasurementEstimatorESProducer_cfi.Chi2MeasurementEstimator.clone(
    ComponentName = cms.string('stripTripletStepChi2Est'),
    nSigma = cms.double(3.0),
    MaxChi2 = cms.double(9.0)
)

# TRACK BUILDING
import RecoTracker.CkfPattern.GroupedCkfTrajectoryBuilderESProducer_cfi
stripTripletStepTrajectoryBuilder = RecoTracker.CkfPattern.GroupedCkfTrajectoryBuilderESProducer_cfi.GroupedCkfTrajectoryBuilder.clone(
    ComponentName = 'stripTripletStepTrajectoryBuilder',
    MeasurementTrackerName = '',
    clustersToSkip = cms.InputTag('stripTripletStepClusters'),
    trajectoryFilterName = 'stripTripletStepTrajectoryFilter',
    minNrOfHitsForRebuild = 4,
    maxCand = 2,
    alwaysUseInvalidHits = False,
    estimator = cms.string('stripTripletStepChi2Est'),
    maxDPhiForLooperReconstruction = cms.double(2.0),
    maxPtForLooperReconstruction = cms.double(0.7) 
    )

# MAKING OF TRACK CANDIDATES
import RecoTracker.CkfPattern.CkfTrackCandidates_cfi
stripTripletStepTrackCandidates = RecoTracker.CkfPattern.CkfTrackCandidates_cfi.ckfTrackCandidates.clone(
    src = cms.InputTag('stripTripletStepSeeds'),
    ### these two parameters are relevant only for the CachingSeedCleanerBySharedInput
    numHitsForSeedCleaner = cms.int32(50),
    #onlyPixelHitsForSeedCleaner = cms.bool(True),#if not present set to false
    TrajectoryBuilder = 'stripTripletStepTrajectoryBuilder'
)

from TrackingTools.TrajectoryCleaning.TrajectoryCleanerBySharedHits_cfi import trajectoryCleanerBySharedHits
stripTripletStepTrajectoryCleanerBySharedHits = trajectoryCleanerBySharedHits.clone(
    ComponentName = cms.string('stripTripletStepTrajectoryCleanerBySharedHits'),
    fractionShared = cms.double(0.11),
    allowSharedFirstHit = cms.bool(True)
    )
stripTripletStepTrackCandidates.TrajectoryCleaner = 'stripTripletStepTrajectoryCleanerBySharedHits'


# TRACK FITTING
import RecoTracker.TrackProducer.TrackProducer_cfi
stripTripletStepTracks = RecoTracker.TrackProducer.TrackProducer_cfi.TrackProducer.clone(
    src = 'stripTripletStepTrackCandidates',
    AlgorithmName = cms.string('iter8'),
    Fitter = cms.string('FlexibleKFFittingSmoother')
    )

# TRACK QUALITY
import RecoTracker.FinalTrackSelectors.multiTrackSelector_cfi
stripTripletStepSelector = RecoTracker.FinalTrackSelectors.multiTrackSelector_cfi.multiTrackSelector.clone(
    src='stripTripletStepTracks',
    trackSelectors= cms.VPSet(
        RecoTracker.FinalTrackSelectors.multiTrackSelector_cfi.looseMTS.clone(
            name = 'stripTripletStepLoose',
            chi2n_par = 0.4,
            res_par = ( 0.003, 0.001 ),
            minNumberLayers = 4,
            maxNumberLostLayers = 1,
            minNumber3DLayers = 3,
            d0_par1 = ( 1.2, 4.0 ),
            dz_par1 = ( 1.2, 4.0 ),
            d0_par2 = ( 1.2, 4.0 ),
            dz_par2 = ( 1.2, 4.0 )
            ),
        RecoTracker.FinalTrackSelectors.multiTrackSelector_cfi.tightMTS.clone(
            name = 'stripTripletStepTight',
            preFilterName = 'stripTripletStepLoose',
            chi2n_par = 0.3,
            res_par = ( 0.003, 0.001 ),
            minNumberLayers = 4,
            maxNumberLostLayers = 0,
            minNumber3DLayers = 3,
            d0_par1 = ( 0.9, 4.0 ),
            dz_par1 = ( 0.9, 4.0 ),
            d0_par2 = ( 0.9, 4.0 ),
            dz_par2 = ( 0.9, 4.0 )
            ),
        RecoTracker.FinalTrackSelectors.multiTrackSelector_cfi.highpurityMTS.clone(
            name = 'stripTripletStep',
            preFilterName = 'stripTripletStepTight',
            chi2n_par = 0.2,
            res_par = ( 0.003, 0.001 ),
            minNumberLayers = 4,
            maxNumberLostLayers = 0,
            minNumber3DLayers = 3,
            max_minMissHitOutOrIn = 2,
            max_lostHitFraction = 1.0,
            d0_par1 = ( 0.7, 4.0 ),
            dz_par1 = ( 0.7, 4.0 ),
            d0_par2 = ( 0.7, 4.0 ),
            dz_par2 = ( 0.7, 4.0 )
            ),
        ) #end of vpset
    ) #end of clone
#now add the quality flag to the track itself
import RecoTracker.FinalTrackSelectors.trackListMerger_cfi
stripTripletStepTracksWithQuality = RecoTracker.FinalTrackSelectors.trackListMerger_cfi.trackListMerger.clone(
    TrackProducers = cms.VInputTag(cms.InputTag('stripTripletStepTracks')),
    hasSelector=cms.vint32(1),
    indivShareFrac=cms.vdouble(1.0),
    selectedTrackQuals = cms.VInputTag(cms.InputTag("stripTripletStepSelector","stripTripletStep") ),
    setsToMerge = cms.VPSet( cms.PSet( tLists=cms.vint32(0), pQual=cms.bool(True) )  ),
    copyExtras = True,
    makeReKeyedSeeds = cms.untracked.bool(False)
)


StripTripletStep = cms.Sequence(
    stripTripletStepClusters*
    stripTripletStepSeeds*
    stripTripletStepTrackCandidates*
    stripTripletStepTracks*
    stripTripletStepSelector*
    stripTripletStepTracksWithQuality
)
