#pragma once

#include <sys/types.h>
#include <string>

#define POOLSIZE 32

using namespace std;

//Used to create a linked list node of next memory location
struct FreeStore {
	FreeStore *next;
};

template<typename T>
class IMemoryManager {
public:
	virtual void *allocate(size_t) = 0;

	virtual void free(void *) = 0;
};

template<typename T>
class MemoryManager : public IMemoryManager {
public:
	MemoryManager() {
		freeStoreHead = nullptr;
		expandPoolSize();
	}

	virtual ~MemoryManager() {
		cleanUp();
	}

	virtual void *allocate(size_t size) {
		if (freeStoreHead == nullptr)
			expandPoolSize();

		FreeStore *head = freeStoreHead;
		freeStoreHead = head->next;
		return head;
	}

	virtual void free(void *ptr) {
		FreeStore *head = static_cast<FreeStore *>(ptr);
		head->next = freeStoreHead;
		freeStoreHead = head;
	}

private:

	void expandPoolSize() {
		size_t size = (sizeof(T) > sizeof(FreeStore *)) ? sizeof(T) : sizeof(FreeStore *);

		FreeStore *head = reinterpret_cast<FreeStore *>(new char[size]);
		freeStoreHead = head;

		for (int i = 0; i < POOLSIZE; i++) {
			head->next = reinterpret_cast<FreeStore *>(new char[size]);
			head = head->next;
		}

		head->next = nullptr;
	}

	void cleanUp() {
		FreeStore *nextPtr = freeStoreHead;
		for (; nextPtr; nextPtr = freeStoreHead) {
			freeStoreHead = freeStoreHead->next;
			delete[] nextPtr;
		}
	}

	FreeStore *freeStoreHead;
};