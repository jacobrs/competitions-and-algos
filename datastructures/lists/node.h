#ifndef INTERVIEWS_NODE_H
#define INTERVIEWS_NODE_H

class Node {
private:
    Node * next;
    int data;

public:
    Node(int val);
    Node *getNext();
    int getValue();
    void setNext(Node * n);
    ~Node();
};

#endif
