/* ------------------------------------------------------------------ * 

Package:         CMS2TestAnalzer
Class:           CMS2TestAnalzer
Description:     Simple EDAnalyzer to test CMS2 
Original Author: Ryan W. Kelley 
Created:         Tue Feb 05 2014

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
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "CMS2/NtupleMacrosHeader/interface/CMS2.h"
#include "CMS2/NtupleMacrosCore/interface/eventSelections.h"

// class declaration
// ------------------------------------------------------------------ //

class CMS2TestAnalyzer : public edm::EDAnalyzer
{
    public:
        // construct:
        explicit CMS2TestAnalyzer(const edm::ParameterSet&);

        // destroy:
        ~CMS2TestAnalyzer();

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
        const bool m_verbose;
        TH1D* h_demo;
};

// constructors and destructor
CMS2TestAnalyzer::CMS2TestAnalyzer(const edm::ParameterSet& iConfig)
    : m_min_ntracks(iConfig.getUntrackedParameter<unsigned int>("min_ntracks", 0))
    , m_verbose(iConfig.getUntrackedParameter<unsigned int>("verbose", true))
    , h_demo(NULL)
{
   //now do what ever initialization is needed
}

CMS2TestAnalyzer::~CMS2TestAnalyzer()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}

// ------------ method called for each event  ------------
void CMS2TestAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    // set the event -- MANDATORY
    cms2.SetEvent(iEvent);

    // require standard cleaning 
    if (!cleaning_standardNovember2011()) 
    {
        if (m_verbose) {std::cout << "fails November2011 cleaning requirement" << std::endl;}
        return;
    }
    std::cout << "number of tracks " << tas::trks_trk_p4().size() << std::endl;
}

// ------------ method called once each job just before starting event loop  ------------
void CMS2TestAnalyzer::beginJob()
{
    edm::Service<TFileService> fs;
    h_demo = fs->make<TH1D>("tracks", "# of Tracks/Event;# tracks", 100, 0, 5000);
}

// ------------ method called once each job just after ending the event loop  ------------
void CMS2TestAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void CMS2TestAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void CMS2TestAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void CMS2TestAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void CMS2TestAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void CMS2TestAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(CMS2TestAnalyzer);

