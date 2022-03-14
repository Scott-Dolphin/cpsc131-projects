#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

// This struct is complete
struct Location {
    string name;
    string address;
    string city;
    long postalCode;
    string province;
    double latitude;
    double longitude;
    int priceRangeMin;
    int priceRangeMax;
};

// This class needs to be completed / implemented
class PizzaZine {
private:
    // use a vector
    vector<Location> entries;

public:
    
    // This function is implemented for you
    void readInFile(const string&, size_t);

    // The following functions need to be implemented
    Location& operator[](size_t);
    void add(Location new_location);
    Location& get(size_t);
    Location& first();
    Location& last();

};

// This function is implemented for you

void PizzaZine::readInFile(const string& filename,size_t c) {
    ifstream inFile(filename);
    Location newLoc;

    string line;
    string cell;

    // Read each line
    for (size_t i = 0; i < c; ++i) {
        // Break each line up into 'cells'
        getline(inFile, line);
        stringstream lineStream(line);
        while(getline(lineStream, newLoc.name, ',')) {
            getline(lineStream, newLoc.address, ',');
            getline(lineStream, newLoc.city, ',');
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.postalCode = stoul(cell);
            }

            getline(lineStream, newLoc.province, ',');
            getline(lineStream, cell, ',');
            newLoc.latitude = stod(cell);
            getline(lineStream, cell, ',');
            newLoc.longitude = stod(cell);

            newLoc.priceRangeMin = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.priceRangeMin = stoul(cell);
            }

            newLoc.priceRangeMax = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty() && cell != "\r") {
                newLoc.priceRangeMax = stoul(cell);
            }
            add(newLoc);
        }
    }
}

// Write remaining functions implementation here. For help, refer to "GuildedRose.hpp" in Sample Project Solution

Location& PizzaZine::get(size_t i) {
    return entries.at(i);
}

Location& PizzaZine::operator[](size_t i) {
    return entries.at(i);
}
Location& PizzaZine::first() {
    return entries.front();
}
Location& PizzaZine::last() {
    return entries.back();
}
void PizzaZine::add(Location newLocation){
    entries.push_back(newLocation);
}
