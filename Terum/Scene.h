//
//  Scene.h
//  Vertex
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Last Modified by Pablo Zebadúa Vega March 31 2016.

//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//

#ifndef __Vertex__
#define __Vertex__

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "Scenery.h"
using namespace std;

template <class V, class A> class Path;
template <class V, class A> class Scene;
template <typename V, typename A> ostream & operator << (ostream & os, Scene<V, A> & v);
template <class V, class A>
class Scene
{
    Scene<V, A> *next;
    Path<V, A> *edges;
    V info;
    Scenery scenery;
public:
    Scene()
    {
        next = NULL;
        edges = NULL;
    }
    
    ~Scene()
    {
        if (edges != NULL)
        {
            Path<V, A> * temp = edges;
            
            while(temp != NULL)
            {
                edges = edges->getNext();
                delete temp;
                temp = edges;
            }
        }
    }
    V getInfo()
    {
        return info;
    }
    
    void setInfo(V value)
    {
        info = value;
    }
    
	    Scene<V, A> *getNext()
    {
        return next;
    }
    
    void setNext(Scene<V, A> *value)
    {
        next = value;
    }
    
    Path<A, V> *getPaths()
    {
        return edges;
    }
    void setNext(Path<V, A> *value)
    {
        edges = value;
    }
    /**** Scenery *****/
    Scenery getScenery();
    void setScenery(Scenery s);

    Path<V, A> *lastPath();
    Scene<V, A> *getPath(Scene<V, A> *v , A value);
    void insertPath(Path<V, A> *a);
    friend ostream & operator << <>(ostream &, Scene<V, A> &);
};

template <class V, class A>
Scenery Scene<V, A> ::getScenery()
{
    return scenery;
}

template <class V, class A>
void Scene<V, A> ::setScenery(Scenery s)
{
    scenery = s;
}

template <class V, class A>
Scene<V, A> *Scene<V, A> :: getPath(Scene<V, A> *v, A value)
{
	transform(value.begin(), value.end(), value.begin(), ::tolower);
    Path<V, A> *temp = edges;
	
    
    
    while (temp != NULL){
        
        //If that checks the path and returns the new Scene once if value exists
        if (temp->getWeight() == value)
        {
            //Block paths here
            return temp->getDestiny();
        }
        temp = temp->getNext();
    }
    
    //If nothing found return the scene
    return v;
}



template <class V, class A>
Path<V, A> *Scene<V, A> :: lastPath()
{
    Path<V, A> *temp = edges;
    
    if(temp != NULL)
    {
        while(temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
    }
    return temp;
}
template <class V, class A>
void Scene<V, A>::insertPath(Path<V, A> *a)
{
    Path<V, A> *temp = lastPath();
    
    if(temp == NULL)
    {
        edges = a;
    }
    else
    {
        temp->setNext(a);
    }
}

template <typename V, typename A>
ostream & operator << (ostream & os, Scene<V, A> & v)
{
	//os << "Scene : " << v.leyend << endl;
    
    //Print outgoing edges
    
    Path<V, A> *temp = v.edges;
    
    cout << "Paths going out: " << endl;
    while(temp != NULL)
    {
        os << *temp;
        temp = temp->getNext();// o getNext()
    }
    
    os << endl;
    
    return os;
}


#endif /* defined(__Vertex__) */
