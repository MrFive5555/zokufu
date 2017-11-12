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
// avoid -lpthread
#define CSV_IO_NO_THREAD
#include"csv.h"

using namespace std;
using namespace boost;

#define MATE_RELATIONSHIP_FILENAME execDir()+"mate.dot"
#define HIERARCHY_RELATIONSHIP_FILENAME execDir()+"hierarchy.dot"
#define PERSON_FILNAME execDir()+"person.csv"
#define MALE string("male")
#define FEMALE string("female")

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
typedef unsigned long date_t;
// "unsigned" conflict with "NO_MOTHER"
typedef long id_type;

// enum Gender {MALE,FEMALE};

extern string execDir();
extern void display_dot(const string);

#endif