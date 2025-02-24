#pragma once

namespace korelib
{
    class StaticOnlyClass
    {
    public:
        StaticOnlyClass() = delete;
        ~StaticOnlyClass() = delete;
    };
}
