#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>

#ifdef _WIN32
#define PATH_JOIN_SEPERATOR   "\\"
#else
#define PATH_JOIN_SEPERATOR   "/"
#endif

int main(int argc, char const *argv[]) {

  execCalc();
  
  time_t t;
  time(&t);
  struct tm tm = *localtime(&t);

  char filename[256];
  sprintf_s(filename, 256, "_pwned-%d-%d-%d--%d-%d-%d--%d", 
    tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec, t);

  FILE *fp = fopen(filename, "w");
  if (fp == NULL)
  {
      printf("Error opening the file %s", filename);
      return -1;
  }

  for (size_t i = 0; i < argc; i++)
  {
    fprintf(fp, "%s ", argv[i]);
  }
  
  fclose(fp);
  return 0;
}

int execCalc() {
  char *args[]={"calc.exe", NULL};
  execvp(args[0], args);
}
