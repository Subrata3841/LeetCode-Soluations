class Solution {
public:
    int countMostk(vector<int>& nums, int k) {
        int left=0, oddCount = 0;
        for(int right = 0;right<nums.size();right++){
            if(nums[right]%2 == 1)k--;
            while(k < 0){
                if(nums[left]%2 == 1)k++;
                left++;
            }
            oddCount += (right - left + 1);
        }
        return oddCount;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countMostk(nums, k) - countMostk(nums, k - 1);
    }
};