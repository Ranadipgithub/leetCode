class TreeAncestor {
public:
    vector<vector<int>> up;
    int cols;
    TreeAncestor(int n, vector<int>& parent) {
        cols = log2(n) + 1;
        up.assign(n, vector<int>(cols, -1));
        for(int i = 0;i<n;i++){
            up[i][0] = parent[i];
        }
        for(int j = 1;j<cols;j++){
            for(int node = 0;node < n;node++){
                if(up[node][j-1] != -1)
                    up[node][j] = up[up[node][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = cols-1;i>=0;i--){
            if(((1<<i)&k)){
                node = up[node][i];
                if(node == -1) return -1;
            } 
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */