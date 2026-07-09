class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = n-1;
        int k = -1;
        while(i<=j){
            int mid = (i+j)/2;
            if(target == matrix[mid][m-1]) {
                return true;
            } else if ( target > matrix [mid][m-1]) i = mid + 1;
            else {
                k = mid;
                j = mid - 1;
            }
        }
        if(k == -1) return false;
        int l = *lower_bound(matrix[k].begin(),matrix[k].end(),target);
        if(l == target) return true;
        return false;
    } 
};
