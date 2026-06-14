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
    // x axis -2 -1 0 1 2
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        // root
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            // node->n  v->x level ->y
            TreeNode* n = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(n->val);
            if (n->left) {
                q.push({n->left, {x - 1, y + 1}});
            }
            if (n->right) {
                q.push({n->right, {x + 1, y + 1}});
            }

        }

        vector<vector<int>>ans;
        for(auto  it: nodes ){
            vector<int>col;
            for(auto q: it.second){

             col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};