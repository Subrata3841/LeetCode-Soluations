class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        int maxi = INT_MIN;
        unordered_set<char> EleFind;
        int left = 0;

        for(int right = 0;right<s.size();right++){
            while(EleFind.find(s[right]) != EleFind.end()){
                EleFind.erase(s[left]);
                left++;
            }
            EleFind.insert(s[right]);
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};