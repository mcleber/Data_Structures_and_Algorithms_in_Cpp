#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void bubbleSort(int array[SIZE]);

/**
 * @brief Main function that demonstrates the sorting algorithm.
 *
 * Initializes an array of integers, prints it, sorts it using the bubble sort
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

    // Sort the array using bubble sort
    bubbleSort(array);

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
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << " |" << array[i] << "| ";
    }
}

/**
 * @brief Sorts an array using the Bubble Sort algorithm.
 *
 * This function sorts an array of integers in ascending order using the bubble
 * sort algorithm. The algorithm repeatedly steps through the list, compares
 * adjacent elements, and swaps them if they are in the wrong order.
 *
 * @param array The integer array to be sorted
 */

void bubbleSort(int array[SIZE])
{
    int temp; // Temporary variable for swapping

    // Outer loop to control the number of passes
    for (int i = 0; i < SIZE - 1; i++)
    {
        // Inner loop to compare adjacent elements
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            // If the current element is greater than the next, swap them
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
