#pragma once

#ifndef CYCLE_BUFFER_HPP
#define CYCLE_BUFFER_HPP

#include "CycleBuffer.h"
#include "iostream"

template<typename T>
inline CycleBuffer<T>::CycleBuffer(int capacity)
{
	buffer_ = malloc(sizeof(T) * capacity);
	capacity_ = capacity;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}

template<typename T>
inline void CycleBuffer<T>::Push(T* pItem)
{
	if (size_ < capacity_)
	{
		head_++;
		if (head_ == capacity_) head_ = 0;
		buffer_[head_] = pItem;
	}
}

template<typename T>
inline T* CycleBuffer<T>::Pop()
{
	if (size_ != 0)
	{
		T* returnValue = buffer_[tail_];
		tail_++;
		if (tail_ == capacity_) tail_ = 0;
		return returnValue;
	}
	else
	{
		return nullptr;
	}
}


#endif // !CYCLE_BUFFER_HPP
