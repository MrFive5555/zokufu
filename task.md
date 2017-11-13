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
* 5-bit-wide bitset, user deceide whether to label name/id/..., color gender/...

| No. | related attr | whether or not do ... |
| -   | -            | -                     |
| 0   | id           | display in label      |
| 1   | name         | display in label      |
| 2   | gender       | color vertex          |
| 3   | birth        | display in label      |
| 4   | death        | display in label      |

default "11100"


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

# Done

* Output to graphviz
* In g++ command, put -lxx after .o files
* read graphviz
* 3 graphs
* test read graphviz
* sh build boost_graph boost_regex
* create a folder for csv/dot data storage, seperate from display(d)
* display test.sh result after stripping chromium warnings
* stable test ("xxxx"?)


