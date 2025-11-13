/**
 * @file manager.h
 * @brief Header file for the Manager class
 * 
 * This file defines the Manager class which serves as the central management system
 * for multimedia objects and groups. The Manager handles creation, storage, retrieval,
 * and deletion of multimedia items (photos, videos, films) and organizes them into groups.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <memory>
#include <map>

#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"

/** @typedef mmPtr
 *  @brief Alias for shared pointer to Multimedia objects
 */
using mmPtr = std::shared_ptr<Multimedia>;

/** @typedef pPtr
 *  @brief Alias for shared pointer to Photo objects
 */
using pPtr = std::shared_ptr<Photo>;

/** @typedef vPtr
 *  @brief Alias for shared pointer to Video objects
 */
using vPtr = std::shared_ptr<Video>;

/** @typedef fPtr
 *  @brief Alias for shared pointer to Film objects
 */
using fPtr = std::shared_ptr<Film>;

/** @typedef gPtr
 *  @brief Alias for shared pointer to Group objects
 */
using gPtr = std::shared_ptr<Group>;

/**
 * @class Manager
 * @brief Central management system for multimedia objects and groups
 * 
 * The Manager class is responsible for creating, storing, retrieving, and managing
 * multimedia objects (photos, videos, and films) and organizing them into groups.
 * It provides a unified interface for multimedia operations including search, playback,
 * deletion, and serialization. The Manager uses shared pointers for automatic memory
 * management and maintains separate collections for media and groups.
 * 
 * @note The Manager uses maps for efficient lookup of multimedia objects and groups by name
 * 
 * @sa Multimedia, Photo, Video, Film, Group
 */
class Manager
{
public:
    /**
     * @brief Default constructor for Manager
     * 
     * Initializes an empty Manager with no media or groups.
     */
    Manager() = default;

    /**
     * @brief Destructor for Manager
     * 
     * Cleans up all managed multimedia objects and groups through automatic
     * cleanup of shared pointers.
     */
    ~Manager() = default;

    /**
     * @brief Creates a new Photo object and adds it to the media collection
     * 
     * Creates a Photo with the specified properties and stores it in the media
     * collection with its name as the key.
     * 
     * @param[in] name The name/identifier of the photo (default: "")
     * @param[in] filepath The file path to the photo (default: "")
     * @param[in] latitude The latitude coordinate for the photo location (default: 0)
     * @param[in] longitude The longitude coordinate for the photo location (default: 0)
     * 
     * @return A shared pointer to the newly created Photo object
     * 
     * @sa Photo
     */
    pPtr createPhoto(std::string name = "", std::string filepath = "", double latitude = 0, double longitude = 0);

    /**
     * @brief Creates a new Video object and adds it to the media collection
     * 
     * Creates a Video with the specified properties and stores it in the media
     * collection with its name as the key.
     * 
     * @param[in] name The name/identifier of the video (default: "")
     * @param[in] filepath The file path to the video (default: "")
     * @param[in] duration The duration of the video in seconds (default: 0)
     * 
     * @return A shared pointer to the newly created Video object
     * 
     * @sa Video
     */
    vPtr createVideo(std::string name = "", std::string filepath = "", int duration = 0);

    /**
     * @brief Creates a new Film object and adds it to the media collection
     * 
     * Creates a Film with the specified properties including chapter information
     * and stores it in the media collection with its name as the key.
     * 
     * @param[in] name The name/identifier of the film (default: "")
     * @param[in] filepath The file path to the film (default: "")
     * @param[in] duration The duration of the film in seconds (default: 0)
     * @param[in] chapters Pointer to an array of chapter lengths (default: nullptr)
     * @param[in] n_chapters The number of chapters (default: 0)
     * 
     * @return A shared pointer to the newly created Film object
     * 
     * @sa Film
     */
    fPtr createFilm(std::string name = "", std::string filepath = "", int duration = 0, const int *chapters = nullptr, size_t n_chapters = 0);

    /**
     * @brief Creates a copy of an existing Film and adds it to the media collection
     * 
     * Performs a deep copy of the provided Film object and stores the copy
     * in the media collection.
     * 
     * @param[in] otherFilm The Film object to copy
     * 
     * @return A shared pointer to the newly created Film copy
     * 
     * @sa Film
     */
    fPtr copyAndCreateFilm(const Film &otherFilm);

    /**
     * @brief Creates a new Group and adds it to the groups collection
     * 
     * Creates a Group with the specified name for organizing multimedia objects.
     * 
     * @param[in] groupName The name of the group (default: "DefaultGroup")
     * 
     * @return A shared pointer to the newly created Group object
     * 
     * @sa Group
     */
    gPtr createGroup(std::string groupName = "DefaultGroup");

    /**
     * @brief Searches for and displays a multimedia object or group by name
     * 
     * Searches both the media collection and groups collection for an object
     * with the specified name and outputs its information to the provided stream.
     * 
     * @param[in] name The name of the multimedia object or group to search for
     * @param[in,out] os The output stream to display the results
     * 
     * @return A reference to the modified output stream
     */
    std::ostream &searchAndDisplay(const std::string &name, std::ostream &os) const;

    /**
     * @brief Plays a multimedia object by name
     * 
     * Searches for a multimedia object by name and plays it using the appropriate
     * playback method for its type (Photo, Video, or Film).
     * 
     * @param[in] name The name of the multimedia object to play
     */
    void playMedia(const std::string &name) const;

    /**
     * @brief Deletes a multimedia object or group by name
     * 
     * Removes the multimedia object or group with the specified name from
     * the respective collection.
     * 
     * @param[in] name The name of the multimedia object or group to delete
     */
    void deleteByName(const std::string &name);

    /**
     * @brief Reads multimedia data from a file and constructs objects
     * 
     * Parses a text file containing multimedia data and creates corresponding
     * multimedia objects, adding them to the media collection. This enables
     * persistence and recovery of multimedia data.
     * 
     * @param[in] filename The path to the file to read from
     */
    void read(const std::string& filename);

    /**
     * @brief Retrieves the media collection
     * 
     * Returns a copy of the media collection map containing all multimedia objects
     * indexed by name.
     * 
     * @return A map of strings (names) to shared pointers of Multimedia objects
     */
    std::map<std::string, mmPtr> getMedias() const;

private:
    /** @brief Collection of multimedia objects indexed by name */
    std::map<std::string, mmPtr> mediaCollection;

    /** @brief Collection of groups indexed by name */
    std::map<std::string, gPtr> mediaGroups;
};

#endif // MANAGER_H