#include <string>
#include <map>

#include "TH1.h"
#include "TFile.h"

#ifndef HIST_TOOLS_H
#define HIST_TOOLS_H

void book_hist(std::map<std::string,TH1F*> &hist_map, const std::string &histname, const std::string &histtitle, const unsigned int nbins, const float min, const float max);
void fill_under_overflow(  TH1F* &hist, double variable, const double weight = 1);
void save_hists(std::map < std::string, TH1F* > &hist_map, TFile &outfile );

#endif
