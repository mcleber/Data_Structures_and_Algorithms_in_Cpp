#include <iostream>
#include <algorithm> // For std::sort

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

/**
 * @brief Performs a binary search on a sorted array.
 *
 * This function implements the binary search algorithm, which efficiently finds
 * an element in a sorted array by repeatedly dividing the search interval in half.
 *
 * @param array The sorted array to search.
 * @param size The size of the array.
 * @param value The value to search for in the array.
 * @return The index of the element if found, or -1 if the element is not found.
 */

int binarySearch(const int *array, int size, int value);

int main()
{
    // Initialize an array with 10 integer values
    int array[10] = {1, 45, 65, 22, 76, 55, 88, 81, 99, 96};
    int valueToFind;

    // Sort the array before performing binary search
    std::sort(array, array + 10);

    // Print the sorted contents of the array
    printArray(array, 10);

    // Ask the user to enter a number they want to find
    std::cout << "Enter the number you want to find: ";
    std::cin >> valueToFind;

    // Use binary search to search for the value in the sorted array
    int index = binarySearch(array, 10, valueToFind);

    // Check if the value was found and display the result
    if (index != -1)
    {
        std::cout << "The value was found at position: " << index << std::endl;
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

int binarySearch(const int *array, int size, int value)
{
    int left{0};
    int right{size - 1};

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate middle index

        // Check if the value is at the middle
        if (array[mid] == value)
        {
            return mid; // Value found, return its index
        }

        // If the value is greater, ignore the left half
        if (array[mid] < value)
        {
            left = mid + 1;
        }
        // If the value is smaller, ignore the right half
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Value not found
}
