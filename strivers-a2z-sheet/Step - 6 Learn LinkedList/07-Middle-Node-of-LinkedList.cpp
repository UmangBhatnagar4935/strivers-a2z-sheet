

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


/*
Apporach-1 - using findout the lenght of the linked lsit and divide the length
Appraoch-2 - using slow and fast Algoritm 

slow = one step run 
fast = two step run 

*/


class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node * slow = head;
        Node * fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // we want to print actual data of the node 
        return slow->data;
    }
};



