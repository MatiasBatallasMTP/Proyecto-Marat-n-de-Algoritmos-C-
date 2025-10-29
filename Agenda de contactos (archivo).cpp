#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contacto{
    string nombre;
    string telefono;
};

int main(){
    ofstream fout("agenda.txt", ios::app);
    Contacto c;
    cout << "Nombre: "; cin >> c.nombre;
    cout << "Teléfono: "; cin >> c.telefono;
    fout << c.nombre << " " << c.telefono << endl;
    fout.close();

    ifstream fin("agenda.txt");
    while(fin >> c.nombre >> c.telefono) cout<<c.nombre<<" "<<c.telefono<<endl;
}
