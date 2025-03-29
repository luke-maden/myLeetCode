class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int start;
        int end;
        int numCyc = 0;
        int orig;
        int size = colors.size();

        if(colors[size - 1] == colors[0]){
            start = 0;
        } else {
            for(int i = 0; i < size - 1; i++){
                if(colors[i] == colors[i + 1]){
                    start = i + 1;
                    i = i * 2;
                }
            }
        }

        orig = start;
        end = start + 1;
        while(colors[start % size] == colors[end % size]){
            start++;
            end++;
            if(start % size == orig){
                return 0;
            }
        }

        orig = start;
        k--;

        // need loop for first iter
        while(start == orig){
            if(end - start == k){
                numCyc++;
                if(colors[end % size] != colors[(end + 1) % size]){
                    start++;
                    end++;
                } else {
                    start = end + 1;
                    end += 2;
                }
            } else {
                if(colors[end % size] != colors[(end + 1) % size]){
                    end++;
                } else {
                    start = end + 1;
                    end += 2;
                }
            }
        }
        while(start % size != orig){
            int diff = end - start;
            int ems = end % size;
            if(diff == k){
                numCyc++;
                if(colors[ems] != colors[(end + 1) % size]){
                    start++;
                    end++;
                } else {
                    start = end + 1;
                    end += 2;
                }
            } else if(diff == 1 && colors[start % size] == colors[ems]){
                start++;
                end++;
            } else if(colors[ems] != colors[(end + 1) % size]){
                end++;
            } else {
                if(end == orig){
                    start = end;
                } else {
                start = end + 1;
                end += 2;
                }
            }
        }

        return numCyc;
    }
};