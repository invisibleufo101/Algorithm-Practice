#include <bits/stdc++.h>
using namespace std;
int n;
int a; 
string s;
struct A{
    int age;
    string name;
    int order;
};
vector<A>v;

bool cmp(A a, A b){
    if (a.age == b.age){
        return a.order < b.order;
    }
    
    return a.age < b.age;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> s;
        v.push_back({a,s,i});
    }

    sort(v.begin(), v.end(), cmp);

    for (A i : v) cout << i.age << " " << i.name << "\n";

    return 0;
}