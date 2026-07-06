class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans(2);
        for(int i = 0; i<n; i++){
            int x = target - numbers[i];
            int j = lower_bound(numbers.begin() + i + 1,numbers.end(), x) - numbers.begin();
            if(j == n) continue;
            else if(numbers[j] == x){
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
        }
        return ans;
    }
};
