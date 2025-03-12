class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> arr(3, -1);
        int count = 0;
        for(int right=0;right<n;right++){
            arr[s[right] - 'a'] = right;
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                count += (1 + min({arr[0], arr[1], arr[2]}));
            }
        }
        return count;
    }
};