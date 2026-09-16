class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int size = n + m, i = 0, j = 0;
        int prev = 0, curr = 0;
        for (int k = 0; k <= size / 2; k++) {
            prev = curr;
            if (i < n && (j >= m || nums1[i] <= nums2[j]))curr = nums1[i++];
            else curr = nums2[j++];
        }
        if (size % 2 == 0)return (prev + curr) / 2.0;
        return curr;
    }
};