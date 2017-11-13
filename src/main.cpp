#include <iostream>
#include <fstream>
#include<cstring>
#include"person.h"
#include"storage.h"
#define COMMAND(C) strcmp(argv[1],C)==0

using namespace std;

void complain(){
	cout<<"What do you want?"<<endl;
}
bool file_both_exist(){
	return(
		ifstream(execDir()+MATE_FILENAME)&&
		ifstream(execDir()+TREE_FILENAME)&&
		ifstream(execDir()+PERSON_FILNAME)
	);
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
	argc_g=argc;
	argv_g=argv;
	storage* s=storage::getInstance();
	// the two blocks below don't need to read file
	{
		if(argc<=1){
			complain();
			exit(1);
		}
		if(COMMAND("i")){
			sure("Are you sure to delete everyone and initialize?");
			s->init();
			s->sync();
			exit(0);
		}
		if(COMMAND("d")){
			s->display();
			exit(0);
		}
	}
	// commands below requires reading file at the beginning and writing file at the end
	{
		if(COMMAND("a")){
			s->load();
			s->attach_to_root(getIdParameters()[0]);
			s->sync();
		}
		if(COMMAND("m")){
			s->load();
			s->mate_might_birth(getIdParameters());
			s->sync();
		}
	}
}
