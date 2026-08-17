class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int index = -1, dis = INT_MAX;
        for(int i = 0; i < drones.size(); i++) {
            int x = abs(drones[i][0] - target[0]);
            int y = abs(drones[i][1] - target[1]);
            int curr = x + y;
            if(curr <= drones[i][2] && curr < dis) {
                dis = curr;
                index = i;
            }
        }

        return index;
    }
};