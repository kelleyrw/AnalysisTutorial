# simple make file to compile the Z_looper

# ----------------------------------------------------------------------- #
# low level stuff that independent of this project
# ----------------------------------------------------------------------- #

# include ROOT friendly c++ variables
include Makefile.arch

# conveniance command to make shared libs
SHAREDLIB.cc = $(CXX) $(ROOTLIBS) $(CPPFLAGS) $(LDFLAGS) $(SOFLAGS) $(TARGET_ARCH) -fPIC -o

# ROOT is missing the GenVector in its default setup 
LDFLAGS += -lGenVector -lEG -lTMVA -lMinuit -lMLP -lXMLIO -lTreePlayer -lMathMore

# ----------------------------------------------------------------------- #
# CMS2 specific includes
# ----------------------------------------------------------------------- #

# add CORE support
cms2_core    := CORE
CPPFLAGS     += -I$(cms2_core)

# add local libraries
local_src := src
CPPFLAGS  += -Iinterface

# add looperTools support
looper_tools  := looper_tools
CPPFLAGS  += -I$(looper_tools)

# ----------------------------------------------------------------------- #
# project specific variables 
# ----------------------------------------------------------------------- #

lib      := libcms2_looper.so
sources  := $(local_src)/CMS2.cc                    \
            $(local_src)/ScanChain.cc               \
            $(local_src)/goodrun.cc                 \
            $(cms2_core)/mcSelections.cc            \
            $(looper_tools)/eventFilter.cc          \
            $(looper_tools)/HistTools.cc
objects  := $(subst .cc,.o,$(sources)) ScanChain_dict.o
deps     := $(subst .cc,.d,$(sources)) ScanChain_dict.d

# ----------------------------------------------------------------------- #
# rules 
# ----------------------------------------------------------------------- #

# all rule should be first
.PHONY: all
all: library 

# for troubleshooting
.PHONY: test
test: 
	@echo "lib          = $(lib)"
	@echo "sources      = $(sources)"
	@echo "objects      = $(objects)"
	@echo "SHAREDLIB.cc = $(SHAREDLIB.cc)"
	@echo "local_src    = $(local_src)"
	@echo "cms2_core    = $(cms2_core)"
	@echo "looper_tools = $(looper_tools)"
	@echo "LDFLAGS      = $(LDFLAGS)"
	@echo "CPPFLAGS     = $(CPPFLAGS)"
	@echo "CXXFLAGS     = $(CXXFLAGS)"
	@echo "CXX          = $(CXX)"
	@echo "CPP          = $(CPP)"

# build the library 
library: $(lib) 

.PHONY: clean
clean:
	@echo "removed object and shared object files from this area"
	@rm $(lib) $(objects) $(deps)
	@if [ -f ScanChain_dict.cc ]; then rm ScanChain_dict.cc; fi 
	@if [ -f ScanChain_dict.h  ]; then rm ScanChain_dict.h ; fi 
	@if [ -f ScanChain_dict.o  ]; then rm ScanChain_dict.o ; fi 
	@if [ -f ScanChain_dict.d  ]; then rm ScanChain_dict.d ; fi 

# actual rule to build the library
$(lib) : $(objects)
	$(SHAREDLIB.cc) $@ $^

# root to build the ROOT CINT dictionary
ScanChain_dict.o : ScanChain_dict.cc

ScanChain_dict.cc : interface/ScanChain.h
	rootcint -v3 -f $@ -c  -I$(cms2_core) -DNDEBUG $^ $(local_src)/LinkDef.h 

# ----------------------------------------------------------------------- #
# check dependencies
# ----------------------------------------------------------------------- #

-include $(deps)

%.d: %.cc
	@$(CXX) -M $(CXXFLAGS) $(CPPFLAGS) $< > $@.$$$$;    \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
