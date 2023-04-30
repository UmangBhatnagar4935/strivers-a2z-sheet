//{ Driver Code Starts
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

// print the Linked List 
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 

class Solution{
  public:
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node* temp = new Node(x);
       
       temp->next = head;
       head = temp;
       return temp;
    }
    

    Node *insertAtEnd(Node *head, int x)  {
        
        // English - appraoch 
      /* a) create a new node
         b) if head is null then offcourse you can print the newnode 
         c) tersal unitl then last node then
         d ) conncect the new node 
         e) return head: starting node of likenlist;
        
      */
     Node * newnode = new Node(x);
     
        if(head == NULL){
            return newnode;
        }
        
        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        
        last->next = newnode;
        return head;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            Solution obj;
            if(indicator)
                head = obj.insertAtEnd(head, data); 
            else
                head = obj.insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 

