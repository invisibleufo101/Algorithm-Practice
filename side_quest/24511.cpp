#include <bits/stdc++.h>
using namespace std;
int n, dataStructure[100001];
int element;
int m, input;
deque<int>dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> dataStructure[i];
    }

    for (int i=0; i<n; i++){
        cin >> element;
        if (dataStructure[i] == 0){
            dq.push_back(element);
        }
    }

    cin >> m;
    for (int i=0; i<m; i++){
        cin >> input;

        dq.push_front(input);
        cout << dq.back() << " ";
        dq.pop_back();
    }
    
    return 0;
}