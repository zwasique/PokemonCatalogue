//two pieces of code from Chat GPT showing how to use <filesystem>

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Assuming you are in "parent/src/mainProgram"
    fs::path parentPath = ".."; // Move up one level to "parent"
    fs::path extraFilesPath = parentPath / "extrafiles"; // Combine with "extrafiles"

    // Now you can construct the full path to a file in "parent/extrafiles/"
    fs::path filePathInExtraFiles = extraFilesPath / "example.txt";

    // Display the full path
    std::cout << "Full Path to File: " << filePathInExtraFiles << std::endl;

    // Check if the file exists
    if (fs::exists(filePathInExtraFiles)) {
        // File exists, you can proceed with further operations
        std::cout << "File exists!" << std::endl;
    } else {
        std::cerr << "File not found!" << std::endl;
    }

    return 0;
}


#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Assuming you are in "parent/src/mainProgram"
    fs::path parentPath = ".."; // Move up one level to "parent"
    fs::path filePathInParent = parentPath / "example.txt"; // Relative path within "parent"

    // Convert the path to a string for ifstream
    std::string filePathString = filePathInParent.string();

    // Open the file using std::ifstream
    std::ifstream fileStream(filePathString);

    // Check if the file is open
    if (fileStream.is_open()) {
        // File is open, you can read from it
        std::cout << "File opened successfully!" << std::endl;

        // Perform file operations here

        // Close the file when done
        fileStream.close();
    } else {
        std::cerr << "Failed to open file!" << std::endl;
    }

    return 0;
}

