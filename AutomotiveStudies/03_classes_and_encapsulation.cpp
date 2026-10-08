/*
 * Exercise: Classes and Encapsulation
 *
 * Create a class called Car with the following private members:
 *
 * - string brand
 * - string model
 * - int year
 * - float price
 *
 * The class must provide public methods to:
 *
 * 1. Set the car information:
 *    - setBrand()
 *    - setModel()
 *    - setYear()
 *    - setPrice()
 *
 * 2. Get the car information:
 *    - getBrand()
 *    - getModel()
 *    - getYear()
 *    - getPrice()
 *
 * 3. Display all car information:
 *    - displayInfo()
 *
 * In the main() function:
 * - Create a Car object.
 * - Set its information using the public methods.
 * - Display all information using displayInfo().
 * - Change the price using setPrice().
 * - Display the information again.
 *
 * Requirements:
 * - The data members must be private.
 * - The methods must be public.
 * - Do not access the private members directly from main().
 * - Use getters and setters to access or modify the data.
 */

 #include<iostream>
 #include<string>


using namespace std;

class Car{
    private:
        string brand;
        string model;
        int year;
        float price;
    public:
        Car(){}
        Car(string brand, string model, int year, float price){
            this->brand = brand;
            this->model = model;
            this->year = year;
            this->price = price;
        }
        ~Car() {
        cout << "Destrutor ativado!" <<endl;
        }
        void setBrand(string brand);
        void setModel(string model);
        void setYear(int year);
        void setPrice(float price);
        void displayInfo();
        string getBrand();
        string getModel();
        int getYear();
        float getPrice();
};


void Car::setBrand(string brand){
    this->brand = brand;
}

void Car::setModel(string model){
    this->model = model;
}

void Car::setYear(int year){
    this->year = year;
}

void Car::setPrice(float price){
    this->price = price;
}

string Car::getBrand(){
    return this->brand;
}

string Car::getModel(){
    return this->model;
}

int Car::getYear(){
    return this->year;
}

float Car::getPrice(){
    return this->price;
}

void Car::displayInfo(){
    cout<<"Dados do Carro:"<<endl;
    cout<<"Marca: "<<this->brand<<" Modelo: "<<this->model<<" Ano: "<<this->year<<" Preço: "<<this->price<<endl;
}

int main(void){

    Car carro;

    carro.setBrand("Toyota");
    carro.setModel("Etios");
    carro.setPrice(1000.0);
    carro.setYear(2000);

    carro.displayInfo();

    carro.setPrice(2000.0);

    carro.displayInfo();

    return 0;
}