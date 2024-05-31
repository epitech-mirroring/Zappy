/*
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
        /**
         * @brief Construct a new IException object
        */
        IException() noexcept = default;
        /**
         * @brief Destroy the IException object
        */
        virtual ~IException() noexcept = default;

        /**
         * @brief Get the what object
         * @return const char* (error message)
        */
        [[nodiscard]] virtual const char* what() const noexcept override = 0;
        /**
         * @brief Get the Type object
         * @return std::string (error type)
        */
        [[nodiscard]] virtual std::string getType() const noexcept = 0;
    };
} // namespace GUI //
#endif /* !IEXCEPTION_HPP_ */
