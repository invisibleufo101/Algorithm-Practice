// 9 Permutation 7

#include <bits/stdc++.h>
using namespace std;
int a[9];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++){
        cin >> a[i];
    }
 
    // sort takes in the memory address as a parameter
    // therefore, we use "a", which is the first address of the first element and "a+9", which is the address of the last element
    // we need to sort the array before we can start the permutation
    sort(a, a+9); 

    
    do{
        // reset sum 
        int sum = 0;

        // add up the first 7 elements in the array 
        for (int i=0; i<7; i++){
            sum += a[i];
        }

        // if sum hits 100, then break out
        if (sum == 100){
            break;
        }
    } while (next_permutation(a, a+9)); // move on to the next permutation

    cout << "result" << "\n";

    for(int i=0; i<7; i++){
        cout << a[i] << "\n";
    }

    return 0;
}