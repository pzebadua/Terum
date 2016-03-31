//
//  Map.h
//  Graph
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//

#ifndef __Map__
#define __Map__

#include <iostream>
#include "Path.h"

template <class V, class A> class Map;
template <typename V, typename A> ostream & operator << (ostream & os, Map<V, A> & v);

template <class V, class A>
class Map
{
    Scene<V, A> *start;
private:
	
    

public:
    Map()
    {
        start = NULL;
    }
    
    ~Map();
	  
    void insertScene(Scene<V, A> *v);
    void insertPath(Scene<V, A> *o, Scene<V, A> *d, A weight);

    friend ostream & operator << <>(ostream &, Map<V, A> &);
};

template <class V, class A>
Map<V, A>::~Map()
{
    if (start != NULL)
    {
        Scene<V, A> * temp = start;
        
        while(temp != NULL)
        {
            start = start->getNext();
            delete temp;
            temp = start;
        }
    }
}


template <class V, class A>
void Map<V, A>::insertScene(Scene<V, A> *v)
{
    if(start == NULL)
    {
        start = v;
    }
    else
    {
        Scene<V, A> *temp = start;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        
        temp->setNext(v);
    }
}

template <class V, class A>
void Map<V, A>::insertPath(Scene<V, A> *o, Scene<V, A> *d, A weight)
{
    if (o != NULL && d != NULL)
    {
        Path<V, A> *nueva = new Path<V, A>(weight, d);
        
        o->insertPath(nueva);
    }
}

template <typename V, typename A>
ostream & operator << (ostream & os, Map<V, A> & g)
{
    
    //Imprimir los vertices 
    
    Scene<V, A> *temp = g.start;
    
    cout << "Paths going out: " << endl;
    while(temp != NULL)
    {
        os << *temp;
        temp = temp->getNext();// o getNext()
    }
    
    os << endl;
    
    return os;
    }

#endif /* defined(__Map__) */
