#!/bin/bash

if [[ `uname` == "Darwin" ]]
then
    CC="clang++"
else
    CC="g++"
fi
   
# cmd="$CC -g -O0 source/TrackingEfficiencyAnalysis.cc source/TRKEFF.cc source/HistTools.cc -o tracking_eff_analysis `root-config --cflags --libs` -lGenVector -Iinclude"
cmd="$CC -O2 source/TrackingEfficiencyAnalysis.cc source/TRKEFF.cc source/HistTools.cc -o tracking_eff_analysis `root-config --cflags --libs` -lGenVector -Iinclude"

echo $cmd
eval $cmd
