/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
     public:
    int height(struct Node* node){
        
        if(node == nullptr){
            return 0;
        }
        
        // left recusive call 
        int left = height(node->left);
        // right recusive call
        int right = height(node->right);
        
        return max(left,right) + 1;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) { 
     
     if(root == nullptr){
         return 0;
     }
     
     int case1 = diameter(root->left);
     int case2 = diameter(root->right);
     
     int case3 = height(root->left) + height(root->right) + 1;
        
     int ans = max(case3, max(case1, case2));
     return ans;
    }
};