class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count1 = 0, count2 = 0, count3 = 0;

        for(auto &it : stones) {
            if(it % 3 == 1) count1++;
            else if(it % 3 == 2) count2++;
            else count3++;
        }

        if(count3 % 2 == 0) {
            return count1 > 0 && count2 > 0;
        }

        return abs(count1 - count2) > 2;
    }
};