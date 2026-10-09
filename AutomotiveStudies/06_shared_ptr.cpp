/*
 * Exercise: Shared Pointers
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
 * - A destructor that prints a message when the Car object is
 *   destroyed.
 * - A const method called displayInfo() that displays all car data.
 *
 * In main():
 * 1. Create a shared_ptr<Car> using std::make_shared<Car>().
 * 2. Create a second shared_ptr by copying the first one.
 * 3. Display the reference count using use_count().
 * 4. Modify the car's year using the first pointer.
 * 5. Display the car information using the second pointer.
 * 6. Make the second pointer leave scope.
 * 7. Display the reference count again.
 * 8. Observe when the Car destructor is called.
 *
 * Requirements:
 * - Include the <memory> header.
 * - Do not use new or delete explicitly.
 * - Use std::make_shared().
 * - Both pointers must share the same Car object.
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

        ~Car(){
            cout<<"Carro destruido!";
        }

        void displayInfo() const;
};

void Car::displayInfo() const{
    cout << brand << " " << model << " " << year << endl;
}

int main(void){

    shared_ptr<Car> ptr = make_shared<Car>("Toyota","Etios", 2020);

    {
    auto ptr_2 = ptr;
    
    //3. Display the reference count using use_count().
    cout << ptr.use_count() << endl;

    //4. Modify the car's year using the first pointer.
    ptr->year = 2021;

    
        //5. Display the car information using the second pointer.
        ptr_2->displayInfo();

    }//6. Make the second pointer leave scope.

    //7. Display the reference count again.
    cout << ptr.use_count() << endl;

    return 0;
}//8. Observe when the Car destructor is called.

//por que a destruição do carro não acontece quando car2 sai de escopo.
//R = como ptr_2 (car2) compartilha o ownership com o ptr(car1), e considerando que ptr ainda está no escopo da main() o objeto não é destruido até ambos os proprietarios desaparecerem