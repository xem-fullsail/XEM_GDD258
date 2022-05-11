// Person.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>
#include <vector>


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

class Comet {

public:
    std::string Name;

    Comet();

    Comet(std::string name) {
        Name = name;
    }

};

std::string GetTextInput(std::string prompt) {
    std::string s;
    std::cout << prompt << " ";
    std::getline(std::cin, s);
    return s;
}

int GetIntInput(const char* message, int min = 0, int max = 0) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid integer.\n";
        }
        else {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            if (min == 0 && max == 0) break;
            else if (value < min || value > max) std::cout << "Input should be between " << min << " and " << max << ".\n";
            else break;
        }
    }
    return value;
}

Person CreatePerson() {
    Person person;
    person.FirstName = GetTextInput("What is your first name?");
    person.LastName = GetTextInput("What is your last name?");
    person.Address = GetTextInput("What is your address?");
    person.City = GetTextInput("What is your city?");
    person.State = GetTextInput("What is your state?");
    person.ZipCode = std::stoi(GetTextInput("What is your zip code?"));
    return person;
}

int main()
{
    std::vector<Person> people;

    bool cont = true;
    while (cont) {
        int numPeople = 0;
        
        std::cout << "+------------------------------------------------+\n1. Create a person\n2. Create people\n0. Quit\n";
        int menuChoice = GetIntInput("What would you like to do ? ", 0, 2);

        switch (menuChoice) {
            case 1:
                std::cout << "+------------------------------------------------+\n";
                people.push_back(CreatePerson());
                break;
            case 2:
                numPeople = GetIntInput("How many people would you like to create? ");
                for (int i = 0; i < numPeople; i++) {
                    std::cout << "+------------------------------------------------+\n";
                    people.push_back(CreatePerson());
                }
                break;
            default:
                cont = false;
                break;
        }
    }

    std::cout << "+------------------------------------------------+\nCurrent People:\n\n";
    for (Person p : people)
        std::cout << p.Display() << std::endl;

    Comet comet = Comet("Sozen's Comet");
    std::cout << "\n+------------------------------------------------+\Current Comets:\n\n";
    std::cout << comet.Name << std::endl;

}

