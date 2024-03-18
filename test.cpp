#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



bool contains(const std::vector<std::string>& arr, const std::string& element)
{
    for (const auto& item : arr)
    {
        if (item == element)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> splitCSVLine(const std::string &line)
{
    std::vector<std::string>parts;
    std::stringstream lineStream(line);

    std::string part;
    while (getline(lineStream, part, ','))
    {
        parts.push_back(part);
    }
    return parts;
}


std::string command()
{
    std:: string commandAction;
    std::cout << "Type a command, buy, sell, check, next and profile  \n" << std::endl;
    std::cin >> commandAction;
    return commandAction;
}

float getStockVal(const std::string& stockChoice, std::vector<std::string>& userProfile)
{
    std::string fileName;
    fileName = stockChoice + ".csv";
    
    std::string line; 
    std::fstream file(fileName);
    std::getline(file, line);
    std::getline(file, line);

    std::vector<std::string>parts;
    parts = splitCSVLine(line);
    std::cout << "The first price is : " << parts[1] << std::endl;

    float stockVal = std::stof(parts[1]);

    return stockVal;
}

void buy(float& money, std::vector<std::string>& userProfile, const std::vector<std::string>& stockChoices)
{
            std::string stockChoice;
            std::cout << "`Which stock would you like to buy?\n";
            std::cin >> stockChoice;
            if (contains(stockChoices,stockChoice))
            {
                float stockVal;
                stockVal = getStockVal(stockChoice,userProfile);
                money = money - stockVal;
                std::cout << "$" << money << "\n";
                userProfile.push_back(stockChoice);
            }
            else
            {
                std::cout << "Not a stock option! ";
            }
}

int main() 
{
    float money = 100.00;
    std::cout << "Day is 2013-02-08 \n Your Bank Account is at $"<< money << "\n";

    std::vector<std::string> userProfile;
    std::vector<std::string> stockChoices = {"A"};
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
            buy(money, userProfile, stockChoices);
        }
        else if (commandA == "sell")
        {
            std::cout << "sell!\n";
        }
        else if (commandA == "profile")
        {
                std::cout << "Profile: ";
                for(const std::string& element : userProfile) 
                {
                    std::cout << element << " | ";
                }
                std::cout << "\n";
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
