//------------------------------------------------------------------------//
// root_tools' link_def.h Kelley 2011-05-01
//------------------------------------------------------------------------//

#ifdef __CINT__  // interpreter and ACLiC

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions; 

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

// classes
#pragma link C++ class CMS2Looper+;

#endif // __CINT__
