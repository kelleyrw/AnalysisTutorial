{
    float max_pt    = 1000;
    float min_pt    = 0.1;
    size_t nbins_pt = 40;
    double step = (log10(max_pt)-log10(min_pt))/float(nbins_pt);
    cout << "const pt_bins[] = {" << min_pt << ",";
    for (size_t i = 1; i < nbins_pt; i++)
    {
        cout << Form("%1.3f", pow(10, log10(min_pt) + i*step)) << ", ";    
    }
    cout << max_pt << "};\n" << endl;

/*     pTintervalsv.push_back(minPt); */
/*     for (int k=1;k<nintPt+1;k++) { */
/*         double d=0; */
/*         if(useLogPt)d=pow(10,minPt+k*stepPt); */
/*         else d=minPt+k*stepPt; */
/*         pTintervalsv.push_back(d); */
/*         totSIMvpT.push_back(0); */
/*         totASSvpT.push_back(0); */
/*         totASS2vpT.push_back(0); */
/*         totRECvpT.push_back(0); */
/*         totloopvpT.push_back(0); */
/*         totmisidvpT.push_back(0); */
/*     } */
/*     pTintervals.push_back(pTintervalsv); */
/*     totSIMpT.push_back(totSIMvpT); */
/*     totASSpT.push_back(totASSvpT); */
/*     totASS2pT.push_back(totASS2vpT); */
/*     totRECpT.push_back(totRECvpT); */
/*     totlooppT.push_back(totloopvpT); */
/*     totmisidpT.push_back(totmisidvpT); */

}
