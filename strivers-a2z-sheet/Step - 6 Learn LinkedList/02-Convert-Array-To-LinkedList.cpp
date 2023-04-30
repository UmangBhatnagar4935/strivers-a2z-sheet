#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


/*

1 - firstofall, aap ek node bano 
2 - useke agae next array ke element ko add kar do 

simple hai Questions )

*/


class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node * head = new Node(arr[0]);
        Node * temp = head; // save rahega head mera staring of the likedlist
        
        for(int i = 1; i<arr.size(); i++){
            Node * newNode = new Node(arr[i]);
            // basically temp ke next me newnode set kar di
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}
