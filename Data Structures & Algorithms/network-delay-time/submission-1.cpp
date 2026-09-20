class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+2);
        for(int i = 0; i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> res(n+2);
        for(int i = 1; i<=n; i++) res[i] = INT_MAX;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        res[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto q = pq.top();
            pq.pop();
            int time = q.first;
            int node = q.second;
            for(auto& [child,wt]: graph[node]){
                if(res[child] > time + wt) {
                    res[child] = time + wt;
                    pq.push({res[child], child});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i<=n; i++){
            ans = max(ans, res[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
