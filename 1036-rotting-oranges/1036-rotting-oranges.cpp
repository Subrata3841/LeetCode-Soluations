class Solution {
public:
bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid){
    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
        return true;
    }
    return false;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        //int vis[n][m];
        int fresh = 0,  time = 0;;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)fresh++;
            }
        }
        if(fresh == 0)return 0;

        //BFS traversal
        while(!q.empty()){
            int size = q.size();
            int temp = 0;
           while( size != 0){
            pair<int, int> p = q.front();
            q.pop();

            int x1 = p.first;
            int x2 = p.second;
            
            int a1[4] = {1, -1, 0, 0};
            int a2[4] = {0, 0, -1, 1};

            for(int i=0;i<4;i++){
                int x = a1[i] + x1;
                int y = a2[i] + x2;

                if(isValid(x, y, n, m, grid)){
                    temp++;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            size--;
           }
            if(temp != 0) time++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    time = 0;
                    break;
                }
            }
        }
        return (time == 0)? -1:time;
    }
};