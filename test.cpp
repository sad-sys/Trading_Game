#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::__fs::filesystem;


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
    std::string fileName = "/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr/" + stockChoice + ".csv";
    
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

void plotProfile(const std::vector<float>& userProfileVals) 
{
    if (userProfileVals.empty()) 
    {
        std::cout << "The vector is empty." << std::endl;
        return;
    }

    int maxVal = *max_element(userProfileVals.begin(), userProfileVals.end());
    int minVal = *min_element(userProfileVals.begin(), userProfileVals.end());
    int height = maxVal - minVal + 1;
    int width = userProfileVals.size();

    // Create and initialize the graph with spaces
    std::vector<std::vector<char>> graph(height, std::vector<char>(width, ' '));

    // Plot the points
    for (int i = 0; i < width; ++i) 
    {
        int value = userProfileVals[i] - minVal;
        graph[height - value - 1][i] = 'x';
    }

    // Print the graph
    for (int i = 0; i < height; ++i) 
    {
        std::cout << maxVal - i << "- ";
        for (int j = 0; j < width; ++j) 
        {
            std::cout << graph[i][j];
            if (j < width - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    // Print the x-axis labels
    std::cout << "   ";
    for (int i = 0; i < width; ++i) 
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
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


void next(int dateNumber, std::string stockChoice)
{
    std::string fileName = "/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr/" + stockChoice + ".csv";
    
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
    float money = 1000.00;
    std::string date = "2013-02-08";
    int dateNumber = 1;
    std::cout << "Day is  " << date << "\n Your Bank Account is at $"<< money << "\n";
    
    static int currentLineNumber = 0;
    std::vector<std::string> userProfile;
    std::vector<float> userProfileVal;

    std::vector<std::string> stockChoices = {"A", "AAL", "AAP", "AAPL", "ABBV", "ABC", "ABT", "ACN", "ADBE", "ADI", "ADM", "ADP", "ADS", "ADSK", "AEE", "AEP", 
                                            "AES", "AET", "AFL", "AGN", "AIG", "AIV", "AIZ", "AJG", "AKAM", "ALB", "ALGN", "ALK", "ALL", "ALLE", "ALXN", "AMAT", 
                                            "AMD", "AME", "AMG", "AMGN", "AMP", "AMT", "AMZN", "ANDV", "ANSS", "ANTM", "AON", "AOS", "APA", "APC", "APD", "APH", 
                                             "MHK", "MKC", "MLM", "MMC", "MMM", "MNST", "MO", "MON", "MOS", "MPC", "MRK", "MRO", "MS", "MSFT", "MSI", "MTB", "MTD", "MU", "A", 
                                               "UNH", "UNM", "UNP", "UPS", "URI", "USB", "UTX", "V", "VAR", "VFC", "VIAB", "VLO", "VMC", "VNO", "VRSK", "VRSN", "VRTX", "VTR", "VZ", 
                                               "WAT", "WBA", "WDC", "WEC", "WFC", "WHR", "WLTW", "WM", "WMB", "WMT", "WRK", "WU", "WY", "WYN", "WYNN", "XEC", "XEL", "XL", "XLNX", 
                                               "XOM", "XRAY", "XRX", "XYL", "YUM", "ZBH", "ZION", "ZTS"};

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
            float profileVal = findProfileVal(userProfile, dateNumber);
            userProfileVal.push_back(profileVal + money);
            next(dateNumber,"A");
        }
        else if (commandA == "buy")
        {
            buy(money, userProfile, stockChoices, dateNumber);
        }
        else if (commandA == "sell")
        {
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
            plotProfile(userProfileVal);
        }
        else
        {
            std::cout << "Not an option\n";
        }
    }
}