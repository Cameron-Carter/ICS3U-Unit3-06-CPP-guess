// Copyright (c) Cameron Carter All rights reserved
//
// Created by: Cameron Carter
// Created on: May 2021
// This program lets the user guess a number from 1-10

#include <iostream>
#include <random>
#include <string>

int main() {
    // This program lets the user guess an integer from 1-10
    std::string guessAsString;
    int guessAsNumber;
    int randomNumber;

    // Input
    std::cout << "Guess an integer from 1-10: ";
    std::cin >> guessAsString;

    // Process and Output
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 10);
    randomNumber = idist(rgen);
    try {
        guessAsNumber = std::stoi(guessAsString);
        if (guessAsNumber == randomNumber) {
            std::cout << "\nCorrect! The number was " << randomNumber << ".";
        } else {
            std::cout << "\nIncorrect! The number was " << randomNumber << ".";
        }
    } catch (std::invalid_argument) {
        std::cout << "\n" << guessAsString
        << " is not an integer!" << std::endl;
    }
    std::cout << "\n\nDone." << std::endl;
}
