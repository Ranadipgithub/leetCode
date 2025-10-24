class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        int m = rectangles[0].size();

        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;
        long long area = 0;
        unordered_set<string> stt;

        for (auto& it : rectangles) {
            x1 = min(x1, it[0]);
            y1 = min(y1, it[1]);
            x2 = max(x2, it[2]);
            y2 = max(y2, it[3]);

            vector<string> corners = {
                to_string(it[0]) + "_" + to_string(it[1]),
                to_string(it[2]) + "_" + to_string(it[3]),
                to_string(it[0]) + "_" + to_string(it[3]),
                to_string(it[2]) + "_" + to_string(it[1])
            };

            for (auto& s : corners) {
                if (stt.count(s))
                    stt.erase(s);
                else
                    stt.insert(s);
            }

            area += 1LL * (it[2] - it[0]) * (it[3] - it[1]);
        }

        long long boundingArea = 1LL * (x2 - x1) * (y2 - y1);

        return stt.size() == 4 &&
               stt.count(to_string(x1) + "_" + to_string(y1)) &&
               stt.count(to_string(x1) + "_" + to_string(y2)) &&
               stt.count(to_string(x2) + "_" + to_string(y1)) &&
               stt.count(to_string(x2) + "_" + to_string(y2)) &&
               area == boundingArea;
    }
};