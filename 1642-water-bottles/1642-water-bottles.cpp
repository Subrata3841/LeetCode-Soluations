class Solution {
public:
    int numWaterBottles(int n, int ex, int empty=0) {
        
        if(n<=0) return 0 ;
        return n + numWaterBottles((empty+n)/ex, ex, (empty+n)%ex);
    }
};