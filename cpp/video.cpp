#include "video.h"
#include <iostream>
#include <string>
#include <fstream>

Video::Video(std::string name, std::string filepath, int duration)
    : Multimedia(name, filepath), duration(duration) {}

Video::Video()
    : Multimedia(), duration(0) {}

Video::~Video()
{
    // std::cout << "Video object DESTROYED: " << name << "\n";
}

int Video::getDuration() const
{
    return duration;
}

void Video::setDuration(int duration)
{
    this->duration = duration;
}

std::ostream &Video::display(std::ostream &os) const
{
    os << "Name: " << name << ", " << "filepath: " << filepath << ", "
       << "Duration: " << duration << std::endl;
    return os;
}

void Video::play() const
{
    std::cout << "Displaying a video\n";
    std::string string = "mpv " + filepath + " &";
    const char *cstring = string.data();
    if (system(cstring))
    {
        std::cout << "File DNE\n";
        exit(EXIT_FAILURE);
    };
}

void Video::write(const std::string& filename) const {
    std::ofstream f(filename, std::ios::app); // append to the file
    f << "Video " << name << " " <<  filepath << " "
       << duration << std::endl;
    std::cout << "Writing Video " << name << std::endl;
    f.close();
}