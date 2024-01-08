//
// Created by Harrison on 1/4/2024.
//

#ifndef RSEMS_NODE_H
#define RSEMS_NODE_H


#include <iostream>

template<class T>
class Node {
private:
    T data;
    Node *next;

public:
    Node();

    Node(T data);

    void print();

    void modifyData(T element);

    void modifyNext(Node *n);

    Node &operator=(const Node &p);

    T getData();

    Node *getNext();
};

template<class T>
Node<T>::Node() {
    data = 0;
    next = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}

template<class T>
void Node<T>::print() {
    std::cout << "||" << data << "||" << "->";
}

template<class T>
T Node<T>::getData() {
    return data;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::modifyData(T element) {
    data = element;
}

template<class T>
void Node<T>::modifyNext(Node<T> *n) {
    next = n;
}


#endif //RSEMS_NODE_H
