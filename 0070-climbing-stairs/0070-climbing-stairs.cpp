class Solution {
public:
    int climbStairs(int n) {
        //Bottom-Up Approach
        if(n == 0)return 1;
        if(n == 1)return 1;
        vector<int>dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i - 1]+dp[i - 2];
        }
        return dp[n];
      /*  //Space reduction approach
        if(n <= 1)return 1;
        int a = 1;
        int b = 1;
        int c = 0;
        for(int i=2;i<=n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;*/
    }
};