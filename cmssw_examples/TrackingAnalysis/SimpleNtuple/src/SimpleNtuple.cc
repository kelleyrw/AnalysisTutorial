/* ------------------------------------------------------------------ * 

Package:         SimpleNtuple
Class:           SimpleNtuple
Description:     Simple EDAnalyzer to make a bare ROOT tree for demostrating loopers 
Original Author: Ryan W. Kelley 
Created:         Fri Nov 22 09:32:25 PST 2013

* ------------------------------------------------------------------ */

// system include files
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "SimTracker/Records/interface/TrackAssociatorRecord.h"
#include "SimTracker/TrackAssociation/interface/TrackAssociatorByHits.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingVertex.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingVertexContainer.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "TrackingTools/TrajectoryState/interface/FreeTrajectoryState.h"
#include "TrackingTools/PatternTools/interface/TSCPBuilderNoMaterial.h"
#include "boost/filesystem.hpp"

// ROOT include files
#include "TFile.h"
#include "TTree.h"
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"

// constants, enums and typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;
typedef std::vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > vecLorentzVectorD;
typedef ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<double> > Point;

// simple struct to hold tree variables 
// ---------------------------------------------------------------------------------- //

struct EventInfo 
{
    // construct:
     EventInfo();

    // methods:
    void Reset();
    void SetBranches(TTree* const tree); 

    // members:

    // event info
    unsigned int run;
    unsigned int ls;
    unsigned int event;

    // reco track info
    std::vector<LorentzVectorD> trks_p4;
    std::vector<double> trks_d0;
    std::vector<double> trks_dz;
    std::vector<double> trks_pterr;
    std::vector<double> trks_d0err;
    std::vector<double> trks_dzerr;
    std::vector<double> trks_chi2;
    std::vector<int> trks_ndof;
    std::vector<int> trks_nlayers;
    std::vector<bool> trks_high_purity;

    // TrakingParticle info
	std::vector<bool> tps_matched;
    std::vector<int> tps_pdgid;
    std::vector<LorentzVectorD> tps_p4;
    std::vector<double> tps_d0;
    std::vector<double> tps_dz;
    std::vector<double> tps_tip;
    std::vector<double> tps_lip;
    std::vector<int> tps_charge;
    std::vector<int> tps_nhits;
};

// construct:
EventInfo::EventInfo()
    : run(999999)
    , ls(999999)
    , event(999999)
{
    const size_t num_reserve = 2500;
    trks_p4.reserve(num_reserve);
    trks_d0.reserve(num_reserve);
    trks_dz.reserve(num_reserve);
    trks_pterr.reserve(num_reserve);
    trks_d0err.reserve(num_reserve);
    trks_dzerr.reserve(num_reserve);
    trks_chi2.reserve(num_reserve);
    trks_ndof.reserve(num_reserve);
    trks_nlayers.reserve(num_reserve);
    trks_high_purity.reserve(num_reserve);
	tps_matched.reserve(num_reserve);
    tps_pdgid.reserve(num_reserve);
    tps_p4.reserve(num_reserve);
    tps_d0.reserve(num_reserve);
    tps_dz.reserve(num_reserve);
    tps_tip.reserve(num_reserve);
    tps_lip.reserve(num_reserve);
    tps_charge.reserve(num_reserve);
    tps_nhits.reserve(num_reserve);
}

// Reset the branches to default values
void EventInfo::Reset()
{
    EventInfo temp;
    std::swap(*this, temp);

    trks_p4.clear();
    trks_d0.clear();
    trks_dz.clear();
    trks_pterr.clear();
    trks_d0err.clear();
    trks_dzerr.clear();
    trks_chi2.clear();
    trks_ndof.clear();
    trks_nlayers.clear();
    trks_high_purity.clear();
	tps_matched.clear();
    tps_pdgid.clear();
    tps_p4.clear();
    tps_d0.clear();
    tps_dz.clear();
    tps_tip.clear();
    tps_lip.clear();
    tps_charge.clear();
    tps_nhits.clear();
}

