//
//  Node.h
//  Node
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//
#pragma once
template <typename T>
class Node
{
public:
	T value;
	Node *nextNode;
	Node();
	Node(T);
	~Node();
};

template <typename T>
Node<T>::Node()
{
	nextNode = NULL;
}

template <typename T>
Node<T>::Node(T Value)
{
	value = Value;
	nextNode = NULL;
}

template <typename T>
Node<T>::~Node()
{
	nextNode = NULL;
	delete nextNode;
}
