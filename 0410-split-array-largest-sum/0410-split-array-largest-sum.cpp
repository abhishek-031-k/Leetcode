class Solution {
public:
    int solve(int mid, vector<int>&nums){
        long long count = 1, sum = 0;
        for(auto &it: nums){
            if(it + sum <= mid)sum += it;
            else {
                count++;
                sum = it;
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(high >= low){
            int mid = low + (high - low)/2;
            if(solve(mid, nums) > k)low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};