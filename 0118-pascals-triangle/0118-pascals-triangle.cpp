class Solution {
public:
    vector<int> pascelTriangle(int n) {
        int a = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col = 1;col<n;col++){
            a = a * (n - col) / col;
            ansRow.push_back(a);
        }
        return ansRow;
    }
   vector<vector<int>> generate(int numRows){
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(pascelTriangle(i));
        }
        return ans;
    }
};