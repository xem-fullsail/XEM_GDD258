// QuestionApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "WHAT! is your favorite color?\n";

    char response[64];
    std::cin >> response;

    std::cout << "That's a great choice!\n";
}

