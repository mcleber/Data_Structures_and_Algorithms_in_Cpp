#include <iostream>
#include <string>

#define SIZE 10 // Define the size of the queue

// FIFO: First In - First Out

// Function prototypes
void PrintQueue(int queue[SIZE], int size);
void QueueConstructor(int *front, int *rear);
bool IsQueueEmpty(int front, int rear);
bool IsQueueFull(int rear);
void Enqueue(int queue[SIZE], int value, int *rear);
void Dequeue(int queue[SIZE], int *front, int rear);
int QueueSize(int rear, int front);

int main()
{
    // Initialize variables
    setlocale(LC_ALL, "en-US");

    int front, rear, value;
    int queue[SIZE] = {0}; // Initialize the queue with zeros

    // Set up the queue with initial values for front and rear
    QueueConstructor(&front, &rear);

    // Enqueue some values
    Enqueue(queue, 5, &rear);
    Enqueue(queue, 7, &rear);

    // Dequeue and print values
    Dequeue(queue, &front, rear);
    Dequeue(queue, &front, rear);
    Dequeue(queue, &front, rear);

    // Enqueue a new value
    Enqueue(queue, 8, &rear);

    // Print the current queue and its size
    PrintQueue(queue, QueueSize(rear, front));

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * Prints the current state of the queue.
 *
 * @param queue The queue array.
 * @param size The size of the queue.
 */
void PrintQueue(int queue[SIZE], int size)
{
    // Print each element in the queue, followed by a separator
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << queue[i] << " - ";
    }
    std::cout << std::endl;
}

/**
 * Initializes the queue with the front at 0 and the rear at -1.
 *
 * @param front A pointer to the front index of the queue.
 * @param rear A pointer to the rear index of the queue.
 */
void QueueConstructor(int *front, int *rear)
{
    *front = 0; // Set the front pointer to 0
    *rear = -1; // Set the rear pointer to -1, indicating an empty queue
}

/**
 * Checks if the queue is empty.
 *
 * @param front The front index of the queue.
 * @param rear The rear index of the queue.
 * @return True if the queue is empty, otherwise false.
 */
bool IsQueueEmpty(int front, int rear)
{
    return front > rear; // Queue is empty if front index is greater than rear
}

/**
 * Checks if the queue is full.
 *
 * @param rear The rear index of the queue.
 * @return True if the queue is full, otherwise false.
 */
bool IsQueueFull(int rear)
{
    return rear == SIZE - 1; // Queue is full if rear reaches the last index
}

/**
 * Adds a value to the queue (enqueue operation).
 *
 * @param queue The queue array.
 * @param value The value to be added to the queue.
 * @param rear A pointer to the rear index of the queue.
 */
void Enqueue(int queue[SIZE], int value, int *rear)
{
    // Check if the queue is full
    if (IsQueueFull(*rear))
    {
        std::cout << "Queue is full.\n";
    }
    else
    {
        *rear = *rear + 1;    // Increment the rear pointer
        queue[*rear] = value; // Place the value at the rear of the queue
    }
}

/**
 * Removes a value from the queue (dequeue operation).
 *
 * @param queue The queue array.
 * @param front A pointer to the front index of the queue.
 * @param rear The rear index of the queue.
 */
void Dequeue(int queue[SIZE], int *front, int rear)
{
    // Check if the queue is empty
    if (IsQueueEmpty(*front, rear))
    {
        std::cout << "\nUnable to dequeue from an empty queue.\n";
    }
    else
    {
        // Print the value that is dequeued
        std::cout << "\nValue " << queue[*front] << " was removed.\n";
        queue[*front] = 0;   // Set the dequeued position to 0 (optional)
        *front = *front + 1; // Increment the front pointer
    }
}

/**
 * Returns the current size of the queue.
 *
 * @param rear The rear index of the queue.
 * @param front The front index of the queue.
 * @return The current size of the queue.
 */
int QueueSize(int rear, int front)
{
    return (rear - front) + 1; // The size of the queue is the difference between rear and front
}
