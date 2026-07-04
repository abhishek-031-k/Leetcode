class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
         int temp = nums[n/2];
        for(int i = 0; i < n; i++){
            if(nums[i] == temp && i != n/2)return false;
        }
        return true;
    }
};