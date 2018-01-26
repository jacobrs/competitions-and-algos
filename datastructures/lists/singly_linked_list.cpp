#include <iostream>
#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList(){
    root = nullptr;
}

SinglyLinkedList::~SinglyLinkedList(){
    delete root;
}

void SinglyLinkedList::addElement(int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    Node *tail = root;

    while(tail->getNext() != nullptr){
        tail = tail->getNext();
    }

    tail->setNext(new Node(val));
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

int SinglyLinkedList::size(){
    Node * tail = root;
    int size = 0;
    while(tail != nullptr){
        tail = tail->getNext();
        size++;
    }

    return size;
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
    l->addElement(3);
    l->addElement(4);
    l->addElement(5);

    l->printList();

    std::cout << l->popElement() << std::endl;

    l->printList();
    std::cout << l->size() << std::endl;

    delete l;
    return 0;
}