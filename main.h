// main.h
// #define HUSBAND_WIFE_WEIGHT 1
// #define HUSBAND_WIFE_COLOR ""
// #define WIFE_SUBSPRING_WEIGHT 2
// #define WIFE_SUBSPRING_COLOR ""
#ifndef MAIN_H
#define MAIN_H

#include<string>
#include<boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

#define MATE_RELATIONSHIP_FILENAME execDir()+"mate.dot"
#define HIERARCHY_RELATIONSHIP_FILENAME execDir()+"hierarchy.dot"
#define PERSON_FILNAME execDir()+"person.csv"

#define MALE "male"
#define FEMALE "female"

// "unsigned" conflict with "NO_MOTHER"
typedef long id_type;
typedef unsigned date_t;
typedef adjacency_list<
  vecS, // OutEdgeList
  vecS, // VertexList
  bidirectionalS, // Directed
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
> Digraph;
typedef adjacency_list<
  vecS, // OutEdgeList
  vecS, // VertexList
  undirectedS, // Directed
  no_property, // VertexProperties
  no_property, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
> Ugraph;

typedef graph_traits<Digraph>::vertex_descriptor Vertex_d;
typedef graph_traits<Ugraph>::vertex_descriptor Vertex_u;
typedef std::pair<int,int> E;

// enum Gender {MALE,FEMALE};

extern string execDir();
extern void display_dot(const string);

#endif