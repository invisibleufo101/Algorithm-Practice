#include <bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
priority_queue<int, vector<int>, greater<int>>pq2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int>rand = {3,5,1,2,4};

    for (int i=0; i<rand.size(); i++){
        pq.push(rand[i]); pq2.push(rand[i]);
    }

    // Ori input: 1,2,3,4
    // PQ : 1,2,3,4
    // PQ2: 4,3,2,1

    while(pq.size()){
        cout << pq.top() << "\n";
        pq.pop();
    }

    cout << "----------\n";

    while(pq2.size()){
        cout << pq2.top() << "\n";
        pq2.pop();
    }

    return 0;
}