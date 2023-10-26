import os
import shutil
import sys

def create_codeforces_directory(input_number):
    directory_name = f"codeforces_{input_number}"

    # Create the directory if it doesn't exist
    if not os.path.exists(directory_name):
        os.makedirs(directory_name)

    # Define the source file path (template.cpp)
    source_file_path = "competitive/template.cpp"

    # Generate the new .cpp files
    for i in range(5):
        new_file_name = f"{directory_name}/codeforces_{input_number}{chr(65 + i)}.cpp"
        shutil.copy(source_file_path, new_file_name)
        print(f"Created {new_file_name}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python create_codeforces_files.py <input_number>")
    else:
        input_number = sys.argv[1]
        create_codeforces_directory(input_number)
