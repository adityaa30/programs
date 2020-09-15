#include <bits/stdc++.h>
#define li int
using namespace std;

li NUM_BITS = sizeof(li) * 8;

li LeftRotate(li n, li d){
    return (n << d) | (n >> (NUM_BITS - d));
}

li RightRotate(li n, li d){
    return (n >> d) | (n << (NUM_BITS - d));
}

int main() {
    cout << "Number of bits: " << NUM_BITS << endl;
    cout << "LeftRotate(16, 2): " << LeftRotate(16, 2) << endl;
    cout << "RightRotate(16, 2): " << RightRotate(16, 2) << endl;
    return 0;
}