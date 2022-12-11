#include <iostream>         // Reyaad Raffik CSCI211
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[]){
    for(int c = 7; c > 0; c--){
        int r = 0;
        r = q[c];
    
        for(int i = 1; i <= c; i++){        // Row test
            if(q[c - i] == r) {
                return false;
            }
            else if (q[c - i] == r - i){        // Up diagonal test
                return false;
            }
            else if (q[c - i] == r + i){        // Down diagonal test
                return false;
            } 
        }
    }
return true;
}

void print(int q[8]){
    static int i = 1;
    cout << "Solution #" << i++ << ":";
    for(int l = 0; l < 8; l++){     // Printing the 1D array
        cout << q[l];
    }
    cout << endl;
    int sol[8][8] = {0};
    for( int j = 0; j < 8; j++){        // Creating the 2D array in order to print out the board
        sol[q[j]][j] = 1;
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main (){
    int q[8] = {0};         // Filling array with zeros.
    for(int r0 = 0; r0 < 8; r0++){      // Each for loop represents going through each row and iterating through 1D array.
        for(int r1 = 0; r1 < 8; r1++){
            for(int r2 = 0; r2 < 8; r2++){
                for(int r3 = 0; r3 < 8; r3++){
                    for(int r4 = 0; r4 < 8; r4++){
                        for(int r5 = 0; r5 < 8; r5++){
                            for(int r6 = 0; r6 < 8; r6++){
                                for(int r7 = 0; r7 < 8; r7++){
                                    q[0] = r0;
                                    q[1] = r1;
                                    q[2] = r2;
                                    q[3] = r3;
                                    q[4] = r4;
                                    q[5] = r5;
                                    q[6] = r6;
                                    q[7] = r7;
                                    
                                    if(ok(q)){  // Calls the ok function to see if it pasts the tests in order to know where to place queen.
                                        print(q);
                                    }
                                    
                                    q[0] = -1;  // Resets board to test other solutions.
                                    q[1] = -1;
                                    q[2] = -1;
                                    q[3] = -1;
                                    q[4] = -1;
                                    q[5] = -1;
                                    q[6] = -1;
                                    q[7] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
} 
