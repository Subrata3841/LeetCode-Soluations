class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0)return 0;
        int left=0, right=0, sum = 0, count = 0; 
        while(right < nums.size()){
            sum += nums[right];
            while(sum > goal){
                sum = sum - nums[left];
                left = left + 1;
            }
            count = count + (right - left + 1);
            right = right + 1;
        }
        return count;
    }

int numSubarraysWithSum(vector<int>& nums, int goal){
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
};