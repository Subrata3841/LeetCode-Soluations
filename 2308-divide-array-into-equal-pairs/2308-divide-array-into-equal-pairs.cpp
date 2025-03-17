class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> fr(501, 0);
        for(int num:nums){
            fr[num]++;
        }
        for( int count : fr){
            if(count%2 != 0)return false;
        }
        return true;
    }
};