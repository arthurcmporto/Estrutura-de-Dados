#include <iostream>
#include "FilaEstaticaGenerica.h"
#include <time.h>


using namespace std;

int main(){

    FilaEstaticaGenerica<int,200> clientes;
    FilaEstaticaGenerica<bool,10>funcionarios;
    srand(time(NULL));

    cria(clientes);
    cria(funcionarios);

    int cont=0, correspondencias=0;

        for(int i=0;i<10;i++){
            insere(funcionarios, true);
        }

        for(int i<=0; i<=10*60;i++){
            if(i%3==0)
                for(int j=0;j<rand()%13;j++)
                    insere(clientes,1);
            if(i % 5 == 0 && i!=0)
                for(int j=0;j<10;j++)
                    if(numeroDeElementos(clientes>0)){
                        if((i>120 && i<=120) || i>=360 && i<=480)
                            correspondencias+=rand()%3+2;
                            cont++;
            }

        }if(primeiro(funcionarios)==true){
            retira(funcionarios);
            insere(funcionarios, false);
        } else {
        retira(funcionarios);
        insere(funcionarios, true);
        }
        retira(clientes)


    return 0;
}
