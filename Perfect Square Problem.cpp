#include <iostream>     // Reyaad Raffik CSCI 211
#include <cmath>
#include <climits>
using namespace std;

int main (){
    for(int i = 1; i < int(sqrt(INT_MAX)); i++){ // The reason why the limit is the square root of INT_MAX is because i * i will not overflow .
        int j = i * i;
        int k = j % 10;  // This is retracting the last digit within i. 
        int l = j / 10 % 10; // This is retracting the second to last digit of i.
        if(k % 2 == 1 && l % 2 == 1){ // This is a check of whether or not the last two numbers are odd.
            cout << i << endl;  
            return 0;
        }
    }
    cout << "There is no perfect square who's last two digits are odd." << endl;
    return 0;
} 
