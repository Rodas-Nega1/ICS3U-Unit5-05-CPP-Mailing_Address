// Copyright (c) 2021 Rodas Nega All rights reserved
//
// Created by: Rodas Nega
// Created on: Oct 2021
// This program prints user inputs into their mailing address


#include <iostream>
#include <string>
#include <cstring>
#include <locale>


std::string ApartmentCheck(std::string fullName, int streetNumber,
                          std::string streetName, std::string cityName,
                          std::string province, std::string postalCode,
                          int apartment = -1) {
    // return apartment value
    std::locale loc;
    std::string liveInApartment;
    std::string liveInApartmentUpper = "";

    // process
    if (apartment != -1) {
        std::cout << "if" << std::endl;
        liveInApartment = fullName + "\n" + std::to_string(apartment) + "-" +
        std::to_string(streetNumber)
        + " " + streetName + "\n" + cityName + " " +
        province + "  " + postalCode;
    } else {
        std::cout << "else" << std::endl;
        liveInApartment = fullName + "\n" + std::to_string(streetNumber)
        + " " + streetName + "\n" + cityName + " " +
        province + "  " + postalCode;
    }

    int liveInApartmentLength = liveInApartment.length();
    // declaring character array
    char char_array[liveInApartmentLength + 1];
    strcpy(char_array, liveInApartment.c_str());

    for (int counter = 0; counter < liveInApartmentLength; counter++) {
        liveInApartmentUpper += std::toupper(char_array[counter], loc);
    }

    return liveInApartmentUpper;
}

int main() {
    // this function calls the precedent function

    // variables
    std::string fullName;
    std::string questionForUser;
    std::string streetNumber;
    int streetNumberInt;
    std::string streetName;
    std::string cityName;
    std::string province;
    std::string postalCode;
    std::string apartment = "";
    int apartmentInt;
    std::string promptList;

    // input & output
    std::cout << "Enter your full name: ";
    getline(std::cin, fullName);

    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, questionForUser);

    // if user inputted y or yes then display additional prompt
    if (questionForUser == "y" || questionForUser == "yes") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartment);
    }

    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumber);

    std::cout << "Enter your street name: ";
    getline(std::cin, streetName);

    std::cout << "Enter your city name: ";
    getline(std::cin, cityName);

    std::cout << "Enter your province (as an abbreviation, ex: ON, BC): ";
    getline(std::cin, province);

    std::cout << "Enter your postal code (123 456): ";
    getline(std::cin, postalCode);

    // if user has apartment then allow user to input their apartment number
    //  and hyphenate with street number, otherwise carry out program while
    //  omitting apartment number
    try {
        streetNumberInt = std::stoi(streetNumber);
        if (streetNumberInt < 0) {
            std::cout << "" << std::endl;
            std::cout << "That is an invalid number." << std::endl;
        } else if (apartment != "") {
        apartmentInt = std::stoi(apartment);
            if (apartmentInt < 0) {
                std::cout << "" << std::endl;
                std::cout << "That is an invalid number." << std::endl;
            } else {
                promptList = ApartmentCheck(fullName, streetNumberInt,
                streetName, cityName, province, postalCode, apartmentInt);
                std::cout << "" << std::endl;
                std::cout << promptList << std::endl;
            }
        } else {
            promptList = ApartmentCheck(fullName, streetNumberInt, streetName,
            cityName, province, postalCode);
            std::cout << "" << std::endl;
            std::cout << promptList << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "" << std::endl;
        std::cout << "That is an invalid response." << std::endl;
    }
        std::cout << "\nDone." << std::endl;
}
