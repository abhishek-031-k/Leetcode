class Solution {
public:
    bool digitCount(string num) {
        map<char, int>mpp;
        for(auto &it : num)mpp[it]++;
        for(int i = 0; i < num.size(); i++){
           if(mpp[i + '0'] != (num[i] - '0'))return false;
        }
        return true;
    }
};