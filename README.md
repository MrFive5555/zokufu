# Genealogy - todo list

## Timeline

* 周四没课, DDL就当它`2017-11-14(Tuesday)`好了
* 不给push权限, 我来批pull request
* 准备上台展示吧, 每个人都要上台
><del>高太公说站在上面的组员才能混到课堂小分</del>

## Requirements from darren

* 2-space indent
* many a small file (no indexing plugin, sorry)
* Reference to the boost header are in &lt;&gt;  
`g++ ... -isystem .`in Makefile makes them work.  
If it won't compile on your platform, please contact me.
* Since there isn't so many a person in a family chart in reality,  
we don't provide many a query method.  
Just make full use of your eyes and read the chart.  
We focus on editing methods. 

## Todo

###### 人

* 死活
* 死亡年月日
>C标准time.h里面提供的time struct参考一波

###### 图

* Boost Graph library?
* **output to file**
* A male decendent can have multiple wives
* A woman from other family can only marry once
* Mate of female decendants are not counted
* Changes of info which is part of a person requires seperate file-op module

## 分工(随做随记)

###### wty

* 存储顾问
* 

###### <ruby>Mr.Five555<rt>海龟大佬</rt></ruby>

* 提供头文件, 指定接口
* 系统设计

###### Darren

* repo管理
* 矢量图生成
* 平台依赖顾问
* 文档?


## Darren's Checklist (ordered)

###### Unead

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
* graph i/o
	* read_graphviz
	* write_graphviz

###### Do

0. Output to graphviz with color (weight)
0. Add person (Parameter PAck)
0. 




