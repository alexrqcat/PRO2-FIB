#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct lliga {
    int equip,punts,marcats,rebuts;
};

struct partit {
    int equip1,equip2;
};

bool comp (const lliga& a, const lliga& b){ /*Bool per poder ordenar loa llista*/
    if (a.punts == b.punts) {
        if (a.marcats == b.marcats ) return a.equip < b.equip;
        else return a.marcats - a.rebuts > b.marcats - b.rebuts;
    }
    else return a.punts > b.punts;
}

int main(){
    int num;
    cin >> num;
    vector < lliga > x(num);
    vector < vector < partit > > matriu(num,vector<partit>(num));
    /*llegim la matriu amb tots els partits*/
    for( int i = 0 ; i < num ; ++i ){
        for (int j = 0 ; j < num ; ++j ){
            cin >> matriu[i][j].equip1 >> matriu[i][j].equip2;
        }
    }
    /*emplenem struct lliga*/
    for( int i = 0 ; i < num ; ++i ){
        for (int j = 0 ; j < num ; ++j ){
            if (i != j) {
                if ( matriu[i][j].equip1 > matriu[i][j].equip2 ) x[i].punts += 3;
                else if ( matriu[i][j].equip1 == matriu[i][j].equip2 ) {
                    x[i].punts += 1;
                    x[j].punts += 1;
                }
                else x[j].punts += 3;
                x[i].marcats = x[i].marcats + matriu[i][j].equip1;
                x[j].marcats = x[j].marcats + matriu[i][j].equip2;
                x[i].rebuts = x[i].rebuts + matriu[i][j].equip2;
                x[j].rebuts = x[j].rebuts + matriu[i][j].equip1;
            }
        }
    }
    for (int k = 0; k < num ; ++k) x[k].equip = k; /*Donem nom als equips*/
    sort(x.begin(),x.end(),comp); /*Ordenem la nostra llista per punts, gols o equips */
    for (int i = 0 ; i < num ; ++i){
        cout << x[i].equip + 1 << ' ' << x[i].punts << ' ' << x[i].marcats << ' ' << x[i].rebuts << endl;
    }
}
