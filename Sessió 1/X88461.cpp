#include <iostream>
#include <vector>

using namespace std;

int main(){

    int numEst;
    cin >> numEst;
    vector<int> x (numEst);
    for (int i=0; i<numEst;++i)
    cin >> x[i];
    int max = x[0];
    int min = x[0];
    for(int i = 1; i < x.size() ; ++i){
        if (x[i] > max) max = x[i];
        if (x[i] < min) min = x[i];
    }
    cout << max << ' ' << min << endl;
}
