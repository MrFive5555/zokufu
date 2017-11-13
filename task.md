# NeverDo

* replace

```c++
using namespace std;
using namespace boost;
```

with

```
using std::cout;
using boost::graph_traits;
```


* Never Provide ANY way to edit idMap
	* maybe some csv op commmands
* time.h time struct
* Focus color

###### Unread

* examples
	* graph coloring
* traits classes
	* property_map
* graph classes
	* adjacency list
* tutorial
* Add relationship ("birth()"?) (Parameter Pack ?)

###### Read later

* quick tour
	* color
	* visitor
* graph i/o
	* read_graphviz
	* write_graphviz

# Todo

* Optimize -O3 on final release
* sync() writes PERSON_FILENAME(person.csv)?
* implement a (very long, 9bits?) bitset imitation, user deceide whether to label name/id/gender/...
* stable test ("xxxx"?)

# Done

* Output to graphviz
* In g++ command, put -lxx after .o files
* read graphviz
* 3 graphs
* test read graphviz
* sh build boost_graph boost_regex
* create a folder for csv/dot data storage, seperate from display(d)
* display test.sh result after stripping chromium warnings


