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

int         array[5]    = {0, 0, 0, 0, 0};
Node*       head        = nullptr;
DoublyNode* dHead       = nullptr;

int operationsMenu(int type);
void create(int type);
void createFront(Node*& head, int element, int type);
void createEnd(Node*& head, int element, int type);
void createAt(Node*& head, int element, int index, int type);
void read(int type);
void update(int type);
void delet(int type);

void createFront(DoublyNode*& dHead, int element, int type);
void createEnd(DoublyNode*& dHead, int element, int type);
void createAt(DoublyNode*& dHead, int element, int index, int type);

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

    switch(type) {

        // Static List
        case 1: {

            printf("Indicate the position to add an element: ");
            scanf("%d", &index);
            printf("Enter the element to add: ");
            scanf("%d", &element);

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
            int choice;

            printf("\n=Linked List Create Menu=\n");
            printf("1. Add Element at Beginning\n");
            printf("2. Add Element at End\n");
            printf("3. Add Element at Position\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Adding Element at Beginning\n");
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createFront(head, element, type);
                    break;
                case 2:
                    printf("Adding Element at End\n");
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createEnd(head, element, type);
                    break;
                case 3:
                    printf("Indicate the position to add an element: ");
                    scanf("%d", &index);
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createAt(head, element, index, type);
                    break;
                default:
                    printf("Invalid choice for Simple Linked List creation.\n");
            }
        
            break;
        }
            
        case 3: {
            int choice;
            printf("\n=Linked List Create Menu=\n");
            printf("1. Add Element at Beginning\n");
            printf("2. Add Element at End\n");
            printf("3. Add Element at Position\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Adding Element at Beginning\n");
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createFront(dHead, element, type);
                    break;
                case 2:
                    printf("Adding Element at End\n");
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createEnd(dHead, element, type);
                    break;
                case 3:
                    printf("Indicate the position to add an element: ");
                    scanf("%d", &index);
                    printf("Enter the element to add: ");
                    scanf("%d", &element);
                    createAt(dHead, element, index, type);
                    break;
                default:
                    printf("Invalid choice for Doubly Linked List creation.\n");
            }
            break;
        }
            
        
        default: 
            printf("Invalid type selected.\n");
            break;
        
            
    }

    return;

}

void createFront(Node*& head, int element, int type){
    printf("type is %d\n", type);
    // Simple Linked List
    if(type == 2){
        Node* newNode = new Node{element, head};
        head = newNode;
    }
    
    // Doubly Linked List
    if(type == 3){
        DoublyNode* newNode = new DoublyNode{element, dHead, nullptr};
        if (dHead) dHead->prev = newNode;
        dHead = newNode;
    }
}


void createEnd(Node*& head, int element, int type){

    // Simple Linked List
    if(type == 2){
        if (head == nullptr) {
            head = new Node{element, nullptr};
        } else {
            // We create a new node because we dont want to modify 
            // the original head instead we want to traverse the list
            Node* current = head;

            while (current->next != nullptr) {
                // Here we are actually modiying the current node
                // assigning the next pointer to the next node
                // so we can traverse the list
                current = current->next;
            }
            // Now we are at the end of the we can add the new node
            // We create a new node and assign the element and next pointer
            // to nullptr because it will be the last node
            current->next = new Node{element, nullptr};
        }
    }

    // Doubly Linked List
    if(type == 3){
        DoublyNode* newNode = new DoublyNode{element, nullptr, nullptr};
        if (!dHead) {
            dHead = newNode;
            return;
        }
        DoublyNode* current = dHead;
        while (current->next) current = current->next;
        current->next = newNode;
        newNode->prev = current;
    }
}

void createAt(Node*& head, int element, int index, int type){

    // Simple Linked List
    if(type == 2){

        // Validation: Index | we create node at the front
        if(index == 0) {
            createFront(head, element, type);
            return;
        }

        Node* current = head;

        // We traverse from start to the index - 1
        // because we want to insert the new node after the current node
        for(int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }

        // Validation: Index
        if(current == nullptr) {
            printf("Index out of bounds. Cannot add element at index %d.\n", index);
            return;
        }
        
        current->next = new Node{element, current->next};
        return;
    }

    // Doubly Linked List
    if(type == 3){

        if (index == 0) {
            createFront(dHead, element, type);
            return;
        }
        DoublyNode* current = dHead;
        for (int i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }
        if (!current) {
            printf("Index out of bounds. Cannot add element at index %d.\n", index);
            return;
        }
        DoublyNode* newNode = new DoublyNode{element, current->next, current};
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
    }
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
        case 2: {
            printf("\n== Read: Simple Linked List Elements ==\n");
            int count = 0;
            Node* current = head;
            while(current != nullptr) {
                count++;
                printf("Element %d: %d\n", count, current->data);
                current = current->next; // Move to the next node
            }
            break;
        }
        case 3: {
            printf("\n== Read: Doubly Linked List Elements ==\n");
            
            DoublyNode* current = dHead;
            while(current != nullptr) {
                printf("Element: %d\n", current->data);
                current = current->next; // Move to the next node
            }
            break;
        }
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
        case 2: {
            // Update in Simple Linked List
            Node* current = head;
            for (int i = 0; i < index && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr) {
                printf("Index out of bounds. Cannot update at index %d.\n", index);
                break;
            }
            current->data = element;
            printf("Element at index %d updated to %d.\n", index, element);
            break;
        }
        case 3: {
            // Update in Doubly Linked List
            DoublyNode* current = dHead;
            for (int i = 0; i < index && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr) {
                printf("Index out of bounds. Cannot update at index %d.\n", index);
                break;
            }
            current->data = element;
            printf("Element at index %d updated to %d.\n", index, element);
            break;
        }
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
        case 2: {
            // Delete from Simple Linked List
            if (head == nullptr) {
                printf("List is empty. Nothing to delete.\n");
                break;
            }
            if (index == 0) {
                Node* temp = head;
                head = head->next;
                printf("Element %d at index 0 deleted.\n", temp->data);
                delete temp;
                break;
            }
            Node* current = head;
            for (int i = 0; i < index - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr) {
                printf("Index out of bounds. Cannot delete at index %d.\n", index);
                break;
            }
            Node* temp = current->next;
            printf("Element %d at index %d deleted.\n", temp->data, index);
            current->next = temp->next;
            delete temp;
            break;}
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