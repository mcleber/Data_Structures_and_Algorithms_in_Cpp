#include <iostream>
#include <algorithm> // For std::find

/**
 * @brief Prints the elements of an integer array (vector).
 *
 * This function takes an array and its size as parameters, and prints all the
 * elements of the array, separating them with a dash (" - ").
 *
 * @param array The integer array to be printed.
 * @param size The size of the array.
 */

void printArray(const int *array, int size);

int main()
{
    // Initialize an array with 10 integer values
    int array[10] = {1, 45, 65, 22, 55, 76, 81, 89, 96, 99};
    int valueToFind;

    // Print the contents of the array
    printArray(array, 10);

    // Ask the user to enter a number they want to find
    std::cout << "Enter the number you want to find: ";
    std::cin >> valueToFind;

    // Use std::find to search for the value in the array
    auto it = std::find(array, array + 10, valueToFind);

    // Check if the value was found and display the result
    if (it != array + 10)
    {
        std::cout << "The value was found at position: " << (it - array) << std::endl;
    }
    else
    {
        std::cout << "The value was not found in the array.\n";
    }

    return 0;
}

void printArray(const int *array, int size)
{
    std::cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " - "; // Print each element followed by " - "
    }
    std::cout << std::endl;
}
