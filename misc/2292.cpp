#include <bits/stdc++.h>
using namespace std;

int n; //1,000,000,000

int main(){
    cin >> n;

    if (n == 1) cout << 1 << "\n";
    else {

        int i = 2;
        int x = 6;
        int level = 2;

        while(true){

            if (n >= i && n <= (i+x-1)) {
                cout << level << "\n";
                break;
            }

            i += x;
            x += 6;
            level++;
        }
    }

    return 0;
}