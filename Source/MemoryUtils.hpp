#pragma once

#include "Assertion.hpp"
#include "RuntimeException.hpp"
#include "StaticOnlyClass.hpp"

#include <memory>

namespace korelib
{
    class MemoryUtils : public StaticOnlyClass
    {
        template<class T>
        std::shared_ptr<T> NonNull(const std::shared_ptr<T>& ptr)
        {
            KORELIB_VERIFY_THROW(ptr != nullptr, RuntimeException, "ptr is NULL");
        }

        template<class T>
        std::shared_ptr<T> NonNull(const T* ptr)
        {
            KORELIB_VERIFY_THROW(ptr != nullptr, RuntimeException, "ptr is NULL");
        }

        template<class T>
        std::shared_ptr<T> NonNull(T* ptr)
        {
            KORELIB_VERIFY_THROW(ptr != nullptr, RuntimeException, "ptr is NULL");
        }
    };
}
