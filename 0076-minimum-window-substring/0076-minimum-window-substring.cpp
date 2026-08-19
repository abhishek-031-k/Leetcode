class Solution {
public:

    string minWindow(string s, string t) {
     int n = s.size(), m = t.size();   
     int sind = -1, count = 0,minlen = INT_MAX;
        vector<int>mpp(255, 0);
        for(auto &it: t)mpp[it]++;
        int  l = 0, r = 0;
        while(r < n){
            if(mpp[s[r]] > 0)count++;
            mpp[s[r]]--;
            while(count == m){
                int length = r-l+1;
              if(length < minlen){
                minlen = length;
                sind = l;
              }
              mpp[s[l]]++;
              if(mpp[s[l]] > 0)count--;
              l++;  
            }
            r++;
        } 
        return sind == -1 ? "" : s.substr(sind,minlen);  
    }
};