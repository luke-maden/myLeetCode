class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        for(auto i = freq.begin(); i != freq.end(); i++){
            if(i->second % 2 == 1){
                return false;
            }
        }

        return true;
    }
};