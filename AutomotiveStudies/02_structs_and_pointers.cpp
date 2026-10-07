/*
 * Exercise: Structs and Pointers
 *
 * Create a struct called Car containing the following members:
 *
 * - string brand
 * - string model
 * - int year
 * - float price
 *
 * Create a function:
 *
 * void updateCar(Car* car)
 *
 * This function must:
 * - Change the car's year to 2026.
 * - Increase its price by 10%.
 *
 * In the main() function:
 * - Create a Car object.
 * - Read its information from the user.
 * - Display the original information.
 * - Call updateCar() using a pointer.
 * - Display the updated information.
 *
 * Requirements:
 * - Use a pointer to access and modify the Car object inside updateCar().
 * - Do not return the Car object from the function.
 * - Access the struct members through the pointer.
 */

#include <iostream>

using namespace std;

struct Car{
   string brand;
   string model;
   int year;
   float price;    
};

void updateCar(Car* car){
    car->year = 2026;
    car->price += car->price * 0.1;
}

int main(void){

    Car carro;
    Car* ptr = &carro;
    
    //IO
    cout<<"Insira a marca do carro: ";
    cin>>carro.brand;
    cout<<endl<<endl;

    cout<<"Insira o modelo do carro: ";
    cin>>carro.model;
    cout<<endl<<endl;

    cout<<"Insira o ano do carro: ";
    cin>>carro.year;
    cout<<endl<<endl;
    
    cout<<"Insira o preço do carro: ";
    cin>>carro.price;
    cout<<endl<<endl;
    
    //Valores Lidos sendo impressos
    cout<<"Valores lidos: ";
    cout<<endl;
    cout<<"Marca do carro: ";
    cout<<carro.brand;
    cout<<endl<<endl;

    cout<<"Modelo do carro: ";
    cout<<carro.model;
    cout<<endl<<endl;

    cout<<"Ano do carro: ";
    cout<<carro.year;
    cout<<endl<<endl;
    
    cout<<"Preço do carro: ";
    cout<<carro.price;
    cout<<endl<<endl;
    
    updateCar(ptr);
     
    //Valores depois do updateCar
    cout<<"Ano atualizado do carro: ";
    cout<<carro.year;
    cout<<endl<<endl;
    
    cout<<"Preço atualizado do carro: ";
    cout<<carro.price;
    cout<<endl<<endl;

    return 0;
}