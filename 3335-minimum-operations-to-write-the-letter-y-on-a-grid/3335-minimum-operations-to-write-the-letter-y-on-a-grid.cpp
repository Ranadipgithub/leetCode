class Solution {
public:
    int minimumOperationsToWriteY(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int y0 = 0, y1 = 0, y2 = 0;
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isY = (i < n / 2 && (i == j || i + j == n - 1)) ||
                           (i >= n / 2 && j == n / 2);

                int val = grid[i][j];
                if (val == 0) {
                    c0++;
                    if (isY) y0++;
                } else if (val == 1) {
                    c1++;
                    if (isY) y1++;
                } else {
                    c2++;
                    if (isY) y2++;
                }
            }
        }

        int cost01 = (y1+y2) + (c0-y0) + (c2-y2);
        int cost02 = (y1 + y2) + ((c0 - y0) + (c1 - y1)); // A=0, B=2
        int cost10 = (y0 + y2) + ((c1 - y1) + (c2 - y2)); // A=1, B=0
        int cost12 = (y0 + y1) + ((c0 - y0) + (c2 - y2)); // A=2, B=1
        int cost20 = (y0 + y1) + ((c1 - y1) + (c2 - y2)); // A=2, B=0
        int cost21 = (y0 + y2) + ((c0 - y0) + (c1 - y1)); // A=1, B=2

        return min({cost01, cost02, cost10, cost12, cost20, cost21});
    }
};
