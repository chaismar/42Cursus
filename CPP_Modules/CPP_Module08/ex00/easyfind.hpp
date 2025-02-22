#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cnt, int tofind)
{
    return (std::find(cnt.begin(), cnt.end() , tofind));
}

#endif