#include "TChain.h"
#include "TChainElement.h"

#include "interface/CMS2.h"

#ifndef SCANCHAIN_H
#define SCANCHAIN_H

class cms2Looper
{

public:
  cms2Looper();
  ~cms2Looper();

  int ScanChain( TChain* chain, bool fast = true, int nEvents = -1 );

};

#endif
