#include <iostream>
#include <new>
#include <string>

// Structure for a person to be stored in the linked list
struct Person
{
    std::string name;
    int rg, position;
    struct Person *next;
};

// Function prototypes
void ClearScreen();
int GetListSize(Person *ptrList);
void PrintList(Person *ptrList);
void AddAtStart(Person *&ptrList, std::string name, int rg);
void AddAtEnd(Person *&ptrList, std::string name, int rg);
void AddAtPosition(Person *&ptrList, std::string name, int rg, int position);
void RemoveFromStart(Person *&ptrList);
void RemoveFromEnd(Person *&ptrList);
void RemoveAtPosition(Person *&ptrList, int position);
std::string GetNameFromRG(Person *&ptrList, int rg);

/**
 * @brief Main function of the program. It controls the menu execution and operations performed on the linked list.
 *
 * @return Returns 0 upon completion.
 */
int main()
{
    int desiredOperation{1};

    // Create the pointer for the start of the linked list.
    Person *ptrList = new Person; // Pointer of type Person
    ptrList->name = "";
    ptrList->rg = 0;
    ptrList->next = nullptr;

    // Control loop to display the menu and execute operations
    while (desiredOperation < 9 && desiredOperation > 0)
    {
        std::cout << "----------------- Operations -----------------" << std::endl;
        std::cout << "[1]. Insert a node at the start of the list" << std::endl;
        std::cout << "[2]. Insert a node at the end of the list" << std::endl;
        std::cout << "[3]. Insert a node at position N" << std::endl;
        std::cout << "[4]. Remove a node from the start of the list" << std::endl;
        std::cout << "[5]. Remove a node from the end of the list" << std::endl;
        std::cout << "[6]. Remove a node from position N" << std::endl;
        std::cout << "[7]. Search for a node by RG" << std::endl;
        std::cout << "[8]. Print the list" << std::endl;
        std::cout << "[9]. Exit the system" << std::endl;

        std::cout << "\nCurrent list size: " << GetListSize(ptrList) << "\n";
        std::cout << "\nChoose the operation and press ENTER: ";
        std::cin >> desiredOperation;

        ClearScreen();

        switch (desiredOperation)
        {
        case 1:
            std::cout << "Chosen operation: 1 - Insert a node at the start of the list.\n\n";
            {
                std::string name;
                int rg;
                std::cout << "Enter a name: ";
                std::cin >> name;
                std::cout << "Enter an RG: ";
                std::cin >> rg;

                // Add to the start of the list or create a new one
                AddAtStart(ptrList, name, rg);

                std::cout << "\nUser: " << name << " , RG: " << rg << " added to the start of the list.\n\n";
            }
            break;

        case 2:
            std::cout << "Chosen operation: 2 - Insert a node at the end of the list.\n\n";
            {
                std::string name;
                int rg;
                std::cout << "Enter a name: ";
                std::cin >> name;
                std::cout << "Enter an RG: ";
                std::cin >> rg;

                // If the list is empty, use the function to add at the start
                if (GetListSize(ptrList) == 0)
                {
                    AddAtStart(ptrList, name, rg);
                }
                else
                {
                    AddAtEnd(ptrList, name, rg);
                }

                std::cout << "\nUser: " << name << " , RG: " << rg << " added to the end of the list.\n\n";
            }
            break;

        case 3:
            std::cout << "Chosen operation: 3 - Insert a node at position N.\n\n";
            {
                std::string name;
                int rg;
                int position;
                std::cout << "Enter a position: ";
                std::cin >> position;
                std::cout << "Enter a name: ";
                std::cin >> name;
                std::cout << "Enter an RG: ";
                std::cin >> rg;

                // If adding at the start
                if (position == 0)
                {
                    AddAtStart(ptrList, name, rg);
                }
                else if (position == GetListSize(ptrList) - 1)
                {
                    AddAtEnd(ptrList, name, rg);
                }
                else
                {
                    AddAtPosition(ptrList, name, rg, position);
                }

                std::cout << "\nUser: " << name << " , RG: " << rg << " added at position: " << position << " in the list.\n\n";
            }
            break;

        case 4:
            std::cout << "Chosen operation: 4 - Remove a node from the start of the list.\n\n";
            RemoveFromStart(ptrList);
            break;

        case 5:
            std::cout << "Chosen operation: 5 - Remove a node from the end of the list.\n\n";
            if (GetListSize(ptrList) == 1)
            {
                RemoveFromStart(ptrList);
            }
            else
            {
                RemoveFromEnd(ptrList);
            }
            break;

        case 6:
            std::cout << "Chosen operation: 6 - Remove a node at position N.\n\n";
            {
                int position;
                std::cout << "Enter a position: ";
                std::cin >> position;

                if (position == 0)
                {
                    RemoveFromStart(ptrList);
                }
                else if (position == GetListSize(ptrList) - 1)
                {
                    RemoveFromEnd(ptrList);
                }
                else
                {
                    RemoveAtPosition(ptrList, position);
                }
            }
            break;

        case 7:
            std::cout << "Chosen operation: 7 - Search for a node by RG.\n\n";

            // If the list is empty
            if (GetListSize(ptrList) == 0)
            {
                std::cout << "\nList is empty.\n\n";
            }
            else
            {
                int rg;
                std::cout << "Enter an RG: ";
                std::cin >> rg;

                std::cout << "\nThe name for RG: " << rg << " is " << GetNameFromRG(ptrList, rg) << "\n\n";
            }
            break;

        case 8:
            std::cout << "Chosen operation: 8 - Print the list.\n\n";
            PrintList(ptrList);
            std::cout << std::endl;
            break;
        }
    }

    std::cout << std::endl;
    system("PAUSE");
    return 0;
}

