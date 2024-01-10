#include <iostream>
#include <vector>

int main() {
    // Declare and initialize a vector of integers
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Print the elements using a range-based for loop
    std::cout << "Vector Elements: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Access and modify elements
    std::cout << "Third Element (before modification): " << myVector[2] << std::endl;
    myVector[2] = 10; // Modify the third element
    std::cout << "Third Element (after modification): " << myVector[2] << std::endl;

    // Add an element to the end
    myVector.push_back(20);

    // Print the updated vector
    std::cout << "Updated Vector: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Print vector size
    std::cout << "Vector Size: " << myVector.size() << std::endl;

    // Remove the last element
    myVector.pop_back();

    // Print the final vector
    std::cout << "Final Vector: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
