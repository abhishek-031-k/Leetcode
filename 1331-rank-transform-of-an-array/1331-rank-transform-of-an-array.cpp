class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int>rank;
        vector<int>sortedarray(arr);
        sort(sortedarray.begin(),sortedarray.end());
        int rank1=1;
        for(int i=0;i<sortedarray.size();i++){
            if(i>0&&sortedarray[i]>sortedarray[i-1])rank1++;
            rank[sortedarray[i]]=rank1;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};