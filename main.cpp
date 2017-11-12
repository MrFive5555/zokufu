#include <iostream>
#include <fstream>
#include<cstring>
#include"person.h"
#include"storage.h"

using namespace std;

void complain(){
	cout<<"What do you want?"<<endl;
}
bool file_both_exist(){
	return(
		ifstream(execDir()+RELATIONSHIP_FILENAME)&&
		ifstream(execDir()+PERSON_FILNAME)
	);
}
void sure(const string msg){
	cout<<msg<<endl;
	cout<<"Press <Enter> to proceed, <Ctrl-C> to abort: "<<endl;
	cin.get();
}
int main(int argc, char** argv) {
	// const map<int,string> command{
	// 	{0,          ""},
	// 	{1,      "init"},
	// 	{2,"new_person"},
	// 	{3,     "birth"},
	// 	{4,       "die"}
	// }
	// de-facto initialized storage instance (before reading file)
	storage* s=storage::getInstance();
	// the two blocks below don't need to read file
	{
		if(argc<=1){
			complain();
			exit(1);
		}
		if(strcmp(argv[1],"init")==0){
			sure("Are you sure to delete everyone and initialize?");
			sync();
			exit(0);
		}
	}
	// the ? number of choices below requires reading file
	s->load();
	{
		if(strcmp(argv[1],"new_person")==0){
			cout<<"Enter name, gender, "<<endl;
			exit(0);
		}
		// cout<<execDir()<<endl;
		// cout<<argv[0]<<endl;
	}
}
