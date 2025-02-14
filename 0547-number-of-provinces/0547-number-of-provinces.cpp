class Solution {
public:
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& vis){
    vis[node] = true;
    for(int i: adjList[node]){
        if(!vis[i]){
            dfs(i, adjList, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    //adjList[j].push_back(i);
                }
            }
        }
        vector<bool> vis(isConnected.size(), false);
        int count = 0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i] == false){
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};