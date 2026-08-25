class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto it: nums)st.insert(it);
        int count = 1;
        while(true){
            int num = k * count;
            if(!st.count(num)) return num;
            count++;
        }
        return -1;
        
    }
};