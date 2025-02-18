class Solution {
public:
    bool isValid(vector<vector<int>>& image, int sr, int sc, int n, int m, int color){
        if(sr>=0 && sr<n && sc>=0 && sc<m && image[sr][sc] == color){
            return true;
        }
        return false;
    }
    void dfsTraversal(vector<vector<int>>& image, int sr, int sc,int n, int m, int color, int newColor){
        image[sr][sc] = newColor;

        if(isValid(image, sr+1, sc, n, m, color)){
            dfsTraversal(image, sr+1, sc, n, m, color, newColor);
        }
        if(isValid(image, sr-1, sc, n, m, color)){
            dfsTraversal(image, sr-1, sc, n, m, color, newColor);
        }
        if(isValid(image, sr, sc+1, n, m, color)){
            dfsTraversal(image, sr, sc+1, n, m, color, newColor);
        }
        if(isValid(image, sr, sc-1, n, m, color)){
            dfsTraversal(image, sr, sc-1, n, m, color, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int newColor = image[sr][sc];
        if(color == newColor){
            return image;
        }
        dfsTraversal(image, sr, sc,n, m, newColor, color);
        return image;
    }
};