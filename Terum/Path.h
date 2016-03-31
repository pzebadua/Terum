//
//  Path.h
//  Edge
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//

#ifndef __Path__
#define __Path__

#include <iostream>
#include "Scene.h"

template <typename V, typename A> ostream & operator << (ostream & os, Path<V, A> & a);

template <class V, class A>
class Path
{
    A weight;
    
    Scene<V, A> *destiny;
    Path<V, A> *next;
    
public:
    Path(A weight, Scene<V, A> *destiny)
    {
        this->weight = weight;
        this->destiny = destiny;
        next = NULL;
    }
    
    A getWeight()
    {
        return weight;
    }
    
    void setWeight(A value)
    {
        weight = value;
    }
    
    Scene<V, A> *getDestiny()
    {
        return destiny;
    }
    
    void setDestiny(Scene<V, A> *value)
    {
        destiny = value;
    }
    
    Path<V, A> *getNext()
    {
        return next;
    }
    
    void setNext(Path<V, A> *value)
    {
        next = value;
    }
    
    friend ostream & operator << <>(ostream &, Path<V, A> &);
};

template <typename V, typename A>
ostream & operator << (ostream & os, Path<V, A> & a)
{
    os << " ---- " << a.weight << " ----> " << a.destiny->getInfo() << endl;
    
    //Imprimir las edges que salen de v
    
    os << endl;
    
    return os;
    }

#endif /* defined(__Path__) */
