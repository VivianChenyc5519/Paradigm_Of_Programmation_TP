/**
 * @file video.h
 * @brief Header file for the Video class
 * 
 * This file defines the Video class, which represents a video multimedia object.
 * Video extends the Multimedia base class with duration information and provides
 * functionality for managing video playback and serialization. The Video class
 * serves as a base class for specialized video types like Film.
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

/**
 * @class Video
 * @brief Represents a video multimedia object with duration
 * 
 * The Video class extends Multimedia to represent video objects with support for
 * duration information. It provides methods for getting/setting the video duration
 * and implements playback and serialization functionality. The class is designed
 * to be inherited by more specialized video types (such as Film) and is managed
 * through the Manager class.
 * 
 * @note Duration is stored in seconds
 * @note This class has protected constructors and member visibility to allow
 *       derivation by specialized video types
 * 
 * @sa Multimedia, Film, Manager
 */
class Video : public Multimedia {
public:
    /**
     * @brief Virtual destructor for the Video class
     * 
     * Cleans up video resources and ensures proper cleanup when deleted
     * through a Multimedia pointer.
     */
    virtual ~Video();

    /**
     * @brief Retrieves the duration of the video
     * 
     * Returns the length of the video content.
     * 
     * @return The duration in seconds as an integer
     */
    int getDuration() const;

    /**
     * @brief Sets the duration of the video
     * 
     * Assigns a new duration value to the video.
     * 
     * @param[in] duration The duration in seconds
     */
    void setDuration(int duration);

    /**
     * @brief Displays video information to an output stream
     * 
     * Outputs the video's name, file path, and duration to the specified
     * output stream in a formatted manner.
     * 
     * @param[in,out] os The output stream to write to
     * @return A reference to the modified output stream
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    std::ostream& display(std::ostream& os) const override;

    /**
     * @brief Plays the video
     * 
     * Initiates playback of the video, typically opening it in an appropriate
     * media player or system default application.
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    void play() const override;

    /**
     * @brief Writes video information to a file
     * 
     * Serializes the video's data (name, file path, duration) to a file
     * for persistence and later retrieval.
     * 
     * @param[in] filename The path to the file where data should be written
     * 
     * @note This overrides the pure virtual method from the Multimedia class
     */
    void write(const std::string& filename) const override;

protected:
    /** @brief The duration of the video in seconds
     *  @details Initialized to 0 by default
     */
    int duration = 0;

    /**
     * @brief Protected default constructor
     * 
     * Initializes a Video object with default values. This constructor is
     * protected to allow derivation by specialized video types while preventing
     * direct instantiation.
     */
    Video();

    /**
     * @brief Protected parameterized constructor
     * 
     * Initializes a video with all necessary information. This constructor is
     * protected to allow derivation by specialized video types and to ensure
     * videos are created through the Manager class.
     * 
     * @param[in] name The name/title of the video
     * @param[in] filepath The file path to the video
     * @param[in] duration The duration of the video in seconds
     * 
     * @sa Manager
     */
    Video(std::string name, std::string filepath, int duration);

    /** @brief Manager class is granted friend access for video creation and management
     *  @sa Manager
     */
    friend class Manager;
};

#endif // VIDEO_H