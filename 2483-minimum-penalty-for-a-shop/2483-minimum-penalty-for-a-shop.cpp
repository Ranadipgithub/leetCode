class Solution {
public:
    int bestClosingTime(string customers) {
        int totYes = 0, totNo = 0;
        int n = customers.size();
        for(char ch: customers){
            if(ch == 'Y') totYes++;
            else totNo++;
        }
        if(totYes == n) return n;
        if(totNo == n) return 0;
        vector<int> preYes(n, 0);
        vector<int> preNo(n, 0);
        preYes[0] = customers[0] == 'Y';
        preNo[0] = customers[0] == 'N';
        for(int i = 1;i<n;i++){
            preYes[i] = preYes[i-1] + (customers[i] == 'Y');
            preNo[i] = preNo[i-1] + (customers[i] == 'N');
        }

        int ans = n;
        int minPenalty = INT_MAX;
        for(int i = 0;i<=n;i++){
            int penalty = i > 0? preNo[i-1]: 0;
            int rem = totYes - (i > 0? preYes[i-1]: 0);
            penalty += rem;
            if(penalty < minPenalty){
                minPenalty = penalty;
                ans = i;
            }
        }
        return ans;
    }
};