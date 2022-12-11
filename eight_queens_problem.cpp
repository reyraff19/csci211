#include <iostream>
using namespace std;

int main (){
    static int sol_num = 1;
    int b[8][8] = {0}, r, c = -1;
    
    nc:
        c++;
        if(c == 8) goto print;  // If it reaches column 8, this means a solution was found.
        r = -1;

    nr:
        r++;
        if(r == 8) goto backtrack;  // This means that there are not any solutions and if it goes off the board, must backtrack.

    // row test:

    for(int i = 0; i < c; i++){
        if(b[r][i] == 1) goto nr;
        }

    //up diagonal test

    for(int i = 1; (r-i) >= 0 && (c-i) >= 0; i++){
        if(b[r-i][c-i] == 1) goto nr;
        }

    //down diagonal test

    for(int i = 1; (r+i) < 8 && (c-i) >= 0; i++){
        if(b[r+i][c-i] == 1) goto nr;
        }

    // If b[r][c] is safe to place a queen.

    b[r][c] = 1;
    goto nc;

    backtrack:

        c--;
        if(c == -1)return 0;    // If there are no more placements for the queen and the column is negative, then the program ends.
        r = 0;
        while(b[r][c] != 1){    // While looping is searching for wherever there is a queen.
            r++;
        }
        b[r][c] = 0;    // Replaces the queen found with 0.
        goto nr;

    print:
        cout << "Solution #: " << sol_num++ << endl;            // Counter for the number of solutions that were found.

        for(int c = 0; c < 8; c++){
            for(int r = 0; r < 8; r++){
                cout << b[r][c] << " ";
            }
	        cout << endl;
        }
        cout << endl;
        goto backtrack; // Goes back to look for the other solutions of the eight queens problem.
}
