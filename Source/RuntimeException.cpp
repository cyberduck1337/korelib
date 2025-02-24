#include "RuntimeException.hpp"
#include "backward.hpp"

namespace korelib
{
    RuntimeException::RuntimeException(const std::string& message) : std::runtime_error(message)
    {
    }

    RuntimeException::RuntimeException(const char* message) : std::runtime_error(message)
    {
    }

    void RuntimeException::printStackTrace(std::ostream& stream)
    {
        backward::StackTrace stacktrace;
        stacktrace.load_here();

        backward::Printer printer;
        printer.print(stacktrace, stream);
    }
}
