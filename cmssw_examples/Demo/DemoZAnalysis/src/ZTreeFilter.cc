/* ------------------------------------------------------------------ * 

Package:         DemoZAnalysis
Class:           ZTreeFilter
Description:     Simple EDFilter
Original Author: Ryan W. Kelley 
Created:         Tue Jan 14 11:30:45 PST 2014

* ------------------------------------------------------------------ */

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// class declaration
// ------------------------------------------------------------------ //

class ZTreeFilter : public edm::EDFilter
{
    public:
        // construct:
        explicit ZTreeFilter(const edm::ParameterSet&);

        // destroy:
        ~ZTreeFilter();

        // public methods:
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

    private:
        // private methods:
        virtual void beginJob() ;
        virtual bool filter(edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;

        virtual bool beginRun(edm::Run&, edm::EventSetup const&);
        virtual bool endRun(edm::Run&, edm::EventSetup const&);
        virtual bool beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
        virtual bool endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

        // member data:
        edm::InputTag m_l1pdgid_label;
        edm::InputTag m_l2pdgid_label;
};

// constructors and destructor
ZTreeFilter::ZTreeFilter(const edm::ParameterSet& iConfig)
    : m_l1pdgid_label(iConfig.getUntrackedParameter<edm::InputTag>("l1pdgid_label", edm::InputTag("ZTreeMaker", "l1pdgid")))
    , m_l2pdgid_label(iConfig.getUntrackedParameter<edm::InputTag>("l2pdgid_label", edm::InputTag("ZTreeMaker", "l2pdgid")))
{
   //now do what ever initialization is needed
}


ZTreeFilter::~ZTreeFilter()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}


// ------------ method called on each new Event  ------------
bool ZTreeFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    edm::Handle<int> l1_pdgid_handle;
    iEvent.getByLabel(m_l1pdgid_label, l1_pdgid_handle); 
    const int l1_pdgid = *l1_pdgid_handle;

    edm::Handle<int> l2_pdgid_handle;
    iEvent.getByLabel(m_l2pdgid_label, l2_pdgid_handle); 
    const int l2_pdgid = *l2_pdgid_handle;

    const bool is_tautau = (abs(l1_pdgid)==15 && abs(l2_pdgid)==15);
    return (not is_tautau);
}

// ------------ method called once each job just before starting event loop  ------------
void ZTreeFilter::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void ZTreeFilter::endJob()
{
}

// ------------ method called when starting to processes a run  ------------
bool ZTreeFilter::beginRun(edm::Run&, edm::EventSetup const&)
{ 
    return true;
}

// ------------ method called when ending the processing of a run  ------------
bool ZTreeFilter::endRun(edm::Run&, edm::EventSetup const&)
{
    return true;
}

// ------------ method called when starting to processes a luminosity block  ------------
bool ZTreeFilter::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
    return true;
}

// ------------ method called when ending the processing of a luminosity block  ------------
bool ZTreeFilter::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
    return true;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void ZTreeFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(ZTreeFilter);
