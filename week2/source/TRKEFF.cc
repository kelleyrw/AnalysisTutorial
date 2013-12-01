
#include "TRKEFF.h"
#include <iostream>

// global object
TRKEFF trkeff_obj;

// implementation of TRKEFF
// ---------------------------------------------------------------------------------------------- //

TRKEFF::TRKEFF()
    : run_handle("run")
    , ls_handle("ls")
    , event_handle("event")
    , trks_p4_handle("trks_p4")
    , trks_d0_handle("trks_d0")
    , trks_dz_handle("trks_dz")
    , trks_pterr_handle("trks_pterr")
    , trks_d0err_handle("trks_d0err")
    , trks_dzerr_handle("trks_dzerr")
    , trks_chi2_handle("trks_chi2")
    , trks_ndof_handle("trks_ndof")
    , trks_nlayers_handle("trks_nlayers")
    , trks_high_purity_handle("trks_high_purity")
    , tps_matched_handle("tps_matched")
    , tps_pdgid_handle("tps_pdgid")
    , tps_p4_handle("tps_p4")
    , tps_d0_handle("tps_d0")
    , tps_dz_handle("tps_dz")
    , tps_charge_handle("tps_charge")
    , tps_nhits_handle("tps_nhits")
{
}

void TRKEFF::Init(TTree& tree)
{
    run_handle.Init(tree);
    ls_handle.Init(tree);
    event_handle.Init(tree);
    trks_p4_handle.Init(tree);
    trks_d0_handle.Init(tree);
    trks_dz_handle.Init(tree);
    trks_pterr_handle.Init(tree);
    trks_d0err_handle.Init(tree);
    trks_dzerr_handle.Init(tree);
    trks_chi2_handle.Init(tree);
    trks_ndof_handle.Init(tree);
    trks_nlayers_handle.Init(tree);
    trks_high_purity_handle.Init(tree);
    tps_matched_handle.Init(tree);
    tps_pdgid_handle.Init(tree);
    tps_p4_handle.Init(tree);
    tps_d0_handle.Init(tree);
    tps_dz_handle.Init(tree);
    tps_charge_handle.Init(tree);
    tps_nhits_handle.Init(tree);

}

void TRKEFF::Init(TTree* const tree)
{
    Init(*tree);
}

void TRKEFF::GetEntry(const unsigned int entry)
{
    run_handle.GetEntry(entry);
    ls_handle.GetEntry(entry);
    event_handle.GetEntry(entry);
    trks_p4_handle.GetEntry(entry);
    trks_d0_handle.GetEntry(entry);
    trks_dz_handle.GetEntry(entry);
    trks_pterr_handle.GetEntry(entry);
    trks_d0err_handle.GetEntry(entry);
    trks_dzerr_handle.GetEntry(entry);
    trks_chi2_handle.GetEntry(entry);
    trks_ndof_handle.GetEntry(entry);
    trks_nlayers_handle.GetEntry(entry);
    trks_high_purity_handle.GetEntry(entry);
    tps_matched_handle.GetEntry(entry);
    tps_pdgid_handle.GetEntry(entry);
    tps_p4_handle.GetEntry(entry);
    tps_d0_handle.GetEntry(entry);
    tps_dz_handle.GetEntry(entry);
    tps_charge_handle.GetEntry(entry);
    tps_nhits_handle.GetEntry(entry);

}

void TRKEFF::LoadAllBranches()
{
    run_handle.Load();
    ls_handle.Load();
    event_handle.Load();
    trks_p4_handle.Load();
    trks_d0_handle.Load();
    trks_dz_handle.Load();
    trks_pterr_handle.Load();
    trks_d0err_handle.Load();
    trks_dzerr_handle.Load();
    trks_chi2_handle.Load();
    trks_ndof_handle.Load();
    trks_nlayers_handle.Load();
    trks_high_purity_handle.Load();
    tps_matched_handle.Load();
    tps_pdgid_handle.Load();
    tps_p4_handle.Load();
    tps_d0_handle.Load();
    tps_dz_handle.Load();
    tps_charge_handle.Load();
    tps_nhits_handle.Load();

}

