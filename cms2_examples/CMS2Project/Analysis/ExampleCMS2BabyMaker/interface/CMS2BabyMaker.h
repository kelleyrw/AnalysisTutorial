#ifndef CMS2LOOPER_H
#define CMS2LOOPER_H

#include <string>
#include <map>
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include "Math/LorentzVector.h"

// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

// class that contains the branch variables
class TreeInfo
{
    public:

        // constructors and destructor
        TreeInfo();

        void Reset();
        void SetBranches(TTree& tree);

        // event level info
        int run;
        int ls;
        int evt;
        std::string sample;
        std::string dataset;
        std::string filename;
        bool is_real_data;
        double scale1fb;
        double scale1fb_cms2;
        double lumi;
        double xsec;
        double nevts_aod;
        double nevts_cms2;
        double nevts_file;
        double kfactor;
        double filt_eff;

        // Gen hypothesis specific info 
        bool is_gen_z;
        bool is_gen_ee;
        bool is_gen_mm;
        LorentzVector gen_p4;
        LorentzVector gen_lep1_p4;
        int gen_lep1_id;
        int gen_lep1_charge;
        LorentzVector gen_lep2_p4;
        int gen_lep2_id;
        int gen_lep2_charge;
};

// Simple class to hold your analysis meta-data
class CMS2BabyMaker
{
    public:
        // construct:
        CMS2BabyMaker
        (
            const std::string& sample_name, 
            const std::string& output_filename,
            const std::string& runlist_filename = "",
            const double lumi = 1.0,
            const double nevts_corr = 1.0,
            const bool verbose = false
        );

        // methods:
        void ScanChain(TChain& chain, const long num_events = -1);

    private:
        // private methods:
        void BeginJob();
        void Analyze(const long event, const std::string& current_filename);
        void EndJob();

        // members:
        std::string m_sample_name;
        std::string m_output_filename;
        std::string m_runlist_filename;
        double m_nevts_corr;
        double m_lumi;
        bool m_verbose;
        TreeInfo m_info;
        TFile& m_file;
        TTree& m_tree;
};

#endif
