/**
 * @file group.h
 * @brief Header file for the Group class
 * 
 * This file defines the Group class which manages collections of multimedia objects.
 * A Group acts as a specialized list container for multimedia items and provides
 * functionality for naming and displaying groups.
 */

#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include <list>
#include <memory>

/** @typedef mmPtr
 *  @brief Alias for shared pointer to Multimedia objects
 *  
 *  Simplifies the syntax for handling shared pointers to Multimedia objects
 *  throughout the application.
 */
using mmPtr = std::shared_ptr<Multimedia>;

/**
 * @class Group
 * @brief A container for multimedia objects with group management capabilities
 * 
 * The Group class extends std::list to store collections of multimedia items
 * (photos, videos, films). It provides functionality to name groups and display
 * their contents. The class is designed to be managed by the Manager class.
 * 
 * @note This class uses shared pointers for memory management of multimedia objects
 *       to ensure safe resource handling in a complex application.
 * 
 * @sa Multimedia, Manager
 */
class Group : public std::list<mmPtr>
{
public:
    /**
     * @brief Destructor for the Group class
     * 
     * Cleans up the group and all its contained multimedia objects through
     * the automatic cleanup of shared pointers.
     */
    ~Group();

    /**
     * @brief Retrieves the name of the group
     * 
     * @return A constant reference to the string containing the group's name
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the group
     * 
     * @param[in] groupName The new name to assign to the group
     */
    void setName(const std::string &groupName);

    /**
     * @brief Displays the group's information to an output stream
     * 
     * Outputs the group's name and all contained multimedia items to the
     * specified output stream in a formatted manner.
     * 
     * @param[in,out] os The output stream to write to
     * @return A reference to the modified output stream
     */
    std::ostream &display(std::ostream &os) const;

private:
    /**
     * @brief Private default constructor
     * 
     * The constructor is private to ensure groups are only created through
     * the Manager class. This maintains encapsulation and consistent group
     * initialization.
     */
    Group() = default;

    /** @brief The name of the group
     *  @details Initialized with a default value of "DefaultGroup"
     */
    std::string name = "DefaultGroup";

    /** @brief Internal list of multimedia items in the group
     *  @deprecated This member shadows the inherited list from std::list
     *  @note Consider removing this if inheritance from std::list is used
     */
    std::list<mmPtr> items;

    /** @brief Manager class is granted friend access to manage group creation
     *  @sa Manager
     */
    friend class Manager;
};

#endif // GROUP_H