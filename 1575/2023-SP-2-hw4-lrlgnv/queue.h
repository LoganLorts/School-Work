#ifndef QUEUE_H
#define QUEUE_H

#include "abstractqueue.h"
#include "linkedlist.h"

template <typename T> class 
Queue : public AbstractQueue<T>
{
    public:
        bool isEmpty() const;
        const T &front() const throw(Oops);
        const T &back() const throw(Oops);
        void enqueue(const T &x);
        void dequeue();
        void clear();
    private:
    LinkedList<T> items;
};

#include "queue.hpp"
#endif


