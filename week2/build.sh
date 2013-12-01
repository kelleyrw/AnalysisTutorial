#!/bin/bash

clang++ -g -O0 source/TrackingEfficiencyAnalysis.cc source/TRKEFF.cc source/HistTools.cc -o analysis `root-config --cflags --libs` -lgenvector -Iinclude