// set the branches of the tree
void EventInfo::SetBranches(TTree* const tree)
{
    // simple types
    tree->Branch("run"  , &run  );
    tree->Branch("ls"   , &ls   );
    tree->Branch("event", &event);

    // class types
    tree->Branch("trks_p4"          , "vecLorentzVectorD"   , &trks_p4         ); 
    tree->Branch("trks_d0"          , "std::vector<double>" , &trks_d0         ); 
    tree->Branch("trks_dz"          , "std::vector<double>" , &trks_dz         ); 
    tree->Branch("trks_pterr"       , "std::vector<double>" , &trks_pterr      ); 
    tree->Branch("trks_d0err"       , "std::vector<double>" , &trks_d0err      ); 
    tree->Branch("trks_dzerr"       , "std::vector<double>" , &trks_dzerr      ); 
    tree->Branch("trks_chi2"        , "std::vector<double>" , &trks_chi2       ); 
    tree->Branch("trks_ndof"        , "std::vector<int>"    , &trks_ndof       ); 
    tree->Branch("trks_nlayers"     , "std::vector<int>"    , &trks_nlayers    ); 
    tree->Branch("trks_high_purity" , "std::vector<bool>"   , &trks_high_purity); 
    tree->Branch("tps_matched"      , "std::vector<bool>"   , &tps_matched     ); 
    tree->Branch("tps_pdgid"        , "std::vector<int>"    , &tps_pdgid       ); 
    tree->Branch("tps_p4"           , "vecLorentzVectorD"   , &tps_p4          ); 
    tree->Branch("tps_d0"           , "std::vector<double>" , &tps_d0          ); 
    tree->Branch("tps_dz"           , "std::vector<double>" , &tps_dz          ); 
    tree->Branch("tps_tip"          , "std::vector<double>" , &tps_tip         ); 
    tree->Branch("tps_lip"          , "std::vector<double>" , &tps_lip         ); 
    tree->Branch("tps_charge"       , "std::vector<int>"    , &tps_charge      ); 
    tree->Branch("tps_nhits"        , "std::vector<int>"    , &tps_nhits       ); 
}



// analyzer class declaration
// ---------------------------------------------------------------------------------- //

class SimpleNtuple : public edm::EDAnalyzer
{
    public:
        explicit SimpleNtuple(const edm::ParameterSet&);
        ~SimpleNtuple();

        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


    private:
        virtual void beginJob() ;
        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;

        virtual void beginRun(edm::Run const&, edm::EventSetup const&);
        virtual void endRun(edm::Run const&, edm::EventSetup const&);
        virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
        virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

        // ----------member data ---------------------------

        // input parameters
        const std::string m_output_file_name;
        const edm::InputTag m_reco_tracks_label;
        const edm::InputTag m_reco_vertex_label;
        edm::ESHandle<TrackAssociatorBase> assoc_handle;

        // members
        TFile* m_output_file;
        TTree* m_tree;
        EventInfo m_evt;

};

// constructors and destructor
SimpleNtuple::SimpleNtuple(const edm::ParameterSet& iConfig)
    : m_output_file_name(iConfig.getUntrackedParameter<std::string>("output_file_name"))
    , m_reco_tracks_label(iConfig.getUntrackedParameter<edm::InputTag>("reco_tracks_label"))
    , m_reco_vertex_label(iConfig.getUntrackedParameter<edm::InputTag>("reco_vertex_label"))
    , m_output_file(NULL)
    , m_tree(NULL)
    , m_evt()
{
}


SimpleNtuple::~SimpleNtuple()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}

