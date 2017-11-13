// util.cpp
// non os-specific headers
#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
// os-specific things
#if defined( _WIN32 ) || defined ( _WIN64 )
// >>> Windows
#include<windows.h>
#define selfPath(STR){\
	char szPath[MAX_PATH];\
	GetModuleFileName(nullptr,szPath,MAX_PATH);\
	STR=string(szPath);\
  STR=STR.substr(0,STR.find_last_of("\\"));\
	/*GetModuleFileName( "", szPath, MAX_PATH );*/\
}
#define APPEND "\\"
// <<< Windows
#elif defined( __linux__ ) || defined ( __gnu_linux__ )
// >>> Linux
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<climits>
#include<cstring>
#define selfPath(STR){\
	/*readlink does not '\0' terminate the C-style string*/\
  char dest[PATH_MAX];\
	memset(dest,0,sizeof(dest));\
  readlink("/proc/self/exe",dest,PATH_MAX);\
  STR=string(dest);\
  STR=STR.substr(0,STR.find_last_of("/"));\
}
#define APPEND "/"
// <<< Linux
#else
	#error "Unsupported OS"
#endif
// here we go
using namespace std;
string execDir(){
  // cout << getCurrentDir() << endl;
  string path;
  selfPath(path);
  // ofstream ofs(path+APPEND);
  // cout<<str.substr(0,str.find_last_of("/"))<<endl;
  // cout<<str<<endl;
  return path+APPEND;
}



