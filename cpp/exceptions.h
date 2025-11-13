#include <stdexcept>
#include <string>
/**
 * @class NamingError
 * @brief All errors that have to do with naminmg
 */
class NamingError: public std::runtime_error {
    public:
    /**
     * @brief NamingError inherits runtime error
     * @param message error message
     */
        NamingError(const std::string& message): std::runtime_error(message) {}
};

/**
 * @class DeleteError
 * @brief All errors that have to do with deletion
 */

class DeleteError: public std::runtime_error {
    public:
    /**
     * @brief NamingError inherits runtime error
     * @param message error message
     */
    DeleteError(const std::string& message): std::runtime_error(message){}
};