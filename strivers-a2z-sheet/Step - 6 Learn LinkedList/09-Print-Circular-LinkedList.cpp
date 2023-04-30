#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

// Circular Linkedlsit 
void printList(struct Node *head)
{
  // code here
   Node * temp = head;
   
   while(temp->next != head){
       cout << temp->data << " ";
       temp = temp->next;
   }
   cout << temp->data;
}
