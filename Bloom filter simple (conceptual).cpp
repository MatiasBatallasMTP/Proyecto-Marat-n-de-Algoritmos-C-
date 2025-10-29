#include <iostream>
#include <bitset>
using namespace std;

class BloomFilter{
    bitset<32> bits;
public:
    void add(int x){
        bits[x%32]=1;
        bits[(x*7)%32]=1;
    }
    bool possiblyContains(int x){
        return bits[x%32] && bits[(x*7)%32];
    }
    void print(){ cout<<bits<<endl; }
};

int main(){
    BloomFilter bf;
    bf.add(10);
    bf.add(20);
    bf.print();
    cout<<bf.possiblyContains(10)<<" "<<bf.possiblyContains(15)<<endl;
}
