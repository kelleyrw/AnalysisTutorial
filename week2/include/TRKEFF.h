
#ifndef TRKEFF_H
#define TRKEFF_H

#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include "TString.h"
#include <vector> 
#include <string>          

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;

// Handle Classes to handle branch loading 
// ------------------------------------------------------------------------------------------------- //

namespace trkeff
{
    struct BranchType
    {
        enum value_type
        {
            CLASS,
            BUILTIN,
            NOT_SET,

            static_size
        };
    };

    template <typename T>
    class Handle
    {
        public:
            
            // construct: 
            explicit Handle(const std::string& branch_name);

            // destroy:
            virtual ~Handle() {}

            // set the branch's entry 
            void GetEntry(const unsigned int entry);

            // initialize the handle's branches
            void Init(TTree& tree);

            // is the branch already loaded
            bool IsLoaded() const;

            // load the branch
            void Load();

            // clear the branch
            void Clear();

            // get the value
            const T& get();

        protected:

            // set the branch type private member (based on the TBranch) 
            void SetBranchType(const std::string& branch_class);

            // members:
            bool                   m_is_loaded;
            unsigned int           m_entry;
            std::string            m_branch_name;
            T*                     m_object_ptr;
            T                      m_object;
            BranchType::value_type m_branch_type;

            // the TTree owns the branch (this is only a reference pointer)
            TBranch*     m_branch;

        private:
            // no default constructor
            Handle() {}
    };

    template <typename T>
    /*explicit*/ Handle<T>::Handle(const std::string& branch_name)
        : m_is_loaded(false)
        , m_entry(0)
        , m_branch_name(branch_name)
        , m_object_ptr(NULL)
        , m_object()
        , m_branch_type(BranchType::NOT_SET)
        , m_branch(NULL)
    {
    }

    template <typename T>
    void Handle<T>::GetEntry(const unsigned int entry)
    {
        Clear();
        m_entry = entry;
    }

    template <typename T>
    bool Handle<T>::IsLoaded() const
    {
        return m_is_loaded;
    }
   
    template <typename T>
    void Handle<T>::Clear()
    {
        m_is_loaded = false;
    }

    template <typename T>
    void Handle<T>::Load()
    {
        if (m_branch)
        {
            m_branch->GetEntry(m_entry);
            m_is_loaded = true;
        }
        else
        {
            throw std::runtime_error("[TRKEFF] ERROR: branch " + m_branch_name + " does not exist!"); 
        }
    }

    template <typename T>
    void Handle<T>::SetBranchType(const std::string& branch_class)
    {
        if (branch_class.find("edm::Wrapper")!=std::string::npos)
        {
            m_branch_type = BranchType::BUILTIN;
        }
        else if 
        (
            branch_class.find("/B")!=std::string::npos || // char
            branch_class.find("/b")!=std::string::npos || // unsigned char
            branch_class.find("/S")!=std::string::npos || // short
            branch_class.find("/s")!=std::string::npos || // unsigned short
            branch_class.find("/I")!=std::string::npos || // int
            branch_class.find("/i")!=std::string::npos || // unsigned int
            branch_class.find("/F")!=std::string::npos || // float
            branch_class.find("/D")!=std::string::npos || // double
            branch_class.find("/L")!=std::string::npos || // long
            branch_class.find("/l")!=std::string::npos || // unsigned long
            branch_class.find("/O")!=std::string::npos    // bool
        )
        {
            m_branch_type = BranchType::BUILTIN;
        }
        else
        {
            m_branch_type = BranchType::CLASS;
        }
    }

    template <typename T>
    void Handle<T>::Init(TTree& tree)
    {
        // no protection if the branch pointer is NULL
        // (so you can use this if the branch doesn't exist
        // as long as you don't call it).
        m_branch = tree.GetBranch(m_branch_name.c_str());
        if (m_branch)
        {
            if (m_branch_type == BranchType::NOT_SET)
            {
                std::string branch_class = m_branch->GetClassName();
                if (branch_class.empty())  // built in types don't have a ClassName --> using title
                {
                    branch_class = m_branch->GetTitle();
                }
                SetBranchType(branch_class);
            }
            switch (m_branch_type)
            {
                case BranchType::CLASS  : m_branch->SetAddress(&m_object_ptr); break;
                case BranchType::BUILTIN: m_branch->SetAddress(&m_object)    ; break;
                default: throw std::runtime_error("[TRKEFF] ERROR: branch type not supported!"); 
            }
        }
    }

