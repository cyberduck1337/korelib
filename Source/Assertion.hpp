#pragma once

#if KORELIB_ENABLE_ASSERTIONS
    #define KORELIB_VERIFY_THROW(EXPR, EXCEPTION, ...) \
        if(!(EXPR))                                    \
        {                                              \
            throw EXCEPTION(__VA_ARGS__);              \
        }
#else
    #define KORELIB_VERIFY_THROW(EXPR, EXCEPTION, ...)
#endif
