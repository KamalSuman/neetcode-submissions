class DSU {
    int n;
    vector<int> par;
    vector<int> sz;
    public:
    DSU(int n){
        this->n = n;
        par.resize(n+1,0);
        sz.resize(n+1,0);
        for(int i = 0; i<=n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
     bool Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(int i = 0; i<n; i++){
            if(!dsu.Union(edges[i][0],edges[i][1])) return edges[i];
            cout << 1 << " ";
        }
        return vector<int>();
    }
};
