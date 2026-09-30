class Solution {
public:
    vector<int> findOrder(int nums, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> g(nums);
        vector<int> indegree(nums,0);
        int n = pre.size();
        for(int i = 0; i<n; i++){
            g[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i<nums; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                int node = q.front();
                q.pop();
                for(auto &child: g[node]){
                    indegree[child]--;
                    if(indegree[child] == 0) {
                        q.push(child);
                        ans.push_back(child);
                    }
                }
            }
        }
        for(int i = 0; i<nums; i++){
            if(indegree[i]!=0) return {};
        }
        return ans;
    }
};
