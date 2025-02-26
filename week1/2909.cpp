#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int t1, t2;
int cnt[100];
int sum=0;

int main(){
    cin >> a >> b >> c;
    
    for(int i=0; i<3; i++){
        cin >> t1 >> t2;
        for (int j=t1; j<t2; j++){
            cnt[j]++;
        }
    }

    for(int i=0; i < 100; i++){
        if (cnt[i]){
            if (cnt[i] == 1){
                sum += a;
            } else if (cnt[i] == 2){
                sum += b*2;
            } else if (cnt[i] == 3){
                sum += c*3;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}