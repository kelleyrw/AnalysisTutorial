#include "Packages/HistTools/interface/HistTools.h"
#include "TFile.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include <stdexcept>
#include <iostream>
#include <string>

typedef std::map<std::string, TH1*> TH1Map;

// Add a histogram to the container
void AddHist(TH1Map& hist_map, TH1* const hist, const bool overwrite)
{
    using namespace std;

    // do we already have the histogram?
    string name = hist->GetName();
    const bool hist_name_used = hist_map.end() != hist_map.find(name);
    if (hist_name_used)
    {
        try
        {
            bool same_pointer = (hist == hist_map.at(name));
            if (overwrite && !same_pointer)
            {
                cout << "[AddHist] Warning: '" << name << "' already exists.  Overwriting!" << endl;
            }
            else if (overwrite && same_pointer)
            {
                cout << "[AddHist] Warning: '" << name << "' already exists.  Leaving it alone!" << endl;
                return;
            }
            else
            {
                cout << "[AddHist] Warning: '" << name << "' already exists.  Skipping!" << endl;
                return;
            }
        }
        catch(exception& e)
        {
            cout << "[AddHist] Error " << e.what() << endl;
        }
    }

    // I want to be in charge of deleting
    hist->SetDirectory(0);
    hist_map.insert(std::make_pair(name, hist));
    return;
}


// save all the hists to a file
void SaveHists(const TH1Map& hist_map, const std::string& filename,  const std::string& option)
{
    TFile file(filename.c_str(), option.c_str());
    if (file.IsZombie()) 
    {
        throw std::runtime_error("[SaveHists] Error -- file cannot be open!");
    }
    for (TH1Map::const_iterator hm_iter = hist_map.begin(); hm_iter != hist_map.end(); hm_iter++)
    {
        TH1* hist_temp = hm_iter->second; 
        hist_temp->Write();
    }
    file.Close();
}

// print all the hists
void PrintHists(const TH1Map& hist_map, const std::string& pathname,  const std::string& suffix)
{
    TCanvas temp_canvas("c1", "c1");
    gSystem->Exec(Form("mkdir -p %s", pathname.c_str()));
    for (TH1Map::const_iterator hm_iter = hist_map.begin(); hm_iter != hist_map.end(); hm_iter++)
    {
        TH1* temp_hist = hm_iter->second; 
        temp_hist->Draw();
        temp_canvas.Print(Form("%s/%s.%s", pathname.c_str(), temp_hist->GetName(), suffix.c_str()));
    }
}

// clear and delete the histogram pointers in the map
void ClearHists(TH1Map& hist_map)
{
    for (TH1Map::const_iterator hm_iter = hist_map.begin(); hm_iter != hist_map.end(); hm_iter++)
    {
        TH1* hist_temp = hm_iter->second; 
        hist_temp->SetDirectory(NULL);
        delete hist_temp;
    }
    hist_map.clear();
}

// load all the hists from the file
void LoadHists(TH1Map& hist_map, const std::string& filename)
{
    TFile file(filename.c_str());
    if (file.IsZombie()) 
    {
        throw std::runtime_error("[LoadHists] Error -- file cannot be open or is not found!");
    }

    // looper over all TH1 ojbects
    for (TObjLink* link = gDirectory->GetListOfKeys()->FirstLink(); link != NULL; link = link->Next())
    {
        if (TH1* hist_ptr = dynamic_cast<TH1*>(gDirectory->Get(link->GetObject()->GetName())))
        {
            hist_ptr->SetDirectory(0);
            const std::string name(hist_ptr->GetName());
            hist_map.insert(std::make_pair(name, hist_ptr));
        }
    }
    return;
}

// print the list of histograms
void ListHists(const TH1Map& hist_map)
{
    std::cout << "List of histograms in the TH1Map:" << std::endl;
    for (TH1Map::const_iterator hm_iter = hist_map.begin(); hm_iter != hist_map.end(); hm_iter++)
    {
        std::cout << hm_iter->first << "\t" << hm_iter->second->GetTitle() << std::endl; 
    }
}

// turn on/off the stats for the histograms 
void SetStats(TH1Map& hist_map, const bool toggle)
{
    for (TH1Map::const_iterator hm_iter = hist_map.begin(); hm_iter != hist_map.end(); hm_iter++)
    {
        hm_iter->second->SetStats(toggle);
    }
}

// set style
void SetStyle(const std::string& option)
{
    TStyle *myStyle = gROOT->GetStyle("Plain");
    TGaxis::SetMaxDigits(5);
    myStyle->SetPaintTextFormat("1.3f");
    myStyle->SetOptStat(option.c_str());
    myStyle->SetOptFit(1111);
    myStyle->SetTitleBorderSize(0);
    myStyle->SetTitleFillColor(0);
    myStyle->SetTitleStyle(0);
    //myStyle->SetTitleX( 0.5 - 2.0*myStyle->GetTitleXSize() );
    //myStyle->SetTitleX( 0.05 );
    //myStyle->SetTitleY( 0.96 );
    //myStyle->SetTitleAlign(22);
    myStyle->SetLegendBorderSize(0);
#if ROOT_VERSION_CODE >= ROOT_VERSION(5,30,0)
    myStyle->SetLegendFillColor(0);
#endif

    //myStyle->SetTitleY(0.985);
    myStyle->SetHistLineColor(kBlue);
    myStyle->SetHistLineWidth(1);
    myStyle->SetPadGridX(1);
    myStyle->SetPadGridY(1);
    myStyle->SetGridColor(kGray+1);
    myStyle->SetCanvasDefW(600);
    myStyle->SetCanvasDefH(600);
    myStyle->SetStatH(0.09);
    myStyle->SetStatW(0.2);
    myStyle->SetStatX(0.99);
    myStyle->SetStatY(0.99);
    myStyle->SetStatBorderSize(myStyle->GetHistLineWidth());
    myStyle->SetStatTextColor(kBlack);
    myStyle->SetStatColor(0);
    //myStyle->SetStatStyle(Style_t style = 1001);
    //void SetStatBoxPosition(TH1* hist_ptr, float x1 = 0.8, float y1 = 0.8, float x2 = 1.0, float y2 = 1.0);

    myStyle->SetTitleOffset(1.2, "Y");
    myStyle->SetLabelSize(0.035, "Y");
    myStyle->SetLabelSize(0.035, "X");
    myStyle->cd();
    gStyle = myStyle;
}

// make an efficiency plot by dividing the two histograms 
TH1* MakeEfficiencyPlot(TH1* const num_hist, TH1* const den_hist, const std::string& name, const std::string& title)
{
    using namespace std;

    // check that hists are valid
    if (!num_hist || !den_hist)
    {
        throw std::runtime_error("[MakeEfficiencyPlot] Error: one of the Histograms are NULL");
    }

    // verify that all histograms have same binning
    if (den_hist->GetNbinsX() != num_hist->GetNbinsX()) 
    {
        throw std::runtime_error("[MakeEfficiencyPlot] Error: Histograms must have same number of bins");
    }

    // get the new histogram
    TH1F* const temp = dynamic_cast<TH1F*>(num_hist->Clone(name.c_str()));
    temp->SetTitle(title.empty() ? name.c_str() : title.c_str());
    temp->Reset();
    if (!temp->GetSumw2N())
    {
        temp->Sumw2();
    }

    // Do the calculation
    temp->Divide(num_hist, den_hist, /*num scale=*/1.0, /*den scale=*/1.0, /*option=*/"B");

    // Done
    return temp;
}
