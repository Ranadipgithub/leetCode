class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int>mpp;
        for(int i = 0;i<n;i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto it : mpp) {
            pq.push({it.second, it.first});
        }
        string str = "";
        while(!pq.empty()){
            int fq = pq.top().first;
            char charac = pq.top().second;
            pq.pop();
            for(int i = 0;i<fq;i++){
                str += charac;
            }
        }
        return str;
    }
};