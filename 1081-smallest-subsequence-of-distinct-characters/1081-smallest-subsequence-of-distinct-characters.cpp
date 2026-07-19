class Solution {
public:
    string smallestSubsequence(string str) {
      
      int n = str.length();
      vector<int> freq(n);
        freq[n-1] = 1<<(str[n-1]-'a');
      for(int i = n-2; i>=0; i--){
        freq[i] = (freq[i+1]|(1<<(str[i] - 'a')));
        // cout<<freq[n-1]<<' ';
      }

      int prev = -1;
      char prevSym = 'z' + 1;
      string res = "";
      int prevFreqCnt = 0;
      for(int i = 0; i<26; i++){
        for(int j = prev+1; j<n; j++){
            if((str[j]<prevSym)&&(prevFreqCnt|freq[j])==freq[0]&&!(prevFreqCnt&(1<<(str[j]-'a')))){
                prev = j;
                prevSym = str[j];
                
            }
        }
        
        res += prevSym;
        prevFreqCnt |= (1<<(prevSym - 'a'));
        prevSym = 'z' + 1;
        if(prevFreqCnt==freq[0]) break;
      }
      return res;
    }

    
};