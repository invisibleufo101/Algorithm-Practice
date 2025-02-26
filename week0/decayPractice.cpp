#include <bits/stdc++.h>
using namespace std;

int a[5] = {1,2,3,4,5};

int main(){
    // Assigning pointer var to array
    int *b = a;

    // Printing pointer var
    cout << "Pointer (b) : " << b << "\n";

    // Lets compare it to the mem addr of the first element of the array
    cout << "Pointer (b) : " << b << " First element : " << &a[0] << "\n";

    // We can also shift to the mem addr of the next element by adding +1 to the pointer (b)
    cout << "Memory address of next element (a[1]) " << b+1 << "\n";
    cout << "Printing actual &a[1]" << &a[1] << "\n";
    
    // Let's take it a step further and create an array that contains ALL the mem addr of elements in array a
    for (int i=0; i < sizeof(a)/sizeof(a[0]); i++){
        cout << "Memory address of a[" << i << "] : " << b + i << "\n";
    }

    return 0;
}