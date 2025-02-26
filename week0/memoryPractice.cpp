#include <bits/stdc++.h>
using namespace std;
int i;
int main(){
    cout << &i << "\n"; // Memory address before assigning a value to the variable
    i = 0;
    cout << &i << "\n"; // Memory address after assigning a value to the variable

    return 0;
}

// We can see that the memory address of the variable doesn't change after assigning a value because 
// the memory address has already been set when we declared in i. 

// Think of this like a house. 
// When the house is first built, it doesn't have an owner yet (int i)
// However, it has its own address
// The owner of the house or anyone living there can change anytime but the address of the house will never change.

