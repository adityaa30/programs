#include <bits/stdc++.h>
#define li long long int

using namespace std;

li mutexx = 1, full = 0, emptyy = 5, x = 0;

li wait(li s) {
    return (--s);
}

li signal(li s) {
    return (++s);
}

void producer() {
    mutexx = wait(mutexx);
    full = signal(full);
    emptyy = wait(emptyy);
    x++;
    cout << "Producer produces the item: " << x << endl;
    mutexx = signal(mutexx);
}

void consumer() {
    mutexx = wait(mutexx);
    full = wait(full);
    emptyy = signal(emptyy);
    cout << "Consumer consumes the item: " << x << endl;
    x--;
    mutexx = signal(mutexx);
}

int main() {
    li ch;
    while(true) {
        cout << "1. Producer\n2. Consumer\n3. Exit\nChoice: " << endl;
        cin >> ch;
        switch(ch) {
            case 1: {
                if(mutexx == 1 && emptyy != 0)
                    producer();
                else 
                    cout << "Buffer is full." << endl;
                break;                
            }
            case 2: {
                if(mutexx == 1 && full != 0) {
                    consumer();
                } else {
                    cout << "Buffer is empty." << endl;
                }
                break;
            }
            case 3: {
                exit(0);
                break;
            }
        }
    }
    return 0;
}