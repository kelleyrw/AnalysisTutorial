#ifndef SCANCHAIN_H
#define SCANCHAIN_H

#include <string>
#include <map>

// forward declare
class TChain;
class TH1;

// convenenice typedef for a simple histogram container
#include "Packages/HistTools/interface/HistTools.h"

// Simple class to hold your analysis data
class CMS2Looper
{
    public:
        // construct:
        CMS2Looper();
        CMS2Looper(const std::string& filename);

        // destroy:
        ~CMS2Looper();

        // methods:
        void ScanChain(TChain& chain, long num_events = -1);
        void SetRunList(const std::string& runlist);

    private:
        // private methods:
        void BeginJob();
        void Analyze(const long event);
        void EndJob();

        // members:
        std::string output_filename;
        std::string runlist_filename;
        TH1Map hists;
};

#endif
