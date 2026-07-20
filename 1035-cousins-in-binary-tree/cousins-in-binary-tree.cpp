/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode* root, int x, int l){
        if(!root) return -1;
        if( root ->val == x) return l;
        int left  = level(root ->left,x,l+1);
        if(left!= -1)return left;
        
        return level(root->right,x,l+1);

    }

    TreeNode* parent(TreeNode* root, int x){
        if(!root )return NULL;
        if((root->left && root->left->val ==x)||(root->right && root->right->val ==x))
        return root;
        TreeNode* left = parent(root->left,x);
        if(left)return left;
        return parent(root->right,x);
        

    }
    bool isCousins(TreeNode* root, int x, int y) {
        return level(root, x,0)==level(root,y,0) && parent(root,x)!= parent(root,y);
    }
};