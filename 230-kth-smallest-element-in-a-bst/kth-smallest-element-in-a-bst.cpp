/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // void inorder( TreeNode* root, vector<int>&ans){
    //     if(!root)return;
    //     //inorder-> lnr
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);

    // }
    // optimizeeeeeeeeeeeeeeeeee sochoooo

    void find(TreeNode* root, int &ans, int &k) {
        if (!root || k <= 0) {
            return;
        }
        find(root->left, ans, k);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        return find(root->right, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        find(root, ans, k);

        return ans;
    }
};