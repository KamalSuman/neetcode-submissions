class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n,0);
        vector<pair<int,int>> v;
        v.push_back({temp.back(),n-1});
        for(int i = n-2; i>=0; i--){
            while(!v.empty() && temp[i] >= v.back().first) {
                v.pop_back();
            }
            if(!v.empty()) res[i] = v.back().second;
            v.push_back({temp[i],i});
        }
        for(int i = 0; i<n; i++){
            if(res[i] == 0) continue;
            res[i] = res[i] - i;
        }
        return res;
    }
};
