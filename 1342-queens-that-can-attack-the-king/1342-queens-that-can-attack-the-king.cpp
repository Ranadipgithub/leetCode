class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 1}, {1, 0}, {1, -1},
                                   {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<vector<int>> st(queens.begin(), queens.end());
        vector<vector<int>> res;
        for (auto dir : directions) {
            int x = king[0], y = king[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                x += dir[0];
                y += dir[1];
                if (st.count({x, y})) {
                    res.push_back({x, y});
                    break;
                }
            }
        }
        return res;
    }
};
