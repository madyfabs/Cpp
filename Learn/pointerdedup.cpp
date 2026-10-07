#include <iostream>

#define SIZE 10

using namespace std;

void readArray(int* array){
    for (int i = 0; i < SIZE; i++){
        cin >> *array;
        array++;
    }
}

void removeDuplicates(int* array, int* dedupSize){

    for (int i = 0; i < *dedupSize - 1; i++){

        for (int j = i + 1; j < *dedupSize; j++){

            if (*(array + i) == *(array + j)){

                // Desloca os elementos para a esquerda
                for (int k = j; k < *dedupSize - 1; k++){
                    *(array + k) = *(array + k + 1);
                }

                (*dedupSize)--;

                // Não incrementamos j aqui
                // porque um novo elemento ocupou a posição j
                j--;
            }
        }
    }
}

void printArray(int* array, int* dedupSize){
    for (int i = 0; i < *dedupSize; i++){
        cout << *array << " ";
        array++;
    }
}

int main(void){

    int array[SIZE];
    int dedupSize = SIZE;

    readArray(array);

    removeDuplicates(array, &dedupSize);

    printArray(array, &dedupSize);

    return 0;
}