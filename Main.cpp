#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>
#include <algorithm>
#include <filesystem>

// Class to handle item tracking functionality
class ItemTracker {
private:
    // Map to store item frequencies
    std::map<std::string, int> itemFrequency;
    // Constants for input and output file names
    const std::string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
    const std::string OUTPUT_FILE = "frequency.dat";

    // Method to load data from input file
    void loadData() {
        std::ifstream inFile(INPUT_FILE);
        // Check if file opened successfully
        if (!inFile.is_open()) {
            std::cerr << "Error: Unable to open file " << INPUT_FILE << std::endl;
            return;
        }
        std::string item;
        int count = 0;
        // Read file line by line
        while (std::getline(inFile, item)) {
            // Remove any trailing whitespace
            item.erase(std::find_if(item.rbegin(), item.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), item.end());
            
            // Convert to lowercase for case-insensitive comparison
            std::transform(item.begin(), item.end(), item.begin(),
                [](unsigned char c){ return std::tolower(c); });
            
            // Increment item count in the map
            itemFrequency[item]++;
            count++;
        }
        inFile.close();
        // Debug output to verify file reading
        std::cout << "Debug: Read " << count << " items from file." << std::endl;
    }

    // Method to save data to output file
    void saveData() {
        std::ofstream outFile(OUTPUT_FILE);
        if (!outFile.is_open()) {
            std::cerr << "Error: Unable to open file " << OUTPUT_FILE << " for writing." << std::endl;
            return;
        }
        // Write each item and its frequency to the file
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        outFile.close();
        std::cout << "Data saved to " << OUTPUT_FILE << std::endl;
    }

public:
    // Constructor: loads data and saves it immediately
    ItemTracker() {
        loadData();
        saveData();
    }

    // Method to get frequency of a specific item
    int getItemFrequency(const std::string& item) {
        std::string lowercaseItem = item;
        std::transform(lowercaseItem.begin(), lowercaseItem.end(), lowercaseItem.begin(),
            [](unsigned char c){ return std::tolower(c); });
        auto it = itemFrequency.find(lowercaseItem);
        if (it != itemFrequency.end()) {
            return it->second;
        }
        return 0;  // Return 0 if item not found
    }

    // Method to print frequencies of all items
    void printAllFrequencies() {
        std::cout << "\n" << std::string(40, '-') << std::endl;
        std::cout << "Item Frequencies" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first 
                      << "| " << pair.second << std::endl;
        }
        std::cout << std::string(40, '-') << std::endl;
    }

    // Method to print histogram of item frequencies
    void printHistogram() {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "Item Frequency Histogram" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first << "| ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << " (" << pair.second << ")" << std::endl;
        }
        std::cout << std::string(50, '=') << std::endl;
    }

    // Debug method to print all items and their frequencies
    void debugPrintAllItems() {
        std::cout << "Debug: All items in tracker:" << std::endl;
        for (const auto& pair : itemFrequency) {
            std::cout << "'" << pair.first << "': " << pair.second << std::endl;
        }
    }
};

// Function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid menu choice from user
int getMenuChoice() {
    int choice;
    while (true) {
        std::cout << "Enter your choice (1-4): ";
        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            clearInputBuffer();
            return choice;
        }
        else {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            clearInputBuffer();
        }
    }
}

// Function to get valid item input from user
std::string getItemInput() {
    std::string item;
    while (true) {
        std::cout << "Enter item to look up: ";
        if (std::cin >> item) {
            // Convert input to lowercase for consistency
            std::transform(item.begin(), item.end(), item.begin(),
                [](unsigned char c){ return std::tolower(c); });
            return item;
        }
        else {
            std::cout << "Invalid input. Please try again." << std::endl;
            clearInputBuffer();
        }
    }
}

int main() {
    // Print current working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Create ItemTracker object
    ItemTracker tracker;
    
    // Debug: Print all items after loading
    tracker.debugPrintAllItems();
    
    int choice;
    std::string item;

    // Main program loop
    while (true) {
        // Display menu
        std::cout << "\n" << std::string(30, '*') << std::endl;
        std::cout << "   Corner Grocer Tracker" << std::endl;
        std::cout << std::string(30, '*') << std::endl;
        std::cout << "1. Look up an item" << std::endl;
        std::cout << "2. Print frequency of all items" << std::endl;
        std::cout << "3. Print histogram" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << std::string(30, '*') << std::endl;

        // Get user choice
        choice = getMenuChoice();

        // Process user choice
        switch (choice) {
            case 1:
                item = getItemInput();
                std::cout << item << " appears " 
                          << tracker.getItemFrequency(item) << " times." << std::endl;
                break;
            case 2:
                tracker.printAllFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Thank you for using Corner Grocer Tracker. Goodbye!" << std::endl;
                return 0;
        }
    }

    return 0;
}