#include <iostream>
#include <chrono>
using namespace std::chrono;


//comment and uncomment algorithms to test time
void loopA(int n){//O(n) or 10000n

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10000; j++) {
            int sum = sum + j;
        }
    }
}

void loopB(int n){//O(n^2) or n^2
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            int sum = sum + j;
        }
    }
}

void loopB2(int n) {// O(n^2) or n^2 + j
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                int sum = sum + k;
            }
        }
    }
}


int main() {
    auto start = high_resolution_clock::now();
    //comment and uncomment the ones you want to test @param for each loop is n-value



    loopA(30);
    //loopB();
    //loopB2();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "the duration in miliseconds " << duration.count();
}

// Q1 at n = 1 loop B is quicker than loop A as n^2 < 10000
// Q2 at
