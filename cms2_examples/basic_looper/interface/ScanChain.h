#include <string>
#include <map>

#include "TH1.h"

#ifndef SCANCHAIN_H
#define SCANCHAIN_H

// forward declare
class TChain;

// Simple class to hold your analysis data
class CMS2Looper
{
    public:
        // construct:
        CMS2Looper();
        CMS2Looper( std::string filename );

        // destroy:
        ~CMS2Looper();

        // methods:
        int ScanChain(TChain& chain, long num_events = -1);

    private:

        void book_hists();

        std::string outfilename;
        std::map < std::string, TH1F* > hists;


};

#endif
