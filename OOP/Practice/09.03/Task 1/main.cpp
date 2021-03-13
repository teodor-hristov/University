#include <iostream>

using namespace std;

struct Person{
private:
    char* name;
    int age;
    int height;
    double weight;
public:
    void setName(char* &value){
        name = value;
    }
    void setAge(int value) {
        age = value;
    }
    void setHeight(int value) {
        height = value;
    }
    void setWeight(double value) {
        weight = value;
    }
    char* getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    int getHeight(){
        return height;
    }
    double getWeight(){
        return weight;
    }

    Person(char* name, int age, int height, int weight){
        setName(name);
        setAge(age);
        setHeight(height);
        setWeight(weight);
    }

    ~Person(){
    };

};

double getBMI(Person &person){
    return person.getWeight()/person.getHeight()*person.getHeight();
}

void sortByBMI(Person* people, int len){
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if(getBMI(people[i]) > getBMI(people[j])){
                swap(people[i], people[j]);
            }
        }
    }
}

void printPerson(Person &person){
    cout << "Name: " << person.getName() << "\nAge: "<< person.getAge()
    << "\nHeight: "<< person.getHeight() << "\nWeight: "<< person.getWeight() << endl;
}

int getOldest(Person* people, int len){
    int max = people[0].getAge();
    for (int i = 0; i < len; ++i) {
        if(people[i].getAge() > max) {
            max = people[i].getAge();
        }
    }
    return max;
}

double avgWeight(Person* people, int len) {
    double result = 0;
    for (int i = 0; i < len; ++i) {
        result += getBMI(people[i]);
    }

    return result / len;
}

void printOldest(Person* people, int len) {
    int oldest = getOldest(people, len);
    for (int i = 0; i < len; ++i) {
        if(people[i].getAge() == oldest) {
            printPerson(people[i]);
        }
    }
}

void printAvgWeightPeople(Person* people, int len){
   double weight = avgWeight(people, len);
    for (int i = 0; i < len; ++i) {
        if(weight > people[i].getWeight()){
            printPerson(people[i]);
        }
    }
}

int main() {
Person peshko = Person("Peshko", 12,180,103);
Person goshko = Person("Goshko", 21, 140, 70);
Person vasko = Person("Azi", 15, 191, 115);

Person gang[3] = {peshko,goshko,vasko};

    sortByBMI(gang,3);

    printOldest(gang,3);
    printAvgWeightPeople(gang,3);


}
