// Programmer:  Logan Lorts
// Section:     102
// Student ID:  12580684
// File:        linkedlist.hpp

#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete m_head;
}

template <typename T>
const LinkedList<T> &LinkedList<T>::operator = (const LinkedList<T> &rhs)
{
    clear();
    append(rhs);
    return *this;
}

template <typename T>
LinkedList<T>:: LinkedList(const LinkedList<T>& rhs)
{
    m_head = new LLNode<T>;
    m_head ->m_next = NULL;
    m_size = 0;
    *this = rhs;
}

template <typename T> 
int LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    if(m_size <= 0)
    {
        return true;
    }
    return false;
}

template <typename T>
LLNode<T> *LinkedList<T>::getFirstPtr()
{
    if(isEmpty())
    {
        cout << "!!! ERROR : LINKEDLIST.getFirstPtr() !!! (list is empty)" << endl;
        return NULL;
    }
        return m_head;
}

template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i)
{
    LLNode<T> *node = m_head;
    if (i > m_size)
    {
        cout << "!!! ERROR : LINKEDLIST.getAtPtr() !!! (index is out of bounds)" << endl;
        return NULL;
    }
    else
    {
        for(int j = 0; j < i; j++)
        {
            node = node -> m_next;
        }
        return node;
    }
}

template <typename T>
const LLNode<T> *LinkedList<T>::getAtPtrCst(int i) const
{
    const LLNode<T> *node = m_head;
    if (i>m_size)
    {
        return NULL;
    }
    while (i--)
    {
        node = node->m_next;
    }
    return node;
}

template <typename T>
void LinkedList<T>::clear()
{
    while(m_size)
    {
        remove_back();
    }
}

template <typename T>
void LinkedList<T>::insert_front(const T &x)
{
    insert(x, m_head);
}

template <typename T>
void LinkedList<T>::insert_back(const T &x)
{
    LLNode<T> *back = getAtPtr(m_size);
    insert(x, back);
}

template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos)
{
    LLNode<T> *next = new LLNode<T>(pos -> m_data, pos -> m_next);
    pos -> m_data = x;
    pos -> m_next = next;
    m_size = m_size + 1;
}

template <typename T>
void LinkedList<T>::remove_front()
{
    if (m_size <= 0)
    {
        cout << "!!! ERROR : LINKEDLIST.remove_front() !!! (the list is empty)" << endl;
    }
    else
    {
        remove(m_head);
    }
}

template <typename T>
void LinkedList<T>::remove_back()
{
    if (m_size <= 0)
    {
        cout << "!!! ERROR : LINKEDLIST.remove_front() !!! (the list is empty)" << endl;
    }
    else
    {
        remove(getAtPtr(m_size-1));
    }
}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos)
{
    if(m_size <= 0)
    {
        cout << "!!! ERROR : LINKEDLIST.remove() !!! (list is empty)" << endl;
    }

    else
    {
    LLNode<T> *tmp = pos -> m_next;
    pos -> m_data = pos -> m_next -> m_data;
    pos -> m_next = pos -> m_next -> m_next;
    delete tmp;
    m_size = m_size -1;
    }
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
    LLNode<T> *here = m_head;
    LLNode<T> *there = rhs.m_head;
    if (size() == rhs.size())
    {
        while ((here -> m_next != NULL) && (there ->m_next != NULL))
        {
            if (here ->m_data != there -> m_data)
            {
                return false;
            }
            here = here -> m_next;
            there = there -> m_next;
        }
    }
    else
    {
        return false;
    }
    return true;
}

template <typename T>
LLNode<T>* LinkedList<T>::find(const T& x)
{
    for(int i = 0; i < m_size; i++)
    {
        if(getAtPtr(i) -> m_data == x)
        {
            return getAtPtr(i);
        }
    }
    return NULL;
}

template <typename T>
void LinkedList<T>::reverse()
{
    LinkedList<T> reversed;
    LLNode<T> *node = m_head;

    for (int i = 0; i <m_size; i++)
    {
        reversed.insert_front(node -> m_data); 
        node = node -> m_next;   
    }
    *this = reversed;
}

template <typename T>
void LinkedList<T>::purge()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int j = i+1; j < m_size; j++)
        {
            if((getAtPtr(i) -> m_data) == (getAtPtr(j) -> m_data))
            {
                remove(getAtPtr(j));
                j--;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& l2)
{
    LLNode<T> *node = l2.m_head;

    while (node -> m_next != NULL)
    {
        insert_back(node -> m_data);
        node = node -> m_next;
    }
}

template <typename T>
void LinkedList<T>::slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop)
{
    clear();
    LLNode<T> *node = start;
    while (node != stop)
    {
        insert_back(node -> m_data);
        node = node -> m_next;
    }
}

template <typename T>
ostream& operator<< (ostream& out, const LinkedList<T>& list)
{
    LLNode<T> *node = list.m_head;
    out << "[ ";
    while (node -> m_next != NULL)
    {
        out << node -> m_data << ", ";
        node = node -> m_next;
    }
    out << "]";
    return out;
}


