#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data originalData = {1, 3.14f, "Test Data"};

    uintptr_t raw = Serializer::serialize(&originalData);

    std::cout << "raw value = " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &originalData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Original Data: " << std::endl;
        std::cout << "id: " << originalData.id << std::endl;
        std::cout << "value: " << originalData.value << std::endl;
        std::cout << "name: " << originalData.name << std::endl;

        std::cout << "Deserialized Data: " << std::endl;
        std::cout << "id: " << deserializedData->id << std::endl;
        std::cout << "value: " << deserializedData->value << std::endl;
        std::cout << "name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    uintptr_t invalidRaw = 12345;
    Data* invalidDeserializedData = Serializer::deserialize(invalidRaw);

    if (invalidDeserializedData == &originalData) {
        std::cout << "Invalid deserialization somehow succeeded (unexpected)!" << std::endl;
    } else {
        std::cout << "Deserialization failed as expected with invalid raw value!" << std::endl;
    }
    return 0;
}