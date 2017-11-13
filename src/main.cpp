#include"def.h"
#include"storage.h"
#include"include.h"
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
		Storage* s=Storage::getInstance();
		// neighter read nor write file
		if(argc<=1){
			complain_exit("What do you want? Give me a parameter please");
		}
		// read but not write
		if(COMMAND("d")){
			s->load();
			// if(argc<=2)
			// 	s->display(format_t("11100"));
			// else{
			// 	if(strlen(argv[2])!=BITSETWIDTH)
			// 		throw runtime_error(string()+"formatter is not "+to_string(BITSETWIDTH)+" bits wide");
			// 	s->display(format_t(argv[2]));
			// }
			s->display();
			s->sync();
			exit(0);
		}
		// write but not read
		if(COMMAND("i")){
			sure("Are you sure to delete everyone and initialize?");
			s->init();
			s->sync();
			exit(0);
		}
		// read and write
		if(COMMAND("r")){
			s->load();
			sure("Read, do nothing, and write back(stability check)");
			s->sync();
			exit(0);
		}
		if(COMMAND("a")){
			s->load();
			s->attach_to_root(stoul(argv[2]));
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
