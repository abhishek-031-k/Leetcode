class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for (int x : nums)freq[x]++;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (k < 2 && freq[k] == 0) {
                k++;
            }
            nums[i] = k;
            freq[k]--;
        }
    }
};