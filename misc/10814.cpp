#include <bits/stdc++.h>
using namespace std;
int n;
int age;
string name; 
struct A{
    int order, age;
    string name;
};
A arr[100002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> age  >> name;
        arr[i] = {i, age, name};
    }

    for (int i=0; i<n; i++){
        for (int j=1; j<n-i; j++){
            if (arr[j-1].age > arr[j].age){
                swap(arr[j-1], arr[j]);
            } else if (arr[j-1].age == arr[j].age){
                if (arr[j-1].order > arr[j].order){
                    swap(arr[j-1], arr[j]);
                }
            }
        }
    }    

    for (int i=0; i<n; i++){
        cout << arr[i].age << " " << arr[i].name << "\n";
    }

    return 0;
}