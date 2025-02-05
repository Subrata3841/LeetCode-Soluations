class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hm;
        int maxi = 0,  sum = 0;
        for(int i=0;i<nums.size();i++){
            if(hm.find(nums[i]) != hm.end()){
                hm[nums[i]]++;
            }else{
                hm.insert({nums[i], 1});
            }
            maxi = max(maxi, hm[nums[i]]);
        }
        for(auto &pair : hm){
            if(pair.second == maxi){
                sum += pair.second;
            }
        }

        return sum;
    }
};