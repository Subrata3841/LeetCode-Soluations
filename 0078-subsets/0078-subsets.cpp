class Solution {
private:
    list<list<int>> subset(vector<int>& nums){
        list<list<int>> outer;
        outer.push_back({});

        for(int n : nums){
            list<list<int>> temp;
            for(auto& subset : outer){
                list<int> inner = subset;
                inner.push_back(n);
                temp.push_back(inner);
            }
            outer.splice(outer.end(), temp); //splice->for tranfer one list to another
        }
        return outer;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        list<list<int>> outer = subset(nums);
        vector<vector<int>> res;

         for (const auto& lst : outer) {
            vector<int> temp(lst.begin(), lst.end());
            res.push_back(temp);
        }

        return res;
    }

    
};