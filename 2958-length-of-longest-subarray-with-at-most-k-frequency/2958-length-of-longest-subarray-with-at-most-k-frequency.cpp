class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int>mpp;
        while(j < nums.size()){
            mpp[nums[j]]++;
                while(mpp[nums[j]] > k){
                    mpp[nums[i]]--;
                    i++;
                }
            ans = max(ans, j-i+1);
             j++;
        }
        return ans;
    }
};