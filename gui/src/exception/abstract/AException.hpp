/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AException
*/

#ifndef AEXCEPTION_HPP_
    #define AEXCEPTION_HPP_

    #include "exception/interface/IException.hpp"
    #include <string>

namespace GUI {
    class AException : public IException {
    public:
        /**
         * @brief Construct a new AException object
         * @param message (error message)
        */
        AException(std::string message, std::string type) noexcept;
        /**
         * @brief Destroy the AException object
        */
        virtual ~AException() noexcept = default;

        /**
         * @brief Get the message object
         * @return const char* (error message)
        */
        [[nodiscard]] const char *what() const noexcept final;
        /**
         * @brief Get the Type object
         * @return std::string (error type)
        */
        [[nodiscard]] std::string getType() const noexcept final;

    protected:
        std::string _message;       // error message
        std::string _type;          // error type (ArgsException, ...)
    private:
    };
} // namespace GUI //
#endif /* !AEXCEPTION_HPP_ */
