#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    for (int i=0; i<5; i++){
        v.push_back(i);
    }

    for (int i : v){
        cout << i << "\n";
    }

    v.erase(v.begin()+3);

    for (int i : v){
        cout << i << "\n";
    }


    return 0;
}