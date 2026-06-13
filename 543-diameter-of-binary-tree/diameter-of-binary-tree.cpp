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

    int maxd(TreeNode* root, int &maxi){
        if(root==NULL)return 0;
        int lh = maxd(root->left,maxi);
        int rh = maxd(root->right,maxi);
        maxi = max(lh +rh , maxi);
        return max(lh , rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;

        maxd(root,maxi);
        return maxi;
    }
};