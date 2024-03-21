import os

path1 = "/Users/sadiqkhawaja/Desktop/Brackets/C++ TradingGame/archive/individual_stocks_5yr/individual_stocks_5yr"

for filename in os.listdir(path1):
    if "data" in filename:
        # Split the filename at the first underscore
        parts = filename.split("data", 1)
        newName = parts[0] + parts[1]  # Rejoin the parts without the underscore

        # Print the new name for verification
        print(newName)

        # If you want to rename the file, uncomment the following line
        os.rename(os.path.join(path1, filename), os.path.join(path1, newName))
