# 题目要求

设计一个家谱什么的

# 数据结构与算法

###### 三张图

* 图是树的推广(是...吧),所以只要对图加以限制就能造树
* 一张描述婚姻关系的无向图`storage::mate`
	* 其实只是无序数对而已
* 一张描述本家的有向图`storage::tree`
	* 其实是一颗树,具有唯一根节点
	* 虚拟root是根
	* 父指向子女,层层下传
* 一张乱七八糟的极其零散的图`storage::tree`
	* 其实是一个森林, 林中每棵树只有两层(某母亲->她的后代)
	* 描述后代和(后代的双亲中的不属于本家的那一个)(i.e.母亲)的关系

###### 图实现

* 拒绝造轮子
>A wheel a day keeps your innovation away.

* 使用纯头库[boost](http://www.boost.org/)提供的[Boost Graph Library(BGL)](http://www.boost.org/doc/libs/1_65_1/libs/graph/doc/table_of_contents.html)来实现
* 陈列部分该库的函数
	* vertices()
	* edge()
	* add_vertex()
	* add_edge()
	* write_graphviz()
	* ...
	* *简单粗暴不必解释*
	
###### 文件读写实现

* 某大神写的用来parse一个csv的纯头库[fast-cpp-csv-parser](https://github.com/ben-strasser/fast-cpp-csv-parser)
* 上文提到的三张"图",全部用不带引号的csv搞,长这样:

```
v1,v2
1,3
1,10
1,11
4,13
4,5
4,6
4,14

```

###### 绘制实现

# 测试数据、结果及分析

###### 使用ShellScript大法

* 使用**伟大的共和国永远的主席**的[金氏家族](https://zh.wikipedia.org/wiki/%E9%87%91%E6%AD%A3%E6%81%A9)来作为例子
	* 

(所输入的数据及相应的运行结果,运行结果要有提示信息,运行结果采用截图
方式给出。)

# 分工、贡献%、自我评分

* 根据汉谟拉比法典,每人33.3%

# 项目总结

* 相信,我两个通宵不会要命

# 程序清单

