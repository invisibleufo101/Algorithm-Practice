#include <bits/stdc++.h>
using namespace std;
int t;
int a,b;

int dolmen(int a, int b){
    int sum, i, j, k;
    sum = 0;
    for (i=0; i < a + b; i++){
        for (j=0; j< a+b; j++){
            for (k=0; k<j; k++){
                sum++;
            }
        }
    }
    return sum;
}

int main(){
    cin >> t;
    while (t--){
        cin >> a >> b;
        cout << dolmen(a,b) << "\n";
    }

    return 0;
}
