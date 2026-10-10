class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        int freetime = INT_MIN, count = 0;
        for(auto &it : intervals){
            if(freetime <= it[0]){
                count++;
                freetime = it[1];
            }
        }
        return intervals.size() - count;
    }
};