class Solution {
public:
void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
    vis[node] = true;
    for(int i=0;i<isConnected.size();i++){
        if(isConnected[node][i] == 1 && !vis[i]){
            dfs(i, isConnected, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        // vector<int> adj(isConnected.size());
        // for(int i=0;i<isConnected.size();i++){
        //     for(int j=0;j<isConnected.size();j++){
        //         if(isConnected[i][j] == 1 && i != j){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        vector<bool> vis(isConnected.size(), false);
        int count = 0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i] == false){
                count++;
                dfs(i, isConnected, vis);
            }
        }
        return count;
    }
};