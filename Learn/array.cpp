#include <iostream>

using namespace std;

#define SIZE 10

#ifdef SIZE
void encheArray(int* array){
    
    cout<<"Insira os 10 elementos do array: ";
    for (int i = 0; i < SIZE; i++){
        cin>>array[i]; 
    }
}

void imprimeArray (int* array){
    for (int i = 0; i < SIZE; i++){
        cout<<array[i]<<" ";
    }
}
#endif 


int main (void){
    
    int array[10];

#ifdef SIZE
    encheArray(array);
    imprimeArray(array);
#else
    cout<<"Erro. Tamanho do array não definido!";
#endif 

    return 0;
}