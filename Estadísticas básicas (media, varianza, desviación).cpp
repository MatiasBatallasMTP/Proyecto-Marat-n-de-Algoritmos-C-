#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<double> v={2,4,4,4,5,5,7,9};
    double sum=0;
    for(double x:v) sum+=x;
    double mean=sum/v.size();

    double var=0;
    for(double x:v) var+=(x-mean)*(x-mean);
    var/=v.size();
    double stddev=sqrt(var);

    cout<<"Media: "<<mean<<"\nVarianza: "<<var<<"\nDesviación: "<<stddev<<endl;
}
