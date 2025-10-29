#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Estudiante{
    string nombre;
    double nota;
};

int main(){
    ofstream fout("notas.txt", ios::app);
    Estudiante e;
    cout << "Nombre: "; cin>>e.nombre;
    cout << "Nota: "; cin>>e.nota;
    fout << e.nombre << " " << e.nota << endl;
    fout.close();

    cout << "Registro de notas:\n";
    ifstream fin("notas.txt");
    while(fin>>e.nombre>>e.nota) cout<<e.nombre<<" "<<e.nota<<endl;
}
