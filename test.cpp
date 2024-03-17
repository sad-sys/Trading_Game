#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


int checkFile(const std::string&fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() 
{
    float money = 100.00;
    std::cout << "Day is 2013-02-08 \nYour Bank Account is at "<< money << "\n";

    std::string stock;
    std::cout << "Type a Stock      ";
    std::cin >> stock;
    std::string csvFile;
    csvFile = ".csv";

    stock = stock + csvFile;

    int answer = checkFile(stock);
    std::cout << answer << "\n" << std::endl;

    return 0;
}



/*
    std::string line;
    while (std::getline(file, line)) 
    {
        std::vector<std::string> row;
        std::stringstream ss(line);

        std::string value;
        while (std::getline(ss, value, ',')) 
        {
            row.push_back(value);
        }

        // Process the row
        for (const auto& field : row) 
        {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }

    file.close();

    */