#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;
using namespace std::chrono;
typedef long long int  ull;
std::mutex m;
int gb = 0;
void func(int x){
    for(int i=0;i<10000;i++)
    {
        if(m.try_lock())
            gb++;
            m.unlock();

    }
}

int main() {
    cout << "Main started" << endl;
    std::thread t1(func,10);
    std::thread t2(func,20);
    t1.join();
    cout << gb << endl;
	
    t2.join();
    return 0;
}