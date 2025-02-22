#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main( void )
{
	// Exercice example
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;
	std::cout << std::endl;

	// Proof of deep copy
	Dog medor;
	std::cout << std::endl;
	Cat fifi;

	Dog & medor_ref = medor;
	Cat & fifi_ref = fifi;

	if (medor_ref.getType() == "pouet" || fifi_ref.getType() == "pouyet\n")
		return 1;

	std::cout << std::endl << "creating copies" << std::endl;
	Dog medor_copy(medor_ref);
	Cat fifi_copy(fifi_ref);

	std::cout << std::endl;


	// Array of animals
	const Animal	*animal_array[4];
	std::cout << std::endl;
	// Half filled with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	// Half filled with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;
}