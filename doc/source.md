# Genealogy - todo list

## What to show

* claimed kid check
* incest check

## Timeline

* 周四没课, DDL就当它`2017-11-14(Tuesday)`好了
* 不给push权限, 我来批pull request
* 准备上台展示吧, 每个人都要上台
><del>高太公说站在上面的组员才能混到课堂小分</del>
## 分工(随做随记)

## Special thanks

* [Boost C++ Library](http://www.boost.org)
	* [Graph](http://www.boost.org/doc/libs/1_65_1/libs/graph/doc/table_of_contents.html)
* [fast-cpp-csv-parser](https://github.com/ben-strasser/fast-cpp-csv-parser)
* https://stackoverflow.com/questions/12272864/linker-error-on-linux-undefined-reference-to


###### wty

* 存储顾问
* 文档

###### <ruby>Mr.Five555<rt>海龟大佬</rt></ruby>

* 提供头文件, 指定接口
* 系统设计

###### Darren

* repo管理
* 矢量图生成
* 平台依赖顾问

# ?

###### Requirements

* 2-space indent
* many a small file (no indexing plugin, sorry)
* Reference to the boost header are in &lt;&gt;  
`g++ ... -isystem .`in Makefile makes them work.  
If it won't compile on your platform, please contact me.
* Since there isn't so many a person in a family chart in reality,  
we don't provide many a query method.  
Just make full use of your eyes and read the chart.  
We focus on editing methods. 
* Because this is a CLI program, we **always** sync() before exit.

###### Requirements-人

###### Rules

* A male decendent can have multiple wives

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
* Add relationship ("birth()"?) (Parameter Pack ?)
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

###### Read later

* quick tour
	* color
	* visitor

# Todo

* Optimize -O3 on final release
* sync() writes PERSON_FILENAME(person.csv)?\
* incest check
* combined rain+tree, highlight our fellow (seperate cheat engine mark fellow)

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
* graph i/o
	* read_graphviz
	* write_graphviz

