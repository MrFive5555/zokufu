// main.h >>>
// 	system includes
// 	typedefs
//  defines
// <<<
#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<fstream>
#include<cstring>
#include<stdexcept>
#include<ctime>
#include<climits>
#include<string>
#include<map>
#include<algorithm>
#include<boost/graph/graph_traits.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#define CSV_IO_NO_THREAD // avoid -lpthread
#include"csv.h"
using namespace std;
using namespace boost;
#define MATE_FILENAME "dat/mate.csv"
#define TREE_FILENAME "dat/tree.csv"
#define RAIN_FILENAME "dat/rain.csv"
#define PERSON_FILNAME "dat/person.csv"
#define MALE string("male")
#define FEMALE string("female")
#define ROOT 0
#define G_CSV_COL1 "v1"
#define G_CSV_COL2 "v2"
typedef adjacency_list<
  setS, // OutEdgeList, enforce the absence of parallel edges
  vecS, // VertexList
  bidirectionalS, // Directed
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
>Digraph;
typedef adjacency_list<
  setS, // OutEdgeList, enforce the absence of parallel edges
  vecS, // VertexList
  undirectedS, // Undirected
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
>Ugraph;
typedef graph_traits<Digraph>::vertex_descriptor Vertex_d;
typedef graph_traits<Ugraph>::vertex_descriptor Vertex_u;
typedef std::pair<int,int> E;
typedef unsigned long id_type;
typedef unsigned short date_t;
#endif