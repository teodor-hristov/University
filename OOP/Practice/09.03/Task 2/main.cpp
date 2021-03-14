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
    Person() {};
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

    void printPersonInfo() {
        cout << "Name: " <<this->getName() << " " << " Surname: " <<this->getSurname() << " " << " EGN " <<this->getEgn() << " " <<" EXP " <<this->getExp() << "  " <<" Sold cars " << this->getSoldCars() << endl;
    }

    bool equalTo(Person &person){
        if(this->getEgn() == person.getEgn()){
            return 1;
        } else {
            return 0;
        }
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
    Car();
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

    void printCar(){
        cout << this->brand << " " << this->model << " " << this->price << endl;
    }

    bool eaqualTo(Car secondCar) {
        if(this->brand == secondCar.brand
        && this->model == secondCar.model
        && this->price == secondCar.price
        && this->mileage == secondCar.mileage
        && this->yearOfCreation == secondCar.yearOfCreation)
        {
            return 1;
        }else {
            return 0;
        }
    }
};
Car::Car() {};
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
    int carCount;
    int workersCount;
public:
    Dealership(Person &owner) :
    owner(owner){
        cout << owner.getName() << " created dealership. " << endl;
        this->owner = owner;
        carCount = 0;
        workersCount = 0;
    }

    void setWorkersCount(int workersCount) {
        this->workersCount = workersCount;
    }

    int getWorkersCount() const {
        return workersCount;
    }

    ~Dealership() {
        if(this->getCars()) {
            delete[] this->getCars();
        }
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
    void setCars(Car* cars){
        this->cars = cars;
    }

    int getCarCount() {
        return this->carCount;
    }

    void setCarCount(int num) {
        this->carCount = num;
    }

    void printCars() {
        for (int i = 0; i < this->getCarCount(); ++i) {
            this->cars[i].printCar();
        }
    }

    void setStaff(Person *staff) {
        Dealership::staff = staff;
    }

    void printWorkers(){
        for(int i = 0; i < this->workersCount; i++) {
            this->getStaff()[i].printPersonInfo();
        }
    }

    void changeOwner(Person &newOwner) {
        this->owner = newOwner;
        cout << "Owner changed to " << newOwner.getName() << endl;
    }

    void sortWorkers(){
        for (int i = 0; i < this->getWorkersCount(); ++i) {
            for (int j = i; j < this->getWorkersCount(); ++j) {
               if((double)this->getStaff()[i].getSoldCars() / (double)this->getStaff()[i].getExp() <
               (double)this->getStaff()[j].getSoldCars() / (double)this->getStaff()[j].getExp()) {
                   swap(this->getStaff()[i], this->getStaff()[j]);
               }
            }
        }
    }

    void sortCars(){
        for (int i = 0; i < this->getCarCount(); ++i) {
            for (int j = i; j < this->getCarCount(); ++j) {
                if((double)this->getCars()[i].getPrice() / (double)this->getCars()[i].getMileage() <
                   (double)this->getCars()[j].getPrice() / (double)this->getCars()[j].getMileage()) {
                    swap(this->getCars()[i], this->getCars()[j]);
                }
            }
        }
    }

};

void addCar(Dealership &dealer, Car &car) {
    Car* newCarArray = new Car[dealer.getCarCount() + 1];
    for (int i = 0; i < dealer.getCarCount(); ++i) {
        newCarArray[i] = dealer.getCars()[i];
    }
    newCarArray[dealer.getCarCount()] = car;
    if(dealer.getCarCount()){
        delete[] dealer.getCars();
    }
    dealer.setCarCount(dealer.getCarCount() + 1);
    dealer.setCars(newCarArray);
}

void sellCar(Dealership &dealer, Car &car, Person &seller) {
    size_t tempCounter = 0;
    Car* newCarArray = new Car[dealer.getCarCount() - 1];
    for (int i = 0; i < dealer.getCarCount(); ++i) {
        if(!dealer.getCars()[i].eaqualTo(car)) {
            newCarArray[tempCounter] = dealer.getCars()[i];
            tempCounter++;
        }
    }
    if(dealer.getCars()){
        delete[] dealer.getCars();
    }
    dealer.setCarCount(dealer.getCarCount() - 1);
    dealer.setCars(newCarArray);
    seller.setSoldCars(seller.getSoldCars() + 1);
    cout << seller.getName() << " sold ";
    car.printCar();
    cout << endl;
}

void addWorker(Dealership &dealer, Person &worker) {
    Person* newWorkerArr = new Person[dealer.getWorkersCount() + 1];
    for (int i = 0; i < dealer.getWorkersCount(); ++i) {
        newWorkerArr[i] = dealer.getStaff()[i];
    }
    newWorkerArr[dealer.getWorkersCount()] = worker;
    if(dealer.getWorkersCount()){
        delete[] dealer.getStaff();
    }
    dealer.setWorkersCount(dealer.getWorkersCount() + 1);
    dealer.setStaff(newWorkerArr);
}

void removeWorker(Dealership &dealer, Person &worker) {
    size_t tempCounter = 0;
    Person* newWorkerArr = new Person[dealer.getWorkersCount() - 1];
    for (int i = 0; i < dealer.getWorkersCount(); ++i) {
        if(!dealer.getStaff()[i].equalTo(worker)) {
            newWorkerArr[tempCounter] = dealer.getStaff()[i];
            tempCounter++;
        }
    }
    if(dealer.getStaff()){
        delete[] dealer.getStaff();
    }
    dealer.setWorkersCount(dealer.getWorkersCount() - 1);
    dealer.setStaff(newWorkerArr);

    cout << worker.getName() << " has been fired." << endl;

}

int main() {
    Person worker1 = Person("Teodor", "Hristov", "01123123", 12, 4);
    Person worker2 = Person("Asen", "Bojilov", "01123223", 11, 5);
    Person owner = Person("Petar", "Armqnov", "011232343", 41, 800);
    Car car1 = Car("Honda", "Civic", 1992, 1400, 200000);
    Car car2 = Car("VW", "Passat", 1989, 950.5, 10000000);


    Dealership sofiaAuto = Dealership(owner);
    addCar(sofiaAuto,car2);
    addCar(sofiaAuto, car1);
    cout << "Cars currently active in dealership Sofia Auto:" << endl;
    sofiaAuto.printCars();
    sellCar(sofiaAuto, car2, worker2);
    sofiaAuto.printCars();

    addWorker(sofiaAuto, worker1);
    addWorker(sofiaAuto, worker2);
    cout << "Workers in Sofia Auto: " << endl;
    sofiaAuto.printWorkers();
    removeWorker(sofiaAuto, worker1);
    sofiaAuto.printWorkers();

    sofiaAuto.sortWorkers();
    cout << "Workers sorted." << endl;
    sofiaAuto.printWorkers();

    sofiaAuto.sortCars();
    cout << "Cars sorted." << endl;
    sofiaAuto.printCars();

}
