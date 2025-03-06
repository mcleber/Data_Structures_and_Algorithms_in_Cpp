// Works well for large lists

#include <iostream>
#include <string>

#define SIZE 10

// Function prototypes
void printArray(int array[]);
void merge(int array[SIZE], int leftIndex, int middle, int rightIndex);
void mergeSort(int array[SIZE], int leftIndex, int rightIndex);

/**
 * @brief Main function demonstrating the Merge Sort algorithm.
 *
 * This function initializes an array, prints it, sorts it using the Merge Sort algorithm,
 * and then prints the sorted array.
 *
 * @return int Status code (0 for success)
 */

int main()
{
    // Initialize the array with values in descending order
    int array[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Print the original array
    printArray(array);
    std::cout << std::endl;
    std::cout << std::endl;

    // Sort the array using Merge Sort
    mergeSort(array, 0, SIZE - 1);

    // Print the sorted array
    printArray(array);

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * @brief Prints the elements of an integer array.
 *
 * This function prints each element of the array with a pipe ('|') separator for better readability.
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
 * @brief Merges two subarrays of the given array.
 *
 * This function merges two sorted subarrays into a single sorted subarray. It is used during
 * the Merge Sort process to combine the divided sections of the array back together.
 *
 * @param array The integer array being sorted
 * @param leftIndex The starting index of the left subarray
 * @param middle The middle index that divides the array
 * @param rightIndex The ending index of the right subarray
 */

void merge(int array[SIZE], int leftIndex, int middle, int rightIndex)
{
    // Calculate the size of the two subarrays to be merged
    int n1 = middle - leftIndex + 1;
    int n2 = rightIndex - middle;

    // Create temporary arrays for the left and right subarrays
    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = array[middle + 1 + j];
    }

    // Merge the two subarrays back into the original array
    int i = 0, j = 0, k = leftIndex;

    while (i < n1 && j < n2)
    {
        // If the element in the left array is smaller or equal, add it to the original array
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left array, if any
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right array, if any
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    delete[] leftArray;
    delete[] rightArray;
}

/**
 * @brief Performs Merge Sort on the given array.
 *
 * This function recursively divides the array into halves, sorts each half, and then merges
 * the sorted halves back together. Merge Sort is a divide-and-conquer sorting algorithm.
 *
 * @param array The integer array to be sorted
 * @param leftIndex The starting index of the array section to be sorted
 * @param rightIndex The ending index of the array section to be sorted
 */

void mergeSort(int array[SIZE], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        // Find the middle index
        int middle = leftIndex + (rightIndex - leftIndex) / 2;

        // Recursively sort the left half
        mergeSort(array, leftIndex, middle);

        // Recursively sort the right half
        mergeSort(array, middle + 1, rightIndex);

        // Merge the two sorted halves
        merge(array, leftIndex, middle, rightIndex);

        // Optional: Print the array after each merge (for visualization)
        printArray(array);
        std::cout << std::endl;
    }
}
