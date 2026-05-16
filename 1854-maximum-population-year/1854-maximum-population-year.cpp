class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> events;
        for(auto &log: logs){
            events.push_back({log[0], +1});
            events.push_back({log[1], -1});
        }
        sort(events.begin(), events.end());
        int maxi = INT_MIN, maxYear = 1940;
        int curr = 0;
        for(auto &event: events){
            curr += event.second;
            if(curr > maxi){
                maxi = curr;
                maxYear = event.first;
            }
        }
        return maxYear;
    }
};