class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
       int totalSum = 0;
       for(int i=0;i<n;i++){
        totalSum += cardPoints[i];
       }
       int wSize = n - k;
       int minSub = 0, currsum = 0;

       for(int i=0;i<wSize;i++){
        currsum += cardPoints[i];
       }
       minSub = currsum;

       for(int j=wSize;j<n;j++){
            currsum += cardPoints[j] - cardPoints[j - wSize];
            minSub = min(minSub, currsum);
       }
       return totalSum - minSub;
    }
};