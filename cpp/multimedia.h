/**
 * @file multimedia.h
 * @brief Header file for the Multimedia base class
 * 
 * This file defines the abstract Multimedia class which serves as the base class
 * for all multimedia types (Photo, Video, Film). It provides common functionality
 * for managing multimedia properties and defines the interface that all multimedia
 * objects must implement.
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>

/**
 * @class Multimedia
 * @brief Abstract base class for all multimedia objects
 * 
 * The Multimedia class is an abstract base class that defines the interface and
 * common properties for all multimedia types. It stores fundamental information
 * like name and file path, and defines pure virtual methods that must be implemented
 * by derived classes (Photo, Video, Film). The Manager class has friend access to
 * control object creation.
 * 
 * @note This is an abstract class with pure virtual methods and should not be
 *       instantiated directly. Use derived classes instead.
 * 
 * @sa Photo, Video, Film, Manager
 */
class Multimedia
{
protected:
    /** @brief The name or title of the multimedia object
     *  @details Initialized with empty string, typically set during construction
     */
    std::string name = "";

    /** @brief The file path to the multimedia resource
     *  @details Initialized with empty string, typically set during construction
     */
    std::string filepath = "";

    /**
     * @brief Protected default constructor
     * 
     * Initializes a Multimedia object with default values (name = "Untitled",
     * filepath = ""). This constructor is protected to prevent direct instantiation
     * and is intended for use by derived classes.
     */
    Multimedia() : name("Untitled"), filepath("") {};

    /**
     * @brief Protected parameterized constructor
     * 
     * Initializes a Multimedia object with specified name and file path.
     * This constructor is protected to prevent direct instantiation and is
     * intended for use by derived classes.
     * 
     * @param[in] n The name/title of the multimedia object
     * @param[in] d The file path to the multimedia resource
     */
    Multimedia(std::string n, std::string d);

    /** @brief Manager class is granted friend access for object creation and management
     *  @sa Manager
     */
    friend class Manager;

public:
    /**
     * @brief Virtual destructor for the Multimedia class
     * 
     * Ensures proper cleanup of derived class objects when deleted through
     * a Multimedia pointer. Enables polymorphic behavior.
     */
    virtual ~Multimedia();

    /**
     * @brief Retrieves the name of the multimedia object
     * 
     * Returns the name or title of this multimedia object.
     * 
     * @return A constant string containing the multimedia object's name
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the multimedia object
     * 
     * Assigns a new name/title to this multimedia object.
     * 
     * @param[in] name The new name to assign
     */
    void setName(std::string name);

    /**
     * @brief Retrieves the file path of the multimedia object
     * 
     * Returns the file path to the multimedia resource.
     * 
     * @return A constant string containing the file path
     */
    std::string getFilepath() const;

    /**
     * @brief Sets the file path of the multimedia object
     * 
     * Assigns a new file path to this multimedia object.
     * 
     * @param[in] filepath The new file path to assign
     */
    void setFilepath(std::string filepath);

    /**
     * @brief Displays multimedia information to an output stream
     * 
     * Pure virtual method that outputs the multimedia object's information
     * to the specified output stream. Implementation is provided by derived classes.
     * 
     * @param[in,out] os The output stream to write to
     * @return A reference to the modified output stream
     * 
     * @note This is a pure virtual method and must be implemented by derived classes
     */
    virtual std::ostream &display(std::ostream &os) const = 0;

    /**
     * @brief Plays the multimedia object
     * 
     * Pure virtual method that initiates playback of the multimedia object.
     * Implementation is provided by derived classes and should use appropriate
     * playback mechanisms for the specific multimedia type.
     * 
     * @note This is a pure virtual method and must be implemented by derived classes
     */
    virtual void play() const = 0;

    /**
     * @brief Writes multimedia object information to a file
     * 
     * Pure virtual method that serializes the multimedia object's data to
     * a file for persistence and later retrieval. Implementation is provided
     * by derived classes.
     * 
     * @param[in] filename The path to the file where data should be written
     * 
     * @note This is a pure virtual method and must be implemented by derived classes
     */
    virtual void write(const std::string& filename) const = 0;
};

#endif // MULTIMEDIA_H
