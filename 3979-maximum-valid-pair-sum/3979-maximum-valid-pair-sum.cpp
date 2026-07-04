class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN, left = INT_MIN;
        for(int j = k; j < n; j++){
            left = max(left, nums[j - k]);
            ans = max(ans, left + nums[j]);
        }

        return ans;
    }
};