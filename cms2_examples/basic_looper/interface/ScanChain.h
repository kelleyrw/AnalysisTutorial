#ifndef SCANCHAIN_H
#define SCANCHAIN_H

#include <string>
<<<<<<< HEAD
#include <map>
=======
>>>>>>> 7decbc79fda0a5dcdb5e11993ac17025de2ab2ec

// forward declare
class TChain;
class TH1;

// convenenice typedef for a simple histogram container
typedef std::map<std::string, TH1*> TH1Map;

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
        int ScanChain(TChain& chain, long num_events = -1);

    private:
        // private methods:
        void BeginJob();
//         void Analyze();
        void EndJob();

        // members:
        std::string outfilename;
        TH1Map hists;
};

#endif
