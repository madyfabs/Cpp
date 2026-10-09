/*
 * Exercise: Unique Pointers
 *
 * Create a class called Car with the following members:
 *
 * - string brand
 * - string model
 * - int year
 *
 * The class must have:
 * - A constructor that initializes all members using a member
 *   initializer list.
 * - A const method called displayInfo() that displays all car data.
 *
 * In main():
 * 1. Create a Car object using std::make_unique<Car>().
 * 2. Display its information.
 * 3. Transfer ownership from the first unique_ptr to a second one
 *    using std::move().
 * 4. Check whether the first unique_ptr is empty.
 * 5. Display the car information using the second unique_ptr.
 *
 * Requirements:
 * - Include the <memory> header.
 * - Do not use new or delete explicitly.
 * - Do not copy a unique_ptr.
 * - Use std::move() to transfer ownership.
 * - Explain in a comment when the Car object is destroyed.
 */

#include <iostream>
#include <string>
#include <memory>

using namespace std;


class Car{

    public:
        string brand;
        string model;
        int year;
    
        Car (string brand, string model, int year) :
            brand(brand),
            model(model),
            year(year)
        {}

        void displayInfo() const;
};

void Car::displayInfo() const{
    cout << brand << " " << model << " " << year << endl;
}

int main(void){

    unique_ptr<Car> ptr = make_unique<Car>("Toyota","Etios", 2020);
    unique_ptr<Car> ptr_2;
    
    ptr->displayInfo();

    //Ownership moved to ptr_2
    ptr_2 = move(ptr);
    
    //Check if ptr is now empty;
    if(ptr){
        cout<<"Não vazio!"<<endl;
    }
    else{
        cout<<"Vazio!"<<endl;
    }

    //Display Car info again but now using the ptr_2
    ptr_2->displayInfo();

    //Now the Car objet is destroyed!

    return 0;
}//Now the Car objet is destroyed!