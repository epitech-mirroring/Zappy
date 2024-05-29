/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** IException
*/

#ifndef IEXCEPTION_HPP_
#define IEXCEPTION_HPP_

#include <exception>
#include <string>

namespace GUI {
class IException : public std::exception {
    public:
        IException() noexcept = default;
        virtual ~IException() noexcept = default;

        virtual const char* what() const noexcept override = 0;
        virtual std::string getType() const noexcept = 0;
};
} // namespace GUI
#endif /* !IEXCEPTION_HPP_ */
