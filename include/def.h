// def.h >>>
// 	system includes
// 	typedefs
//  defines
// <<<
#pragma once
#include"include.h"
#define MATE_STORAGE "dat/mate.csv"
#define TREE_STORAGE "dat/tree.csv"
#define RAIN_STORAGE "dat/rain.csv"
#define PERSON_STORAGE "dat/person.csv"
#define MATE_PRINT "dot/mate.dot"
#define TREE_PRINT "dot/tree.dot"
#define RAIN_PRINT "dot/rain.dot"
#define MALE string("male")
#define FEMALE string("female")
#define ROOT 0
#define G_CSV_COL1 "v1"
#define G_CSV_COL2 "v2"
#define BITSETWIDTH 5
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
struct Person{
  // a person's birthday and gender cannot be changed
  // Person()=delete;
  // Person(string name, Date birthday, Gender gender) : name(name), birthday(birthday), gender(gender) {}
  // Person
  
  /*
  * 对错误或未定义的Date，所有时间都定为0
  */
  // 1(id)+8(attr)=9(cols in csv)
  const string name;
  const string gender;

  const date_t birth_year;
  const date_t birth_month;
  const date_t birth_day;

  const date_t death_year;
  const date_t death_month;
  const date_t death_day;
};typedef map<id_type,Person> idmap_t;