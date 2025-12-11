class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> mppx, mppy;

        for (auto &it : buildings) {
            int x = it[0], y = it[1];
            mppx[x].insert(y);
            mppy[y].insert(x); 
        }

        int cnt = 0;
        for (auto &it : buildings) {
            int x = it[0], y = it[1];
            int miniy = *mppx[x].begin();
            int maxiy = *mppx[x].rbegin();
            
            int minix = *mppy[y].begin();
            int maxix = *mppy[y].rbegin();
            if ((y > miniy && y < maxiy) &&
                (x > minix && x < maxix))
                cnt++;
        }

        return cnt;
    }
};