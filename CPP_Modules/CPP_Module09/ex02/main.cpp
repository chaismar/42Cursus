#include "PmergeMe.hpp"
// Fonction pour vérifier si une chaîne est un nombre valide
bool checkVal(const std::string& str) {
	if (str.empty())
		return false;
	size_t start = 0;
	if (str[0] == '-')
		return false;
	for (std::string::const_iterator it = str.begin() + start; it != str.end(); ++it) {
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

// Fonction pour vérifier les doublons dans la liste
bool containsDuplicate(char **av) {
	for (size_t i = 1; av[i]; i++) {
		int currentVal = std::atoi(av[i]);
		for (size_t j = i + 1; av[j]; j++) {
			if (currentVal == std::atoi(av[j]))
				return true;
		}
	}
	return false;
}

// Fonction de parsing pour vérifier la validité des arguments
int parsing(char **av) {
	for (size_t i = 1; av[i]; i++) {
		if (!checkVal(av[i]))
			return (std::cout << "Error: not only positive int in list" << std::endl, 1);
	}
	if (containsDuplicate(av))
		return (std::cout << "Error: list contains duplicate" << std::endl, 1);
	return 0;
}

// Typedef générique pour créer une liste de type T
template <typename T>
T makeList(char **av) {
	T list;
	for (size_t i = 1; av[i]; i++) {
		list.push_back(std::atoi(av[i]));
	}
	return list;
}

template <typename T>
double measureSortTime(T& container) {
	std::cout << "------------start-----------" << std::endl;
	std::cout << "Before : ";
	printArr(container);
	clock_t start = clock();
	T res = fmji(container);
	clock_t end = clock();
	std::cout << "After  : ";
	printArr(res);
	std::cout << "State  : ";
	if (is_sorted(res)) {
		std::cout << "container is sorted" << std::endl;
	}
	else
		std::cout << "error : list not sorted !" << std::endl;
	std::cout << "-----------end------------\n" << std::endl;
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convertir en microsecondes
	return duration;
}

int main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "Error: not enough args" << std::endl, 1);
	if (parsing(av))
		return 1;
	double totalVectorTime = 0.0;
	double totalDequeTime = 0.0;

	// Utilisation des typedef pour vector et deque
	typedef std::vector<int> VectorInt;
	typedef std::deque<int> DequeInt;

	VectorInt vecListToSort = makeList<VectorInt>(av);
	DequeInt deqListToSort = makeList<DequeInt>(av);
	if (is_sorted(vecListToSort))
		return (std::cout << "Error : container are already sorted", 1);

	totalVectorTime += measureSortTime(vecListToSort);
	totalDequeTime += measureSortTime(deqListToSort);

	std::cout << "Temps pour trier " << vecListToSort.size() << " elements avec vector : " << totalVectorTime << " µs" << std::endl;
	std::cout << "Temps pour trier " << deqListToSort.size() << " elements avec deque : " << totalDequeTime << " µs" << std::endl;

	return 0;
}
