#include <iostream>     // Reyaad Raffik CSCI211
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    for(int i = 0; i < c; i++){
        if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])){       // Same ok function as the 8-queens to test for row, up and down diagonal.
            return false;       
        }
    }
    return true;
}

int nqueens(int n){
    int solutions = 0;
    int* q = new int [n];   // Returns the address of where it found space for int n.
    int c = 0;  // Column is initialized to 0 so that it starts there.
    q[0] = 0;   // Row is initialized to 0 in order to start at box (0,0)
    
    while (c >= 0){     // Same while loop as the 8-queens problem.
        c++;
        if (c == n){
            solutions++;
            c--;
        } else{
            q[c] = -1;
        }
        while (c >= 0){
            q[c]++;
            if (q[c] == n){
                c--;
            } else if (ok(q,c) == true) break;
        }
    }
    
    delete [] q;        // Delete is used within this scope in order to return the memory, the value stored.
    return solutions;       // Returns number of solutions
}

int main (){
    int n = 12;
    for (int i = 1; i <= n; i++){
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";        // Checks how many solutions there are for the queens problem, from 1 queen to 12 queens.
    }
    return 0;
}
        
