#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool contains(const std::vector<std::string>& arr, const std::string& element) {
    for (const auto& item : arr) {
        if (item == element) {
            return true;
        }
    }
    return false;
}

std::string getCommand() {
    std::string commandAction;
    std::cout << "Type a command: buy, sell, check, next, profile \n" << std::endl;
    std::cin >> commandAction;
    return commandAction;
}

void processCheck(const float& money) 
{
    std::cout << "$" << money << "\n";
}

void processNext() 
{
    std::cout << "next!\n";
}

void processBuy(float& money, std::vector<std::string>& userProfile, const std::vector<std::string>& stockChoices) 
{
    std::string stockChoice;
    std::cout << "Which stock would you like to buy?\n";
    std::cin >> stockChoice;
    if (contains(stockChoices, stockChoice)) {
        money = money - 10;
        std::cout << "$" << money << "\n";
        userProfile.push_back(stockChoice);
    } else {
        std::cout << "Not a stock option! ";
    }
}

void processSell() {
    std::cout << "sell!\n";
}

void processProfile(const std::vector<std::string>& userProfile) {
    std::cout << "Profile: ";
    for(const std::string& element : userProfile) 
    {
        std::cout << element << " | ";
    }
    std::cout << "\n";
}

void processCommand(const std::string& command, float& money, std::vector<std::string>& userProfile, const std::vector<std::string>& stockChoices) {
    if (command == "check") {
        processCheck(money);
    } else if (command == "next") {
        processNext();
    } else if (command == "buy") {
        processBuy(money, userProfile, stockChoices);
    } else if (command == "sell") {
        processSell();
    } else if (command == "profile") {
        processProfile(userProfile);
    } else {
        std::cout << "Not an option\n";
    }
}

int main() {
    float money = 100.00;
    std::cout << "Day is 2013-02-08 \n Your Bank Account is at $" << money << "\n";

    std::vector<std::string> userProfile;
    std::vector<std::string> stockChoices = {"A"};

    std::string commandA;

    while (true) {
        commandA = getCommand();
        processCommand(commandA, money, userProfile, stockChoices);
    }
}
