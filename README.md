# Graph_project
* Final project for Intoduction to Graph Theory
* Creator: Marcin Kosiba 
* student id: 406876

## Table of contest:
1. Analitical part is placed in included ***Czesc_analityczna.pdf***
2. Implementation is in ***Bellman-Ford***
3. Bellman-Ford analyse is in ***Bellman-Ford_analyse.md***

## How to run Bellman-Ford algorithm:
* It is written in C++ so You have to have compiler and cmake installed.
#### If You run it by console:
Go to Bellman-Ford file and:

```
$ mkdir build
$ cd build
$ cmake ..
$ make 
$ ./src/Bellman-Ford
```

#### If You run it using IDE:
Just select CmakeList.txt in Bellman-Ford and project should be build.

#### Problems with "Unable to open matrix file"
If any problems with opening matrix occur, You should check in main if right filepath is given to filename string.
You should localize localize executable .exe and recursively give path from it to matrix.
If this fails try to give direct path to matrix.txt on Your computer.

#### I hope everything will be alright. 
If not, please contact me.
