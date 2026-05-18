class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int, int>> events;
        for(auto &it: flowers){
            events.push_back({it[0], 1});
            events.push_back({it[1]+1, -1});
        }
        sort(events.begin(), events.end());
        int curr = 0;
        map<int, int> mpp;
        for(auto &event: events){
            curr += event.second;
            mpp[event.first] = curr;
        }
        for(auto it: mpp) cout << it.first << " " << it.second << endl;
        vector<int> res(people.size());
        for(int i = 0;i<people.size();i++){
            auto it = mpp.lower_bound(people[i]);
            if(it != mpp.end() && it->first == people[i]){
                res[i] = it->second;
            } else if(it != mpp.begin()){
                auto prev_it = prev(it);
                res[i] = prev_it->second;
            } else res[i] = 0;
        }
        return res;
    }
};