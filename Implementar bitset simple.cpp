#include <iostream>
using namespace std;

class SimpleBitset{
    unsigned int bits=0;
public:
    void set(int pos){ bits |= (1U<<pos); }
    void reset(int pos){ bits &= ~(1U<<pos); }
    bool test(int pos){ return bits & (1U<<pos); }
    void print(){
        for(int i=31;i>=0;i--) cout<<((bits>>i)&1);
        cout<<endl;
    }
};

int main(){
    SimpleBitset b;
    b.set(1);
    b.set(3);
    b.print();
    cout<<b.test(3)<<" "<<b.test(2)<<endl;
    b.reset(3);
    b.print();
}
