#include <bits/stdc++.h>
using namespace std;

int a = 4; // Integer uses 4 bytes
double c = 4.20; // Double uses 8 bytes

int main(){
    // pointer format
    // (data type) * (variable name) = & (whatever variable is being pointed at)
    // !!! pointer data type MUST MATCH whatever data type that it's pointing at !!!
    int *b = &a;
    double *d = &c;

    // If we print out the results, we can see that both the &a and *b 
    // are pointing at the same memory address !
    cout << "&a : " << &a << "\n";
    cout << "*b : " << b << "\n";

    cout << "memory address for (doube) c" << d << "\n";

    // The pointers' ( b and d ) data size are not different
    cout << "data size for b : " << sizeof(b) << " bytes" << "\n";
    cout << "data size for d : " << sizeof(d) << " bytes" << "\n";

    // BUT keep in mind that the data size of pointer DEPENDS on the VERSION OF THE OS THAT YOU'RE USING!
    // ex) Windows 32 bit -> 4 byte
    //     Windows 64 bit -> 8 byte

    

    return 0;
}