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

float getStockVal(const std::string& stockChoice, int dateNumber)
{
    std::string fileName = stockChoice + ".csv";
    
    std::string line; 
    std::fstream file(fileName);

    for (int lineNumber = 0; lineNumber<=dateNumber; ++lineNumber)
    {
        std::getline(file, line);
    }

    std::vector<std::string> parts = splitCSVLine(line);
    std::cout << "The price is : " << parts[1] << std::endl;

    float stockVal = std::stof(parts[1]);

    return stockVal;
}

void sell(float& money, std::vector<std::string>& userProfile, const std::vector<std::string>& stockChoices, int dateNumber)
{
    if (userProfile.empty())
    {
        std::cout << "You don't own any stocks to sell.\n";
        return;
    }

    std::string stockChoice;
    std::cout << "Which stock would you like to sell?\n";
    std::cin >> stockChoice;

    // Check if the user owns the stock
    auto it = std::find(userProfile.begin(), userProfile.end(), stockChoice);
    if (it != userProfile.end())
    {
        // User owns the stock, proceed with selling
        float stockVal = getStockVal(stockChoice, dateNumber);
        money += stockVal; // Increase user's money by the stock value
        userProfile.erase(it); // Remove the stock from the user's profile
        std::cout << "Sold " << stockChoice << " for $" << stockVal << ". Your balance is now $" << money << ".\n";
    }
    else
    {
        std::cout << "You do not own " << stockChoice << " stock.\n";
    }
}


std::string command()
{
    std:: string commandAction;
    std::cout << "Type a command, buy, sell, check, next and profile  \n" << std::endl;
    std::cin >> commandAction;
    return commandAction;
}

void buy(float& money, std::vector<std::string>& userProfile, const std::vector<std::string>& stockChoices, int dateNumber)
{
    std::string stockChoice;
    std::cout << "Which stock would you like to buy?\n";
    std::cin >> stockChoice;
    if (contains(stockChoices,stockChoice))
    {
        float stockVal = getStockVal(stockChoice, dateNumber);
        money = money - stockVal;
        std::cout << "$" << money << "\n";
        userProfile.push_back(stockChoice);
    }
    else
    {
        std::cout << "Not a stock option! ";
    }
}

float findProfileVal(std::vector<std::string> userProfile, int dateNumber)
{
    float initial = 0;
    for (int eachStock=0; eachStock < userProfile.size(); ++eachStock)
    {
        float stockVal = getStockVal(userProfile[eachStock], dateNumber);
        initial = initial + stockVal;
    }
    return initial;
}

void next(int dateNumber, std::string stockChoice)
{
    std::string fileName = stockChoice + ".csv";
    
    std::string line; 
    std::fstream file(fileName);

    for (int lineNumber = 0; lineNumber<=dateNumber; ++lineNumber)
    {
        std::getline(file, line);
    }
    
    std::vector<std::string> parts = splitCSVLine(line);
    std::cout << "The Date Now is : " << parts[0] << std::endl;
}
void check(int dateNumber, int money, std::vector<int>&userProfile)
{

}
int main() 
{
    float money = 100.00;
    std::string date = "2013-02-08";
    int dateNumber = 1;
    std::cout << "Day is  " << date << "\n Your Bank Account is at $"<< money << "\n";
    
    static int currentLineNumber = 0;
    std::vector<std::string> userProfile;
    std::vector<std::string> stockChoices = {"A"};

    while (true)
    {
        std::string commandA  = command();
        if (commandA == "check")
        {
            float profileVal = findProfileVal(userProfile, dateNumber);
            std::cout <<"$"<<money<<" left \n";
            std::cout <<"Profile Value: $"<< profileVal <<"\n";
            std::cout <<"Total : $"<< profileVal + money <<"\n";
        }
        else if (commandA == "next")
        {
            dateNumber = dateNumber + 1;
            next(dateNumber,"A");
        }
        else if (commandA == "buy")
        {
            buy(money, userProfile, stockChoices, dateNumber);
        }
        else if (commandA == "sell")
        {
            std::cout << "sell!\n";
            sell(money, userProfile, stockChoices, dateNumber);
        }
        else if (commandA == "profile")
        {
                std::cout << "Profile: ";
                for(const std::string& element : userProfile) 
                {
                    std::cout << element << " | ";
                }
                std::cout << "\n";
                float profileVal = findProfileVal(userProfile, dateNumber);
                std::cout <<"Profile Value: $"<< profileVal <<"\n";
        }
        else
        {
            std::cout << "Not an option\n";
        }
    }
}