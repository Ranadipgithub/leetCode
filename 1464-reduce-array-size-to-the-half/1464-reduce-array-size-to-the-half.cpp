class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mpp;
        for(int i = 0;i<n;i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }
        int cnt = 0;
        int freq = 0;
        while(!pq.empty()){
            int el = pq.top().second;
            freq += pq.top().first;
            pq.pop();
            cnt++;
            if((n - freq) <= n/2){
                return cnt;
            }
        }
        return -1;
        // int n = arr.size();
        // map<int, int> freq;
        // for (int num : arr) {
        //     freq[num]++;
        // }

        // vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        // sort(freqVec.begin(), freqVec.end(), [](pair<int, int> a, pair<int, int> b) {
        //     return a.second > b.second;  
        // });

        // int cnt = 0;
        // int removed = 0;
        // for (auto& p : freqVec) {
        //     removed += p.second;
        //     cnt++;
        //     if((n - removed) <= n/2) break;
            
        // }
        // return cnt;
        
        // set<int> st;
        // for(int i = 0;i<n;i++){
        //     st.i
        // }
        // for(int i = 0;i<n;i++){
        //     if((n-fq[i]) < n/2){
        //         cnt++;
        //         break;
        //     }
        //     cnt++;
        // }
    }
};