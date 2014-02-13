// to compile:  g++ src/with_root.cpp `root-config --cflags --libs` -o bin/with_root 

#include "TH1F.h"
#include "TFile.h"

int main()
{
    TFile file("file.root", "RECREATE");
    TH1F h1("h1", "h1", 100, -5, 5);
    h1.FillRandom("gaus", 10000);
    h1.Write();
    file.Close();
    return 0;
}

