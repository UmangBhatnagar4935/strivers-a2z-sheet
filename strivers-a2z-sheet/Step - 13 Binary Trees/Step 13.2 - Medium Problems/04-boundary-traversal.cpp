#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}




class Solution {
public:
    // case - 1 print the all left nodes,but not include leaf node 
    void leftcall(Node * root, vector<int> & arr){
        
        // if root is null
        if(root == nullptr)
           return;
        
        // avoid leaf nodes, we will print in future 
        if(root->left == nullptr && root->right == nullptr)
        return;
        
        arr.push_back(root->data);
        
        if(root->left){
            leftcall(root->left,arr);
        }else{
            leftcall(root->right,arr);
        }
    }
    // case -2 print the all leaves node 
    void printleafs(Node * root, vector<int> & arr){
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr)
        arr.push_back(root->data);
        
        printleafs(root->left,arr);
        printleafs(root->right,arr);
    }
    // case - 3 print the right nodes but not include leaf node
    void rightcall(Node * root, vector<int> & arr){
        // if root is null
        if(root == nullptr)
           return;
        
        // avoid leaf nodes, we will print in future 
        if(root->left == nullptr && root->right == nullptr)
        return;
        
        if(root->right) 
            rightcall(root->right,arr);
        else
           rightcall(root->left,arr);
         
        arr.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> result;
        result.push_back(root->data);
        
        leftcall(root->left,result);
        printleafs(root->left,result);
        printleafs(root->right,result);
        rightcall(root->right,result);
        
        return result;
    } 
};



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}