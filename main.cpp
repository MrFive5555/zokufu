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
int main(int argc, char** argv) {
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
		// cout<<execDir()<<endl;
		// cout<<argv[0]<<endl;
	}
}
