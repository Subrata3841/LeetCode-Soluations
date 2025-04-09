class Solution {
public:
    int climbStairs(int n) {
        //----------Using recursion------
        /*if (n == 0) return 1;
        if (n < 0) return 0; 
       return climbStairs(n-1)+ climbStairs(n-2);*/
       //----------using dp----------
       if(n == 0)return 1;
        if(n == 1)return 1;
       vector<int> dp(n+1, 0);
       dp[0] = 1;
       for(int i=1;i<=n;i++){
        if(i-1 >=0)dp[i] += dp[i - 1];
        if(i-2 >=0)dp[i] += dp[i - 2];
       }
       return dp[n];
    }
};