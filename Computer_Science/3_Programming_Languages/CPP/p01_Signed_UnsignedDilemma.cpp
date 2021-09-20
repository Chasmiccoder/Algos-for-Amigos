#include<iostream>
#include<limits.h>
using namespace std;

unsigned int returnUnsigned() {
    unsigned int count = (unsigned int) -10; 
    cout << "Inside Unsigned: " << count << endl;
    return count; 
}

int returnSigned() {
    unsigned int count = -10;
    cout << "Inside Signed: " << count << endl;
    return count; 
}

int main() {

    cout << "Limit of Uint: " << UINT32_MAX << endl;

    cout << "Outside Signed: " << returnSigned() << endl;
    cout << "Outside Unsigned: " << returnUnsigned() << endl; 

    return 0;
}

/*
Why this happens:
maxvalue of unsigned int = 4294967295
What happened: 0 -> 4294967295 -> 4294967294 -> 4294967293 -> 4294967292 -> 4294967291 
-> 4294967290 -> 4294967289 -> 4294967288 -> 4294967287 -> 4294967286 
i.e, we got 10 subtractions
*/