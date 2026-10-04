/*Objetivo: ler um vetor de 8 números inteiros, modificá-lo usando ponteiros e calcular algumas estatísticas.
Requisitos
Você deverá implementar estas 4 funções:
1. readArray(int* ptr) — lê os 8 números do usuário.
2. doubleValues(int* ptr) — dobra o valor de cada elemento do vetor, utilizando aritmética de ponteiros.
3. findExtremes(int* ptr, int* min, int* max) — encontra o menor e o maior valor do vetor e os devolve por meio dos ponteiros min e max.
4. printArray(int* ptr) — imprime todos os elementos do vetor. */

#include <iostream>

#define SIZE 8

using namespace std;


void readArray(int* array){
    for(int i = 0; i < SIZE; i++){
        cin>> *array;
        array++;
    }
}

void doubleValues(int* array){
    for(int i = 0; i < SIZE; i++){
        *(array+i) = *(array+i) * 2;
    }
}

void findExtremes(int* array, int* min, int* max){
    *min = *max = *array;
    for(int i = 0; i < SIZE; i++){
        if (*array > *max){
            *max = *array;
        }
        if (*array < *min){
            *min = *array;
        }
        array++;
    }
}

void printArray(int* array){
    for(int i = 0; i < SIZE; i++){
        cout<<*array<<" ";
        array++;
    }
}

int main(void){

    int array[SIZE];
    int min, max;
    
    readArray(array);

    cout <<"Vetor antes de dobrar os valores: "<<endl;
    printArray(array);
    cout <<endl;

    doubleValues(array);
    findExtremes(array, &min, &max);

    cout <<"Vetor após dobrar os valores: "<<endl;
    printArray(array);
    cout <<endl;

    cout <<"Menor valor: "<<min<<endl;
    cout <<"Maior valor: "<<max<<endl;

    return 0;
}