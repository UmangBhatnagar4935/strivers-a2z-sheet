#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution{
    public:
   // case - 1 findout the insection point of the linkedList
   Node* FDL(Node* head){
   if(head==NULL){
       return head;
   }
   Node* slow=head;
   Node* fast=head;
   while(fast!=NULL&&slow!=NULL){
       fast=fast->next;
       if(fast!=NULL){
           fast=fast->next;
             slow=slow->next;
       }
      
       if(slow==fast){
         return slow;  
       }
   }
   return NULL;
}

    // case - 03 - find out the first node of the likendlist 
    Node* getFirstNode(Node* head){

    if(head==NULL)
        return head;
    Node* slow=head;
        // find out the meeting point both of node slow and fast 
    Node* intersection=FDL(head);
    if(intersection==NULL){
        return NULL;
    }
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
    }

   // case 3- startind ->next == NUllpter set karna hai
   void removeLoop(Node* head){   
        if(head==NULL)
            return;

        Node* start = getFirstNode(head);

        if(start==NULL){
            return;
        }

        Node* temp=start;
        while(temp->next!=start){
        temp=temp->next;
        }
        temp->next=NULL;
    }
};
    

