#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node* head;
    head = new Node;
    head -> data = 30;
    head -> next = NULL;
    cout << head -> data << endl;
}