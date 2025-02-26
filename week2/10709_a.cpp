#include <bits/stdc++.h>
using namespace std;
int h, w;
string s;
int arr[104][104];

void print(int a[104][104]){
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> h >> w;

    for (int i=0; i<h; i++){
        cin >> s;

        // Row has NO clouds
        if (s == string(w, '.')){
            for (int j=0; j<w; j++){
                arr[i][j] = -1;
            }
        // Row HAS clouds
        } else {
            bool before_cloud = 1;
            for (int j=0; j<w; j++){

                // If Row 
                if (before_cloud && s[j] == '.'){
                    arr[i][j] = -1;
                }

                if (s[j] == 'c'){
                    before_cloud = 0;
                    // Mark Clouds as 0
                    arr[i][j] = 0;

                    int cnt = 1;
                    // Mark all the dots that comes after clouds with cnt
                    // Increment clouds by 1 
                    // IF there is another cloud, then break out of the loop
                    for (int x=j+1; x<=w; x++){
                        if (s[x] == '.'){
                            arr[i][x] = cnt;
                            cnt++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    print(arr);
    

    return 0;
}