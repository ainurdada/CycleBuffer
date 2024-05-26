#pragma once

template <typename T>
class CycleBuffer {
public:
	CycleBuffer(int capacity);
	void Push(T* pItem);
	T* Pop();

private:
	T* buffer_;
	int capacity_;
	int size_;
	int head_;
	int tail_;
};

#include "CycleBuffer.hpp"


