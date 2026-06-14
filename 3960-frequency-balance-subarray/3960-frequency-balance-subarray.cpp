class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        for(int i = 0;i<n;i++){
            unordered_map<int, int> fq;
            unordered_map<int, int> fq_cnt;
            for(int j = i;j<n;j++){
                int oldf = fq[nums[j]];
                fq[nums[j]]++;
                if(oldf > 0){
                    fq_cnt[oldf]--;
                    if(fq_cnt[oldf] == 0){
                        fq_cnt.erase(oldf);
                    }
                }
                fq_cnt[oldf+1]++;
                if(fq.size() == 1){
                    maxi = max(maxi, j-i+1);
                    continue;
                }
                if(fq_cnt.size() > 2) continue;
                if(fq_cnt.size() == 1) {
                    if(fq.size() == 1){
                        maxi = max(maxi, j-i+1);
                    }
                    continue;
                }
                auto it = fq_cnt.begin();
                int first = it->first;
                ++it;
                int second = it->first;
                if(first == 2*second || second == 2*first){
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};