#include <iostream>     // Reyaad Raffik CSCI 211
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])) {     //This is the row and diagonal test to see whether or not a queen can be placed.
            return false;       // If it returns false, that means it cannot be placed as continues through the for loop.
        }
    }
    return true;    // If it returns true that means that the value of c and q[c], or the row, works
}

void print(int q[]){
    static int numSolutions = 1;
    cout << "Solution #" << numSolutions++ << ":" << " ";     // counter for the number of solutions
    int b[8][8] = {0};
    for(int i = 0; i < 8; i++){     // This iterates through the 1D array made.
        cout << q[i];   // Prints 1D array
        b[q[i]][i] = 1;     // This takes the value in q[c] and c itself and places a 1 in the 2D array.
    }
    cout << "\n";
    
    for(int i = 0; i < 8; i++){     // Prints the 2D array
        for(int j = 0; j < 8; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int q[8] = {};
    int c = 0;
    q[c] = 0;       // Places a queen in the spot [0][0]

    while (c >= 0){     // This outer while loop is the same as the "goto nc".
        c++;
        if(c == 8){
            print(q);   //If the column has reached 8, it is off the board and has found a solution which it will print.
            c--;
        } else{
            q[c] = -1;
        }
        while (c >= 0){     // This inner while loop is the same as the "goto nr".
            q[c]++;
            if(q[c] == 8){      // If the row reaches 8, that means it is off the board and must backtrack since a queen cannot be placed in that column.
               c--;
            } else if(ok(q,c)) {    // This is a check in order to know where a queen can be placed and if it can, the inner loop is broken and goes back to the outer loop.
               break;  
            }
        }
    }
    return 0;
}
