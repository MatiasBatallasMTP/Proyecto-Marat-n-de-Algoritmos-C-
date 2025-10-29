#include <iostream>
#include <bitset>
#include <functional>
using namespace std;

class BloomFilter {
    bitset<100> bitArray;
public:
    void add(int val) {
        bitArray[val%100] = 1;
        bitArray[(val*7)%100] = 1; // simple hash2
    }
    bool possiblyContains(int val) {
        return bitArray[val%100] && bitArray[(val*7)%100];
    }
};

int main() {
    BloomFilter bf;
    bf.add(10);
    bf.add(20);
    cout << bf.possiblyContains(10) << endl; // 1
    cout << bf.possiblyContains(15) << endl; // 0 (probable)
}
