#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    void setTail(Node *node)
    {
        if (tail == NULL)
        {
            setHead(node);
            return;
        }
        insertAfter(tail, node);
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->next = node;
        nodeToInsert->prev = node->prev;
        if (node->prev == NULL)
        {
            head = nodeToInsert;
        }
        else
        {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;
    }

    //O(1) time | O(1) space

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (node->next == NULL)
        {
            tail = nodeToInsert;
        }
        else
        {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    //O(p) time | O(1) space

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        if (position == 1)
        {
            setHead(nodeToInsert);
            return;
        }
        Node *node = head;
        int currentPosition = 1;
        while (node != NULL && currentPosition++ != position)
            node = node->next;
        if (node != NULL)
        {
            insertBefore(node, nodeToInsert);
        }
        else
        {
            setTail(nodeToInsert);
        }
    }

    //O(n) time | O(1) space

    void removeNodeWithValue(int value)
    {
        Node *node = head;
        while (node != NULL)
        {
            Node *NodeToRemove = node;
            node = node->next;
            if (NodeToRemove->value == value)
            {
                remove(NodeToRemove);
            }
        }
    }

    //O(1) time | O(1) space

    void remove(Node *node)
    {
        if (node == head)
            head = node->next;
        if (node == tail)
            tail = node->prev;
        removeNodeBindings(node);
    }

    //O(n) time | O(1) space

    bool containsNodeWithValue(int value)
    {
        Node *node = head;
        while (node != NULL && node->value != value)
            node = node->next;
        return node != NULL;
    }

    void removeNodeBindings(Node *node)
    {
        if (node->prev != NULL)
            node->prev->next = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
        node->prev = NULL;
        node->next = NULL;
    }

    void print()
    {
        Node *node = head;
        while (node != NULL)
        {
            cout << node->value << " ";
            node = node->next;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    DoublyLinkedList list;
    Node *node1 = new Node(1);
    list.setHead(node1);
    Node *node2 = new Node(2);
    list.setTail(node2);
    Node *node3 = new Node(3);
    list.insertBefore(node1, node3);
    Node *node4 = new Node(4);
    list.insertAfter(node3, node4);
    Node *node5 = new Node(5);
    list.setTail(node5);
    list.setTail(node4);
    list.setHead(node4);
    list.insertAtPosition(2, node5);
    list.remove(node1);
    list.removeNodeWithValue(2);
    bool a = list.containsNodeWithValue(1);
    cout << a << endl;
    list.print();
    return 0;
}
