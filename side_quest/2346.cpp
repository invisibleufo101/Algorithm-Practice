#include <bits/stdc++.h>
using namespace std;
int n,target,arr[1001];
deque<pair<int,int>>dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    for (int i=1; i<=n; i++){
        cin >> target;

        dq.push_back({i, target});
    }

    // Popping the first balloon
    int num = dq.front().first;
    int target = dq.front().second;
    cout << num << " ";
    dq.pop_front();

    // Then everything after
    while(dq.size()){
        if (target > 0){
            int iter = target;

            while(iter--){

                if (iter == 0){
                    cout << dq.front().first << " ";
                    target = dq.front().second;
                    dq.pop_front();
                } else {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }

            }

        } else if (target < 0){
            int iter = abs(target);
            while(iter--){

                if (iter == 0){
                    cout << dq.back().first << " ";
                    target = dq.back().second;
                    dq.pop_back();
                } else {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }

            }
        }     
    }

    return 0;
}