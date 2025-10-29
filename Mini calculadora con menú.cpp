#include <iostream>
using namespace std;

int main(){
    int op; double a,b;
    cout << "1:+ 2:- 3:* 4:/ 0:Salir\n";
    while(true){
        cout << "Opción: "; cin>>op;
        if(op==0) break;
        cout << "Ingrese dos números: "; cin>>a>>b;
        switch(op){
            case 1: cout<<a+b<<endl; break;
            case 2: cout<<a-b<<endl; break;
            case 3: cout<<a*b<<endl; break;
            case 4: cout<<a/b<<endl; break;
            default: cout<<"Opción inválida"<<endl;
        }
    }
}
