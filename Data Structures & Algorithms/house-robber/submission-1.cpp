class Solution {
public:
    vector<int> dp;
    int help(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans, max(nums[i] + help(nums, i+2), help(nums, i+1))); 
        return dp[i] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return help(nums,0);
    }
};
