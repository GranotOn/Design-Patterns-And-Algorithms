template<class InputIt, class UnaryPredicat>
void copy_if(InputIt begin, InputIt end, InputIt src, UnaryPredicat fn)
{
    while (begin != end)
    {
        if (fn(*begin))
            *src = *begin;
        ++begin;
        ++src;
    };
}