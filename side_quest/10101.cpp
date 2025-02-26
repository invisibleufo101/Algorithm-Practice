#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3;

int main(){
    cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 != 180) cout << "Error\n";
    else if (a1 == 60 && a2 == 60 && a3 == 60) cout << "Equilateral\n";
    else if (a1 == a2 || a2 == a3 || a1 == a3) cout << "Isosceles\n";
    else cout << "Scalene\n";

    return 0;
}