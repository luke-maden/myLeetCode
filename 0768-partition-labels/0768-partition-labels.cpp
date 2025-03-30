class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastInd;
        vector<int> result;
        int ind1 = 0;
        int ind2 = 0;
        int lim1 = s.length();

        for(int i = 0; i < lim1; i++){
            lastInd[s[i]] = i;
        }

        while(ind1 < s.length()){
            lim1 = lastInd[s[ind1]];
            ind2 = ind1 + 1;

            while(ind2 < lim1){
                lim1 = max(lim1, lastInd[s[ind2]]);
                ind2++;
            }

            result.push_back(lim1 - ind1 + 1); // might need to switch our lim1 for ind2...
            ind1 = lim1 + 1;
        }

        return result;
    }
};