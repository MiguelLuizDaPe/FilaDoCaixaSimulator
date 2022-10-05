#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"

int main(){
    srand (time(NULL));

    Queue<int> fila;
    for(int i = 0; i < 5; i++){ //5 dias
        for(int j = 0; j < 8; j++){ //8 horas de trabalho por dia
            for(int k = 0; k < 60; k++){ // contar os min pra ter mais controle
                int qntChego = (rand() % 7) + 1;
                for(int l = 0; l < qntChego; l++){ // coloca nego na fila
                    fila.enqueue(k);
                }
                fila.dequeue();
            }
        }
    }
    std::cout << fila.size() << "\n";

    //3 dias de inferno
    for(int i = 0; i < 3; i++){ //3 dias
        for(int j = 0; j < 8; j++){ //8 horas de trabalho por dia
            for(int k = 0; k < 60; k++){ // contar os min pra ter mais controle
                for(int l = 0; l < 6; l++){ // tira nego na fila (5 atendentes)
                    try {fila.dequeue();}
                    catch (const char* err){std::cout << err; goto jump;} // pula quando da catch
                }
            }
        }
    }
    jump: // pulou pra ca

    std::cout << fila.size() << "\n";





    return 0;
}
