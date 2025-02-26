#include <bits/stdc++.h>
using namespace std;
long long n;
long long arr[500002];
stack<long long>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int cur;
    int next;
    int cnt = 0;
    for (int i=1; i<n; i++){
        cur = arr[i-1];
        next = arr[i];

        if (cur < next){
            cnt++;

        } else if (cur == next){
            
            cnt++;
            bool isHeightened = 0;
            int changedHeight = 0;

            for (int j=i+1; j<n; j++){
                
                int nNext = arr[j];

                if (!isHeightened){
                    if (nNext == next){
                        cnt++;
                    } else if (nNext < next){
                        continue;
                    } else if (nNext > next){
                        changedHeight = nNext;
                        isHeightened = 1;
                        cnt++;
                    }
                } else if (isHeightened){
                    if (nNext < changedHeight){
                        continue;
                    } else if (nNext == changedHeight){
                        cnt++;
                    } else if (nNext > changedHeight){
                        changedHeight = nNext;
                        cnt++;
                        isHeightened = 1;
                    }
                }
            }
        } else if (cur > next){
            cnt++;
            bool isHeightened = 0;
            int changedHeight;

            for (int j=i+1; j<n; j++){
                int nNext = arr[j];

                if (!isHeightened){
                    if (nNext < next){
                        continue;
                    } else if (nNext == next){
                        cnt++;
                    } else if (nNext > next){
                        isHeightened = 1;
                        changedHeight = nNext;
                        cnt++;
                    }

                } else if (isHeightened){
                    if (nNext < changedHeight){
                        continue;
                    } else if (nNext == changedHeight){
                        cnt++;
                    } else if (nNext > changedHeight){
                        changedHeight = nNext;
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}