#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>

int findIndex(int index, int rec);

static int jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};


template <typename Container>
bool is_sorted(const Container& cont) {
    for (typename Container::const_iterator it = cont.begin(); it != cont.end() - 1; ++it) {
        if (*it > *(it + 1)) {
            return false;
        }
    }
    return true;
}

template <typename T>
struct iter
{
	typename T::iterator	it;

	iter(typename T::iterator _it) : it(_it){}
};

template <typename T>
void printArr(T toPrint)
{
	int i = 0;
	for (typename T::iterator it = toPrint.begin(); it != toPrint.end() && i < 5; ++it, i++)
		std::cout << *it << " ";
	if (toPrint.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;
}

template <typename T>
void 	swapIt(iter<T> &it1, iter<T> &it2, int size)
{
	typename T::iterator	first;
	typename T::iterator	second;

	first = it1.it;
	second = it2.it;
	for (int i = 0; i <= size - 1; i++)
	{
		std::swap(*first, *second);
		--first;
		--second;
	}
}

template <typename T>
int mergeSort(T &container, int rec)
{
	static int recMax = 0;
	if (rec > recMax)
		recMax = rec;
	size_t n = container.size();
	size_t groupSize = 1 << rec;
	size_t i = 0;
	size_t total = n / groupSize;

	iter<T> it1(container.begin() + groupSize - 1);
	iter<T> it2(container.begin() + groupSize * 2 - 1);
	while (i < total / 2)
	{
		if (*it1.it > *it2.it)
			swapIt(it1, it2, groupSize);
		it1.it += groupSize * 2;
		it2.it += groupSize * 2;
		i++;
	}
	if (total / 2 <= 3)
		return recMax + 1;
	else
		mergeSort(container, rec + 1);
	return recMax + 1;
}

template<typename T>
void initInsert(T &container, T& temp, int rec)
{
	int groupSize = 1 << rec;
	iter<T> it1(container.begin() + groupSize - 1);
	iter<T> it2(container.begin() + groupSize + groupSize - 1);
	if (*it1.it < *it2.it)
		temp.insert(temp.begin(), container.begin(), it2.it + 1);
	else
	{
		temp.insert(temp.begin(), (it2.it + 1) - groupSize, it2.it + 1);
		temp.insert(temp.end(), container.begin(), it1.it + 1);
	}
	if (container.size() > temp.size())
	{
		if (temp.size() + groupSize == container.size())
		{
			it1.it = temp.end() - 1;
			it2.it = container.end() - 1;
			if(*it1.it < *it2.it){
				temp.insert(temp.end(), container.end() - groupSize, container.end());
				return ;
			}
			it1.it -= groupSize;
			if(*it1.it < *it2.it){
				temp.insert(it1.it + 1, container.end() - groupSize, container.end());
				return ;
			}
			else
				temp.insert(temp.begin(), container.end() - groupSize, container.end());
		}
		else
			temp.insert(temp.end(), container.end() - (container.size() - temp.size()), container.end());
	}
}

template <typename T>
void copyArr(T &container, T&temp)
{
	container.clear();
	container.insert(container.begin(), temp.begin(), temp.end());
	temp.clear();
}

template <typename T>
void insertFirst(T &container, T &temp, int rec)
{
	int groupSize = 1 << rec;
	temp.insert(temp.begin(), container.begin(), container.begin() + groupSize);
}

template <typename T>
iter<T> binarySearch(int target, T &temp, int rec)
{
	int sizeGroup = std::pow(2, rec) / 2;
	iter<T> start(temp.begin() + sizeGroup - 1);
	iter<T> end(temp.end() - 1);
	iter<T> middle(start.it + ( (end.it - start.it) / (2 * sizeGroup) ) * sizeGroup);
	if (target < *start.it)
		return temp.begin();
	if (target > *end.it)
		return temp.end();
	while (start.it < end.it)
	{
		middle.it = start.it + ( (end.it - start.it) / (2 * sizeGroup) ) * sizeGroup;
		if (*middle.it < target)
			start.it = middle.it + sizeGroup;
		else
			end.it = middle.it;
	}
	return start.it - sizeGroup + 1;
}

template <typename T>
void insertPair(T &container, T &temp, int rec, int index)
{
	int groupSize = std::pow(2, rec);
    iter<T> leftPart(container.begin() + (groupSize) + (index * groupSize) - (groupSize/2) - 1);
    iter<T> rightPart(container.begin() + (groupSize) + (index * groupSize) - 1);
	iter<T> pos(binarySearch(*leftPart.it, temp, rec));
	temp.insert(pos.it, (leftPart.it - groupSize/2) + 1, leftPart.it + 1);
	pos = binarySearch(*rightPart.it, temp, rec);
	temp.insert(pos.it, (rightPart.it - groupSize/2) + 1, rightPart.it + 1);
}

template <typename T>
void insertRest(T &container, T &temp, int rest)
{
	iter<T> pair(container.end() - 1);
	temp.insert(temp.end(), (pair.it - rest) + 1, pair.it + 1);
}

template <typename T>
void insertSort(T &container, T&temp, int rec)
{
    while (rec > 0)
    {
        copyArr(container, temp);
        insertFirst(container, temp, rec);
        int size = std::pow(2,rec);
        int nbrGroup = container.size() / size;
        std::vector<int> indexes;
        int i = 0;
        while (jacob[i] <= nbrGroup)
        {
            if (jacob[i] < nbrGroup)
                indexes.push_back(jacob[i]);
            i++;
        }
        for (int j = nbrGroup - 1; j >= 1; j--)
            if (std::find(indexes.begin(), indexes.end(), j) == indexes.end())
                indexes.push_back(j);
        for (size_t idx = 0; idx < indexes.size(); idx++)
            insertPair(container, temp, rec, indexes[idx]);
        int rest = container.size() - nbrGroup * size;
        if (rest != 0)
            insertRest(container, temp, rest);
            
        rec--;
    }
    copyArr(container, temp);
}

template <typename T>
T& sortLow(T& container)
{
    typename T::iterator it1 = container.begin();
    typename T::iterator it2 = container.end();
    --it2;
    if (container.size() == 2) {
        std::swap(*it1, *it2);
        return container;
    }
    else if (container.size() > 2) {
        bool swapped;
        do {
            swapped = false;
            typename T::iterator it = container.begin();
            typename T::iterator end = container.end();
            --end;
            while (it != end) {
                typename T::iterator next = it;
                ++next;
                if (*it > *next) {
                    std::swap(*it, *next);
                    swapped = true;
                }
                ++it;
            }
        } while (swapped);
    }
    return container;
}


template <typename T>
T fmji(T &container)
{
	int save;
	bool wasOddSize = false;
	if (container.size() <= 3)
		return sortLow(container);
	if (container.size() % 2 == 1)
	{
		wasOddSize = true;
		save = container.back();
        container.pop_back();
	}
	int rec = mergeSort(container, 0);
	T temp;
	initInsert(container, temp , rec);
	insertSort(container, temp, rec);
	if (wasOddSize)
	{
		iter<T> pos(binarySearch(save, container, 1));
		container.insert(pos.it, save);
	}
	return(container);
}
#endif