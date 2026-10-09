/*
 * Exercise: Weak Pointers
 *
 * Create a class called Car with the following members:
 *
 * - string brand
 * - string model
 *
 * The class must have:
 * - A constructor that initializes the members using a member
 *   initializer list.
 * - A destructor that prints a message when the Car object is
 *   destroyed.
 * - A const method called displayInfo() that displays the car data.
 *
 * In main():
 * 1. Create a shared_ptr<Car> using std::make_shared<Car>().
 * 2. Create a weak_ptr<Car> observing the same object.
 * 3. Check whether the weak_ptr has expired.
 * 4. Use lock() to access and display the car information.
 * 5. Reset the shared_ptr, releasing its ownership.
 * 6. Check whether the weak_ptr has expired again.
 * 7. Try to use lock() after the object has been destroyed.
 *
 * Requirements:
 * - Include the <memory> header.
 * - Do not use new or delete explicitly.
 * - Use std::make_shared().
 * - Do not access the object directly through the weak_ptr.
 * - Check the result of lock() before accessing the object.
 * - Explain in a comment why the object is destroyed after reset().
 */
#include <iostream>
#include <string>
#include <memory>


using namespace std;


class Car{

    public:
        string brand;
        string model;
            
        Car (string brand, string model) :
            brand(brand),
            model(model)
        {}

        ~Car(){
            cout<<"Carro destruido!"<<endl;
        }

        void displayInfo() const;
};

void Car::displayInfo() const{
    cout << brand << " " << model << endl;
}

int main(void){

    shared_ptr<Car> ptr = make_shared<Car>("Toyota","Etios");
    weak_ptr<Car> ptr2 = ptr;

    if (ptr2.expired()) {
      cout<<"Objeto voyeurado n existe mais!"<<endl;
    }

   if(auto tempPtr = ptr2.lock()){
      tempPtr->displayInfo();
   }
   else{
     cout<<"Objeto voyeurado n existe mais!"<<endl;
   }

   ptr.reset();

    if (ptr2.expired()) {
      cout<<"Objeto voyeurado n existe mais!"<<endl;
    }

    if(auto tempPtr = ptr2.lock()){
      tempPtr->displayInfo();
   }
   else{
     cout<<"Objeto voyeurado n existe mais!"<<endl;
   }


    return 0;
}
