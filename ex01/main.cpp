#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
// #include <cstdint>
Data sample;

int main()
{
  sample.data = 42;

  std::cout << "Original Address: " << &sample << std::endl;

  uintptr_t serializedData = Serializer::serialize(&sample);

  std::cout << "Serialized Address: " << serializedData << std::endl;

  // Deserialize the data
  Data *deserializedData = Serializer::deserialize(serializedData);

  std::cout << "Deserialized Address: " << deserializedData << std::endl;

  // Compare original and deserialized data pointers
  if (&sample == deserializedData)
  {
    std::cout << "serialize, deserialize success" << std::endl;

    std::cout << "Original Data Value: " << sample.data << std::endl;
    std::cout << "Deserialized Data Value: " << deserializedData->data << std::endl;
  }
  else
  {
    std::cout << "serialize, deserialize failed" << std::endl;
  }
}
