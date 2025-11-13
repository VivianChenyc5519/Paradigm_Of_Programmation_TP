/**
 * @file film.h
 * @brief Header file for the Film class
 * 
 * This file defines the Film class, which represents a video with chapter support.
 * Film extends the Video class with additional functionality for managing chapter
 * information and chapter-based navigation.
 */

#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>

/**
 * @class Film
 * @brief Represents a film with chapter management capabilities
 * 
 * The Film class extends Video to add support for film chapters. It allows storing
 * and retrieving chapter information (chapter lengths) for a video file, enabling
 * chapter-based navigation and display. Films are managed through the Manager class
 * which controls their creation and lifecycle.
 * 
 * @note Chapter data is managed dynamically and properly copied during object
 *       duplication to ensure safe memory management.
 * 
 * @sa Video, Manager, Multimedia
 */
class Film : public Video
{
public:
    /**
     * @brief Assignment operator (copy assignment)
     * 
     * Assigns the contents of another Film object to this object, including
     * all chapter information. Ensures proper deep copying of chapter data.
     * 
     * @param[in] otherFilm The Film object to copy from
     * @return A reference to this Film object after assignment
     */
    Film &operator=(const Film &otherFilm);

    /**
     * @brief Sets the chapters for this film
     * 
     * Stores the chapter length information for the film. Each chapter's duration
     * is provided as an array of integers.
     * 
     * @param[in] chapters A pointer to an array of integers representing chapter lengths
     * @param[in] n_chapters The number of chapters in the array
     * 
     * @note This method performs deep copying of the chapter data
     */
    void setChapters(const int *chapters, size_t n_chapters);

    /**
     * @brief Retrieves the chapters array
     * 
     * Returns a const pointer to the internal chapters array containing
     * the length of each chapter.
     * 
     * @return A const pointer to the chapters array
     * @sa getChapterNumber()
     */
    const int *getChapters() const;

    /**
     * @brief Gets the number of chapters
     * 
     * Returns the count of chapters in this film.
     * 
     * @return The number of chapters
     */
    size_t getChapterNumber() const;

    /**
     * @brief Displays film information to an output stream
     * 
     * Outputs detailed information about the film including inherited video
     * properties and chapter information to the specified output stream.
     * 
     * @param[in,out] os The output stream to write to
     * @return A reference to the modified output stream
     * 
     * @note This overrides the display method from the Video class
     */
    std::ostream &display(std::ostream &os) const override;

    /**
     * @brief Writes film information to a file
     * 
     * Serializes the film's data (including chapter information) to a file for
     * persistence and later retrieval.
     * 
     * @param[in] filename The path to the file where data should be written
     * 
     * @note This overrides the write method from the Video class
     */
    void write(const std::string &filename) const override;

    /**
     * @brief Destructor for the Film class
     * 
     * Cleans up dynamically allocated chapter data and inherited Video resources.
     */
    ~Film() override;

private:
    /** @brief Array storing the length of each chapter
     *  @details Dynamically allocated and managed by the Film class
     */
    int *chapters;

    /** @brief The number of chapters in this film */
    size_t n_chapters;

    /**
     * @brief Private constructor for Film object creation
     * 
     * Initializes a film with all necessary information. Constructor is private
     * to ensure films are created only through the Manager class.
     * 
     * @param[in] name The name/title of the film
     * @param[in] filepath The file path to the film media
     * @param[in] duration The total duration of the film in seconds
     * @param[in] chapters A pointer to an array of chapter lengths
     * @param[in] n_chapters The number of chapters
     * 
     * @sa Manager
     */
    Film(std::string name, std::string filepath, int duration, const int *chapters, size_t n_chapters);

    /**
     * @brief Copy constructor for deep copying
     * 
     * Creates a new Film object as a deep copy of another Film object,
     * including all chapter information.
     * 
     * @param[in] otherFilm The Film object to copy from
     */
    Film(const Film &otherFilm);

    /** @brief Manager class is granted friend access for film creation and management
     *  @sa Manager
     */
    friend class Manager;
};

#endif // FILM_H