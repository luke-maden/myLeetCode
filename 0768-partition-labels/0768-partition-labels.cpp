class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, bool> seen;
        vector<int> result;
        int ind1 = 0;
        int ind2 = 0;
        unsigned long lim1 = s.length();

        while(ind1 < s.length()){
            lim1 = s.find_last_of(s.at(ind1));
            ind2 = ind1 + 1;
            seen[s.at(ind1)] = true;

            while(ind2 < lim1){
                if(!seen[s.at(ind2)]){
                    lim1 = max(lim1, s.find_last_of(s.at(ind2)));
                    seen[s.at(ind2)] = true;
                }

                ind2++;
            }

            result.push_back(lim1 - ind1 + 1); // might need to switch our lim1 for ind2...
            ind1 = lim1 + 1;
        }

        return result;
    }
};