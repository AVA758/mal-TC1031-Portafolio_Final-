// =================================================================
// ESTE ES EL CÓDIGO QUE SE NOS PROPORCIONÓ PARA LA ACTIVIDAD 2.2
// SU USO ES EXCLUSIVAMENTE PARA EL FUNCIONAMENTO DE LISTAS DE DOBLE ENLACE
// SE HICIERON MODIFICACIONES COMO LA ELIMINACIÓN DE FUNCIONES NO NECESARIAS PARA EL PROGRAMA
// Y LA ESPECIFIACIÓN DE UN VALOR INT EN VEZ DE UINT
//
// Archivo: list.h
// Autor: 
// Fecha: 18/10/2022
//
// =================================================================
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"

template <class T> class DoubleLinkedList;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    	value;
	Node<T> *previous, *next;

	friend class DoubleLinkedList<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), previous(NULL), next(NULL) {
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {
}

// =================================================================
// Definition of the DoubleLinkedList class
// =================================================================
template <class T>
class DoubleLinkedList {
private:
	Node<T> *head;
	int 		size;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	bool empty() const;

	void clear();
	std::string toString() const;

	void push_front(T);
	void push_back(T);
	
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() :head(NULL), size(0) {
}

// =================================================================
// Destructor. Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

// =================================================================
// Returns if the DoubleLinkedList is empty or not
//
// @returns true if the DoubleLinkedList is empty, false otherwise.
// =================================================================
template <class T>
bool DoubleLinkedList<T>::empty() const {
	return (head == NULL);
}


// =================================================================
// Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}

	head = NULL;
	size = 0;
}

// =================================================================
// String representation of the elements in the DoubleLinkedList.
//
// @returns a string containing all the elements of the DoubleLinkedList.
// =================================================================
template <class T>
std::string DoubleLinkedList<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "";
	while (p != NULL) {
		aux << p->value;
		if (p->next != NULL) {
			aux << " ";
		}
		p = p->next;
	}
	aux << "";
	return aux.str();
}


// =================================================================
// Add an item to the beginning of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_front(T val) {
	Node<T> *q, *p;

	q = new Node<T>(val);
	if (head == NULL) {
		q->next = NULL;
		q->previous = NULL;
	} 
    else {
		p = head;

		q->next = p; // q->next = head;
		q->previous = NULL;

		p->previous = q; //head->previous = q;
	}
	head = q;
	size++;
}

// =================================================================
// Add an item to the end of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_back(T val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	q->previous = p;

	p->next = q;
	size++;
}



#endif /* DoubleLinkedList_H */
