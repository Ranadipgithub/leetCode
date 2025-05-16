class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int color, int initial){
        int n = image.size();
        int m = image[0].size();
        if(i<0 || i>=n || j<0 || j>=m || image[i][j] != initial){
            return;
        }
        image[i][j] = color;
        dfs(image, i+1, j, color, initial);
        dfs(image, i-1, j, color, initial);
        dfs(image, i, j+1, color, initial);
        dfs(image, i, j-1, color, initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initial = image[sr][sc];
        if(initial == color) return image;
        dfs(image, sr, sc, color, initial);
        return image;
    }
};