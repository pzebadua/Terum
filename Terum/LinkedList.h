//
//  LinkedList.h
//  LinkedList
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//


#pragma once
#include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T> *first;
	int size;
public:
	LinkedList();
	bool isEmpty();
	int getSize();
	Node<T>* getElementAt(int);
	T getValueAt(int);
	void insertFirst(T);
	void insertLast(T);
	void insertAt(int, T);
	void removeFirst();
	void removeLast();
	void removeAt(int);
	void removeAll();
	Node<T>& operator[](int);
	//const Node<T>& operator[](int) const;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	first = NULL;;
	size = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
int LinkedList<T>::getSize()
{
	return size;
}

template <typename T>
Node<T>* LinkedList<T>::getElementAt(int n)
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		Node<T> *temp = first;
		int i = 0;
		while (i < n && temp->nextNode != NULL)
		{
			temp = temp->nextNode;
			i++;
		}
		return temp;
	}
}

template <typename T>
void LinkedList<T>::insertFirst(T value)
{
	Node<T> *newNode = new Node<T>(value);
	newNode->nextNode = first;
	first = newNode;
	size++;
}

template <typename T>
void LinkedList<T>::insertLast(T value)
{
	Node<T> *newNode = new Node<T>(value);
	if (isEmpty())
	{
		first = newNode;
		size = 1;
	}
	else
	{
		Node<T> *temp = getElementAt(size - 1);
		temp->nextNode = newNode;
		size++;
	} 
}

template <typename T>
void LinkedList<T>::insertAt(int n, T value)
{
	Node<T> *element = getElementAt(n);
	Node<T> *temp = element->nextNode;
	Node<T> *newNode = new Node<T>(value);
	element->nextNode = newNode;
	newNode->nextNode = temp;
	size++;
}

template <typename T>
void LinkedList<T>::removeFirst()
{
	removeAt(0);
	size--;
	if (size == 0) { first = NULL; }
}

template <typename T>
void LinkedList<T>::removeLast()
{
	removeAt(size--);
	if (size == 0) { first = NULL; }
}

template <typename T>
void LinkedList<T>::removeAt(int n)
{
	Node<T> *firstNode = getElementAt(n - 1);
	if (firstNode != NULL)
	{
		Node<T> *removedNode = firstNode->nextNode;
		firstNode->nextNode = removedNode->nextNode;
		delete removedNode;
	}
	if (size == 0) { first = NULL; }
}

template <typename T>
void LinkedList<T>::removeAll()
{
	Node<T> *deletedNode = first;
	while (deletedNode != NULL)
	{
		first = deletedNode->nextNode;
		delete deletedNode;
		deletedNode = first;
	}
	first = NULL;
	size = 0;
}

template <typename T>
Node<T>& LinkedList<T>::operator[](int n)
{
	return *getElementAt(n);
}
