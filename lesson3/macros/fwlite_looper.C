#include "DataFormats/FWLite/interface/Handle.h"
/* #include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h" */
#include <iostream>

void fwlite_looper()
{
   TFile file("/nfs-7/userdata/edm/53X/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_AODSIM_PU_S10_START53_V7A-v1.root");
   fwlite::Event ev(&file);

   for (ev.toBegin(); !ev.atEnd(); ++ev)
   {
       fwlite::Handle<std::vector<reco::GenParticle> > gps_handle;
       gps_handle.getByLabel(ev,"genParticles");

       // now can access data
       std::cout << "# of gen particles = "<< gps_handle.ptr()->size() << std::endl;
   }
}
