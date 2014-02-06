#ifndef EVENTFILTER_H
#define EVENTFILTER_H

// this is a workaround for not having unique event id's in MC  
struct DorkyEventIdentifier {
  unsigned long int run, event, lumi;
  bool operator < (const DorkyEventIdentifier &) const;
  // bool operator > (const DorkyEventIdentifier &) const;
  bool operator == (const DorkyEventIdentifier &) const;
};
bool is_duplicate (const DorkyEventIdentifier &);

#endif
