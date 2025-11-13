#include "photo.h"
#include <string>
#include <iostream>
#include <fstream>

Photo::Photo(): Multimedia(), latitude(0), longitude(0){}

Photo::Photo(std::string name, std::string filepath, double latitude, double longitude)
: Multimedia(name, filepath), latitude(latitude), longitude(longitude){}

Photo::~Photo(){
    std::cout << "Photo object DESTROYED: " << name <<"\n";
}

double Photo::getLatitude() const{
    return latitude;
}

void Photo::setLatitude(double latitude){
    this->latitude = latitude;
}

double Photo::getLongitude() const{
    return longitude;
}

void Photo::setLongitude(double longitude){
    this->longitude = longitude;
}

std::ostream& Photo::display(std::ostream& os) const{
    os << "Name: " << name << ", "<< "filepath: " << filepath << ", "
    <<  "Latitude: " << latitude << ", " << "Longitude: " << longitude << std::endl;
    return os;
}

void Photo::play() const {
    std::cout << "Displaying a photo\n" ;
    std::string string = "imagej "+filepath+" &";
    const char *cstring = string.data();
    if (system(cstring)){
        std::cout << "File DNE\n" ;
        exit(EXIT_FAILURE);
    };

}

void Photo::write(const std::string& filename) const {
    std::ofstream f(filename, std::ios::app); // if append to the file: 
    f << "Photo " << name << " "<< filepath << " "
    << latitude << " " << longitude << std::endl;
    std::cout << "Writing Photo " << name << std::endl;
    f.close();
}


