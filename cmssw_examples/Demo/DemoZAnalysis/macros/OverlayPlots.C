#include "RootTools.h"
#include <string>

void OverlayPlots
(
    const std::string& input_file_name  = "plots/dy_plots.root",
    const std::string& output_path = "plots/overlay",
    const std::string& suffix = "png"
)
{
    // load the histograms
    rt::TH1Container hc(input_file_name);
    hc.List();

    // write
    hc.Print(output_path, suffix);

    // done
    return;
}
