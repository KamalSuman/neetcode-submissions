class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int num: nums) m[num]++;
        vector<pair<int,int>> v1;
        for(auto m1: m ){
            v1.push_back({m1.second, m1.first});
        }
        sort(v1.begin(), v1.end());
        reverse(v1.begin(),v1.end());
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(v1[i].second);
        }
        return ans;
    }
};
