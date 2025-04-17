class Solution {
public:
void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& vis){
    vis[i] = true;
    for(int j=0;j<isConnected.size();j++){
        if(!vis[j] && isConnected[i][j] == 1){
            dfs(isConnected, j, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(isConnected, i, vis);
            }
        }
        return count;
    }
};