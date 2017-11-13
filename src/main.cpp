#include <iostream>
#include <fstream>
#include<cstring>
#include"person.h"
#include"storage.h"
#define COMMAND(C) strcmp(argv[1],C)==0
#define RED "\033[31m"
#define RESET "\033[0m"
using namespace std;

void complain_exit(const string s){
	cout<<s<<endl;
	exit(1);
}
void sure(const string msg){
	cout<<msg<<endl;
	cout<<"Press <Enter> to proceed, <Ctrl-C> to abort: "<<endl;
	cin.get();
}
int argc_g=0;
char** argv_g=nullptr;
vector<id_type> getIdParameters(){
	vector<id_type> ret;
	for(int i=2;i!=argc_g;++i){
		ret.push_back(stoul(argv_g[i]));
	}
	return ret;
}
int main(int argc, char** argv) {
	try{
		argc_g=argc;
		argv_g=argv;
		storage* s=storage::getInstance();
		// the two blocks below don't need to read file
		if(argc<=1){
			complain_exit("What do you want? Give me a parameter please");
		}
		if(COMMAND("i")){
			sure("Are you sure to delete everyone and initialize?");
			s->init();
			s->sync();
			exit(0);
		}
		if(COMMAND("xxxx")){
			s->load();
			sure("Read properly, and sync won't corrupt? ");
			s->sync();
			exit(0);
		}
		// if(COMMAND("d")){
		// 	// don't read file
		// 	// just call graphviz(dot) and chromium-browser 
		// 	s->display();
		// 	exit(0);
		// }
		// commands below requires reading file at the beginning and writing file at the end
		if(COMMAND("a")){
			s->load();
			s->attach_to_root(getIdParameters()[0]);
			s->sync();
			exit(0);
		}
		if(COMMAND("m")){
			s->load();
			s->mate_might_birth(getIdParameters());
			s->sync();
			exit(0);
		}
		complain_exit("Invalid/unimplemented command");
	}catch(runtime_error e){
		cout<<RED<<"Error: "<<RESET<<e.what()<<endl;
	}
}
