class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& nodes, int& edges) {
        vis[node] = true;
        nodes++;
        edges += adj[node].size();
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, edgesCount = 0;
                dfs(i, adj, vis, nodes, edgesCount);
                if (edgesCount == nodes * (nodes - 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