    template <typename T>
    const T& Handle<T>::get()
    {
        if (not IsLoaded())
        {
            Load();
        }
        switch (m_branch_type)
        {
            case BranchType::CLASS  : return *m_object_ptr;
            case BranchType::BUILTIN: return m_object;
            default: throw std::runtime_error("[TRKEFF] ERROR: branch type not supported!"); 
        }
    }
    
} // namespace trkeff


// TRKEFF to handle all the branches for the TTree 
// ------------------------------------------------------------------------------------------------- //

class TRKEFF
{
    public:
        TRKEFF();

        // methods:
        void Init(TTree* const tree);
        void Init(TTree& tree);
        void GetEntry(const unsigned int entry);
		void LoadAllBranches();


       	// static methods:
       	static void progress(const int nEventsTotal, const int nEventsChain);

        // branch accessors
        const unsigned int& run();
        const unsigned int& ls();
        const unsigned int& event();
        const std::vector<LorentzVectorD >& trks_p4();
        const std::vector<double>& trks_d0();
        const std::vector<double>& trks_dz();
        const std::vector<double>& trks_pterr();
        const std::vector<double>& trks_d0err();
        const std::vector<double>& trks_dzerr();
        const std::vector<double>& trks_chi2();
        const std::vector<int>& trks_ndof();
        const std::vector<int>& trks_nlayers();
        const std::vector<bool>& trks_high_purity();
        const std::vector<bool>& tps_matched();
        const std::vector<int>& tps_pdgid();
        const std::vector<LorentzVectorD >& tps_p4();
        const std::vector<double>& tps_d0();
        const std::vector<double>& tps_dz();
        const std::vector<int>& tps_charge();
        const std::vector<int>& tps_nhits();

    private:
    
        // handles
        trkeff::Handle< unsigned int > run_handle;
        trkeff::Handle< unsigned int > ls_handle;
        trkeff::Handle< unsigned int > event_handle;
        trkeff::Handle< std::vector<LorentzVectorD > > trks_p4_handle;
        trkeff::Handle< std::vector<double> > trks_d0_handle;
        trkeff::Handle< std::vector<double> > trks_dz_handle;
        trkeff::Handle< std::vector<double> > trks_pterr_handle;
        trkeff::Handle< std::vector<double> > trks_d0err_handle;
        trkeff::Handle< std::vector<double> > trks_dzerr_handle;
        trkeff::Handle< std::vector<double> > trks_chi2_handle;
        trkeff::Handle< std::vector<int> > trks_ndof_handle;
        trkeff::Handle< std::vector<int> > trks_nlayers_handle;
        trkeff::Handle< std::vector<bool> > trks_high_purity_handle;
        trkeff::Handle< std::vector<bool> > tps_matched_handle;
        trkeff::Handle< std::vector<int> > tps_pdgid_handle;
        trkeff::Handle< std::vector<LorentzVectorD > > tps_p4_handle;
        trkeff::Handle< std::vector<double> > tps_d0_handle;
        trkeff::Handle< std::vector<double> > tps_dz_handle;
        trkeff::Handle< std::vector<int> > tps_charge_handle;
        trkeff::Handle< std::vector<int> > tps_nhits_handle;

};


// public interface 
// ------------------------------------------------------------------------------------------------- //

namespace trkeff
{

    const unsigned int& run();
    const unsigned int& ls();
    const unsigned int& event();
    const std::vector<LorentzVectorD >& trks_p4();
    const std::vector<double>& trks_d0();
    const std::vector<double>& trks_dz();
    const std::vector<double>& trks_pterr();
    const std::vector<double>& trks_d0err();
    const std::vector<double>& trks_dzerr();
    const std::vector<double>& trks_chi2();
    const std::vector<int>& trks_ndof();
    const std::vector<int>& trks_nlayers();
    const std::vector<bool>& trks_high_purity();
    const std::vector<bool>& tps_matched();
    const std::vector<int>& tps_pdgid();
    const std::vector<LorentzVectorD >& tps_p4();
    const std::vector<double>& tps_d0();
    const std::vector<double>& tps_dz();
    const std::vector<int>& tps_charge();
    const std::vector<int>& tps_nhits();

} // namespace trkeff

#ifndef __CINT__
extern TRKEFF trkeff_obj;
#endif


#endif // TRKEFF_H
