#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main( void )
{
	std::cout << "Exercice example:\n";

	const AAnimal* dog = new Dog();
	std::cout << std::endl;
	const AAnimal* cat = new Cat();

	std::cout << std::endl;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Proof of deep copy:\n";
	Dog medor;
	std::cout << std::endl;
	Cat fifi;

	Dog & medor_ref = medor;
	Cat & fifi_ref = fifi;

	std::cout << std::endl << "creating copies:" << std::endl;
	Dog medor_copy(medor_ref);
	Cat fifi_copy(fifi_ref);

	std::cout << std::endl;


	std::cout << "Array of animals:\n";
	const AAnimal	*animal_array[4];
	std::cout << std::endl;
	std::cout << "Half filled with dogs:\n";
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	std::cout << "Half filled with cats:\n";
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;
}