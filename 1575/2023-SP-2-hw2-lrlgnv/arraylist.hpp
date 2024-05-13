// Programmer:	Logan Lorts
// Section:	102
// Student ID:	12580684
// Date:	3/6/2023
// File:	arraylist.hpp

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
void ArrayList<T>::grow()
{
    T *tmp = new T[m_max * 2];
    for (int i = 0; i < m_max; i++)
    {
        tmp[i] =  m_data[i];
    }
    delete [] m_data;
    m_data = tmp;
    m_max *= 2;
}

template <typename T>
void ArrayList<T>::shrink()
{
    T *tmp = new T[m_max/2];
    for(int i = 0; i < m_max/2; i++)
    {
        tmp[i] = m_data[i];
    }
    delete [] m_data;
    m_data = tmp;
    m_max /= 2;
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
    m_errobj = 0;
    m_size = s;
    m_max = s;
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = x;
    }
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete [] m_data;
    m_max = m_size = 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &rhs)
{
    m_data = new T[rhs.m_max];
    for (int i = 0; i < rhs.m_max; i++)
    {
        m_data[i] = rhs.m_data[i];
    }
    m_size = rhs.m_size;
    m_max = rhs.m_max;

    return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
    m_data = new T[cpy.m_max];
    for (int i = 0; i < cpy.m_max; i++)
    {
        m_data[i] = cpy.m_data[i];
    }
    m_size = cpy.m_size;
    m_max = cpy.m_max;
}

template <typename T>
int ArrayList<T>::size() const
{
    return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
    if (m_size ==0)
    {
        cout << "!!! ERROR : ARRAYLIST.function() !!! " << endl;
        return m_errobj;
    }
    else 
    {
        return m_data[0];
    }
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
    if (i > m_size)
    {
        cout << "!!! ERROR : ARRAYLIST.function() !!! " << endl;
        return m_errobj;
    }
    else
    {
        return m_data[i];
    }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
    if (i > m_size)
    {
        cout << "!!! ERROR : ARRAYLIST.function() !!! " << endl;
        return m_errobj;
    }
    else
    {
        return m_data[i];
    }
}

template <typename T>
int ArrayList<T>::search(const T& x) const
{
    for (int i = 0; i < m_size; i++)
    {
        if (m_data[i] == x)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
    delete [] m_data;
    m_data = new T[4];
    m_size = 0;
    m_max = 4;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
    insert(x, m_size);
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
    if(i > m_size)
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.insert() (index out of bounds)" << endl;
    }
    else
    {
        for (int z = m_size; z > i; z--)
        {
            m_data[z] = m_data[z-1];
        }
        m_data[i] = x;
        m_size = m_size +1;
        if (m_size == m_max)
        {
            grow();
        }
    }
}

template <typename T>
void ArrayList<T>::remove(int i)
{
    if (i > m_size)
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.remove() (index out of bounds)" << endl;
    }
    else
    {
        for(int y = i; y < m_size - 1; y++)
        {
            m_data[y] = m_data[y+1];
        }
        m_size = m_size - 1;
        if (m_size < (m_max/4))
        {
            shrink();
        }
    }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
    if( i > m_size || k > m_size)
    {
        cout << "!!! ERROR : PANIC in ARRAYLIST !!!.swap() (index out of bounds)" << endl;
    }
    else
    {
    T tmp = m_data[k];
    m_data[k] = m_data[i];
    m_data[i] = tmp;
    }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
    int new_size = m_size + alist.size();
    T *tmp = new T[new_size];

    for (int i = 0; i < m_size; i++)
    {
        tmp[i] = m_data[i];
    }
    for (int i =0; i < alist.size(); i++)
    {
        tmp[i + m_size] = alist[i];
    }
    delete [] m_data;
    m_data = tmp;
    m_size += alist.size();
    m_max += alist.size();
}

template <typename T>
void ArrayList<T>::reverse()
{
    for(int i = 0; i < (m_size/2); i++)
    {
        swap(i, (m_size-i));
    }
}

#endif