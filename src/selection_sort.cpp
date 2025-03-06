// Good for small arrays

#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void selectionSort(int array[SIZE]);

/**
 * @brief Main function that demonstrates the sorting algorithm.
 *
 * Initializes an array of integers, prints it, sorts it using the selection sort
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

    // Sort the array using selection sort
    selectionSort(array);

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
 * @brief Sorts an array using the Selection Sort algorithm.
 *
 * The Selection Sort algorithm works by finding the smallest element in the unsorted part
 * of the array and swapping it with the first unsorted element. This process is repeated
 * for each element until the array is sorted.
 *
 * @param array The integer array to be sorted
 */

void selectionSort(int array[SIZE])
{
    int minIndex, temp, i, j;

    // Loop through each element of the array
    for (i = 0; i < SIZE; i++)
    {
        // Assume the current position holds the smallest element
        minIndex = i;

        // Look for a smaller element in the unsorted part of the array
        for (j = i + 1; j < SIZE; j++)
        {
            // If a smaller element is found, update the index of the minimum element
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        // If the smallest element is not in the current position, swap them
        if (minIndex != i)
        {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }

        // Print the array after each iteration to show the sorting progress
        printArray(array);
        std::cout << std::endl;
    }
}
