/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AException
*/

#ifndef AEXCEPTION_HPP_
#define AEXCEPTION_HPP_

#include "../interface/IException.hpp"
#include <string>

namespace GUI {
class AException : public IException {
    public:
        AException(const std::string& message,
            const std::string& type) noexcept;
        virtual ~AException() noexcept = default;

        const char *what() const noexcept override final;
        std::string getType() const noexcept override final;

    protected:
        std::string _message;
        std::string _type;
    private:
};
} // namespace GUI
#endif /* !AEXCEPTION_HPP_ */
