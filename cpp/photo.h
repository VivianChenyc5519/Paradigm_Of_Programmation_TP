/**
 * @file photo.h
 * @brief Header file for the Photo class
 * 
 * This file defines the Photo class, which represents a photograph multimedia object.
 * Photo extends the Multimedia base class with geographic location information (latitude
 * and longitude) allowing photos to be tagged with their capture location.
 */

#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

/**
 * @class Photo
 * @brief Represents a photograph with location metadata
 * 
 * The Photo class extends Multimedia to represent photograph objects with support
 * for geographic coordinates (latitude and longitude). This enables storing and
 * retrieving location information for photos, useful for location-based organization
 * and display. Photos are created and managed through the Manager class.
 * 
 * @note Photos are immutable after creation (coordinates set via constructor)
 * 
 * @sa Multimedia, Manager
 */
class Photo : public Multimedia {
public:
    /**
     * @brief Virtual destructor for the Photo class
     * 
     * Cleans up photo resources and ensures proper cleanup when deleted
     * through a Multimedia pointer.
     */
    virtual ~Photo();

    /**
     * @brief Retrieves the latitude coordinate of the photo location
     * 
     * Returns the geographic latitude where the photo was taken or assigned.
     * 
     * @return The latitude value as a double (range typically -90.0 to 90.0)
     */
    double getLatitude() const;

    /**
     * @brief Sets the latitude coordinate of the photo location
     * 
     * Assigns a new latitude coordinate to the photo.
     * 
     * @param[in] latitude The latitude value to set (range typically -90.0 to 90.0)
     */
    void setLatitude(double latitude);

    /**
     * @brief Retrieves the longitude coordinate of the photo location
     * 
     * Returns the geographic longitude where the photo was taken or assigned.
     * 
     * @return The longitude value as a double (range typically -180.0 to 180.0)
     */
    double getLongitude() const;

    /**
     * @brief Sets the longitude coordinate of the photo location
     * 
     * Assigns a new longitude coordinate to the photo.
     * 
     * @param[in] longitude The longitude value to set (range typically -180.0 to 180.0)
     */
    void setLongitude(double longitude);

    /**
     * @brief Displays photo information to an output stream
     * 
     * Outputs the photo's name, file path, and geographic coordinates to the
     * specified output stream in a formatted manner.
     * 
     * @param[in,out] os The output stream to write to
     * @return A reference to the modified output stream
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    std::ostream& display(std::ostream& os) const override;

    /**
     * @brief Plays the photo
     * 
     * Initiates playback/display of the photo, typically opening it in an
     * appropriate viewer or system default application.
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    void play() const override;

    /**
     * @brief Writes photo information to a file
     * 
     * Serializes the photo's data (name, file path, coordinates) to a file
     * for persistence and later retrieval.
     * 
     * @param[in] filename The path to the file where data should be written
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    void write(const std::string& filename) const override;

private:
    /** @brief The latitude coordinate of the photo location (range: -90.0 to 90.0)
     *  @details Initialized to 0 by default
     */
    double latitude = 0;

    /** @brief The longitude coordinate of the photo location (range: -180.0 to 180.0)
     *  @details Initialized to 0 by default
     */
    double longitude = 0;

    /**
     * @brief Private default constructor
     * 
     * The constructor is private to ensure photos are only created through
     * the Manager class.
     */
    Photo();

    /**
     * @brief Private parameterized constructor
     * 
     * Initializes a photo with all necessary information. Constructor is private
     * to ensure photos are only created through the Manager class.
     * 
     * @param[in] name The name/title of the photo
     * @param[in] filepath The file path to the photo
     * @param[in] latitude The geographic latitude of the photo location
     * @param[in] longitude The geographic longitude of the photo location
     * 
     * @sa Manager
     */
    Photo(std::string name, std::string filepath, double latitude, double longitude);

    /** @brief Manager class is granted friend access for photo creation and management
     *  @sa Manager
     */
    friend class Manager;
};

#endif // PHOTO_H