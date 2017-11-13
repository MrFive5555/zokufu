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
#include<boost/graph/graph_traits.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#define CSV_IO_NO_THREAD // avoid -lpthread
#include"csv.h"

using namespace std;
using namespace boost;

// #define DATA_DIRECTORY "dat"
// #define MATE_FILENAME execDir()+DATA_DIRECTORY+"/"+"mate.dot"
// #define TREE_FILENAME execDir()+DATA_DIRECTORY+"/"+"tree.dot"
// #define RAIN_FILENAME execDir()+DATA_DIRECTORY+"/"+"rain.dot"
// #define PERSON_FILNAME execDir()+DATA_DIRECTORY+"/"+"person.csv"
#define MATE_FILENAME "dat/mate.dot"
#define TREE_FILENAME "dat/tree.dot"
#define RAIN_FILENAME "dat/rain.dot"
#define PERSON_FILNAME "dat/person.csv"
#define MALE string("male")
#define FEMALE string("female")
#define ROOT 0
// #define TEST4(G){
//   cout<<in_degree(4,G)<<endl;
// }

typedef adjacency_list<
  setS, // OutEdgeList, enforce the absence of parallel edges
  vecS, // VertexList
  // listS, // OutEdgeList
  // listS, // VertexList
  bidirectionalS, // Directed
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
> Digraph;
typedef adjacency_list<
  setS, // OutEdgeList, enforce the absence of parallel edges
  vecS, // VertexList
  // listS, // OutEdgeList
  // listS, // VertexList
  undirectedS, // Undirected
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
> Ugraph;
typedef graph_traits<Digraph>::vertex_descriptor Vertex_d;
typedef graph_traits<Ugraph>::vertex_descriptor Vertex_u;
typedef std::pair<int,int> E;
typedef unsigned long id_type;
typedef unsigned short date_t;

// extern string execDir();
extern void display_dot(const string);
#endif