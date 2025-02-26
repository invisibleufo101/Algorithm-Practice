#include <bits/stdc++.h>
using namespace std;

int turnBitOff(int s, int idx){
    s &= ~(1 << idx);
    return s;
}

int XORbit(int s, int idx){
    s ^= (1 << idx);
    return s;
}

int findLowestBit(int s){
    int idx = (s & -s);
    return idx;
}

int addBit(int s, int idx){
    s |= (1 << idx);
    return s;
}

int getAllBits(int n){
    return (1 << n) - 1;
}

int main(){
    /**
     * We are trying to turn the bit OFF at 2^1
     * 0b10010 => 0b10000
    */

    int s = 18;
    int idx = 4;

    if (s & (1 << idx)){
        cout << idx << "th index is turned on!\n";
    } else {
        cout << idx << "th index is turned off!\n";
    }

    return 0;
}