class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int total = 0;
        int twos = 0;
        for(int i = 0; i < colsum.size(); i++){
            total += colsum[i];
            if(colsum[i] == 2){
                twos++;
            }
        }

        if(total > upper + lower || total < upper + lower){
            vector<vector<int>> failure;
            return failure;
        } else if(twos > lower || twos > upper){
            vector<vector<int>> failure;
            return failure;
        }

        vector<vector<int>> matrix(2, vector<int>(colsum.size()));
        int ind = 0;
        for(int i = 0; i < colsum.size(); i++){
            switch(colsum[i]){
                case 2:
                    matrix[0][i] = 1;
                    matrix[1][i] = 1;
                    upper--;
                    lower--;
                    break;
            }
        }

        while(upper > 0){
            if(matrix[0][ind] == 0 && colsum[ind] == 1){
                matrix[0][ind] = 1;
                upper--;
            }
            ind++;
        }

        while(lower > 0){
            if(colsum[ind] == 1){
                matrix[1][ind] = 1;
                lower--;
            }
            ind++;
        }

        return matrix;
    }
};