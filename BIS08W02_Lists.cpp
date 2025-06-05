#include <iostream>
#include <string>
// Homework 1: Implement CRUD operations in C++

struct Node {
    int data;
    Node* next;
};

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};

int array[5] = {0, 0, 0, 0, 0};
// Static List with a fixed size of 5
// Simple Linked List and Doubly Linked List will be implemented later

int operationsMenu(int type);
void create(int type);
void read(int type);
void update(int type);
void delet(int type);

int main(){

    int choice;
    while (true) {
        printf("\n== Homework 1: Implement CRUD operations for lists == \n"
                "Select list type:      \n"
                "1. Static List         \n"
                "2. Simple Linked List  \n"
                "3. Doubly Linked List  \n"
                "4. Exit                \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(operationsMenu(choice)) {
            case 0:
                return 0;
            case 1:
                create(choice);
                break;
            case 2:
                read(choice);
                break;
            case 3:
                update(choice);
                break;
            case 4:
                delet(choice);
                break;
            case 5:
                main();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    }

    return 0;
}


void create(int type){

    int index, element;

    printf("Indicate the position to add an element: ");
    scanf("%d", &index);
    printf("Enter the element to add: ");
    scanf("%d", &element);

    switch(type) {

        // Static List
        case 1: {

            // Validation: Index
            if(index < 0 || index >= 5) {
                printf("Index out of bounds. Please enter a valid index (0-4).\n");
                break;
            }

            // Validation: Element at the index
            if(array[index] != 0) {
                printf("Position %d is already occupied by element %d.\n", index, array[index]);
                break;
            }

            // Create the element
            array[index] = element;
            printf("Element %d added at index %d.\n", element, index);
            break;
        }

        // Simple Linked List
        case 2: {
            // Implementation for Simple Linked List creation will go here
            // Implementation below
        
            break;
        }
            
        
        case 3: 
            break;
        
        default: 
            printf("Invalid type selected.\n");
            break;
        
            
    }

    return;

}

void read(int type) {

    switch(type){
        case 1: {
            printf("\n== Read: Static List Elements ==\n");
            for(int i = 0; i < 5; i++) {
                printf("Index %d: %d\n", i, array[i]);
            }
            break;
        }
        case 2: 
            // Read from Simple Linked List
            break;
        case 3: 
            // Read from Doubly Linked List
            break;
    }

    return;

}

void update(int type) {

    int index, element;

    printf("Indicate the position to update an element: ");
    scanf("%d", &index);
    printf("Enter the new element: ");
    scanf("%d", &element);

    switch(type) {

        // Static List
        case 1: {

            // Validation: Index
            if(index < 0 || index >= 5) {
                printf("Index out of bounds. Please enter a valid index (0-4).\n");
                break;
            }

            // Update the element
            array[index] = element;
            printf("Element at index %d updated to %d.\n", index, element);
            break;
        }
        case 2: 
            // Update in Simple Linked List
            break;
        
        case 3: 
            // Update in Doubly Linked List
            break;
        
        default: 
            printf("Invalid type selected.\n");
            break;
        
    }
    return;

}

void delet(int type) {

    int index;

    printf("Indicate the position to delete an element: ");
    scanf("%d", &index);

    switch(type) {

        // Static List
        case 1: {

            // Validation: Index
            if(index < 0 || index >= 5) {
                printf("Index out of bounds. Please enter a valid index (0-4).\n");
                break;
            }

            // Delete the element
            if(array[index] == 0) {
                printf("Position %d is already empty.\n", index);
            } else {
                printf("Element %d at index %d deleted.\n", array[index], index);
                array[index] = 0; // Reset the position
            }
            break;
        }
        case 2: 
            // Delete from Simple Linked List
            break;
        case 3: 
            // Delete from Doubly Linked List
            break;
        
        default: 
            printf("Invalid type selected.\n");
            break;
        
    }

    return;
}


int operationsMenu(int type) {

    int choice;
    std::string listType;

    switch(type){
        case 1: 
            printf("NOTICE: Static List has a fixed size of 5.\n");
            listType = "Static List";
            break; 
        case 2: 
            listType = "Simple Linked List";
            break;    
        case 3: 
            listType = "Doubly Linked List";
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0; 
        default:
            return -1;
    }

    printf("== %s Operations Menu == \n"
           "1. Create                \n"
           "2. Read                  \n"
           "3. Update                \n"
           "4. Delete                \n"
           "5. Back to Main Menu     \n", listType.c_str());

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}   