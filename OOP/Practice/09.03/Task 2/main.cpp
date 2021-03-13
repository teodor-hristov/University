#include <iostream>

using namespace std;

struct Person{
private:
    char* name;
    char* surname;
    char* egn;
    int experience;
    int soldCars;
public:
    Person(char* name, char* surname, char* egn, int exp, int soldCars);
    ~Person();

    char* getName() {
        return name;
    }
    char* getSurname() {
        return surname;
    }
    char* getEgn(){
        return egn;
    }
    int getExp(){
        return experience;
    }
    int getSoldCars(){
        return soldCars;
    }
    void setName(char* value){
        name = value;
    }
    void setSurname(char* value){
        surname = value;
    }
    void setEgn(char* value){
        egn = value;
    }
    void setExp(int value){
        experience = value;
    }
    void setSoldCars(int value){
        soldCars = value;
    }
};

Person::Person(char* name, char* surname, char* egn, int exp, int soldCars) {
    this->setName(name);
    this->setSurname(surname);
    this->setEgn(egn);
    this->setExp(exp);
    this->setSoldCars(soldCars);
}
Person::~Person() {
}

struct Car{
private:
    char* brand;
    char* model;
    int yearOfCreation;
    double price;
    double mileage;
public:
    Car(char* brand, char* model, int year, double price, double mileage);
    ~Car();
    char* getBrand(){
        return brand;
    }
    char* getModel(){
        return model;
    }
    int getYearOfCreation(){
        return yearOfCreation;
    }
    double getPrice(){
        return price;
    }
    double getMileage(){
        return mileage;
    }
};

Car::Car(char *brand, char *model, int year, double price, double mileage) {
    this->brand = brand;
    this->model = model;
    this->yearOfCreation = year;
    this->price = price;
    this->mileage = mileage;
}
Car::~Car() {

}

struct Dealership{
private:
    Person owner;
    Person* staff;
    Car* cars;
public:
    Dealership(const Person &owner, Person *staff, Car *cars) :
    owner(owner){
        this->owner = owner;
        this->staff = staff;
        this->cars = cars;
    }

    ~Dealership() {
    }

    Person getOwner(){
        return owner;
    }
    Person* getStaff() {
        return staff;
    }
    Car* getCars(){
        return cars;
    }
};

int main() {
    Person worker1 = Person("Teodor", "Hristov", "01123123", 12, 4);
    Person worker2 = Person("Asen", "Bojilov", "01123223", 11, 5);
    Person owner = Person("Petar", "Armqnov", "011232343", 41, 800);
    Car car1 = Car("Honda", "Civic", 1992, 1400, 200000);
    Car car2 = Car("VW", "Passat", 1989, 950.5, 10000000);

    Person staff[2] = {worker1, worker2};
    Car cars[2] = {car1, car2};

    Dealership sofiaAuto = Dealership(owner,staff, cars);

    //TODO: finish the task

}
