#include<iostream>      // Reyaad Raffik    CSCI211
using namespace std;

bool ok(int q[], int c){
    static int mp[3][3] = { { 0,2,1 },      // Man #0's preferences
                            { 0,2,1 },      // Man #1's preferences
                            { 1,2,0 } };    // Man #2's preferences

    static int wp[3][3] = { { 2,1,0 },      // Woman #0's preferences
                            { 0,1,2 },      // Woman #1's preferences
                            { 2,0,1 } };    // Woman #2's preferences

    for(int i = 0; i < c; i++){
        if (q[c] == q[i]){      // Checks if same women is marreid to two different man.
            return false;
        }
        if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]){  // Checks if current man and new woman like each other more than current spouse
            return false;
        }
        if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]){ // Checks if new man and current woman both like each other more than current spouse
            return false;
        }
    }
return true;
}

void print(int q[]){
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";    // Prints solution
    for(int i = 0; i < 3; i++){
        cout << i << "\t" << q[i] << endl;
    }
    cout << endl;
}

int main(){
    int q[3];
    int c = 0;
    q[c] = 0;
    
    while (c >= 0){     // Outer while loop is for man
        c++;
        if(c == 3){     // Checks if all men have been checked already
            print(q);   // If all men have been checked, prints solution and then backtracks
            c--;
        } else{
            q[c] = -1;
        }
        while (c >= 0){     // Inner while loop is for woman
            q[c]++;
            if (q[c] == 3){ // Same function as in 1D 8 queens, if you have gotten to woman 3, although she does not exist, needs to backtrack
                c--;
            } else if(ok(q,c)) {        // Goes to the ok function
                break;
            }
        }
    }
    return 0;
}
        
