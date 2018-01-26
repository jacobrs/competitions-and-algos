#ifndef INTERVIEWS_SINGLY_LINKED_LIST_H
#define INTERVIEWS_SINGLY_LINKED_LIST_H

#include "node.h"

class SinglyLinkedList{
private:
    Node * root;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void addElement(int val);
    int popElement();
    void printList();
    int size();
};

#endif
