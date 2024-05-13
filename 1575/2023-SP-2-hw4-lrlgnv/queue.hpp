#include "linkedlist.h"

template <typename T>
bool Queue<T>::isEmpty() const
{
    return items.isEmpty();
}

template <typename T> const T&
Queue<T>:: front() const throw (Oops)
{
    if(isEmpty())
    {
        throw Oops("front(): queue is empty");
    }
    return items.getAtPtrCst(0) -> m_data;
}

template <typename T> const T& 
Queue<T>::back() const throw (Oops)
{
    if(isEmpty())
    {
        throw Oops("back(): queue is empty");
    }
    return items.getAtPtrCst(items.size() -1)->m_data;
}

template <typename T>
void Queue<T>::enqueue(const T &x)
{
    items.insert_back(x);
}

template <typename T>
void Queue<T>:: dequeue()
{
    if(items.size())
    {
    items.remove_front();
    }
}

template <typename T>
void Queue<T>::clear()
{
    if(items.size())
    {
    items.clear();
    }
}
