#! /bin/bash

if [ ! "$CMSSW_BASE" == "" ]; then
	if [ -d "CORE" ]; then
		echo "CORE exists at $CMSSW_BASE/src/CMS2/NtupleMacros/CORE"
	else
		echo "Creating simlink to CORE from $CMSSW_BASE/src/CMS2/NtupleMacros/CORE"
		ln -s "$CMSSW_BASE/src/CMS2/NtupleMacros/CORE"
	fi
else
	echo "Error: CMSSW path not set. Exiting."
	exit 1
fi

echo "Compiling Looper:"
make -j5
if [ ! "$?" -eq "0" ]; then
	echo "Did not Compile, Exiting"
	exit 2
fi

echo
echo "Setup complete. Type 'root run_sample.C' to run looper."
echo
