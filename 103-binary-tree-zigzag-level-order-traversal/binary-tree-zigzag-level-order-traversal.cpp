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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (!root)
            return ans;
        q.push(root);
        int counter = 1;
        while (!q.empty()) {
            vector<int> store;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                store.push_back(top->val);
                if (top->left != NULL)
                    q.push(top->left);
                if (top->right != NULL)
                    q.push(top->right);
            }
            if (counter % 2 == 0) {
                reverse(store.begin(), store.end());
            }
            ans.push_back(store);
                    counter++;

        }

        return ans;
    }
};