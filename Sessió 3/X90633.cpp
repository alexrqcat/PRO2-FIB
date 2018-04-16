#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest,0,nest-1,dni);
    b = pos < nest && dni == vest[pos].consultar_DNI();
    if (not b){
        ++nest;
        for(int i=nest-1; i > pos ; --i){
            vest[i] = vest[i-1];
        }
        vest[pos] = est;
        if(est.te_nota()){
            suma_notes = suma_notes + est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){
    int pos = cerca_dicot(vest,0,nest-1,dni);
    b = pos < nest && dni == vest[pos].consultar_DNI();
    if (b){
        if (vest[pos].te_nota()){
            suma_notes = suma_notes - vest[pos].consultar_nota();
            --nest_amb_nota;
        }
        for(int i=pos; i < nest-1 ; ++i){
            vest[i] = vest[i+1];
        }
        --nest;
    }
}
