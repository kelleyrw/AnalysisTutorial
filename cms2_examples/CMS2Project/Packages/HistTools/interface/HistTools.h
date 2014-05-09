#ifndef HISTTOOLS_H
#define HISTTOOLS_H

#include <map>
#include <string>
#include "TColor.h"
#include "TStyle.h"
#include "TH1.h"
#include "TDirectory.h"

// forward declarations

// convenenice typedef for a simple histogram container
typedef std::map<std::string, TH1*> TH1Map;

// set the directory
void SetDirectory(TH1Map& hist_map, TDirectory* const dir);

// set the color
void SetLineColor(TH1Map& hist_map, const Color_t color);

// normalize hists
void NormalizeHists(TH1Map& hist_map, const double norm = 1.0);

// scale hists
void ScaleHists(TH1Map& hist_map, const double scale);

// Add a histogram to the container
void AddHist(TH1Map& hist_map, TH1* const hist, const bool overwrite = false);

// save all the hists to a file
void SaveHists(const TH1Map& hist_map, const std::string& filename,  const std::string& option = "RECREATE");

// print all the hists
void PrintHists(const TH1Map& hist_map, const std::string& pathname = "",  const std::string& suffix = "png");

// load all the hists from the file
void LoadHists(TH1Map& hist_map, const std::string& filename);

// print the list of histograms
void ListHists(const TH1Map& hist_map);

// clear and delete the histogram pointers in the map
void ClearHists(TH1Map& hist_map);

// Set style
void SetStyle(const std::string& option = "emrou");

// turn on/off the stats for the histograms 
void SetStats(TH1Map& hist_map, const bool toggle);

// make an efficiency plot by dividing the two histograms 
TH1* MakeEfficiencyPlot
(
    TH1* const num_hist,
    TH1* const den_hist,
    const std::string& name = "h_eff",
    const std::string& title = "" // uses name if blank
);

#endif // HISTTOOLS_H
