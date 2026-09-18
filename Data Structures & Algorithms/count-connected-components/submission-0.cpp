class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<int>& vis){
        vis[i] = true;
        for(auto& child: graph[i]){
            if(vis[child]) continue;
            dfs(graph,child,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]) {
                ans++;
                dfs(graph, i, vis);
            }
        }
        return ans;
    }
};
