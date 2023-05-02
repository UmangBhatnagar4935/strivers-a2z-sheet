//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
//Function to remove duplicates from sorted linked list.


/*

TC- 0(N) 
if list ki node, list next node ke sath same hai
if(curr->data == curr->next->data){
    remove the duplicate node
    link to next node 
    curr->next = curr->next->next;
}


*/
Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node * curr = head;
    
    while(curr != nullptr){
        if(curr->next != nullptr && curr->data == curr->next->data){
            Node * deleteNode = curr->next;
            Node * nextNode = curr->next->next;
            delete(deleteNode);
            curr->next = nextNode;
        }else{
            curr = curr->next;
        }
    }
    return head;
}