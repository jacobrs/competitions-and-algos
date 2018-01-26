#include <iostream>
#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList(){
    root = nullptr;
}

void SinglyLinkedList::addElement(int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    Node *tail = root;
    Node *prev = nullptr;

    while(tail != nullptr){
        prev = tail;
        tail = tail->getNext();
    }

    tail = new Node(val);
    if(prev != nullptr){
        prev->setNext(tail);
    }
}

int SinglyLinkedList::popElement(){
    Node *tail = root;
    Node *prev = nullptr;

    while(tail->getNext() != nullptr){
        prev = tail;
        tail = tail->getNext();
    }

    int val = tail->getValue();
    delete tail;
    if(prev != nullptr){
        prev->setNext(nullptr);
    }

    return val;
}

void SinglyLinkedList::printList(){
    Node * curr = root;
    while(curr != nullptr){
        std::cout << curr->getValue() << " ";
        curr = curr->getNext();
    }
    std::cout << std::endl;
}

int main(){
    auto *l = new SinglyLinkedList();

    l->addElement(1);
    l->addElement(2);

    l->printList();

    std::cout << l->popElement() << std::endl;

    l->printList();

    delete l;
    return 0;
}