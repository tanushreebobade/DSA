class Solution {
private:
    bool dfs(int node, vector<int> adj[],
             vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[adjacentNode]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
          if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false; // cycle found
            }
        }

        return true; // no cycle
    }
};