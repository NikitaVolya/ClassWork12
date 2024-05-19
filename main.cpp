
#include <iostream>

template <typename T>
class Queue
{
private:
	T* elements;
	size_t capacity;
	size_t first = 3;
	size_t next = 3;
	bool over = false;
	size_t number;
public:
	Queue() : elements(nullptr), capacity(0), number(0) {};
	Queue(size_t pSize) : elements(new T[pSize]), capacity(pSize), number(0) {};
	~Queue();

	T& top() { return elements[first]; }

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
		if (i)
		out << elements[i];
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

int main()
{
	Queue<int> testQ(10);

	testQ.push(1);
	testQ.push(2);
	testQ.push(3);
	testQ.push(4);
	testQ.push(5);
	testQ.push(6);
	testQ.push(7);
	testQ.push(8);
	testQ.push(9);
	testQ.push(10);
	testQ.pop();
	testQ.push(11);
	std::cout << testQ << std::endl;

	return 0;
}


