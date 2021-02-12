#include "utility"

template<class InputIterator, class Function>

Function for_each(InputIterator first, InputIterator last, Function fn)
{
    while (first != last)
    {
        fn (*first);
        (++ first);
    }

    return std::move(fn);
}