#include <iostream>

using namespace std;

int main(){
    int row, col;
    cin >> row >> col;
    int matrix[row][col];
    
    int numbers_of_cmd;
    cin >> numbers_of_cmd;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }

    while (numbers_of_cmd > 0){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // check if INVALID, OUTSIDE or valid
        if ((r1 > r2) || (c1 > c2)){
            cout << "INVALID" << endl;
        } else if ((r1 > row ) || (c1 > col)){
            cout << "OUTSIDE" << endl;
        } else { // valid case
            if (r2 > row){
                r2 = row;
            }
            if (c2 > col){
                c2 = col;
            }

            int maxValue = matrix[r1 - 1][c1 - 1];
            for (int i = (r1 - 1); i <= (r2 -1); i++){
                for (int j = (c1 - 1 ); j <= (c2 - 1); j++){
                    if (matrix[i][j] > maxValue){
                        maxValue = matrix[i][j];
                    }
                }
            }
            cout << maxValue << endl;
        }

        numbers_of_cmd--;
    }
    return 0;
}