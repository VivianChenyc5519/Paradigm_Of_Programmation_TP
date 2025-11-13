#include "film.h"
#include <string>
#include <iostream>
#include <fstream>

Film::Film(std::string name, std::string filepath, int duration, const int *c, size_t n_c)
    : Video(name, filepath, duration), n_chapters(n_c)
{
    if (c == nullptr)
    {
        throw std::invalid_argument("Chapters cannot be empty!");
    }

    chapters = new int[n_c];
    for (size_t i = 0; i < n_c; ++i)
    {
        chapters[i] = c[i];
    }
}

Film::Film(const Film &otherFilm) : Video(otherFilm)
{
    if (otherFilm.chapters && n_chapters > 0)
    {
        chapters = new int[n_chapters];
        for (size_t i = 0; i < n_chapters; ++i)
        {
            chapters[i] = otherFilm.chapters[i]; // deep copy
        }
    }
    else
    {
        chapters = nullptr;
    }
}

Film &Film::operator=(const Film &otherFilm)
{
    if (this != &otherFilm)
    {
        Video::operator=(otherFilm);
        delete[] this->chapters;

        n_chapters = otherFilm.n_chapters;
        if (otherFilm.n_chapters > 0 && otherFilm.chapters)
        {
            chapters = new int[n_chapters];
            for (size_t i = 0; i < n_chapters; ++i)
            {
                chapters[i] = otherFilm.chapters[i];
            }
        }
        else
        {
            chapters = nullptr;
        }
    }
    return *this;
}

Film::~Film()
{
    // Avoid memory leak
    delete[] chapters;
    // std::cout << "Film is destroyed\n";
}

// Make a deep copy of the original array to ensure encapsulation
// Use keyword const to avoid changing the origianl value
void Film::setChapters(const int *c, size_t n)
{
    delete[] chapters;
    if (!c || n == 0)
    {
        chapters = nullptr;
        n_chapters = 0;
        return;
    }

    n_chapters = n;
    chapters = new int[n_chapters];
    for (size_t i = 0; i < n; ++i)
    {
        chapters[i] = c[i];
    }
}

const int *Film::getChapters() const
{
    return chapters;
}

size_t Film::getChapterNumber() const
{
    return n_chapters;
}

std::ostream &Film::display(std::ostream &os) const
{
    if (n_chapters != 0 && chapters) // Avoid accessing nullptr
    {
        for (size_t i = 0; i < n_chapters; ++i)
        {
            os << "The duration for chapter " << i 
               << " of the film is " << chapters[i] << std::endl;
        }
        return os;
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

void Film::write(const std::string &filename) const
{
    std::ofstream f(filename, std::ios::app); // append to the file
    f << "Film " << name << " " << filepath << " "
    << duration << " " << n_chapters;
    if (n_chapters != 0 && chapters != nullptr)
    {
        for (size_t i = 0; i < n_chapters; ++i)
            f << " " << chapters[i];
    }
    f << std::endl;
    std::cout << "Writing Film " << name << std::endl;
    f.close();
}
