#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Estudiante{
    string nombre;
    double nota;
};

int main(){
    vector<Estudiante> v={{"Ana",9.5},{"Luis",7.2},{"Mia",9.5}};
    stable_sort(v.begin(),v.end(), [](Estudiante a, Estudiante b){ return a.nota>b.nota; });
    for(auto e:v) cout<<e.nombre<<" "<<e.nota<<endl;
}
