#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into the queue and mark their distance as 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Step 2: Define 4 possible movements (up, right, down, left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Step 3: Perform BFS
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // Check if within bounds and if a shorter path is found
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && dist[nrow][ncol] == INT_MAX){
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return dist;
    }
};
