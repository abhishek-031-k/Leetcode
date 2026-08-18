class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i = 0; i < n; i++)mpp[nums[i]]++;

        if(k == 1) {
            int ans = -1;
            for(auto it : mpp) {
             if(it.second == 1)
            ans = max(ans, it.first);
            }
            return ans;
        }

        if(k == n)return *max_element(nums.begin(), nums.end());
        int ans = -1;
        if(mpp[nums[0]] == 1)ans = max(ans, nums[0]);
        if(mpp[nums[n - 1]] == 1)ans = max(ans, nums[n - 1]);
        return ans;
    }
};