#include <iostream>
#include <new>
#include <string>

// Define the person structure to hold the name, RG, and position
struct person
{
    std::string name;
    int rg;
    int position; // This is used for inserting nodes at specific positions
};

// Function prototypes
void clearScreen();
void printListSequentially(person *ptrSequential, int listSize);
void addAtStartSequentially(person *&ptrSequential, int *listSize, std::string name, int rg);
void addAtEndSequentially(person *&ptrSequential, int *listSize, std::string name, int rg);
void addAtPositionSequentially(person *&ptrSequential, int *listSize, std::string name, int rg, int position);
void removeFromStartSequentially(person *&ptrSequential, int *listSize);
void removeFromEndSequentially(person *&ptrSequential, int *listSize);
void removeAtPositionSequentially(person *&ptrSequential, int *listSize, int position);
std::string getNameByRGSequentially(person *&ptrSequential, int *listSize, int rg);

/**
 * @brief Main function of the program.
 *
 * This is where the interactive menu is displayed and operations are performed based on the user's choice.
 */
int main()
{
    int desiredOperation{1};         // Variable to store the user's operation choice
    person *ptrSequential = nullptr; // Pointer to hold the list of people
    int listSize{0};                 // The current size of the list
    person Person;                   // Temporary variable to store data for the person being added

    // Keep running the menu as long as the operation choice is valid
    while (desiredOperation < 9 && desiredOperation > 0)
    {
        std::cout << "----------------- Operations -----------------" << std::endl;
        std::cout << "[1]. Add a node at the start of the list" << std::endl;
        std::cout << "[2]. Add a node at the end of the list" << std::endl;
        std::cout << "[3]. Add a node at position N" << std::endl;
        std::cout << "[4]. Remove a node from the start of the list" << std::endl;
        std::cout << "[5]. Remove a node from the end of the list" << std::endl;
        std::cout << "[6]. Remove a node at position N" << std::endl;
        std::cout << "[7]. Search for a node by RG" << std::endl;
        std::cout << "[8]. Print the list" << std::endl;
        std::cout << "[9]. Exit the system" << std::endl;

        std::cout << std::endl;
        std::cout << "Choose an operation and press ENTER: " << std::flush;
        std::cin >> desiredOperation;

        clearScreen(); // Clear the screen after user input

        switch (desiredOperation)
        {
        case 1:
            std::cout << "Chosen operation: 1 - Add a node at the start of the list.\n\n";
            std::cout << "Enter a name: ";
            std::cin >> Person.name;
            std::cout << "Enter an RG: ";
            std::cin >> Person.rg;

            addAtStartSequentially(ptrSequential, &listSize, Person.name, Person.rg);
            std::cout << "\nUser: " << Person.name << " , RG: " << Person.rg << " added to the start of the list.\n\n";
            break;

        case 2:
            std::cout << "Chosen operation: 2 - Add a node at the end of the list.\n\n";
            std::cout << "Enter a name: ";
            std::cin >> Person.name;
            std::cout << "Enter an RG: ";
            std::cin >> Person.rg;

            if (listSize == 0)
            {
                addAtStartSequentially(ptrSequential, &listSize, Person.name, Person.rg);
            }
            else
            {
                addAtEndSequentially(ptrSequential, &listSize, Person.name, Person.rg);
            }

            std::cout << "\nUser: " << Person.name << " , RG: " << Person.rg << " added to the end of the list.\n\n";
            break;

        case 3:
            std::cout << "Chosen operation: 3 - Add a node at position N.\n\n";
            std::cout << "Enter a name: ";
            std::cin >> Person.name;
            std::cout << "Enter an RG: ";
            std::cin >> Person.rg;
            std::cout << "Enter a position: ";
            std::cin >> Person.position;

            if (listSize == 0)
            {
                addAtStartSequentially(ptrSequential, &listSize, Person.name, Person.rg);
            }
            else if (Person.position == listSize)
            {
                addAtEndSequentially(ptrSequential, &listSize, Person.name, Person.rg);
            }
            else
            {
                addAtPositionSequentially(ptrSequential, &listSize, Person.name, Person.rg, Person.position);
            }

            std::cout << "\nUser: " << Person.name << " , RG: " << Person.rg << " added at position: " << Person.position << " in the list.\n\n";
            break;

        case 4:
            std::cout << "Chosen operation: 4 - Remove a node from the start of the list.\n\n";

            if (listSize == 0)
            {
                std::cout << "\nThe list is empty.\n\n";
            }
            else
            {
                removeFromStartSequentially(ptrSequential, &listSize);
            }
            break;

        case 5:
            std::cout << "Chosen operation: 5 - Remove a node from the end of the list.\n\n";

            if (listSize == 0)
            {
                std::cout << "\nThe list is empty.\n\n";
            }
            else
            {
                removeFromEndSequentially(ptrSequential, &listSize);
            }
            break;

        case 6:
            std::cout << "Chosen operation: 6 - Remove a node at position N.\n\n";

            if (listSize == 0)
            {
                std::cout << "\nThe list is empty.\n\n";
            }
            else
            {
                std::cout << "Enter a position: ";
                std::cin >> Person.position;

                if (Person.position == 0)
                {
                    removeFromStartSequentially(ptrSequential, &listSize);
                }
                else if (Person.position == listSize - 1)
                {
                    removeFromEndSequentially(ptrSequential, &listSize);
                }
                else
                {
                    removeAtPositionSequentially(ptrSequential, &listSize, Person.position);
                }
            }
            break;

        case 7:
            std::cout << "Chosen operation: 7 - Search for a node by RG.\n\n";

            if (listSize == 0)
            {
                std::cout << "\nThe list is empty.\n\n";
            }
            else
            {
                std::cout << "Enter an RG: ";
                std::cin >> Person.rg;

                std::cout << "\nName associated with RG: " << getNameByRGSequentially(ptrSequential, &listSize, Person.rg) << "\n\n";
            }
            break;

        case 8:
            std::cout << "Chosen operation: 8 - Print the list.\n\n";
            printListSequentially(ptrSequential, listSize);
            std::cout << std::endl;
            break;

        case 9:
            std::cout << "\nExiting the system...\n";
            break;
        }
    }

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * Clears the console screen.
 */
void clearScreen()
{
    system("CLS || CLEAR");
}

/**
 * Prints the list of people.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Current size of the list.
 */
void printListSequentially(person *ptrSequential, int listSize)
{
    // Loop through the list and print each person
    for (int i = 0; i < listSize; i++)
    {
        std::cout << i << "- Name: " << ptrSequential[i].name << ", RG: " << ptrSequential[i].rg << std::endl;
    }
}

/**
 * Adds a person at the start of the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 * @param name Name of the person to be added.
 * @param rg RG of the person to be added.
 */
void addAtStartSequentially(person *&ptrSequential, int *listSize, std::string name, int rg)
{
    // If the list is empty, create a new array with one element
    if (*listSize == 0)
    {
        person *newList = new person[1];
        newList[0].name = name;
        newList[0].rg = rg;
        ptrSequential = newList;
    }
    else
    {
        // Otherwise, create a new array with one extra element
        person *newList = new person[*listSize + 1];
        newList[0].name = name;
        newList[0].rg = rg;

        // Copy existing list elements to the new list
        for (int i = 0; i < *listSize; i++)
        {
            newList[i + 1].name = ptrSequential[i].name;
            newList[i + 1].rg = ptrSequential[i].rg;
        }
        ptrSequential = newList;
    }
    (*listSize)++; // Increment the list size
}

/**
 * Adds a person at the end of the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 * @param name Name of the person to be added.
 * @param rg RG of the person to be added.
 */
void addAtEndSequentially(person *&ptrSequential, int *listSize, std::string name, int rg)
{
    // Create a new list with one more element
    person *newList = new person[*listSize + 1];

    // Copy existing list elements to the new list
    for (int i = 0; i < *listSize; i++)
    {
        newList[i].name = ptrSequential[i].name;
        newList[i].rg = ptrSequential[i].rg;
    }

    // Add the new person at the end of the list
    newList[*listSize].name = name;
    newList[*listSize].rg = rg;

    ptrSequential = newList;
    (*listSize)++; // Increment the list size
}

/**
 * Adds a person at a specific position in the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 * @param name Name of the person to be added.
 * @param rg RG of the person to be added.
 * @param position Position where the person will be inserted.
 */
void addAtPositionSequentially(person *&ptrSequential, int *listSize, std::string name, int rg, int position)
{
    // Create a new list with one extra element
    person *newList = new person[*listSize + 1];

    // Copy elements before the insertion position
    for (int i = 0; i < position; i++)
    {
        newList[i].name = ptrSequential[i].name;
        newList[i].rg = ptrSequential[i].rg;
    }

    // Insert the new person at the specified position
    newList[position].name = name;
    newList[position].rg = rg;

    // Copy remaining elements after the insertion point
    for (int i = position + 1; i < *listSize + 1; i++)
    {
        newList[i].name = ptrSequential[i - 1].name;
        newList[i].rg = ptrSequential[i - 1].rg;
    }

    ptrSequential = newList;
    (*listSize)++; // Increment the list size
}

/**
 * Removes a person from the start of the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 */
void removeFromStartSequentially(person *&ptrSequential, int *listSize)
{
    // Create a new list with one less element
    person *newList = new person[*listSize - 1];

    // Copy all elements except the first one
    for (int i = 1; i < *listSize; i++)
    {
        newList[i - 1].name = ptrSequential[i].name;
        newList[i - 1].rg = ptrSequential[i].rg;
    }
    ptrSequential = newList;
    (*listSize)--; // Decrement the list size
}

/**
 * Removes a person from the end of the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 */
void removeFromEndSequentially(person *&ptrSequential, int *listSize)
{
    // Create a new list with one less element
    person *newList = new person[*listSize - 1];

    // Copy all elements except the last one
    for (int i = 0; i < *listSize - 1; i++)
    {
        newList[i].name = ptrSequential[i].name;
        newList[i].rg = ptrSequential[i].rg;
    }

    ptrSequential = newList;
    (*listSize)--; // Decrement the list size
}

/**
 * Removes a person from a specific position in the list.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 * @param position Position where the person will be removed from.
 */
void removeAtPositionSequentially(person *&ptrSequential, int *listSize, int position)
{
    // Create a new list with one less element
    person *newList = new person[*listSize - 1];

    // Copy elements before the specified position
    for (int i = 0; i < *listSize; i++)
    {
        if (i < position)
        {
            newList[i].name = ptrSequential[i].name;
            newList[i].rg = ptrSequential[i].rg;
        }
        else
        {
            newList[i].name = ptrSequential[i + 1].name;
            newList[i].rg = ptrSequential[i + 1].rg;
        }
    }
    ptrSequential = newList;
    (*listSize)--; // Decrement the list size
}

/**
 * Returns the name of a person from their RG.
 * @param ptrSequential Pointer to the array of people.
 * @param listSize Pointer to the current size of the list.
 * @param rg RG of the person to be searched.
 * @return Name of the person with the given RG or "Not found" if not present.
 */
std::string getNameByRGSequentially(person *&ptrSequential, int *listSize, int rg)
{
    std::string name = "Not found."; // Default name if RG is not found
    for (int i = 0; i < *listSize; i++)
    {
        if (ptrSequential[i].rg == rg)
        {
            name = ptrSequential[i].name;
        }
    }
    return name;
}
