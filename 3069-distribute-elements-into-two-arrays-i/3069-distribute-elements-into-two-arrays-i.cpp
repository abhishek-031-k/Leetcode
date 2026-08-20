class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size(), last1 = nums[0], last2 = nums[1];
        vector<int>ans1, ans2;
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
           if(ans1.back() > ans2.back())ans1.push_back(nums[i]);
           else ans2.push_back(nums[i]);
        }
        for(auto &it: ans2)ans1.push_back(it);
        return ans1;
    }
};