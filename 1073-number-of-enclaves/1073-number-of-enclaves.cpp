class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& m, int& n){
        if(i<0 || i>=m || j<0 || j>=n|| grid[i][j] == 0)return;
        
        grid[i][j] = 0;
        
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //for 1st and last col
        for(int r=0;r<m;r++){
            if(grid[r][0] == 1)dfs(grid, r, 0, m, n);
            if(grid[r][n-1] == 1)dfs(grid, r, n-1, m, n);
        }
        
        //for 1st and lost row
        for(int c=0;c<n;c++){
            if(grid[0][c] == 1)dfs(grid, 0, c, m, n);
            if(grid[m-1][c] == 1)dfs(grid, m-1, c, m, n);
        }
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};