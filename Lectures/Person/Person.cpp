// Person.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>


class Person {

public:
    std::string FirstName;
    std::string LastName;
    std::string Address;
    std::string City;
    std::string State;
    int ZipCode;

    Person(std::string first, std::string last, std::string address, std::string city, std::string state, int zip) {
        FirstName = first;
        LastName = last;
        Address = address;
        City = city;
        State = state;
        ZipCode = zip;
    }

};

int main()
{
    std::string firstName;
    std::cout << "Hello! Tell me more about you!\nWhat is your first name?\n";
    std::cin >> firstName;

    std::string lastName;
    std::cout << "What is your last name?\n";
    std::cin >> lastName;

    std::string address;
    std::cout << "What is your street address?\n";
    std::cin >> address;

    std::string city;
    std::cout << "What is your city?\n";
    std::cin >> city;

    std::string state;
    std::cout << "What is your state?\n";
    std::cin >> state;

    int zip;
    std::cout << "What is your zip code?\n";
    std::cin >> zip;

    Person person = Person(firstName, lastName, address, city, state, zip);
    std::cout << person.FirstName << " " << person.LastName << "\n" << person.Address << "\n" << person.City << ", " << person.State << " " << person.ZipCode << "\n";
}