// ------------ method called once each job just before starting event loop  ------------
void SimpleNtuple::beginJob()
{
    // create the directory
    const std::string full_file_name = boost::filesystem::current_path().string() + "/" + m_output_file_name;
    try 
    { 
        const boost::filesystem::path file(full_file_name);
        const boost::filesystem::path directory(file.parent_path());
        if (not boost::filesystem::exists(directory))
        {
            boost::filesystem::create_directories(directory); 
        }
    } 
    catch (boost::filesystem::filesystem_error& e) 
    { 
        std::cerr << e.what() << std::endl; 
    } 

    // initialize ROOT file and tree
    try 
    { 
        // create the ROOT file
        m_output_file = TFile::Open(full_file_name.c_str(), "RECREATE");
        if (not m_output_file or m_output_file->IsZombie())
        {
            throw std::runtime_error("[SimpleNtuple] Error: could not open " + full_file_name); 
        }

        // create the TTree
        m_tree = new TTree("tree", "Simple Tracking Tree");
        m_tree->SetDirectory(m_output_file);
    } 
    catch (std::exception& e) 
    { 
        std::cerr << e.what() << std::endl; 
    } 

    // set the branches
    m_evt.SetBranches(m_tree);
}

// ------------ method called for each event  ------------
void SimpleNtuple::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;
    using namespace std;

    // reset the branches of the TTree
    m_evt.Reset();

    // event info
    m_evt.run   = iEvent.id().run();
    m_evt.event = iEvent.id().event();
    m_evt.ls    = iEvent.luminosityBlock();

    // get the reco::Track collection
    edm::Handle<View<reco::Track> > track_handle;
    iEvent.getByLabel(m_reco_tracks_label, track_handle);

    // Get the reco vertices
    Handle<reco::VertexCollection> vertex_handle;
    iEvent.getByLabel(m_reco_vertex_label, vertex_handle);
    const reco::VertexCollection& trks_vtxs = *vertex_handle;
