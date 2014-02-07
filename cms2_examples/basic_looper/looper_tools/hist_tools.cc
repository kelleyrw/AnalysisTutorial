#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <stdexcept>

#include "TH1.h"
#include "hist_tools.h"

void book_hist(std::map<std::string,TH1F*> &hist_map, const std::string &histname, const std::string &histtitle, const unsigned int nbins, const float min, const float max)
{
  std::cout<<"Booking Hist: "<<histname<<std::endl;
  hist_map.insert ( std::pair<std::string,TH1F*>(histname, new TH1F(histname.c_str(), histtitle.c_str(), nbins, min, max)));
  hist_map.at(histname)->Sumw2();
  return;
}


void fill_hist( TH1F* &hist, double variable, const double weight )
{
  float min = hist->GetXaxis()->GetXmin();
  float max = hist->GetXaxis()->GetXmax();

  if (variable > max) variable = hist->GetBinCenter(hist->GetNbinsX());
  if (variable < min) variable = hist->GetBinCenter(1);

  hist->Fill(variable, weight);

  return;
}

void save_hists(std::map < std::string, TH1F* > &hist_map, TFile &outfile )
{  
  // outfile.cd();
  for (std::map<std::string, TH1F*>::iterator itr = hist_map.begin(); itr != hist_map.end(); itr++){
	itr->second->Write(itr->first.c_str(), TObject::kOverwrite);
  }

  return;
}
