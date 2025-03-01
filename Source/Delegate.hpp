#pragma once

#include "Assertion.hpp"
#include "RuntimeException.hpp"

#include <functional>
#include <optional>

namespace korelib
{
    template<class ReturnType, class... Parameters>
    class Delegate final
    {
    public:
        Delegate() : m_function(std::nullopt)
        {
        }

        ~Delegate() = default;

        bool isBound() const
        {
            return m_function.has_value();
        }

        void bind(std::function<ReturnType(Parameters...)> func)
        {
            m_function = func;
        }

        template <class... Args>
        ReturnType execute(Args&&... args)
        {
            KORELIB_VERIFY_THROW(isBound(), RuntimeException, "Attempt to execute unbound delegate!");
            return m_function.value()(std::forward<Args>(args)...);
        }

    private:
        std::optional<std::function<ReturnType(Parameters...)>> m_function;
    };
}