/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ICommand
*/

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_

    #include <functional>
    #include <string>
    #include <sstream>
    #include <memory>

namespace network {
    class ICommand {
    public:
        /**
         * @brief Construct a new ICommand object
         */
        ICommand() noexcept = default;
        /**
         * @brief Destroy the ICommand object
         */
        virtual ~ICommand() noexcept = default;

        /**
         * @brief Execute the command
         * @param iss std::istringstream
         */
        virtual void execute(std::istringstream& iss) = 0;

        /**
         * @brief Clone the command
         * @return std::unique_ptr<ICommand>
         */
        virtual std::unique_ptr<ICommand> clone() const = 0;

        /**
         * @brief Set the callback
         * @param callback std::function<void(std::istringstream&)>
         */
        using Callback = std::function<void(std::istringstream&)>;
        void setCallback(Callback callback) {
            _callback = std::move(callback);
        }
    protected:
        Callback _callback;     // Callback function
    };
} // namespace network //
#endif /* !ICOMMAND_HPP_ */
