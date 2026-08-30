class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        int largeidx = -1, smallidx = -1, maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                largeidx = i;
            }
             if(nums[i] < mini){
                mini = nums[i];
                smallidx = i;
            }
        }
         int left = min(largeidx, smallidx);
        int right = max(largeidx, smallidx);

        int ans1 = right + 1;
        int ans2 = n - left;
        int ans3 = (left + 1) + (n - right);
        return min({ans1, ans2, ans3});

    }
};