#pragma once

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

namespace korelib
{
    class RuntimeException : public std::runtime_error
    {
    public:
        explicit RuntimeException(const std::string& message);
        explicit RuntimeException(const char* message);
        void printStackTrace(std::ostream& stream = std::cout);
    };
}
