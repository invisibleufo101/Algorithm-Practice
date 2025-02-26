#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int arr[10];

int main(){
    cin >> a >> b >> c;
    long long sum = a * b *c;
    string s = to_string(sum);
    for (char c : s){
        arr[c - '0']++;        
    }

    for (int i=0; i<10; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}