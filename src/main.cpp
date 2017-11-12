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
		ifstream(execDir()+MATE_RELATIONSHIP_FILENAME)&&
		ifstream(execDir()+HIERARCHY_RELATIONSHIP_FILENAME)&&
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
		if(COMMAND("init")){
			sure("Are you sure to delete everyone and initialize?");
			s->sync();
			exit(0);
		}
		if(COMMAND("display")){
			s->display();
			exit(0);
		}
	}
	// the ? number of choices below requires reading file
	s->load();
	{
		if(COMMAND("mate")){
			const vector<id_type> idVec=getIdParameters();
			s->mate_might_birth(idVec);
			// s->mate_might_birth();
			s->sync();
		}
	}
}
