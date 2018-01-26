class Node {
private:
    Node * next;
    int data;

public:
    explicit Node(int val){
        next = nullptr;
        data = val;
    }

    Node *getNext(){
        return next;
    }

    int getValue(){
        return data;
    }

    void setNext(Node * n){
        next = n;
    }

    ~Node(){
        delete next;
    }
};

class SinglyLinkedList {
private:
    Node * root;

public:
    SinglyLinkedList(){
        root = nullptr;
    }

    void addElement(int val){
        Node *tail = root;
        while(tail->getNext() != nullptr){
            tail = tail->getNext();
        }

        tail->setNext(new Node(val));
    }

    void popElement(){
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
    }
};