// main.h
// #define HUSBAND_WIFE_WEIGHT 1
// #define HUSBAND_WIFE_COLOR ""
// #define WIFE_SUBSPRING_WEIGHT 2
// #define WIFE_SUBSPRING_COLOR ""
#ifndef MAIN_H
#define MAIN_H

#include<string>

using namespace std;

#define NO_MOTHER -1
// #define RELATIONSHIP_FILENAME "relationship.csv"
#define RELATIONSHIP_FILENAME "relationship.dot"
#define PERSON_FILNAME "person.csv"

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
> Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef std::pair<int,int> E;

enum Gender {MALE,FEMALE};

extern string execDir();

#endif