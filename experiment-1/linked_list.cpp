
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *insertAtStart(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

void insertAtEnd(Node *head, int val)
{
    Node *temp = head;

    Node *newNode = new Node(val);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(Node *head, int val)
{
    Node *temp = head;

    if(head == nullptr) return;

    if(head->data == val){
        Node* temp = head;
       head = temp->next;
       delete head;
       return;
    }

    while (temp->next != nullptr)
    {
        if (val == temp->next->data)
        {
            Node *next = temp->next->next;
            delete temp->next;
            temp->next = next;
            break;
        }
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head = insertAtStart(head, 20);
    head = insertAtStart(head, 50);
    insertAtEnd(head, 20);
    deleteNode(head, 50);
    insertAtEnd(head, 30);
    printLL(head);
}