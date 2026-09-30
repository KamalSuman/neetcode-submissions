class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                vector<int> node = q.front();
                q.pop();
                for(auto &d: dir){
                    int r = node[0] + d[0];
                    int s = node[1] + d[1];
                    if(r < 0 || s < 0 || r >= n || s >=m || grid[r][s] != 2147483647) continue;
                    q.push({r,s});
                    grid[r][s] = grid[node[0]][node[1]] + 1;
                }
            }
        }
    }
};
