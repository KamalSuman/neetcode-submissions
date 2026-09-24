class DSU {
    int n;
    vector<int> par;
    vector<int> sz;
    public:
    DSU(int n){
        this->n = n;
        par.resize(n);
        for(int i = 0; i<n; i++) par[i] = i;
        sz.resize(n,1);
    }
    int find(int x){
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool uni(int u, int v){
        int u1 = find(u);
        int v1 = find(v);
        if(u1 == v1) return false;
        if(sz[u1] < sz[v1]) swap (u1,v1);
        par[v1] = u1;
        sz[u1] += sz[v1];
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU ds(n);
        vector<vector<int>> v;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back({dist, i , j});
            }
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0; i<v.size(); i++){

            int wt = v[i][0];
            int u1 = v[i][1];
            int u2 = v[i][2];
            // cout << true << " ";
            if(ds.uni(u1,u2)) {
                // cout << false << " ";
                ans += wt;
            }
        }
        return ans;
    }
};
