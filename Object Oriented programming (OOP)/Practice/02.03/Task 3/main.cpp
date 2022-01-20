#include <iostream>
#include <cmath>

using namespace std;

const int SPEED_OF_LIGHT = 299792;

struct Planet{
    char name[32] = {0,};
    double distanceFromSun;
    double diameter;
    double mass;
};

Planet createPlanet(){
    Planet result;
    cout << "Name: " << endl;
    cin >> result.name;
    cout << "Distane from the Sun: " << endl;
    cin >> result.distanceFromSun;
    cout << "Diameter: " << endl;
    cin >> result.diameter;
    cout << "Mass: " << endl;
    cin >> result.mass;

    return result;
}

void printPlanetData(Planet &planet) {
    cout << "Name: " << endl;
    cout << planet.name<< endl;
    cout << "Distane from the Sun: " << endl;
    cout << planet.distanceFromSun<< endl;
    cout << "Diameter: " << endl;
    cout << planet.diameter<< endl;
    cout << "Mass: " << endl;
    cout << planet.mass << endl;
}

double getTravelTime(Planet planet) {
    return planet.distanceFromSun/ SPEED_OF_LIGHT;
}

int main() {
    Planet planets[10] = {0,};

    for(int i = 0; i < 10; i++) {
        planets[i] = createPlanet();
    }

    for (int i = 0; i < 10; ++i) {
        cout << "=========================" << endl;
        printPlanetData(planets[i]);
    }
    cout << "======================" << endl;
    Planet minMass = planets[0];
    for (int i = 0; i < 10; ++i) {
                if(planets[i].mass < minMass.mass) {
            minMass = planets[i];
        }
    }
    printPlanetData(minMass);
}
