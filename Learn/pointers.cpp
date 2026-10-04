/*Crie um programa em C++ que leia 5 números inteiros digitados pelo usuário e utilize ponteiros para calcular algumas estatísticas desses números.

Requisitos
1. Crie um array de inteiros com 5 posições.
2. Utilize um laço for para ler os números.
3. Crie um ponteiro que aponte para o primeiro elemento do array.
4. Percorra o array utilizando o ponteiro para encontrar:
   - A soma de todos os elementos.
   - O maior valor.
   - O menor valor.
5. Exiba os resultados na tela.
Regra: depois de criar o ponteiro, percorra o array utilizando aritmética de ponteiros, como *(ptr + i), para acessar os elementos. Não utilize numeros[i] nos cálculos. */

#include <iostream>

using namespace std;

#define SIZE 5


void readArray(int* ptr){
    cout <<"Insira os 5 numeros: ";
    for (int i = 0; i < SIZE; i++){
        cin >> *ptr;
        ptr++;
    }
}

int sumArray(int* ptr){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
       sum = sum + *ptr;
       ptr++;
    }
    return sum;
}

int lowestValue(int* ptr){
    int low = *ptr;
    ptr++;
    for (int i = 1; i < SIZE; i++){
       if (*ptr < low){
        low = *ptr;
       }
       ptr++;
    }
    return low;
}

int highestValue(int* ptr){
    int high = *ptr;
    
    ptr++;
    for (int i = 1; i < SIZE; i++){
       if (*ptr > high){
        high = *ptr;
       }
       ptr++;
    }

    return high;
}

int main(void){

    int array[SIZE];
    int* ptr = array;
    
    
    readArray(ptr);

    cout<<"Soma dos valores do vetor: "<< sumArray(ptr)<<endl;
    cout<<"Menor valor do vetor: "<< lowestValue(ptr)<<endl;
    cout<<"Maior valor do vetor: "<< highestValue(ptr)<<endl;



    return 0;
}