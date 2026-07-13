class Solution {
public:
    vector<vector<int>> dp;
    int help(int i, vector<int> &nums, bool flag){
        if(i >= nums.size()) return 0;
        if(dp[flag][i] != -1) return dp[flag][i];
        if(i == nums.size() - 1 && flag) return 0;
        return dp[flag][i] = max(nums[i]+help(i+2,nums,i==0?true:flag), help(i+1,nums,flag));
    }
    int rob(vector<int>& nums) {
        bool flag = false;
        dp.resize(2,vector<int>(nums.size(),-1));
        return help(0, nums, false);
    }
};
