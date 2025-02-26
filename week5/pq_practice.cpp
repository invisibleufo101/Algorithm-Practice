#include <bits/stdc++.h>
using namespace std;
int n;
double score;
priority_queue<double, vector<double>, greater<double>>pq;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> score;
        pq.push(score);
    }

    for(int i=0; i<7; i++){
        printf("%.3lf\n", pq.top()); 
        pq.pop();
    }

    return 0;
}