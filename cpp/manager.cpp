#include <vector>
#include <memory>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "manager.h"
#include "exceptions.h"

using mmPtr = std::shared_ptr<Multimedia>;
using pPtr = std::shared_ptr<Photo>;
using vPtr = std::shared_ptr<Video>;
using fPtr = std::shared_ptr<Film>;
using gPtr = std::shared_ptr<Group>;

pPtr Manager::createPhoto(std::string name, std::string filepath, double latitude, double longitude)
{
    pPtr p = pPtr(new Photo(name, filepath, latitude, longitude));
    if (mediaCollection.count(name) > 0)
    {
        throw NamingError("Photo name already exists!");
    }
    mediaCollection[name] = p;
    return p;
}

vPtr Manager::createVideo(std::string name, std::string filepath, int duration)
{
    vPtr v = vPtr(new Video(name, filepath, duration));
    if (mediaCollection.count(name) > 0)
    {
        throw NamingError("Video name already exists!");
    }
    mediaCollection[name] = v;
    return v;
}

fPtr Manager::createFilm(std::string name, std::string filepath, int duration, const int *chapters, size_t n_chapters)
{
    fPtr f = fPtr(new Film(name, filepath, duration, chapters, n_chapters));
    if (mediaCollection.count(name) > 0)
    {
        throw NamingError("Film name already exists!");
    }
    mediaCollection[name] = f;
    return f;
}

fPtr Manager::copyAndCreateFilm(const Film &otherFilm)
{
    fPtr f = fPtr(new Film(otherFilm));
    mediaCollection[otherFilm.getName()] = f;
    return f;
}

gPtr Manager::createGroup(std::string groupName)
{
    gPtr group = gPtr(new Group());
    group->setName(groupName);
    if (mediaGroups.count(groupName) > 0)
    {
        throw NamingError("Group name already exists!");
    }
    mediaGroups[groupName] = group;
    return group;
}

std::ostream &Manager::searchAndDisplay(const std::string &name, std::ostream &os) const
{
    auto mediaIt = mediaCollection.find(name);
    if (mediaIt != mediaCollection.end())
    {
        mediaIt->second->display(os);
        return os;
    }

    auto groupIt = mediaGroups.find(name);
    if (groupIt != mediaGroups.end())
    {
        groupIt->second->display(os);
        return os;
    }

    throw NamingError("No group or multimedia with this name exists!");
}

void Manager::playMedia(const std::string &name) const
{
    auto mediaIt = mediaCollection.find(name);
    if (mediaIt != mediaCollection.end())
    {
        mediaIt->second->play();
        return;
    }
    std::cout << "No multimedia found with the name: " << name << std::endl;
}

void Manager::deleteByName(const std::string &name)
{
    auto mediaIt = mediaCollection.find(name);
    if (mediaIt != mediaCollection.end())
    {
        mediaCollection.erase(mediaIt);
        std::cout << "Multimedia object with name " << name << " deleted.\n";
        return;
    }

    auto groupIt = mediaGroups.find(name);
    if (groupIt != mediaGroups.end())
    {
        mediaGroups.erase(groupIt);
        std::cout << "Group with name " << name << " deleted.\n";
        return;
    }

    // std::cout << "No multimedia or group found with the name: " << name << std::endl;
    throw NamingError("No multimedia or group found with the name " + name);
}

void Manager::read(const std::string &filename)
{
    std::string line;
    std::ifstream f(filename);
    if (!f.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    while (std::getline(f, line))
    {
        //std::cout << "Getting line: " << line << std::endl;
        std::stringstream ss(line);
        std::string className;
        std::string Name;
        std::string Filepath;
        std::string Latitude;
        std::string Longitude;
        std::string Duration;
        std::string N_chapters;
        ss >> className;
        if (className == "Photo")
        {
            ss >> Name >> Filepath >> Latitude >> Longitude;
            double latitudeNum;
            double longitudeNum;
            latitudeNum = atof(Latitude.c_str());
            longitudeNum = atof(Longitude.c_str());
            try
            {
                createPhoto(Name, Filepath, latitudeNum, longitudeNum);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                return;
            }
        }
        else if (className == "Video")
        {
            ss >> Name >> Filepath >> Duration;
            int durationNum;
            durationNum = atoi(Duration.c_str());
            try
            {
                createVideo(Name, Filepath, durationNum);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                return;
            }
        }
        else if (className == "Film")
        {
            ss >> Name >> Filepath >> Duration >> N_chapters;
            int chaptersNum;
            chaptersNum = atoi(N_chapters.c_str());
            int durationNum;
            durationNum = atoi(Duration.c_str());
            if (chaptersNum != 0)
            {
                int *chapters = new int[chaptersNum];
                for (int i = 0; i < chaptersNum; ++i)
                {
                    std::string chapter;
                    ss >> chapter;
                    chapters[i] = atoi(chapter.c_str());
                }
                try
                    {
                        createFilm(Name, Filepath, durationNum, chapters, chaptersNum);
                        delete[] chapters;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                        return;
                    }
            }
            else
            {
                throw std::invalid_argument("Chapters cannot be empty!");
            }
        }
        else
        {
            std::cerr << "Class type " << className << " doesn't exist" << std::endl;
        }
    }
}

std::map<std::string, mmPtr> Manager::getMedias() const
{
    return mediaCollection;
}