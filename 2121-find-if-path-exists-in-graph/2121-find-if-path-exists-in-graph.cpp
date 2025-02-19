class Solution {
public:
   bool bfsTraversal(vector<vector<int>>& adj, int source, int destination, vector<int>& vis) {
        queue<int> q;
        vis[source] = true;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
           if(node == destination)return true;

            for (int e : adj[node]) {
                if (!vis[e]) {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
            vector<int> vis(n, false);
            return bfsTraversal(adj, source, destination, vis);
        

    }
};