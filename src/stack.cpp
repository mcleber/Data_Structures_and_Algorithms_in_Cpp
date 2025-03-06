#include <iostream>
#include <string>

#define TAM 10 // Maximum size of the stack

// LIFO: Last In - First Out

// Function prototypes
void PrintStack(int stack[TAM], int top);
bool IsStackEmpty(int top);
bool IsStackFull(int top);
int GetStackSize(int top);
int GetTopValue(int stack[TAM], int *top);
void PushToStack(int stack[TAM], int value, int *top);
void PopFromStack(int stack[TAM], int *top);
void StackConstructor(int stack[TAM], int *top);

int main()
{
    int top = -1; // No elements in the stack initially

    // Create the stack
    int stack[TAM]{};

    // Initialize the stack
    StackConstructor(stack, &top);

    // Print the stack
    PrintStack(stack, top);
    std::cout << std::endl;

    // Push some values to the stack
    PushToStack(stack, 8, &top);
    PrintStack(stack, top);

    std::cout << "\nTop value of the stack: " << GetTopValue(stack, &top) << std::endl;
    std::cout << "Stack size: " << GetStackSize(top) << std::endl;
    std::cout << std::endl;

    // Push more values to the stack
    PushToStack(stack, 3, &top);
    PushToStack(stack, 4, &top);
    PushToStack(stack, 9, &top);
    PushToStack(stack, 1, &top);
    PushToStack(stack, 7, &top);
    PushToStack(stack, 6, &top);
    PushToStack(stack, 5, &top);

    // Print the stack after pushing values
    PrintStack(stack, top);
    std::cout << std::endl;

    // Pop a value from the stack
    PopFromStack(stack, &top);
    PrintStack(stack, top);
    std::cout << std::endl;

    return 0;
}

/**
 * Prints the current state of the stack.
 * @param stack The stack array.
 * @param top The current top of the stack.
 */
void PrintStack(int stack[TAM], int top)
{
    for (int i = 0; i < TAM; ++i)
    {
        std::cout << stack[i] << " - ";
    }

    std::cout << "Top: " << top << std::endl;
}

/**
 * Checks if the stack is empty.
 * @param top The current top of the stack.
 * @return True if the stack is empty, otherwise false.
 */
bool IsStackEmpty(int top)
{
    return top == -1;
}

/**
 * Checks if the stack is full.
 * @param top The current top of the stack.
 * @return True if the stack is full, otherwise false.
 */
bool IsStackFull(int top)
{
    return top == TAM - 1;
}

/**
 * Returns the current size of the stack.
 * @param top The current top of the stack.
 * @return The size of the stack.
 */
int GetStackSize(int top)
{
    return top + 1;
}

/**
 * Returns the value at the top of the stack.
 * @param stack The stack array.
 * @param top Pointer to the current top of the stack.
 * @return The value at the top of the stack, or a message if the stack is empty.
 */
int GetTopValue(int stack[TAM], int *top)
{
    if (IsStackEmpty(*top))
    {
        std::cout << "\nThe stack is empty." << std::endl;
        return -1; // Return an invalid value if the stack is empty
    }
    else
    {
        return stack[*top];
    }
}

/**
 * Pushes a value onto the stack.
 * @param stack The stack array.
 * @param value The value to be pushed.
 * @param top Pointer to the current top of the stack.
 */
void PushToStack(int stack[TAM], int value, int *top)
{
    if (IsStackFull(*top))
    {
        std::cout << "\nStack is full!" << std::endl;
    }
    else
    {
        *top += 1;
        stack[*top] = value;
    }
}

/**
 * Pops a value from the stack.
 * @param stack The stack array.
 * @param top Pointer to the current top of the stack.
 */
void PopFromStack(int stack[TAM], int *top)
{
    if (IsStackEmpty(*top))
    {
        std::cout << "\nThe stack is already empty." << std::endl;
    }
    else
    {
        std::cout << "\nValue popped: " << stack[*top] << std::endl;
        stack[*top] = 0; // Optionally reset the popped value
        *top -= 1;
    }
}

/**
 * Initializes the stack and sets the top index to -1.
 * @param stack The stack array.
 * @param top Pointer to the current top of the stack.
 */
void StackConstructor(int stack[TAM], int *top)
{
    *top = -1;

    // Initialize stack with 0 values
    for (int i = 0; i < TAM; ++i)
    {
        stack[i] = 0;
    }
}
