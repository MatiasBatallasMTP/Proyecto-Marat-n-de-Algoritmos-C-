#include <cassert>
#include <iostream>
using namespace std;

int suma(int a, int b){ return a+b; }

int main(){
    assert(suma(2,3)==5);
    assert(suma(-1,1)==0);
    cout << "Todas las pruebas pasaron." << endl;
}
