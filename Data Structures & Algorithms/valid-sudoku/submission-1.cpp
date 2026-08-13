class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for row
        for(vector<char> row : board){
            vector<int> hash(10, 0);
            for(char value : row){
                if(value != '.'){
                    if(hash[value - '0'] != 0){
                        // cout << "from row" << endl;
                        return false;
                    }
                    hash[value - '0']++;
                }
            }
        }

        //check for column
        for(int i = 0; i < 9; i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(hash[board[j][i] - '0'] != 0){
                        // cout << "from column" << endl;
                        return false;
                    }
                    hash[board[j][i] - '0']++;
                }
            }
        }

        //Check for the box
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                vector<int> hash(10, 0);
                for(int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        if(board[a + i * 3][b + j * 3] != '.'){
                            if(hash[board[a + i * 3][b + j * 3] - '0'] != 0){
                                // cout << "from BOX "  << endl;
                                return false;
                            }
                            hash[board[a + i * 3][b + j * 3] - '0']++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
