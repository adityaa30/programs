#include <bits/stdc++.h>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        unsigned long long current;
        cin >> current;
        
        if (current == 1) {
            cout << 0 << endl;
            continue;
        }
        
        unsigned long long temp = 1;
        int position = -1;
        int counter = -1;
        do {
            counter++;
            position++;
            temp *= p[position];
        } while (temp <= current);
        
        cout << counter << endl;
    }
    return 0;
}