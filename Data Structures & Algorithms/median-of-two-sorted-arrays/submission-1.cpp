class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size()) swap(nums1,nums2);
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = n - 1;
        int t = (m+n+1)/2;
        int p = (m+n) % 2;
        while(i <= j){
            int mid = (i+j)/2;
            int l1 = -1, l2 = -1, r1 = 1001, r2 = 1001; l1 = nums1[mid];
            int k2 = t - mid - 1; 
            if(k2>0) l2 = nums2[k2-1];
            if(mid + 1 < n) r1 = nums1[mid+1];
            if( k2 < m) r2 = nums2[k2];
            if(l1 > r2) {
                j = mid - 1;
            }
            else if(l2 > r1) {
                i = mid + 1;
            }
            else{
                return p == 0 ? (max(l1,l2) + min(r1,r2))/2.0 : max(l1,l2);
            }
        }
        return 0;
    }
};
