//
// Created by Harrison on 1/4/2024.
//

#ifndef RSEMS_LIST_H
#define RSEMS_LIST_H


#include <iostream>
#include "Node.h"

using std::cout;
using std::cin;

template<class T>
class List {
private:
    Node <T> *first;
    Node <T> *last;
    int numElements;

public:
    List();

    List(const List &other);

    bool isEmpty();

    void add(T x);

    void display();

    void insert(T value, int position);

    void remove(int position);

    T get(int position);

    void reverse();

    void copyFrom(const List &other);

    void create(int num);

    void clear();

    ~List();
};

template<class T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
    numElements = 0;
}

template<class T>
bool List<T>::isEmpty() {
    return (first == nullptr);
}

template<class T>
void List<T>::add(T x) {
    Node <T> *temp = new Node<T>(x);

    if (isEmpty())
        first = last = temp;
    else {
        last->setNext(temp);
        last = temp;
    }

    numElements++;
}

template<class T>
void List<T>::display() {
    Node <T> *temp = first;
    int i = 1;

    if (isEmpty()) {
        cout << "The list is empty" << std::endl;
    } else {
        while (temp != nullptr) {
            temp->print();
            temp = temp->getNext();
            i++;
        }
        cout << "NULL" << std::endl;
    }
}

template<class T>
void List<T>::insert(T value, int position) {
    Node <T> *current, *previous, *temp;
    temp = new Node<T>(value);
    int i = 1;
    current = first;

    if (position == 0 || position == 1) {
        first = temp;
        first->setNext(current);
    } else {
        while (i < position) {
            previous = current;
            current = current->getNext();
            i++;
        }

        if (position == numElements) {
            last->setNext(temp);
            last = last->getNext();
        } else {
            temp->setNext(current);
            previous->setNext(temp);
        }
    }

    numElements++;
}

template<class T>
T List<T>::get(int position) {
    Node <T> *temp;
    int i = 1;

    if (position <= numElements) {
        temp = first;
        while (i < position) {
            temp = temp->getNext();
            i++;
        }
    }

    return (temp->getData());
}

template<class T>
List<T>::List(const List &other) {
    Node <T> *temp, *creating;
    temp = other.first;
    first = new Node<T>(temp->getData());
    temp = temp->getNext();
    creating = first;

    while (temp) {
        creating->setNext(new Node<T>(temp->getData()));
        creating = creating->getNext();
        temp = temp->getNext();
    }
}

template<class T>
void List<T>::create(int n) {
    int i = 1;
    int value;

    for (i = 1; i <= n; i++) {
        cout << "Insert the value to add to element " << i << std::endl;
        cin >> value;
        add(value);
    }
}

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
void List<T>::clear() {
    Node <T> *freeing;

    while (first != nullptr) {
        freeing = first;
        first = first->getNext();
        delete freeing;
    }

    first = nullptr;
    last = nullptr;
    numElements = 0;
}

template<class T>
void List<T>::remove(int position) {
    Node <T> *current, *previous;
    int i = 1;
    current = first;

    if (position > numElements) {
        cout << "There are not enough elements in the list" << std::endl;
    } else {
        if (position == 1) {
            first = first->getNext();
        } else {
            while (i < position) {
                previous = current;
                current = current->getNext();
                i++;
            }
            if (numElements == position) {
                last = previous;
                last->setNext(nullptr);
            } else {
                previous->setNext(current->getNext());
            }
        }
        numElements--;
    }
}

template<class T>
void List<T>::reverse() {
    Node <T> *prev = nullptr;
    Node <T> *current = first;
    Node <T> *next;

    while (current != nullptr) {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    first = prev;
}

template<class T>
void List<T>::copyFrom(const List<T> &other) {
    Node <T> *temp;
    temp = other.first;

    while (temp) {
        add(temp->getData());
        temp = temp->getNext();
    }
}


#endif //RSEMS_LIST_H




