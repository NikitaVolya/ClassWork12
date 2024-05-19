#pragma once

#include <iostream>

template <typename T>
class Queue
{
private:
	T* elements;
	size_t capacity;
	size_t first = 0;
	size_t next = 0;
	bool over = false;
	size_t number;
public:
	Queue(size_t pSize) : elements(new T[pSize]), capacity(pSize), number(0) {};
	~Queue();

	T& front() { return elements[first]; }
	T& back() { return elements[next - 1 < 0 ? capacity - 1 : next - 1]; }

	void pop();
	void push(const T& pValue);

	std::ostream& debugPrint(std::ostream& out) const;
	std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Queue& queue)
	{
		queue.print(out);
		return out;
	}
};

template<typename T>
Queue<T>::~Queue()
{
	if (elements)
		delete[] elements;
}

template<typename T>
void Queue<T>::pop()
{
	first++;
	number--;
	if (first == capacity)
	{
		over = true;
		first = 0;
	}
}

template<typename T>
void Queue<T>::push(const T& pValue)
{
	if (capacity == number || !elements)
		throw std::out_of_range("owerflow");

	elements[next++] = pValue;
	number++;

	if (next == capacity)
	{
		over = true;
		next = 0;
	}
}

template<typename T>
std::ostream& Queue<T>::debugPrint(std::ostream& out) const
{
	for (int i = 0; i < capacity; i++)
	{
		out << elements[i] << ", ";
	}
	return out;
}

template<typename T>
std::ostream& Queue<T>::print(std::ostream& out) const
{
	for (int i = 0; i < number; i++)
	{
		int index = first + i;
		if (index >= capacity)
			index -= capacity;
		out << elements[index] << ", ";
	}
	return out;
}