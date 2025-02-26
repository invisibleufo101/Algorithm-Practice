#include <bits/stdc++.h>
using namespace std;
int n;

string print(int n, int i){
    return to_string(n) + " * " + to_string(i) + " = " + to_string(n*i);
}

int main(){
    cin >> n;

    for (int i=1; i<10; i++){
        cout << print(n, i) << "\n";
    }

    return 0;
}