#include "RootTools.h"
#include <string>
#include <iostream>
#include <iomanip>

void PrintAnalysisNumbers()
{
    using namespace std;
    const std::string& input_file_name  = "plots/dy_plots.root";
    rt::TH1Container hc(input_file_name);
    cout << "e1 eta acceptance  = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_e1_eta" ], -2.5, 2.5) << endl;
    cout << "e2 eta acceptance  = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_e2_eta" ], -2.5, 2.5) << endl;
    cout << "mu1 eta acceptance = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_mu1_eta"], -2.5, 2.5) << endl;
    cout << "mu2 eta acceptance = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_mu2_eta"], -2.5, 2.5) << endl;
    
    cout << "e1 pt acceptance  = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_e1_pt" ], 5.0, 10000) << endl;
    cout << "e2 pt acceptance  = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_e2_pt" ], 5.0, 10000) << endl;
    cout << "mu1 pt acceptance = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_mu1_pt"], 5.0, 10000) << endl;
    cout << "mu2 pt acceptance = " << std::setprecision(2) << rt::CalcPercentOfIntegral(hc["h_gen_mu2_pt"], 5.0, 10000) << endl;
}
