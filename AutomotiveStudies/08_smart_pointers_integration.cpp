
/*
 * Exercise: Smart Pointers Integration
 *
 * Create a class called Car with the following members:
 *
 * - string brand
 * - string model
 * - int year
 *
 * The class must have:
 * - A constructor using a member initializer list.
 * - A destructor that prints a message when the Car is destroyed.
 * - A const method called displayInfo() that displays all car data.
 *
 * In main():
 *
 * 1. Create a unique_ptr<Car> using std::make_unique().
 * 2. Display the car information.
 * 3. Transfer ownership to a second unique_ptr using std::move().
 * 4. Check whether the first unique_ptr is empty.
 *
 * 5. Create a shared_ptr<Car> using std::make_shared().
 * 6. Create a second shared_ptr by copying the first one.
 * 7. Display the ownership count.
 * 8. Modify the car's year and display the updated information
 *    using the second shared_ptr.
 *
 * 9. Create a weak_ptr<Car> observing the shared object.
 * 10. Use lock() to access the car if it still exists.
 * 11. Reset both shared_ptr instances.
 * 12. Check whether the weak_ptr has expired.
 * 13. Try to access the object through lock() and handle the case
 *     where the object no longer exists.
 *
 * Requirements:
 * - Include the <memory> header.
 * - Do not use new or delete explicitly.
 * - Use std::make_unique() and std::make_shared().
 * - Do not copy a unique_ptr.
 * - Use std::move() to transfer unique_ptr ownership.
 * - Do not access an object directly through a weak_ptr.
 * - Check the result of lock() before accessing the object.
 * - Explain in comments when each Car object is destroyed.
 */

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

    Car(string brand, string model, int year)
        : brand(brand),
          model(model),
          year(year)
    {}

    ~Car() {
        cout << "Carro destruido!" << endl;
    }

    void displayInfo() const;
};

void Car::displayInfo() const {
    cout << brand << " " << model << " " << year << endl;
}

int main(void) {

    unique_ptr<Car> ptr =
        make_unique<Car>("Toyota", "Etios", 2020);

    unique_ptr<Car> ptr_2;

    // Display the first car.
    ptr->displayInfo();

    // Transfer ownership from ptr to ptr_2.
    // ptr becomes empty, but the Car object remains alive.
    // The object will be destroyed when ptr_2 releases ownership.
    ptr_2 = move(ptr);

    // Check whether ptr is empty after the ownership transfer.
    if (ptr) {
        cout << "Objeto vive" << endl;
    } else {
        cout << "Vazio!" << endl;
    }

    // Create a second, independent Car object managed by shared_ptr.
    shared_ptr<Car> ptr_3 =
        make_shared<Car>("Honda", "HRV", 1999);

    // Create another shared owner of the same Car object.
    auto shared = ptr_3;

    // There are now two shared_ptr owners.
    cout << ptr_3.use_count() << endl;

    // Modify the shared Car object and display it using the second owner.
    shared->year = 2099;
    shared->displayInfo();

    // Create a weak_ptr that observes the shared Car without owning it.
    weak_ptr<Car> weak = ptr_3;

    // lock() temporarily obtains shared ownership if the object still exists.
    if (auto temp = weak.lock()) {
        cout << "Carro [2] ainda acessivel" << endl;
        // temp is destroyed at the end of this if block.
        // ptr_3 and shared continue to own the Car object.
    } else {
        cout << "Carro [2] NAO acessivel" << endl;
    }

    // Release the ownership held by ptr_3.
    // The shared ownership count decreases from 2 to 1.
    // The Car object is NOT destroyed yet because shared still owns it.
    ptr_3.reset();

    // Release the last shared ownership.
    // The ownership count reaches 0, so this Car object is destroyed here.
    shared.reset();

    // weak still exists, but the Car object it observed has been destroyed.
    if (weak.expired()) {
        cout << "Objeto observado n existe mais!" << endl;
    } else {
        cout << "Objeto observado AINDA existe!" << endl;
    }

    // lock() returns an empty shared_ptr because the object no longer exists.
    if (auto temp = weak.lock()) {
        cout << "Carro [2] ainda acessivel" << endl;
        temp->displayInfo();
    } else {
        cout << "Carro [2] NAO acessivel" << endl;
    }

    return 0;

    // When main() ends, ptr_2 is destroyed.
    // This releases the unique ownership and destroys the first Car object.
}
