// Allows swapping values that are far apart
// Works well for large lists

#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void shellSort(int array[SIZE]);

/**
 * @brief Main function that demonstrates the sorting algorithm.
 *
 * Initializes an array of integers, prints it, sorts it using the Shell Sort
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
    std::cout << std::endl;

    // Sort the array using Shell Sort
    shellSort(array);

    // Print the sorted array
    printArray(array);

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * @brief Prints the elements of an integer array.
 *
 * This function prints each element of the array separated by a pipe ('|') for easy readability.
 *
 * @param array The integer array to be printed
 */

void printArray(int array[])
{
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << " |" << array[i] << "| ";
    }
}

/**
 * @brief Sorts an array using the Shell Sort algorithm.
 *
 * Shell Sort is an in-place comparison-based sorting algorithm. It generalizes
 * insertion sort to allow the exchange of items that are far apart. It works by
 * comparing and sorting elements at a certain gap and progressively reducing the gap.
 *
 * @param array The integer array to be sorted
 */

void shellSort(int array[SIZE])
{
    int i, j, currentValue;
    int gap = 1; // Initial gap (jump) size for sorting

    // Increase gap size until it exceeds array size
    while (gap < SIZE)
    {
        gap = (3 * gap) + 1; // Multiply by 3 to generate gap sequence
    }

    // Perform sorting by reducing gap
    while (gap > 1)
    {
        // Reduce the gap size
        gap = gap / 3;

        // Perform insertion sort for each gap value
        for (i = gap; i < SIZE; i++)
        {
            currentValue = array[i];
            j = i - gap;

            // Shift elements to the right until we find the correct position for currentValue
            while (j >= 0 && currentValue < array[j])
            {
                array[j + gap] = array[j];
                j = j - gap;
            }

            // Place the current element in its correct position
            array[j + gap] = currentValue;

            // Print the array after each pass to show sorting progress
            printArray(array);
            std::cout << std::endl;
        }
    }
}
