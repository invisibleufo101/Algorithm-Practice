#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;

    for (int i=-999; i<1000; i++){
        for (int j=-999; j<1000; j++){
            if (i*a + j*b == c && i*d + j*e == f){
                cout << i << " " << j << "\n";
                break;
            }
        }
    }
    
    return 0;
}