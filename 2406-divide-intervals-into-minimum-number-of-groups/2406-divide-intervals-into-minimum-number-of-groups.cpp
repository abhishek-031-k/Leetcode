class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
       vector<int>left, right;
       for(auto &it: intervals){
        left.push_back(it[0]);
        right.push_back(it[1]);
       }
       sort(left.begin(), left.end());
       sort(right.begin(),right.end());
       int count = 0, i = 0, j = 0, temp = 0;
       while(i < n && j < n){
        if(left[i] <= right[j]){
            temp++;
            i++;
        }
        else {
            temp--;
            j++;
        }
        count = max(count, temp);
       }
       return count;
    }
};