/**
 * @brief Clears the screen in the console.
 */
void ClearScreen()
{
    system("CLS || CLEAR");
}

/**
 * @brief Returns the size of the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 * @return The size of the linked list.
 */
int GetListSize(Person *ptrList)
{
    if (ptrList->name == "")
    {
        return 0;
    }

    int size{0};
    Person *p = ptrList;

    while (p != nullptr)
    {
        p = p->next;
        size++;
    }

    return size;
}

/**
 * @brief Prints the elements of the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 */
void PrintList(Person *ptrList)
{
    Person *p = ptrList;

    while (p != nullptr)
    {
        std::cout << p->name << " , " << p->rg << "\n";
        p = p->next;
    }
}

/**
 * @brief Adds a new element at the start of the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 * @param name Name of the person.
 * @param rg General registration (RG) of the person.
 */
void AddAtStart(Person *&ptrList, std::string name, int rg)
{
    Person *newValue = new Person;
    newValue->name = name;
    newValue->rg = rg;

    if (ptrList->name == "")
    {
        newValue->next = nullptr;
    }
    else
    {
        newValue->next = ptrList;
    }

    ptrList = newValue;
}

/**
 * @brief Adds a new element at the end of the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 * @param name Name of the person.
 * @param rg General registration (RG) of the person.
 */
void AddAtEnd(Person *&ptrList, std::string name, int rg)
{
    Person *newValue = new Person;
    newValue->name = name;
    newValue->rg = rg;
    newValue->next = nullptr;

    Person *p = ptrList;
    while (p != nullptr)
    {
        if (p->next == nullptr)
        {
            p->next = newValue;
            return;
        }

        p = p->next;
    }
}

/**
 * @brief Adds a new element at position N in the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 * @param name Name of the person.
 * @param rg General registration (RG) of the person.
 * @param position Position where the new element should be inserted.
 */
void AddAtPosition(Person *&ptrList, std::string name, int rg, int position)
{
    Person *newValue = new Person;
    newValue->name = name;
    newValue->rg = rg;
    newValue->next = nullptr;

    Person *p = ptrList;
    int count{0};
    while (count < position - 1)
    {
        p = p->next;
        count++;
    }

    Person *aux = new Person;
    aux->next = p->next;
    p->next = newValue;
    newValue->next = aux->next;
    free(aux);
}

/**
 * @brief Removes the first element from the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 */
void RemoveFromStart(Person *&ptrList)
{
    if (ptrList->next == nullptr)
    {
        Person *newValue = new Person;
        newValue->name = "";
        newValue->rg = 0;
        newValue->next = nullptr;

        ptrList = newValue;
    }
    else
    {
        ptrList = ptrList->next;
    }
}

/**
 * @brief Removes the last element from the linked list.
 *
 * @param ptrList Pointer to the start of the list.
 */
void RemoveFromEnd(Person *&ptrList)
{
    Person *p = ptrList;
    Person *aux = new Person;

    while (p->next != nullptr)
    {
        aux = p;
        p = p->next;
    }

    aux->next = nullptr;
}

/**
 * @brief Removes an element from the linked list at position N.
 *
 * @param ptrList Pointer to the start of the list.
 * @param position Position of the element to be removed.
 */
void RemoveAtPosition(Person *&ptrList, int position)
{
    Person *p = ptrList;
    int count{0};

    while (count < position - 1)
    {
        p = p->next;
        count++;
    }

    Person *aux = p->next;
    p->next = aux->next;
    free(aux);
}

/**
 * @brief Returns the name of the person based on their RG.
 *
 * @param ptrList Pointer to the start of the list.
 * @param rg RG of the person to be searched.
 * @return The name of the person or a message indicating it was not found.
 */
std::string GetNameFromRG(Person *&ptrList, int rg)
{
    std::string name{"\nNot found."};
    Person *p = ptrList;

    while (p != nullptr)
    {
        if (p->rg == rg)
        {
            name = p->name;
            return name;
        }

        p = p->next;
    }

    return name;
}
