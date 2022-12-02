// =================================================================
//
// File: pqueue.h
// Author: Pedro Perez
// Description: This file contains the implementation of TDA Priority
//							Queue.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef PQUEUE_H
#define PQUEUE_H

#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"
#include "queue.h"
#include "heap.h"

template <class T> class PriorityQueue;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous;
	Node<T> *next;



	friend class PriorityQueue<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val)
	: value(val), previous(0), next(0) {}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {}

// =================================================================
// Definition of the PriorityQueue class
// =================================================================
template <class T>
class PriorityQueue : public Queue<T>{
private:
	Node<T> *head;
	Node<T> *tail;

public:
	PriorityQueue();
	~PriorityQueue();

	void push(T); //TO DO #1
	void pop();   //TO DO #2
	T top() const; //TO DO #3
	bool empty() const; //TO DO #4
	void clear();
	int Size();  //TO DO #5
	std::string toString() const;
};

	// =================================================================
	// Constructor. Initializes both instance variables to NULL.
	// =================================================================
template <class T>
PriorityQueue<T>::PriorityQueue()
	: head(NULL), tail(NULL) {}

// =================================================================
// Destructor. Remove all items from the PriorityQueue.
// =================================================================
template <class T>
PriorityQueue<T>::~PriorityQueue() {
	clear();
}


// =================================================================
// TO DO #5: EMPTY
// COMPLEXITY: O(1)
// 
// Returns whether the queue is empty or not.
//
// @return true if head and tail are NULL, false otherwise.
// =================================================================
template <class T>
bool PriorityQueue<T>::empty() const {
	return (head == NULL && tail == NULL);
}

// =================================================================
// TO DO #1: PUSH
// COMPLEXITY: O(n)
//
// Add an item at the end to the queue.
//
// @param val, the value to put in the position referenced by tail.
// =================================================================
template <class T>
void PriorityQueue<T>::push(T val) {
	Node<T> *p, *q, *new_link;

	new_link = new Node<T>(val);
	if (empty()) {
		head = new_link;
		tail = new_link;
		return;
	}

	if (val <= head->value) {
		new_link->next = head;
		head->previous = new_link;
		head = new_link;
		return;
	}

	if (val >= tail->value) {
		new_link->previous = tail;
		tail->next= new_link;
		tail = new_link;
		return;
	}

	p = head;
	while (p != NULL){
	 	if (p->value >= val) {
			break;
		}
		p = p->next;
	}

	q = p->previous;
	new_link->next = p;
	new_link->previous = q;

	q->next = new_link;
	p->previous = new_link;
}

// =================================================================
// TO DO #3: TOP
// COMPLEXITY: O(1) 
// 
// Returns the item at the front of the queue.
//
// @return the item at the position referenced by head.
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
T PriorityQueue<T>::top() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

// =================================================================
// TO DO #2: POP
// COMPLEXITY: O(1)
// 
// Removes the item at the front of the queue.
//
// @throw NoSuchElement, when the queue is empty
// =================================================================
template <class T>
void PriorityQueue<T>::pop() {
	Node<T> *p;
	
	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	} else {
		head = p->next;
		p->next->previous = NULL;
	}
	delete p;
}

// =================================================================
// Removes all items from the queue.
// =================================================================
template <class T>
void PriorityQueue<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	head = NULL;
	tail = NULL;
}

// =================================================================
// Returns the string representation of the elements on the queue.
//
// @return an string with the representation of the queue.
// =================================================================
template <class T>
std::string PriorityQueue<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != NULL) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}


#endif /* PQUEUE_H */
