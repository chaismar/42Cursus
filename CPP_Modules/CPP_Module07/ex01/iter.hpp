#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, unsigned int len, F fun)
{
    for(unsigned int i = 0; i < len; i++)
        fun(array[i]);
}

#endif