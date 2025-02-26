#include <bits/stdc++.h>
using namespace std;
int a,b,v;

int main(){
    cin >> a >> b >> v;

    if ((v - a) % (a - b) == 0){
        cout << (v-a) / (a - b) + 1;
    } else if ((v - a) % (a - b)){
        cout << (v-a) / (a - b) + 2;
    }
    
    return 0;
}