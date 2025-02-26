#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){

    while (cin >> a >> b >> c && a != 0 && b != 0 && c != 0){

        if (a + b <= c || b + c <= a || a + c <= b){
            cout << "Invalid\n";
        } else if (a == b && b == c && a == c){
            cout << "Equilateral\n";
        } else if (a == b || b == c || a == c){
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }

    return 0;
}