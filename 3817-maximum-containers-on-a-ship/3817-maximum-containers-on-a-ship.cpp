class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total = n*n;
        if(total*w > maxWeight){
            return maxWeight/w;
        } else{
            return total;
        }
    }
};