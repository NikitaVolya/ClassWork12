#include <list>
#include <iostream>
#include <math.h>

using namespace std;

template <typename T, bool (*greaterThen)(T, T)>
class PriorityQueue
{
private:
    list<T> queue; // queue list
    bool (*prevGreater)(T, T) = greaterThen;
public:
    PriorityQueue() : queue(list<T>())
    {};
    void push(const T& value); // push item to queue back
    void pop(); // remove item from queue top
    T& top(); // return queue top item
    bool empty() const; // if queue is empty
    int size() const; // queue size
    void print() const; // print queue
};

template <typename T, bool (*prevGreater)(T, T)>
void PriorityQueue<T, prevGreater>::push(const T& value)
{
    queue.push_back(value);
    auto it = queue.rbegin();    //    4 5 6 7 8
    while (next(it) != queue.rend())
    {
        if (prevGreater(*next(it), *it))
        {
            swap(*next(it), *it);
        }
        ++it;
    }
}

template <typename T, bool (*prevGreater)(T, T)>
void PriorityQueue<T, prevGreater>::pop()
{
    queue.pop_front();
}

template <typename T, bool (*prevGreater)(T, T)>
T& PriorityQueue<T, prevGreater>::top()
{
    return queue.front();
}

template <typename T, bool (*prevGreater)(T, T)>
bool PriorityQueue<T, prevGreater>::empty() const
{
    return queue.empty();
}

template <typename T, bool (*prevGreater)(T, T)>
int PriorityQueue<T, prevGreater>::size() const
{
    return queue.size();
}

template <typename T, bool (*prevGreater)(T, T)>
void PriorityQueue<T, prevGreater>::print() const
{
    cout << " * ";
    for (T it : queue)
    {
        cout << it.toString();
    }
    cout << endl;
}