// branch accessor methods:
const unsigned int& TRKEFF::run() {return run_handle.get();}
const unsigned int& TRKEFF::ls() {return ls_handle.get();}
const unsigned int& TRKEFF::event() {return event_handle.get();}
const std::vector<LorentzVectorD >& TRKEFF::trks_p4() {return trks_p4_handle.get();}
const std::vector<double>& TRKEFF::trks_d0() {return trks_d0_handle.get();}
const std::vector<double>& TRKEFF::trks_dz() {return trks_dz_handle.get();}
const std::vector<double>& TRKEFF::trks_pterr() {return trks_pterr_handle.get();}
const std::vector<double>& TRKEFF::trks_d0err() {return trks_d0err_handle.get();}
const std::vector<double>& TRKEFF::trks_dzerr() {return trks_dzerr_handle.get();}
const std::vector<double>& TRKEFF::trks_chi2() {return trks_chi2_handle.get();}
const std::vector<int>& TRKEFF::trks_ndof() {return trks_ndof_handle.get();}
const std::vector<int>& TRKEFF::trks_nlayers() {return trks_nlayers_handle.get();}
const std::vector<bool>& TRKEFF::trks_high_purity() {return trks_high_purity_handle.get();}
const std::vector<bool>& TRKEFF::tps_matched() {return tps_matched_handle.get();}
const std::vector<int>& TRKEFF::tps_pdgid() {return tps_pdgid_handle.get();}
const std::vector<LorentzVectorD >& TRKEFF::tps_p4() {return tps_p4_handle.get();}
const std::vector<double>& TRKEFF::tps_d0() {return tps_d0_handle.get();}
const std::vector<double>& TRKEFF::tps_dz() {return tps_dz_handle.get();}
const std::vector<int>& TRKEFF::tps_charge() {return tps_charge_handle.get();}
const std::vector<int>& TRKEFF::tps_nhits() {return tps_nhits_handle.get();}




/*static*/ void TRKEFF::progress(const int nEventsTotal, const int nEventsChain)
{
    int period = 1000;
    if (nEventsTotal%1000 == 0)
    {
        // xterm magic from L. Vacavant and A. Cerri
        if (isatty(1))
        {
            if ((nEventsChain - nEventsTotal) > period)
            {
                float frac = (float)nEventsTotal/(nEventsChain*0.01);
                printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%\033[0m\033[32m <---\033[0m\015", frac);
                fflush(stdout);
            }
            else
            {
                printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%\033[0m\033[32m <---\033[0m\015", 100.0);
                std::cout << std::endl;
            }
        }
    }
}
namespace trkeff
{

    const unsigned int& run() {return trkeff_obj.run();}
    const unsigned int& ls() {return trkeff_obj.ls();}
    const unsigned int& event() {return trkeff_obj.event();}
    const std::vector<LorentzVectorD >& trks_p4() {return trkeff_obj.trks_p4();}
    const std::vector<double>& trks_d0() {return trkeff_obj.trks_d0();}
    const std::vector<double>& trks_dz() {return trkeff_obj.trks_dz();}
    const std::vector<double>& trks_pterr() {return trkeff_obj.trks_pterr();}
    const std::vector<double>& trks_d0err() {return trkeff_obj.trks_d0err();}
    const std::vector<double>& trks_dzerr() {return trkeff_obj.trks_dzerr();}
    const std::vector<double>& trks_chi2() {return trkeff_obj.trks_chi2();}
    const std::vector<int>& trks_ndof() {return trkeff_obj.trks_ndof();}
    const std::vector<int>& trks_nlayers() {return trkeff_obj.trks_nlayers();}
    const std::vector<bool>& trks_high_purity() {return trkeff_obj.trks_high_purity();}
    const std::vector<bool>& tps_matched() {return trkeff_obj.tps_matched();}
    const std::vector<int>& tps_pdgid() {return trkeff_obj.tps_pdgid();}
    const std::vector<LorentzVectorD >& tps_p4() {return trkeff_obj.tps_p4();}
    const std::vector<double>& tps_d0() {return trkeff_obj.tps_d0();}
    const std::vector<double>& tps_dz() {return trkeff_obj.tps_dz();}
    const std::vector<int>& tps_charge() {return trkeff_obj.tps_charge();}
    const std::vector<int>& tps_nhits() {return trkeff_obj.tps_nhits();}

} // namespace trkeff
