class Solution {
public:
bool dfsrec(int i, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj){
    if(vis[i] == 1) return true;
    if(vis[i] == 2) return false;
    vis[i] = 1;
    for(int e: adj[i]){
        if (dfsrec(e, st, vis, adj)) return true;
    }
     vis[i] = 2; // Mark as processed
     st.push(i);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        stack<int> s;
        vector<int> vis(numCourses, 0);

        for(int i=0;i<numCourses;i++){
           if(vis[i] == 0){
                if(dfsrec(i, s, vis, adj)){
                    return {};
                }
        }
        }

        vector<int> res;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            res.push_back(x);
        }
        return res;
    }
};