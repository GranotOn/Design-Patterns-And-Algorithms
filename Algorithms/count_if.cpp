template <class InputIterator, class UnaryPredicate>

int count_if(InputIterator first, InputIterator last, UnaryPredicate fn)
{
    int ret = 0;
    while (first != last)
    {
        if (fn(*first)) ++ret;
        ++first;
    }

    return ret;
}
