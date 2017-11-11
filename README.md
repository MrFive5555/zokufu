# Genealogy - 不是需求分析的文档

## 废话放前面

* 周四没课, DDL就当它`2017-11-14(Tuesday)`好了
* 不给push权限, 我来批pull request
* 准备上台展示吧, 每个人都要上台
><del>高太公说站在上面的组员才能混到课堂小分</del>

## 人(封进人存储结构的内部, 与树无关)

* 死活
* 性别
* 姓名
* 出生年月日
>C标准time.h里面提供的time struct参考一波

* id不存储在人的内部


## 树结构

* 推荐用 Boost Graph library 做
* 阵亡的人不移出树, 把他的死活属性改一下即可
* 支持多娶/多嫁

## 综合(这个地方最麻烦)

```c++
typedef unsigned id_t;
class Human;
template<typename T>class Tree;
```
>人树分离

```c++
typedef map<id_t,Human> storage;
Tree<id_t> zokufu;
```

## 输入输出

* Graphviz提供的DOT语言自动生成(很丑的)矢量图(Darren来做)
* <del>示例的话, 建议上中文维基拿我朝鲜大金家来, 要多少有多少</del>

## 分工(说了100+遍了排名不分先后)

###### wty

* ?

###### <ruby>Mr.Five555<rt>海龟大佬</rt></ruby>

* ?

###### Darren

* 提供**所有**头文件, 强行指定接口标准
* 强行推销GraphViz和Boost库
* 学习pull requests模型
* 想办法让Visual Studio的sln和Makefile协作(至少不打架)
* DOT输出担当(尽快做出静态示例)
* 整理实验报告, 学习使用WYSIWYG软件

## 废话后面也有

* 使用union和类型标签模拟弱变量?
* rst替md





