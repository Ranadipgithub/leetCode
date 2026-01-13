class Solution {
public:
    bool isPossible(double mid, vector<vector<int>>& squares) {
        double upperArea = 0, lowerArea = 0;

        for (auto &it : squares) {
            double y = it[1];
            double l = it[2];
            double top = y + l;

            if (mid <= y) {
                upperArea += l * l;
            } else if (mid >= top) {
                lowerArea += l * l;
            } else {
                double up = top - mid;
                double down = mid - y;
                upperArea += l * up;
                lowerArea += l * down;
            }
        }
        return upperArea <= lowerArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        for (auto &it : squares) {
            low = min(low, (double)it[1]);
            high = max(high, (double)it[1] + it[2]);
        }

        double ans = high; 

        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2.0;
            
            if (isPossible(mid, squares)) {
                ans = mid;
                high = mid;
            } else {
                low = mid; 
            }
        }
        return ans;
    }
};