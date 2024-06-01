/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ArgsException
*/

#ifndef ARGSEXCEPTION_HPP_
    #define ARGSEXCEPTION_HPP_

    #include "abstract/AException.hpp"

namespace GUI {
    class ArgsException : public AException {
    public:
        /**
         * @brief Construct a new ArgsException object
         * @param message (error message)
         */
        ArgsException(const std::string &message);

    protected:
    };
} // namespace GUI //
#endif /* !ARGSEXCEPTION_HPP_ */
