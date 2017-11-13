#include"main.h"
int main(){
  Digraph g;
  dynamic_properties dp;
  cout<<TREE_STORAGE<<endl;
  ifstream ifs(TREE_STORAGE);
  // read_graphviz(ifs,g);
  string gs="asdfasdf";
  read_graphviz(gs,g);
  ifs.close();

  // ofstream ofs("dat/tree_rewrite.dot");
  // write_graphviz(ofs,g);
  write_graphviz(cout,g);

  // read_graphviz(ifstream(TREE_STORAGE),g,dp);


  // cout<<master<<" marry "<<slave<<endl;
  // for(unsigned i=0;i<=11;++i){
  //   cout<<in_degree(i,g)<<endl;
  //   if(in_degree(i,g)!=0){
  //     auto e=*(in_edges(i,g).first);
  //     cout<<"from "<<source(e,g)<<" to "<<target(e,g)<<endl;
  //   }
  // }
}