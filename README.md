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




