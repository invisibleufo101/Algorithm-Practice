#include <bits/stdc++.h>
using namespace std;
string line;
char arr[16][16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    memset(arr, '.', sizeof(arr));

    for (int i=0; i<5; i++){
        cin >> line;
        for (int j=0; j<line.length(); j++){
            arr[i][j] = line[j];
        }        
    }


    string ret = "";
    for (int j=0; j<16; j++){
        for (int i=0; i<16; i++){
            if (arr[i][j] != '.'){
                ret += arr[i][j];
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}