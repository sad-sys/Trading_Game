import os

def find_csv_filenames(path, suffix=".csv"):
    filenames = []
    if os.path.exists(path):
        for root, dirs, files in os.walk(path):
            for file in files:
                if file.endswith(suffix):
                    filenames.append(file)
    else:
        print("The specified path does not exist.")
    return filenames

def extract_stock_names(filenames):
    stock_names = [filename.split('.')[0] for filename in filenames]
    return sorted(stock_names)

path = "/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr"
csv_filenames = find_csv_filenames(path)
stock_names = extract_stock_names(csv_filenames)

# Convert list to string and replace single quotes with double quotes
stock_names_str = str(stock_names).replace("'", '"')
print(stock_names_str)
