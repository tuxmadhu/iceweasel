#include "toolspath.h"

int
main(int argc, char **argv)
{
  int iRetVal;
  char* args[1000];
  int i = 0;
  int j = 0;
  int k = 0;
  int s = 0;
  args[i++] = LINK_PATH;

  args[i++] = "/LIBPATH:\"" WCE_LIB "\"";
  args[i++] = "/LIBPATH:\"" WCE_CRT "\"";
  args[i++] = "/NODEFAULTLIB";

#ifdef HAVE_SHUNT   // simple test to see if we're in configure or not
  if(getenv("NO_SHUNT") == NULL) {
    args[i++] = "/LIBPATH:\"" SHUNT_LIB "\"";
    args[i++] = "mozce_shunt.lib";
  }
#endif

  args[i++] = "corelibc.lib";
  args[i++] = "coredll.lib";
  args[i++] = "ceshell.lib";
  args[i++] = "mmtimer.lib";

  // if -DLL is not passed, then change the entry to 'main'
  while(argv[j]) {

      if (strncmp(argv[j], "-DLL", 4) == 0 ||
	  strncmp(argv[j], "/DLL", 4) == 0) {
	k = 1;
      }
      if (strncmp(argv[j], "-entry", 6) == 0 ||
	  strncmp(argv[j], "/entry", 6) == 0 ||
	  strncmp(argv[j], "-ENTRY", 6) == 0 ||
	  strncmp(argv[j], "/ENTRY",6 ) == 0) {
	k = 1;
      }
      if (strncmp(argv[j], "-subsystem:", 11) == 0 ||
	  strncmp(argv[j], "/subsystem:", 11) == 0 ||
	  strncmp(argv[j], "-SUBSYSTEM:", 11) == 0 ||
	  strncmp(argv[j], "/SUBSYSTEM:", 11) == 0) {
	s = 1;
      }
      j++;
  }

  if (k==0)
    args[i++] = "/ENTRY:main";

  if (s==0){
    args[i++] = "/subsystem:\"WINDOWSCE,5.02\"";
  }

  argpath_conv(&argv[1], &args[i]);

  //  dumpargs(args);

  return run(args);
}