//     const GlobalPoint trks_vtx = (trks_vtxs.empty() ? GlobalPoint(0,0,0) : GlobalPoint(trks_vtxs.front().x(), trks_vtxs.front().y(), trks_vtxs.front().z())); 

    // Get the tracking vertices
    Handle<TrackingVertexCollection> tracking_vertex_handle;
    iEvent.getByLabel("mergedtruth", "MergedTrackTruth", tracking_vertex_handle);
    const TrackingVertexCollection& tps_vtxs = *tracking_vertex_handle;
    const GlobalPoint tps_vtx = (tps_vtxs.empty() ? GlobalPoint(0,0,0) : GlobalPoint(tps_vtxs.front().position().x(), tps_vtxs.front().position().y(), tps_vtxs.front().position().z())); 

	// Get the TrackingParicles (simulated particle tracks)
	edm::Handle<TrackingParticleCollection>  tracking_particle_handle;
    iEvent.getByLabel("mergedtruth", "MergedTrackTruth", tracking_particle_handle);

    // setup the associator 
    iSetup.get<TrackAssociatorRecord>().get("TrackAssociatorByHits", assoc_handle);
    const TrackAssociatorBase& assoc = *assoc_handle;
    reco::SimToRecoCollection sim_to_reco = assoc.associateSimToReco(track_handle, tracking_particle_handle, &iEvent, &iSetup);

    // Get the magnetic field data from the event (used to calculate the point of closest approach for simTracks)
    edm::ESHandle<MagneticField> magnetic_field_handle;
    iSetup.get<IdealMagneticFieldRecord>().get(magnetic_field_handle);
    const MagneticField& magnetic_field = *magnetic_field_handle;
        
    // get the builder:

    // loop over tracking particles
    for(size_t tp_idx = 0; tp_idx < tracking_particle_handle->size(); ++tp_idx)
    {
        TrackingParticleRef tp_ref(tracking_particle_handle, tp_idx);
        const TrackingParticle& tp = *tp_ref;

        // fill tracking particle variables
        try
        {
            // impact parameter for tracking particle
            const GlobalPoint tp_vtx(tp.vx(), tp.vy(), tp.vz()); 
            const GlobalVector tp_p3(tp.px(), tp.py(), tp.pz()); 
            FreeTrajectoryState fts(tp_vtx, tp_p3, tp.charge(), &magnetic_field);
            TSCPBuilderNoMaterial tscp_builder;
            TrajectoryStateClosestToPoint ts = tscp_builder(fts, tps_vtx);
            double d0 = ts.perigeeParameters().transverseImpactParameter();
            double dz = ts.perigeeParameters().longitudinalImpactParameter();

            m_evt.tps_p4.push_back(LorentzVectorD(tp.px(), tp.py(), tp.pz(), tp.p()));
            m_evt.tps_pdgid.push_back(tp.pdgId());
            m_evt.tps_d0.push_back(d0);
            m_evt.tps_dz.push_back(dz);
            m_evt.tps_tip.push_back(tp.vertex().rho()); // according to CommonTools/RecoAlgos/interface/TrackingParticleSelector.h 
            m_evt.tps_lip.push_back(tp.vertex().z());   // according to CommonTools/RecoAlgos/interface/TrackingParticleSelector.h 
            m_evt.tps_charge.push_back(tp.charge());
            m_evt.tps_nhits.push_back(static_cast<int>(tp.trackPSimHit().size()));
        }
        catch (cms::Exception& e)
        {
            // skip to next tracking particle
            continue;
        }

        if (sim_to_reco.find(tp_ref) != sim_to_reco.end())
        {
            m_evt.tps_matched.push_back(true);

            // get the 'best' associated TP from the reco to sim collection
            const reco::Track& assoc_trk = *sim_to_reco[tp_ref].front().first;

            // fill reco track variables
            m_evt.trks_p4.push_back(LorentzVectorD(assoc_trk.px(), assoc_trk.py(), assoc_trk.pz(), assoc_trk.p()));
            m_evt.trks_d0.push_back(trks_vtxs.empty() ? assoc_trk.d0() : -1.0*assoc_trk.dxy(trks_vtxs.front().position()));
            m_evt.trks_dz.push_back(trks_vtxs.empty() ? assoc_trk.dz() : assoc_trk.dz(trks_vtxs.front().position()));
            m_evt.trks_pterr.push_back(assoc_trk.ptError());
            m_evt.trks_d0err.push_back(assoc_trk.d0Error());
            m_evt.trks_dzerr.push_back(assoc_trk.dzError());
            m_evt.trks_chi2.push_back(assoc_trk.chi2());
            m_evt.trks_ndof.push_back(assoc_trk.ndof());
            m_evt.trks_nlayers.push_back(assoc_trk.hitPattern().trackerLayersWithMeasurement());
            m_evt.trks_high_purity.push_back(assoc_trk.quality(reco::TrackBase::highPurity));
        }
        else
        {
            m_evt.tps_matched.push_back(false);

            // fill reco track variables with bogus values
            m_evt.trks_p4.push_back(LorentzVectorD(-999999,-999999,-999999,-999999));
            m_evt.trks_d0.push_back(-999999);
            m_evt.trks_dz.push_back(-999999);
            m_evt.trks_chi2.push_back(-999999);
            m_evt.trks_ndof.push_back(-999999);
            m_evt.trks_nlayers.push_back(-999999);
            m_evt.trks_high_purity.push_back(false);
        }
    }

    // fill tree
    m_tree->Fill();
}


// ------------ method called once each job just after ending the event loop  ------------
void SimpleNtuple::endJob() 
{
    // save the ROOT tree
    m_output_file->cd();
    m_tree->Write();
    m_output_file->Close();
}

// ------------ method called when starting to processes a run  ------------
void SimpleNtuple::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void SimpleNtuple::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void SimpleNtuple::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void SimpleNtuple::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void SimpleNtuple::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

 //Specify that only 'tracks' is allowed
 //To use, remove the default given above and uncomment below
 //ParameterSetDescription desc;
 //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
 //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(SimpleNtuple);
