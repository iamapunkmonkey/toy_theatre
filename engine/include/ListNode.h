#pragma once

template<typename T>
class ListNode {
public:
	T value;
	ListNode *next, *prev;

	ListNode(T obj) {
		value = obj;
		next = nullptr;
		prev = nullptr;
	}
};