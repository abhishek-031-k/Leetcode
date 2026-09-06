class Solution {
public:

   bool dfs(int node, int colors, vector<int>&color, vector<vector<int>>&graph){
    color[node] = colors;
    for(auto &adjNode: graph[node]){
        if(color[adjNode] == -1){
            if(!dfs(adjNode, !colors, color, graph))return false;
        }
        else if(color[adjNode] == colors)return false;
    }
       return true;
   }

    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int>color(n, -1);
       for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(dfs(i, 0, color, graph) == false)return false;
        }
       }   
       return true;
    }
};