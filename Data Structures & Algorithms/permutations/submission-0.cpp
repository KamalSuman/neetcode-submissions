class Solution {
public:
    vector<vector<int>> ans;
    int check(int num, vector<int> &res){
        for(int i = 0; i<res.size(); i++){
            if(res[i] == num) return true;
        }
        return false;
    }
    void help(vector<int>& nums, vector<int>& res){
        for(int i = 0; i<nums.size(); i++){
            if(check(nums[i],res)) continue;
            res.push_back(nums[i]);
            help(nums,res);
            res.pop_back();
        }
        if(res.size() == nums.size()) ans.push_back(res);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        help(nums,res);
        return ans;
    }
};
