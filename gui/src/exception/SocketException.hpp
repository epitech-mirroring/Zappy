/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SocketException
*/

#ifndef SOCKETEXCEPTION_HPP_
    #define SOCKETEXCEPTION_HPP_

    #include "abstract/AException.hpp"

namespace zappy {
    class SocketException : public AException {
    public:
        /**
         * @brief Construct a new SocketException object
         * @param message (error message)
        */
        SocketException(std::string message);

    protected:
    };
} // namespace network //
#endif /* !SOCKETEXCEPTION_HPP_ */
