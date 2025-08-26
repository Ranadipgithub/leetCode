class Solution {
public:
    double calDiag(int a, int b){
        return sqrt(1.0 * a * a + 1.0 * b * b); 
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea = INT_MIN;
        double maxi = -1; 

        for(auto &d : dimensions){
            int l = d[0];
            int w = d[1];
            double diag = calDiag(l, w);

            if (diag > maxi) { 
                maxi = diag;
                maxarea = l * w;
            } 
            else if (abs(diag - maxi) < 1e-9) { 
                maxarea = max(maxarea, l * w);
            }
        }
        return maxarea;
    }
};