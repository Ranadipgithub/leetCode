class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0; 

        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        int x = 0, y = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) { 
                d = (d + 1) % 4;
            } else if (cmd == -2) { 
                d = (d + 3) % 4;
            } else { 
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + directions[d].first;
                    int ny = y + directions[d].second;
                   
                    if (obstacleSet.find(to_string(nx) + "," + to_string(ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        break; 
                    }
                }
            }
        }

        return maxDistSq;
    }
};