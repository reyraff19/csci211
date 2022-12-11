#include <iostream>         // Reyaad Raffik CSCI 211
#include <cmath>
using namespace std;

bool okay(int q[], int c){
    static int a[8][5] = {  // Helper Array
        {-1},
        {0,-1},
        {0,1,-1},
        {0,2,-1},
        {1,2,-1},
        {1,2,3,4,-1},
        {2,3,5,-1},
        {4,5,6,-1},
    };
    for(int i = 0; i < c; i++){     // Checks if the number in position c has already been used.
        if(q[c] == q[i]){
            return false;           
        }
    }
    for(int i = 0; a[c][i] != -1; i++){     // Checks to see if the numbers are adjacent, one under or over the number that is being checked.
        if(abs(q[c] - q[a[c][i]]) == 1){
            return false;
        }
    }
    return true;
}

void print(int q[]){        // Manually printing the eight numbers in a cross as if it were in a table.
    static int sol = 1;
    cout << "Solution#: " << sol++ << endl;
    cout << " " << q[1] << q[4] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    cout << endl;
}

int main (){
    int q[8] = {};  // 1D array that will be used to store our numbers.
    int c = 0;
    q[c] = 1;   // Starts with the number 1 since the range is from 1-8, inclusive.
     
    while(c >= 0){      // Works the same as our goto nc from the 8 queens problem.
        c++;
        if(c == 8){     // Checks if the index is higher than 7, since the index is from 0-7.
            print(q);       // Prints the output.
            c--;
        } else{
            q[c] = 0;
        }
        while(c >= 0){      // Works the same as out goto nr from the 8 queens problem.
            q[c]++;
            if(q[c] == 9){  //If we reach a number that is greater than 9, then we backtrack because a number cannot be placed there.
                c--;
            } else if(okay(q,c)){   // Runs the tests to see if the number is consecutive or adjacent to any other number.
                break;
            }
        }
    }
    return 0;
}
