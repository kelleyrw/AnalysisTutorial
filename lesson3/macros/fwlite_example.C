{
    TChain e("Events");
    e.Add("/nfs-7/userdata/edm/53X/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_AODSIM_PU_S10_START53_V7A-v1.root");

    // list the branches
    e.GetListOfBranches()->ls();

    // draw a plot
    e.SetAlias("trks", "recoTracks_generalTracks__RECO.obj"    );
    e.SetAlias("gps" , "recoGenParticles_genParticles__SIM.obj");
    e.SetAlias("trkExtras","recoTrackExtras_generalTracks__RECO.obj");

    // plot the Z mass
    // https://cmssdt.cern.ch/SDT/doxygen/CMSSW_5_3_2_patch4/doc/html/d9/d47/classreco_1_1GenParticle-members.html
    e.Draw("gps.mass()>>(100,0,200)", "gps.pdgId()==23");

    // scan the event numbers
    // https://cmssdt.cern.ch/SDT/doxygen/CMSSW_5_3_2_patch4/doc/html/d1/dc5/classedm_1_1EventAuxiliary.html 
    // In CMS one Luminosity Block is a time interval whose length is equal to 2^18 orbits, about 23,3 seconds and the Luminosity Block counter is reset at the beginning of each run
    e.SetScanField(0);
    e.Scan("EventAuxiliary.run():EventAuxiliary.luminosityBlock():EventAuxiliary.event()");
    e.Scan("EventAuxiliary.run():EventAuxiliary.luminosityBlock():EventAuxiliary.event()", "", "colsize=20 precision=12", 10);

    // number of hits per track 
    // https://cmssdt.cern.ch/SDT/doxygen/CMSSW_5_3_2_patch4/doc/html/dd/d42/classreco_1_1TrackExtra.html
    e.Draw("trkExtras.recHitsSize()");
}
