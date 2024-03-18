# Trading_Game
Stock Trading Simulator
This Stock Trading Simulator is a console-based application designed to provide a simple and interactive experience of trading stocks without using real money. It is built using C++ and is aimed at demonstrating basic programming concepts, file I/O operations, and handling user input/output. Ideal for beginners and those interested in learning the basics of stock trading simulations.

Features
Stock Trading: Users can buy stocks based on their current budget. The stock prices are read from CSV files corresponding to each stock.
Portfolio Management: Users can view their current portfolio, including the stocks they own and the total value of their holdings.
Market Simulation: Navigate through different dates to simulate the passing of time in the market. The stock prices change according to the data in the CSV files for each date.
Budget Tracking: Users start with a predefined budget and can track their remaining money as they buy stocks.
How to Use
Starting the Program: Run the program in a C++ compatible IDE or compile and run it from the command line using a C++ compiler.

Main Commands:

buy: Purchase a stock. You will be prompted to enter the name of the stock you wish to buy.
next: Move to the next date in the simulation. This will update the stock prices according to the CSV data.
profile: View your current portfolio, including the stocks you own and their current values.
check: Display your current budget, the total value of your portfolio, and the overall total value.
Stock Data: Ensure the CSV files for the stocks are present in the same directory as the program. The CSV files should be named according to the stock (e.g., A.csv) and contain date and price information.

Project Structure
main.cpp: Contains the main logic for the stock trading simulator, including user input handling, stock trading, and portfolio management functionalities.
Enhancements and Contributions
This project is open for enhancements, and contributions are welcome. Potential areas for improvement include:

Implementing error handling for file operations and user inputs.
Adding functionality to sell stocks.
Enhancing the user interface for a better experience.
Introducing more complex market simulation features, such as price fluctuations and different stock options.
License
This project is licensed under MIT License.R