class Solution {
public:
    void bfsTraversal(vector<vector<int>>& adj, int i, vector<int>& vis, int& node, int& edge) {
        queue<int> q;
        vis[i] = true;
        q.push(i);
        node = 0;
        edge = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            node++;

            for (int e : adj[x]) {
                edge++;
                if (!vis[e]) {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {  //Loop through all nodes, not edges
            if (!vis[i]) {  // Only start BFS if the node is unvisited
                int node = 0, edge = 0;
                bfsTraversal(adj, i, vis, node, edge);
                if (node * (node - 1) / 2 == edge / 2) {
                    count++;
                }
            }
        }
        return count;
    }
};
