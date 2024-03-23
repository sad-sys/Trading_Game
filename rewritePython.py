import csv
import os
from typing import List, Union

# Define the filesystem namespace for compatibility with the original C++ code
fs = os


def contains(arr: List[str], element: str) -> bool:
    return element in arr


def split_csv_line(line: str) -> List[str]:
    return line.strip().split(',')


def get_stock_val(stock_choice: str, date_number: int) -> float:
    file_path = f"/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr/{stock_choice}.csv"
    
    with open(file_path, 'r') as file:
        for _ in range(date_number):
            next(file)
        line = next(file)

    parts = split_csv_line(line)
    print(f"The price is : {parts[1]}")
    stock_val = float(parts[1])
    return stock_val


def find_profile_val(user_profile: List[str], date_number: int) -> float:
    total = 0
    for stock in user_profile:
        stock_val = get_stock_val(stock, date_number)
        total += stock_val
    return total


def sell(money: Union[int, float], user_profile: List[str], stock_choices: List[str], date_number: int):
    if not user_profile:
        print("You don't own any stocks to sell.")
        return

    stock_choice = input("Which stock would you like to sell?\n")

    if stock_choice in user_profile:
        stock_val = get_stock_val(stock_choice, date_number)
        money += stock_val
        user_profile.remove(stock_choice)
        print(f"Sold {stock_choice} for ${stock_val}. Your balance is now ${money}.")
    else:
        print(f"You do not own {stock_choice} stock.")


def command() -> str:
    command_action = input("Type a command, buy, sell, check, next and profile\n")
    return command_action


def buy(money: Union[int, float], user_profile: List[str], stock_choices: List[str], date_number: int):
    stock_choice = input("Which stock would you like to buy?\n")
    if stock_choice in stock_choices:
        stock_val = get_stock_val(stock_choice, date_number)
        money -= stock_val
        print(f"${money}")
        user_profile.append(stock_choice)
    else:
        print("Not a stock option!")


def next_day(date_number: int, stock_choice: str):
    file_path = f"/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr/{stock_choice}.csv"

    with open(file_path, 'r') as file:
        for _ in range(date_number):
            next(file)
        line = next(file)

    parts = split_csv_line(line)
    print(f"The Date Now is : {parts[0]}")


def check(date_number: int, money: Union[int, float], user_profile: List[str]):
    # This function was empty in the original C++ code
    pass


def main():
    money = 1000.00
    date = "2013-02-08"
    date_number = 1
    print(f"Day is {date}\nYour Bank Account is at ${money}")

    user_profile = []
    user_profile_val = []

    stock_choices = [
        "A", "AAL", "AAP", "AAPL", "ABBV", "ABC", "ABT", "ACN", "ADBE", "ADI", "ADM", "ADP", "ADS", "ADSK", "AEE", "AEP",
        "AES", "AET", "AFL", "AGN", "AIG", "AIV", "AIZ", "AJG", "AKAM", "ALB", "ALGN", "ALK", "ALL", "ALLE", "ALXN", "AMAT",
        "AMD", "AME", "AMG", "AMGN", "AMP", "AMT", "AMZN", "ANDV", "ANSS", "ANTM", "AON", "AOS", "APA", "APC", "APD", "APH",
        "MHK", "MKC", "MLM", "MMC", "MMM", "MNST", "MO", "MON", "MOS", "MPC", "MRK", "MRO", "MS", "MSFT", "MSI", "MTB", "MTD",
        "MU", "UNH", "UNM", "UNP", "UPS", "URI", "USB", "UTX", "V", "VAR", "VFC", "VIAB", "VLO", "VMC", "VNO", "VRSK", "VRSN",
        "VRTX", "VTR", "VZ", "WAT", "WBA", "WDC", "WEC", "WFC", "WHR", "WLTW", "WM", "WMB", "WMT", "WRK", "WU", "WY", "WYN",
        "WYNN", "XEC", "XEL", "XL", "XLNX", "XOM", "XRAY", "XRX", "XYL", "YUM", "ZBH", "ZION", "ZTS"
    ]

    while True:
        command_a = command()
        if command_a == "check":
            profile_val = find_profile_val(user_profile, date_number)
            print(f"${money} left\nProfile Value: ${profile_val}\nTotal: ${profile_val + money}")
        elif command_a == "next":
            date_number += 1
            profile_val = find_profile_val(user_profile, date_number)
            user_profile_val.append(profile_val + money)
            next_day(date_number, "A")
        elif command_a == "buy":
            buy(money, user_profile, stock_choices, date_number)
        elif command_a == "sell":
            sell(money, user_profile, stock_choices, date_number)
        elif command_a == "profile":
            print("Profile: ", " | ".join(user_profile))
            profile_val = find_profile_val(user_profile, date_number)
            print(f"Profile Value: ${profile_val}")
        else:
            print("Not an option")

main()