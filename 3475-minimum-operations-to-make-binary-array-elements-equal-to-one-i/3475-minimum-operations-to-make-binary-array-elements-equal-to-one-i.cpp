class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0, count = 0, n = nums.size();
        if(n < 3)return -1;
        for (int i = 0; i <= n - 3; i++) {
            if(nums[i] == 0){
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                count++;
            }
        }

        if(all_of(nums.begin(), nums.end(), [](int x) {return x == 1; })){
            return count;
        }
        return -1;
    }
};