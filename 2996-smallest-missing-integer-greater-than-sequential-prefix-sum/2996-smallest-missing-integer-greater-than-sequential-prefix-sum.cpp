class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        int sum = nums[0];
        int n = nums.size();
        if(n == 1)return nums[0] + 1;
        for(int i = 1; i < nums.size(); i++){
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