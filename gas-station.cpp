class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int sgas = 0;
        int scost = 0;
        int i = 0, j = 0; // to
        do {
            if (sgas < scost){
                i = (i - 1 + n) % n;
                sgas += gas[i];
                scost += cost[i];
            }
            else{
                sgas += gas[j];
                scost += cost[j];
                j = (j + 1)  % n;
            }
        }
        while(i != j);
        return (sgas < scost) ? -1 : i;
    }
};