#include <bits/stdc++.h>
using namespace std;

int i = 4;

int main(){
    int *p = &i; // Memory Pointer

    string a = "Tony";
    string *b = &a;

    // print pointer
    cout << "memory address for a : " << b << "\n";

    // If we put another asterisk on the pointer, then we can get the variable that it's pointing at!!
    
    string dereference = *b;
    cout << "Dereferencing pointer b. The variable is : " << dereference << "\n";

    return 0;
}
