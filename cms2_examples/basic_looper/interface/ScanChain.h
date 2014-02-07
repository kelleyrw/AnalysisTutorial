#ifndef SCANCHAIN_H
#define SCANCHAIN_H

#include <string>

// forward declare
class TChain;

// Simple class to hold your analysis data
class CMS2Looper
{
    public:
        // construct:
        CMS2Looper();

        // destroy:
        ~CMS2Looper();

        // methods:
        int ScanChain(TChain& chain, long num_events = -1);

        // members:
        std::string output_filename;
};

#endif
