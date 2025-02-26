#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    while (!cin.eof()) {
        cin >> n;

        int rmder = 1;
        int cnt = 1;

        while (rmder != 0){
            rmder = (rmder * 10 + 1) % n;
            cnt ++;
        }

        cout << "Result: " << cnt << "\n";
    }
    return 0;
}

/** 
 * Some test cases:
*/

// 3 Result : 3
// 7 Result: 6 
// 9901 Result: 12

// 47
// Result: 46
// 39
// Result: 6
// 67
// Result: 33
// 89
// Result: 44