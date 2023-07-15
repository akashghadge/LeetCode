import os

# Get the current directory
directory = os.getcwd()

# Iterate over all files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".txt"):
        # Rename the file by replacing the .txt extension with .cpp
        new_filename = os.path.join(directory, filename.replace(".txt", ".cpp"))

        # Rename the file
        os.rename(os.path.join(directory, filename), new_filename)
        print(f"Renamed {filename} to {new_filename}")
