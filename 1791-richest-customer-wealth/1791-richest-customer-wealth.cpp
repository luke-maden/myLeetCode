class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        map<int, int> cust;
        int maxbal = 0;

        for(int i = 0; i < accounts.size(); i++){
            for(int k = 0; k < accounts[i].size(); k++){
                cust[i] += accounts[i][k];
            }
        }

        for(int i = 0; i < cust.size(); i++){
            maxbal = max(maxbal, cust[i]);
        }

        return maxbal;
    }
};