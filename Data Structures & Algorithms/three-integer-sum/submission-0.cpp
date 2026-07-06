class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            for(int j = i + 1; j < n; j++){
                int y = nums[j];
                int z = -1 * (x + y);
                int k = lower_bound(nums.begin() + j + 1, nums.end(), z) - nums.begin();
                if( k == n) continue;
                else if(z == nums[k]) {
                    ans.insert({x,y,z});
                }
            }
        }
        vector<vector<int>> ans1;
        for(auto &s: ans){
            ans1.push_back(s);
        }
        return ans1;
    }
};
