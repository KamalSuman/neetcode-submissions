class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        bool f = true;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) f = false;
            }
        }
        if(f) return 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz){
                vector<int> point = q.front();
                q.pop();
                for(auto &d:dir){
                    int x = point[0] + d[0];
                    int y = point[1] + d[1];
                    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                }
                sz--;
            }
            ans++;
        }
        ans--;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) ans = -1;
            }
        }
        return ans;
    }
};
