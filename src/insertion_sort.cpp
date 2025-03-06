#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void insertionSort(int array[SIZE]);

/**
 * @brief Main function that demonstrates the sorting algorithm.
 *
 * Initializes an array of integers, prints it, sorts it using the insertion sort
 * algorithm, and prints the sorted array.
 *
 * @return int Status code (0 for success)
 */

int main()
{
    // Initialize an array of integers in descending order
    int array[SIZE]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Print the original array
    printArray(array);
    std::cout << std::endl;

    // Sort the array using insertion sort
    insertionSort(array);

    // Print the sorted array
    printArray(array);

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * @brief Prints the elements of an integer array.
 *
 * This function takes an array of integers and prints each element separated
 * by a pipe ('|') for easy readability.
 *
 * @param array The integer array to be printed
 */

void printArray(int array[])
{
    // Loop through each element of the array and print it with separators
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << " |" << array[i] << "| ";
    }
}

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 *
 * The Insertion Sort algorithm works by repeatedly taking the next element in the array
 * and comparing it to the elements before it, shifting larger elements one position to the
 * right, and inserting the current element into its correct position.
 *
 * @param array The integer array to be sorted
 */

void insertionSort(int array[SIZE])
{
    int currentElement, position;

    // Loop through each element starting from the second (index 1)
    for (int i = 1; i < SIZE; i++)
    {
        // The current element being analyzed
        currentElement = array[i];

        // The position of the element just before the one being analyzed
        position = i - 1;

        // Shift elements that are greater than the current element one position to the right
        while (position >= 0 && currentElement < array[position])
        {
            array[position + 1] = array[position]; // Move the element one position ahead
            position--;                            // Move to the previous element
        }

        // Place the current element in its correct position
        array[position + 1] = currentElement;
    }
}
