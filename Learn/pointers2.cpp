/*Crie um programa que leia 10 números inteiros em um array e utilize ponteiros para separar os números pares dos ímpares.

Requisitos
1. Declare um array com 10 posições.
2. Crie uma função readArray() para ler os números.
3. Crie uma função separateNumbers() que receba:
   - Um ponteiro para o array original.
   - Um ponteiro para armazenar os números pares.
   - Um ponteiro para armazenar os números ímpares.
   - Ponteiros para armazenar as quantidades de pares e ímpares.
4. Dentro de separateNumbers(), percorra o array usando aritmética de ponteiros.
5. Crie uma função printArray() para exibir os resultados.
Regra: não utilize a sintaxe array[i] para acessar os elementos. Utilize *(ptr + i) ou avance o ponteiro.
Entrada:
Digite 10 numeros:
7 2 9 4 6 3 8 1 5 10

Saída esperada:
Numeros pares: 2 4 6 8 10
Quantidade de pares: 5

Numeros impares: 7 9 3 1 5
Quantidade de impares: 5
*/

#include <iostream>

#define SIZE 10

using namespace std;


void readArray(int* ptr){
    cout <<"Digite 10 numeros: ";
    for (int i = 0; i < SIZE; i++){
        cin>>*ptr;
        ptr++;
    }
}

void separateNumbers (int* array, int* pares, int* impares, int* qtdPares, int* qtdImpares){

    for (int i = 0; i< SIZE; i++){
        if (*array%2 == 0){
            *pares = *array;
            (*qtdPares)++;
            pares++;   
        }
        else{
            *impares = *array;
            (*qtdImpares)++;
            impares++;
        }
        array++;
    }
}

void printArray(int* pares, int* impares, int* qtdPares, int* qtdImpares){
    
    cout<<"Numeros pares: ";
    for (int i = 0; i<*qtdPares;i++){
        cout<<*pares<<" ";
        pares++;
    }
    cout<<endl;
    cout<<"Quantidade de pares: "<<*qtdPares<<" ";
    
    cout<<endl;
    cout<<"Numeros impares: ";
    for (int i = 0; i<*qtdImpares;i++){
        cout<<*impares<<" ";
        impares++;
    }
    cout<<endl;
    cout<<"Quantidade de impares: "<<*qtdImpares<<" ";
}

int main (void){
    
    int par = 0, imp = 0;
    int array[SIZE],pares[SIZE],impares[SIZE];

    int* qtdPares = &par;
    int* qtdImpares = &imp;
    
    readArray(array);
    separateNumbers(array, pares, impares, qtdPares, qtdImpares);
    printArray(pares, impares, qtdPares, qtdImpares);

    return 0;
}