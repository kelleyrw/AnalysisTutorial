/* ------------------------------------------------------------------ * 

Package:         DemoAnalzer
Class:           DemoAnalzer
Description:     Simple EDAnalyzer example
Original Author: Ryan W. Kelley 
Created:         Tue Jan 14 11:30:45 PST 2014

* ------------------------------------------------------------------ */

// system include files
#include <memory>

// ROOT includes
#include "TH1D.h"

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

// class declaration
// ------------------------------------------------------------------ //

class DemoAnalyzer : public edm::EDAnalyzer
{
    public:
        // construct:
        explicit DemoAnalyzer(const edm::ParameterSet&);

        // destroy:
        ~DemoAnalyzer();

        // methods:
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

    private:
        // private methods:
        virtual void beginJob() ;
        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;

        virtual void beginRun(edm::Run const&, edm::EventSetup const&);
        virtual void endRun(edm::Run const&, edm::EventSetup const&);
        virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
        virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

        // member data:
        unsigned int m_min_ntracks;
        TH1D* h_demo;
};

// constructors and destructor
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)
    : m_min_ntracks(iConfig.getUntrackedParameter<unsigned int>("min_ntracks", 0))
    , h_demo(NULL)
{
   //now do what ever initialization is needed
}

DemoAnalyzer::~DemoAnalyzer()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}

// ------------ method called for each event  ------------
void DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    Handle<reco::TrackCollection> tracks;
    iEvent.getByLabel("generalTracks", tracks); 
    h_demo->Fill(tracks->size());
    if (m_min_ntracks <= tracks->size())
    {
        LogInfo("Demo") << "number of tracks " << tracks->size();
    }
}

// ------------ method called once each job just before starting event loop  ------------
void DemoAnalyzer::beginJob()
{
    edm::Service<TFileService> fs;
    h_demo = fs->make<TH1D>("tracks", "# of Tracks/Event;# tracks", 100, 0, 5000);
}

// ------------ method called once each job just after ending the event loop  ------------
void DemoAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void DemoAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void DemoAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void DemoAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void DemoAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
