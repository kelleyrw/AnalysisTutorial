#include <set>

#include "eventFilter.h"

std::set<DorkyEventIdentifier> already_seen;

//usage example:

//goes in main looper
// #include "../looperTools/goodrun.h"

//goes before file loop
// set_goodrun_file("/home/users/benhoob/ZMet2012/jsons/final_19p47fb_cms2.txt");

// //parse events from json
// if( cms2.evt_isRealData() ){
// 	if( !goodrun_json( cms2.evt_run(), cms2.evt_lumiBlock() ) ){continue;}
// 	DorkyEventIdentifier id = { cms2.evt_run(), cms2.evt_event(), cms2.evt_lumiBlock() };
// 	if ( is_duplicate( id ) ){
// 	  // cout << "\t! ERROR: found duplicate." << endl;
// 	  // nDuplicates++;
// 	  continue;
// 	}
// }


bool DorkyEventIdentifier::operator < (const DorkyEventIdentifier &other) const
{
  if (run != other.run)
	return run < other.run;
  if (event != other.event)
	return event < other.event;
  if(lumi != other.lumi)
	return lumi < other.lumi;
  return false;
}

bool DorkyEventIdentifier::operator == (const DorkyEventIdentifier &other) const
{
  if (run != other.run)
	return false;
  if (event != other.event)
	return false;
  return true;
}

bool is_duplicate (const DorkyEventIdentifier &id) {
  std::pair<std::set<DorkyEventIdentifier>::const_iterator, bool> ret =
	already_seen.insert(id);
  return !ret.second;
}
