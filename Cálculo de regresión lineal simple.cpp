#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<double> x={1,2,3,4,5};
    vector<double> y={2,4,5,4,5};
    int n=x.size();
    double sumx=0,sumy=0,sumxy=0,sumxx=0;
    for(int i=0;i<n;i++){
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=x[i]*y[i];
        sumxx+=x[i]*x[i];
    }
    double slope=(n*sumxy - sumx*sumy)/(n*sumxx - sumx*sumx);
    double intercept=(sumy - slope*sumx)/n;
    cout<<"y = "<<slope<<"*x + "<<intercept<<endl;
}
