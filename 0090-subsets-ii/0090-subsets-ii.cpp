class Solution {
    private:
    list<list<int>> subset(vector<int>& nums){
        list<list<int>> outer;
        outer.push_back({});

        for(int i=0;i<nums.size();i++){
            list<list<int>> temp;
            for(auto& subset: outer){
                 list<int> inner = subset;
                inner.push_back(nums[i]);
                temp.push_back(inner);
            }
            outer.splice(outer.end(), temp); //splice->for tranfer one list to another
        }
        return outer;
        }
public:
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Step 1: Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> res = {{}};
        
        // Step 2: Generate subsets
        int start = 0, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            // If it's a duplicate, adjust the starting index
            if (i > 0 && nums[i] == nums[i - 1]) {
                start = end + 1;
            } else {
                start = 0;
            }
            
            // Update the end index before modifying `res`
            end = res.size() - 1;

            // Add the current number to existing subsets
            for (int j = start; j <= end; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }

        return res;
    }
};