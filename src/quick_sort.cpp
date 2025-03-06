// Fast and efficient method for large lists
// Good for when we don't know the state of the list

#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void quickSort(int array[SIZE], int start, int end);

/**
 * @brief Main function that demonstrates the sorting algorithm.
 *
 * Initializes an array of integers, prints it, sorts it using the quicksort
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

    // Sort the array using quicksort
    quickSort(array, 0, SIZE - 1);

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
 * @brief Sorts an array using the QuickSort algorithm.
 *
 * The QuickSort algorithm is a divide-and-conquer algorithm. It works by selecting a pivot element
 * from the array and partitioning the other elements into two sub-arrays, according to whether they
 * are smaller or greater than the pivot. The sub-arrays are then recursively sorted.
 *
 * @param array The integer array to be sorted
 * @param start The starting index of the section of the array to be sorted
 * @param end The ending index of the section of the array to be sorted
 */

void quickSort(int array[SIZE], int start, int end)
{
    int pivot, left, right, middle, temp;

    // Left and right boundaries of the section being analyzed
    left = start;
    right = end;

    // Find the middle index and set it as the pivot
    middle = (left + right) / 2;
    pivot = array[middle];

    // Partition the array around the pivot
    while (right > left)
    {
        // Move the left boundary to the right until an element larger than the pivot is found
        while (array[left] < pivot)
        {
            left++;
        }

        // Move the right boundary to the left until an element smaller than the pivot is found
        while (array[right] > pivot)
        {
            right--;
        }

        // If the left boundary is less than or equal to the right boundary, swap the elements
        if (left <= right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;

            // Move the boundaries towards the center
            left++;
            right--;
        }

        // Print the array after each partition to show the sorting progress
        printArray(array);
        std::cout << std::endl;
    }

    // Recursively sort the left partition if necessary
    if (start < right)
    {
        quickSort(array, start, right);
    }

    // Recursively sort the right partition if necessary
    if (left < end)
    {
        quickSort(array, left, end);
    }
}
