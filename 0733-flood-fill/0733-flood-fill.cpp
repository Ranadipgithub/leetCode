class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        int orig = image[sr][sc];

        if (orig == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir: directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || image[nx][ny] != orig) continue;
                if(image[nx][ny] == orig){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};