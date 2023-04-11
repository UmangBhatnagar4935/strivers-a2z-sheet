
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        
        if(root == nullptr) 
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftToright = true;
        
        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size);   

           for(int i =0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();  

                // go the left to right and right to left ) we are finding here ):
                int index = leftToright? i : size-1-i;
                ans[index] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            leftToright = !leftToright;
            v.push_back(ans);
        }
        return v;    
    }
};