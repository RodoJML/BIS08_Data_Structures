#include <iostream>
void countdown(int n);

int main() {
    int userInput;

    std::cout << "Enter number to countdown: ";
    std::cin >> userInput;

    countdown(userInput);

    return 0;
}


void countdown(int n){

    if(n <= 0)
        return;

    countdown(n - 1);

    printf("%i", n);

    if(n = 1)
        return;
    
    countdown(n + 1);


    for (int i = 0; i < n; i++)
        printf("%i", i);
}