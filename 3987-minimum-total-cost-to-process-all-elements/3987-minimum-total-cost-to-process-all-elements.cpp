class Solution {
public:
    int mod = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k) {
        int resourcesleft = k, count = 0;
        for (auto &it : nums) {
            if (resourcesleft >= it)resourcesleft -= it;
             else {
                int required = it - resourcesleft;
                int need = (required + k - 1) / k;
                count = (count + need) % mod;
                resourcesleft = need * k - required;
            }
        }
        return (1LL * count * (count + 1) / 2) % mod;
    }
};