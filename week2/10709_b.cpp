#include <bits/stdc++.h>
using namespace std;
int h,w;
string s;
int arr[104][104];

void print(int a[104][104]){
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> h >> w;
    for (int i=0; i<h; i++){
        cin >> s;
        for (int j=0; j<w; j++){
            if (s[j] == '.'){
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }
        }        
    }

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (arr[i][j] == 0){
                int cnt = 1;
                while (arr[i][j+1] != 0){
                    arr[i][j+1] = cnt;
                    cnt++;
                    j++;
                }
            }
        }
    }

    print(arr);

    return 0;
}