class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp = triangle[m - 1];
        //int sum = 0;
        for(int i= m - 2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                //triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
    return dp[0];
    }
};