import os

path1 = "/Users/sadiqkhawaja/Desktop/individual_stocks_5yr"
nameList = []  # Initialize nameList outside the loop to avoid resetting it in each iteration

for filename in os.listdir(path1):
    print(filename)
    if ".csv" in filename:
        newName = filename.replace('.csv', '')  # Remove '.csv' from the filename
        # Print the new name for verification
        print(newName)
        nameList.append(newName)  # Append the new name to nameList

print(nameList)
