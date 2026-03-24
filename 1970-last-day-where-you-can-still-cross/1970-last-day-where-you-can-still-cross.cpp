class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool dfs(int i, int j, int mid, int row, int col, set<pair<int, int>> &st, vector<vector<int>>& visited){
        if(i < 0 || i >= row || j < 0 || j >= col) return false;
        if(st.count({i, j}) || visited[i][j]) return false;
        if(i == row - 1) return true;
        visited[i][j] = 1;

        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(dfs(newi, newj, mid, row, col, st, visited)) return true;
        }

        return false;
    }

    bool isPossible(int mid, int row, int col, vector<vector<int>>& cells){
        set<pair<int, int>> st;

        for(int i = 0; i <= mid; i++){
            st.insert({cells[i][0] - 1, cells[i][1] - 1});
        }

        vector<vector<int>> visited(row, vector<int>(col, 0));
        for(int j = 0; j < col; j++){
            if(!st.count({0, j}) && dfs(0, j, mid, row, col, st, visited))
                return true;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size() - 1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(mid, row, col, cells)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans + 1;
    }
};