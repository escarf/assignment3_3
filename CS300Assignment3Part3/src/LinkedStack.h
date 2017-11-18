/*
* LinkedStack.h
*
*  Created on: Oct 28, 2017
*      Author: escarf
*/

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class LinkedStack {
	node<T> *top;
public:
	//provide function prototypes for a Stack here
	LinkedStack();
	bool isEmpty();
	void push(T&);
	T pop();
	T stop();
	void destroy();
	void copy(LinkedStack<T>&);
	~LinkedStack();
	template <class U>
	friend ostream& operator<<(ostream& os, LinkedStack<U>& stack);
	int size();

};
//provide function implementations here

template <class T>
LinkedStack<T>::LinkedStack() {
		top = NULL;
}

template <class T>
bool LinkedStack<T>::isEmpty() {
	return top == NULL;
}

template <class T>
void LinkedStack<T>::push(T& item) {

	node<T> *newnode = new node<T>;
	newnode->data = item;

	if (top == NULL) {
		top = newnode;
		top->next = NULL;
	}

	else {
		newnode->next = top;
		top = newnode;
	}

}

template <class T>
T LinkedStack<T>::pop() {

	if (!isEmpty()) {
		T result = top->data;

		// only 1 node
		if (top->next == NULL) {
			delete top;
			top = NULL;

		}

		// more than 1 node
		else {
			node<T>* p = top;
			top = top->next;
			result = p->data;
			delete p;

		}
		return result;
	}

}

template <class T>
T LinkedStack<T>::stop() {
	if (!isEmpty()) {
		return top->data;
	}
}

template <class T>
void LinkedStack<T>::destroy() {
	node<T> *p;
	while (top != NULL) {
		p = top;
		top = top->next;
		delete p;
	}

}

template <class T>
LinkedStack<T>::~LinkedStack() {
	destroy();
}

template <class T>
void LinkedStack<T>::copy(LinkedStack<T>& other) {
	// empties current list
	destroy();

	// if other is empty, this should just be empty as well
	if (other.isEmpty()) {
		return;
	}

	else {
		node<T> *p = other->top; // for passing over other stack
		node<T> *q;	// for passing over this stack

		while (p != NULL) {
			if (isEmpty()) {
				node<T> *newnode = new node<T>;
				top = newnode;
				q = top;
				continue;
			}

			q->data = p->data;
			if (p->next == NULL) {
				return;
			}
			node<T> *temp = new node<T>;
			q->next = temp;

			p = p->next;
			q = q->next;

		}
	}
}


template <class T>
ostream& operator<<(ostream& os, LinkedStack<T>& stack) {
	if(stack.isEmpty()) {
		return os;
	}
	node<T>* print = stack.top;

	while (print!= NULL) {
		os << print->data << " ";
		print = print->next;
	}
	return os;
}
template <class T>
int LinkedStack<T>::size() {
	if(isEmpty()) {
		return 0;
	}

	node<T> *p = top;
	int count = 1;

	while (p->next!= NULL) {
		p = p->next;
		count++;
	}
	return count;

}

#endif /* LINKEDSTACK_H_ */
