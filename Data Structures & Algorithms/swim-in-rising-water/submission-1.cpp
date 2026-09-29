class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> val(n,vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                val[i][j] = INT_MAX;
            }
        }
        val[0][0] = grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            int sz = pq.size();
            for(int i = 0; i<sz; i++){
                vector<int> node = pq.top();
                pq.pop();
                int wt = node[0];
                int l = node[1];
                int r = node[2];
                for(auto d: dir){
                    int p = l + d[0];
                    int q = r + d[1];
                    if(p < 0 || q < 0 || p >= n || q >= m || val[p][q] <= wt + grid[p][q]) continue;
                    val[p][q] = max(wt , grid[p][q]);
                    pq.push({val[p][q], p, q});
                }
            }
        }
        return val[n-1][m-1];
    }
};
