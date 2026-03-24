class Solution {
public:
    bool check(vector<int>& temp){
        vector<int> actual = {1, 2, 3, 4, 5, 0};
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != actual[i]) return false;
        }
        return true;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> nums(6);
        int k = 0;
        int idx = -1;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0) idx = k;
                nums[k++] = board[i][j];
            }
        }

        unordered_map<int, vector<int>> mpp;
        mpp[0] = {1, 3};
        mpp[1] = {0, 2 ,4};
        mpp[2] = {1, 5};
        mpp[3] = {0, 4};
        mpp[4] = {1, 3, 5};
        mpp[5] = {2, 4};

        queue<pair<vector<int>, int>> q;
        q.push({nums, idx});

        map<pair<vector<int>, int>, int> visited;
        visited[{nums, idx}] = 1;

        int moves = 0; 

        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int> temp = q.front().first;
                int index = q.front().second;
                q.pop();

                if(check(temp)) return moves;

                for(auto it: mpp[index]){ 
                    vector<int> t = temp;
                    swap(t[index], t[it]);

                    if(!visited[{t, it}]){
                        visited[{t, it}] = 1;
                        q.push({t, it});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};