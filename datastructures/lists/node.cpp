#include "node.h"

Node::Node(int val){
    next = nullptr;
    data = val;
}

Node* Node::getNext(){
    return next;
}

int Node::getValue(){
    return data;
}

void Node::setNext(Node * n){
    next = n;
}

Node::~Node(){
    delete next;
}