#include <bits/stdc++.h>
using namespace std;

struct linkNode
{
    int data;
    linkNode *prev;
    linkNode *next;
};

linkNode *head = NULL;
linkNode *tail = NULL;

void RemoveNodeBindings(linkNode *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }

    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    node->prev = NULL;
    node->next = NULL;
}

void RemoveElement(int data)
{
    linkNode *node = head;
    while (node != NULL && node->data != data)
    {
        node = node->next;
    }
    if (node != NULL)
    {
        if (node == head)
        {
            head = head->next;
        }
        if (node == tail)
        {
            tail = tail->prev;
        }
        RemoveNodeBindings(node);
    }
    else
        cout << "Element not found to remove!";
}

bool ContainsNodeWithValue(int value)
{
    linkNode *node = head;
    while (node != NULL && node->data != value)
    {
        node = node->next;
    }
    return (node != NULL);
}

void InsertAfterTail(int data)
{
    linkNode *tempNode;
    tempNode = new linkNode();
    tempNode->data = data;
    if (head == NULL && tail == NULL)
    {
        tempNode->prev = NULL;
        tempNode->next = NULL;
        head = tail = tempNode;
        return;
    }
    else
    {
        tail->next = tempNode;
        tempNode->next = NULL;
        tempNode->prev = tail;
        tail = tempNode;
        return;
    }
}

void InsertBeforeHead(int data)
{
    linkNode *tempNode;
    tempNode = new linkNode();
    tempNode->data = data;
    if (head == NULL && tail == NULL)
    {
        tempNode->prev = NULL;
        tempNode->next = NULL;
        head = tail = tempNode;
        return;
    }
    else
    {
        head->prev = tempNode;
        tempNode->next = head;
        tempNode->prev = NULL;
        head = tempNode;
        return;
    }
}

print()
{
    linkNode *a = head;
    linkNode *b = tail;
    cout << "From head: ";
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n"
         << "From tail: ";
    while (b != NULL)
    {
        cout << b->data << " ";
        b = b->prev;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        //InsertBeforeHead(x);
        InsertAfterTail(x);
    }
    print();
    int s;
    cout << "\n"
         << "Enter value to search: ";
    cin >> s;
    bool contain = ContainsNodeWithValue(s);
    if (contain)
        cout << "Node found with entered value!"
             << "\n";
    else
        cout << "Node not found with entered value!"
             << "\n";

     int r;
     cout << "Enter the value you want to remove: ";
     cin >> r;
     RemoveElement(r);
     cout << "Nodes after remove an elements: " << "\n";
     print();
    return 0;
}
