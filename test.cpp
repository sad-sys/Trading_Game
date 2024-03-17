#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool contains(const std::string arr[], int size, const std::string& element)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }
    return false;
}

std::string command()
{
    std:: string commandAction;
    std::cout << "Type a command, buy, sell, check, next and profile  \n" << std::endl;
    std::cin >> commandAction;
    return commandAction;
}

bool checkFile(const std::string&fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main() 
{
    float money = 100.00;
    std::cout << "Day is 2013-02-08 \nYour Bank Account is at $"<< money << "\n";

    std::vector<std::string> userProfile;
    std::string stockChoices[1];
    stockChoices[0] = "A";

    std::string commandA;

    while (true)
    {
        commandA  = command();
        if (commandA == "check")
        {
            std::cout <<"$"<<money<<"\n";
        }
        else if (commandA == "next")
        {
            std::cout << "next!\n";
        }
        else if (commandA == "buy")
        {
            std::string stockChoice;
            std::cout << "Which stock would you like to buy?\n";
            std::cin >> stockChoice;
            if (contains(stockChoices, 1, stockChoice))
            {
                money = money - 10;
                std::cout << money << "\n";
            }
        }
        else if (commandA == "sell")
        {
            std::cout << "sell!\n";
        }
        else if (commandA == "profile")
        {
            std::cout << "profile\n";
        }
        else
        {
            std::cout << "Not an option\n";
        }
    }



}

/*
    std::string stock;
    std::string csvFile;
    stock = "A";
    csvFile = ".csv";

    stock = stock + csvFile;

    int answer = checkFile(stock);
    std::cout << answer << "\n" << std::endl;
*/
