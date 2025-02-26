class Solution {
public:
    bool dfsrec(int s, vector<bool>& vis, vector<bool>& dfsvisited, vector<vector<int>>& graph, 
    vector<bool>& presentCycle){
        vis[s] = true;
        dfsvisited[s] = true;

        vector<int> data = graph[s];
        for(auto x: data){
            if(!vis[x]){
                if(dfsrec(x, vis, dfsvisited, graph, presentCycle)){
                    return presentCycle[s] = true;
                }
            }else if(vis[x] && dfsvisited[x]){
                return presentCycle[s] = true;
            }
        }
        dfsvisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<bool> vis(n, false), dfsvisited(n, false);
        vector<bool> presentCycle(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsrec(i, vis, dfsvisited, graph, presentCycle);
            }
        }
        for(int i=0;i<n;i++){
            if(!presentCycle[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};