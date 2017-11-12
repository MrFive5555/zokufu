#include"main.h"
using namespace std;

int main() {
	Digraph dg;
	add_edge(0,3,dg);
	// for(unsigned i:{1,2})
	// 	remove_vertex(i,dg);


  // for (;vp.first != vp.second; ++vp.first){
  //   std::cout << *vp.first << "=" << index[*vp.first] <<  ", ";
  // }

	typedef property_map<Digraph, vertex_index_t>::type IndexMap;
	IndexMap index=get(vertex_index,dg);

	graph_traits<Digraph>::vertex_iterator vi, vi_end, next;
	tie(vi, vi_end) = vertices(dg);
	for (next = vi; vi != vi_end; vi = next) {
		++next;
		if(index[*vi]==1){
			remove_vertex(*vi,dg);
			break;
		}
	}

	write_graphviz(cout,dg);



	return 0;
}
