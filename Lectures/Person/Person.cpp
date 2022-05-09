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

    Person() {
        //
    }

    Person(std::string first, std::string last, std::string address, std::string city, std::string state, int zip) {
        FirstName = first;
        LastName = last;
        Address = address;
        City = city;
        State = state;
        ZipCode = zip;
    }

    std::string Display() {
        return FirstName + " " + LastName + "\n" + Address + "\n" + City + ", " + State + " " + std::to_string(ZipCode) + "\n";
    }

};

std::string GetTextInput(std::string prompt) {
    std::string s;
    std::cout << prompt << " ";
    std::getline(std::cin, s);
    return s;
}

int main()
{
    Person person;
    person.FirstName = GetTextInput("What is your first name?");
    person.LastName = GetTextInput("What is your last name?");
    person.Address = GetTextInput("What is your address?");
    person.City = GetTextInput("What is your city?");
    person.State = GetTextInput("What is your state?");
    person.ZipCode = std::stoi(GetTextInput("What is your zip code?"));
    std::cout << person.Display();
}

