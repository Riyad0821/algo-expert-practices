#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int value);
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail: NULL;
    }

    void setHead(Node* node) {
        if(head == NULL){
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    void setTail(Node* node){
        if(tail == NULL){
            setHead(node);
            return;
        }
        insertAfter(tail, node);
    }

    void insertBefore(Node* node, Node* nodeToInsert) {
        if(nodeToInsert == head && nodeToInsert == tail) return;
        remove(node)
    }
};
