/*
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
    #define AOBJECT_HPP_

    #include "../interface/IObject.hpp"

namespace GUI {
    class AObject : public IObject {
    public:
        /**
         * @brief Construct a new AObject object
         * @param density
         */
        AObject(float density);
        /**
         * @brief Destroy the AObject object
         */
        virtual ~AObject() noexcept = default;

        /**
         * @brief Get the Density object
         * @return float (density of the object)
         */
        [[nodiscard]] float getDensity() const noexcept override final;
    protected:
        float _density;         // density of the object
    };
}  // namespace GUI //
#endif /* !AOBJECT_HPP_ */
