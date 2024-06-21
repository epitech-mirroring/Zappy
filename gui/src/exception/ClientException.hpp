/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ClientException
*/

#ifndef CLIENTEXCEPTION_HPP_
    #define CLIENTEXCEPTION_HPP_

    #include "abstract/AException.hpp"

namespace network {
    class ClientException : public GUI::AException {
    public:
        /**
         * @brief Construct a new ClientException object
         * @param message (error message)
        */
        ClientException(std::string message);
    };
} // namespace network //
#endif /* !CLIENTEXCEPTION_HPP_ */
