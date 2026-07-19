class Solution {
public:
   string rearrangeString(string s, char x, char y) {
    string start = "", mid = "", end = "";
    for(int i = 0; i < s.size(); i++){
    if(s[i] == y)start += s[i];    
    else if(s[i] == x)mid += s[i];
    else  end += s[i];
    } 
    return start + mid + end;
    }
};