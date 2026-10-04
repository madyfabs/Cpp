#include <iostream>

#define SIZE 5

using namespace std;

void readArray(int* ptr){
    cout<<"Insira os 5 elementos do vetor: ";
    for (int i = 0; i < SIZE; i++){
        cin>> *ptr;
        ptr++;
    }
    cout<<endl;
}

void reverseArray(int* ptr){
   
    int aux = 0;
    int j = 0;

    for (int i = SIZE-1; i >=0; i--){

        if (i == j){
            break;
        }
        aux = *(ptr+j);
        *(ptr+j) = *(ptr+i);
        *(ptr+i) =  aux;
        j++;
    } 

    for (int i = 0; i < SIZE; i++){
        cout<<*ptr<<" ";
        ptr++;
    }

}

int main(void){
   
    int array[SIZE];

    readArray(array);
    reverseArray(array);

    return 0;
}