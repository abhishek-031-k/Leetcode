class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0], n = nums.size();
        set<int>st(nums.begin(), nums.end());
        if(n == 1)return nums[0] + 1;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1){
                while(true){
                if(st.count(sum) == 0)return sum;
                else  sum++;
            }
            }
            else sum += nums[i];
        }
        return sum;
    }
};