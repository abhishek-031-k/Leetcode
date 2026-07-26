// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int ans1 = nums[0]*nums[1]*nums[n-1];
//         int ans2 = nums[n-1]*nums[n-2]*nums[n-3];
//         return max(ans1, ans2);
//     }
// };

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int maxi = INT_MIN, maxi1 = INT_MIN, maxi2 = INT_MIN;
       int mini = INT_MAX, mini1 = INT_MAX;
       for(auto &it: nums){
        if(it >= maxi){
            maxi2 = maxi1;
            maxi1 = maxi;
            maxi = it;
        }
        else if(it >= maxi1){
            maxi2 = maxi1;
            maxi1 = it;
        }
        else if(it >= maxi2)maxi2 = it;

         if(it <= mini){
            mini1 = mini;
            mini = it;
        }
        else if(it <= mini1)mini1 = it;
       }
       int ans1 = mini * mini1 * maxi;
       int ans2 = maxi * maxi1 * maxi2;
       return max(ans1, ans2);
    }
};