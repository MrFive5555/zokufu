#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<stdexcept>
#include<ctime>
#include<climits>
#include<string>
#include<map>
#include<algorithm>
#include<bitset>
#include<boost/graph/graph_traits.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#define CSV_IO_NO_THREAD // avoid -lpthread
#include"csv.h"
using namespace std;
using namespace boost;