#pragma once

#include "ListNode.h"

template<typename T>
class List {
public:
	void addNode(T);

	void addNode(T, int);

	void deleteNode(T);

	void deleteNode(int);

	T get(int);

	int count();

	List();

	~List();

	ListNode<T> *start;
};

template<typename T>
List<T>::List() {
	start = nullptr;
}

template<typename T>
List<T>::~List() {
	delete start;
}

template<typename T>
void List<T>::addNode(T obj) {
	ListNode<T> *p, *temp;

	temp = new ListNode<T>(obj);
	if (start == nullptr) {
		temp->prev = nullptr;
		start = temp;
	}
	else {
		p = start;
		while (p->next != nullptr)
			p = p->next;

		p->next = temp;
		temp->prev = p;
	}
}

template<typename T>
void List<T>::addNode(T obj, int pos) {
	if (start == nullptr) {
		addNode(obj);
		return;
	}

	ListNode<T> *temp, *p;
	p = start;

	temp = new ListNode<T>(obj);
	if (pos == 0) {
		temp->next = start;
		temp->next->prev = temp;
		start = temp;
		return;
	}

	for (int i = 0; i < pos - 1; i++) {
		if (p->next == nullptr)
			break;
		p = p->next;
	}

	if (p->next == nullptr) {
		p->next = temp;
		temp->next = nullptr;
		temp->prev = p;
	}
	else {
		temp->next = p->next;
		temp->next->prev = temp;
		p->next = temp;
		temp->prev = p;
	}
}

template<typename T>
void List<T>::deleteNode(T obj) {
	if (start == nullptr)
		return;

	ListNode<T> *temp, *p;

	if (start->value == obj) {
		temp = start;
		start = start->next;
		start->prev = nullptr;
		delete temp;
		return;
	}

	p = start;

	while (p->next->next != nullptr) {
		if (p->next->value == obj) {
			temp = p->next;
			p->next = temp->next;
			temp->next->prev = p;
			delete temp;
			return;
		}
		p = p->next;
	}

	if (p->next->value == obj) {
		temp = p->next;
		delete temp;
		p->next = nullptr;
		return;
	}
}

template<typename T>
void List<T>::deleteNode(int pos) {
	if (start == nullptr)
		return;

	ListNode<T> *temp, *p;

	p = start;

	if (pos == 0) {
		temp = start;
		start = start->next;
		start->prev = nullptr;
		delete temp;
		return;
	}

	p = start;

	for (int i = 0; i < pos - 1; i++) {
		if (p->next == nullptr)
			break;
		p = p->next;
	}

	if (p->next != nullptr) {
		temp = p->next;
		p->next = temp->next;
		temp->next->prev = p;
		delete temp;
		return;
	}
}

template<typename T>
int List<T>::count() {
	ListNode<T> *p = start;

	int count = 0;

	while (p != nullptr) {
		p = p->next;
		count++;
	}

	return count;
}

template<typename T>
T List<T>::get(int pos) {
	if (pos == 0)
		return start->value;

	ListNode<T> *p = start;

	for (int i = 0; i < pos - 1; i++) {
		if (p->next == nullptr)
			return nullptr;
		p = p->next;
	}

	if (p->next != nullptr)
		return p->next->value;
	return nullptr;
}