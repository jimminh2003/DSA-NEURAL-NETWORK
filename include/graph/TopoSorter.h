/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSorter.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:21 PM
 */

#ifndef TOPOSORTER_H
#define TOPOSORTER_H
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "sorting/DLinkedListSE.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "hash/xMap.h"

template<class T>
class TopoSorter{
public:
   static const int DFS = 0;
    static const int BFS = 1;
    
protected:
    DGraphModel<T>* graph;
    int (*hash_code)(T&, int);
    
public:
    TopoSorter(DGraphModel<T>* graph, int (*hash_code)(T&, int)=0){
        //TODO
         this->graph = graph;
        this->hash_code = hash_code;
    }   
    DLinkedList<T> sort(int mode=0, bool sorted=true){
        //TODO
         
    }
    DLinkedList<T> bfsSort(bool sorted=true){ 
        //TODO
        
    }

    DLinkedList<T> dfsSort(bool sorted=true){
        //TODO
        
    }

protected:
    XHashMap<T, int> vertex2inDegree(int (*hash)(T&, int)) {
       
    }

    XHashMap<T, int> vertex2outDegree(int (*hash)(T&, int)) {
       
    }

    DLinkedList<T> listOfZeroInDegrees() {
       
    }
}; //TopoSorter


/////////////////////////////End of TopoSorter//////////////////////////////////


#endif /* TOPOSORTER_H */

