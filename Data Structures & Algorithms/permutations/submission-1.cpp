class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& nums, vector<int>& res, int bits){
        for(int i = 0; i<nums.size(); i++){
            if(((bits >> i) & 1)) continue;
            res.push_back(nums[i]);
            help(nums,res, bits|(1<<i) );
            res.pop_back();
        }
        if(res.size() == nums.size()) ans.push_back(res);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int bits = 0;
        help(nums,res,0);
        return ans;
    }
};
