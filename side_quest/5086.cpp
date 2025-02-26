#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){

    while (cin >> a >> b && a != 0 && b != 0){
        if (b % a == 0){
            cout << "factor\n";
        } else if (a % b == 0){
            cout << "multiple\n";
        } else {
            cout << "neither\n";
        }
    }
    
    return 0;
}