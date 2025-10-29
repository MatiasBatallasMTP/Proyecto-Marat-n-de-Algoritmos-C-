#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Usuario{
    string nombre;
    int edad;
};

int main(){
    ofstream fout("usuarios.txt", ios::app);
    Usuario u;
    cout << "Nombre: "; cin>>u.nombre;
    cout << "Edad: "; cin>>u.edad;
    fout << u.nombre << " " << u.edad << endl;
    fout.close();

    cout << "Usuarios guardados:\n";
    ifstream fin("usuarios.txt");
    while(fin>>u.nombre>>u.edad) cout<<u.nombre<<" "<<u.edad<<endl;
}
