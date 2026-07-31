class Solution {
public:
    vector<vector<int>> dp;
    bool help(int idx, vector<int>& nums, int target){
        if(idx >= nums.size() ){
            if(target > 0) return false;
            else return true;
        }
        if(target == 0) return true;
        if(dp[idx][target] != -1) return dp[idx][target];
        bool ans = help(idx + 1, nums, target);
        if(target - nums[idx] >= 0) {
            ans = ans | help(idx +1, nums, target - nums[idx]);
        }
        return dp[idx][target] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2) return false;
        int target = sum/2;
        dp.resize(n,vector<int>(target+1,-1));
        return help(0, nums, target);
    }
};
