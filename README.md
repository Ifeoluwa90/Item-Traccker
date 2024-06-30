# Corner Grocer Item Tracker

## Overview
The Corner Grocer Item Tracker is a C++ application designed to analyze sales data for a grocery store. It helps optimize product placement by tracking and reporting item purchase frequencies.

## Features
- Read sales data from a text file
- Look up frequency of individual items
- Display a list of all items and their purchase frequencies
- Generate a text-based histogram of item frequencies
- Save processed data to a file for future reference

## Requirements
- C++17 compatible compiler
- Input file named "CS210_Project_Three_Input_File.txt" in the same directory as the executable

## Installation
1. Clone this repository
2. Compile the source code:

## Usage
1. Ensure "CS210_Project_Three_Input_File.txt" is in the same directory as the executable
2. Run the compiled program:

3. Follow the on-screen menu to interact with the program

## Menu Options
1. Look up an item's frequency
2. Print all item frequencies
3. Print a histogram of item frequencies
4. Exit the program

## Output
The program generates a "frequency.dat" file containing all items and their frequencies.



## Project Reflection

This project was completed as part of my coursework, demonstrating my skills in C++ programming and software design. Below are my reflections on the project:

### Project Summary and Problem Solved
The Corner Grocer Item Tracker was developed to solve the problem of optimizing product placement in a grocery store. By analyzing sales data from daily text records, the program helps store managers understand which items are purchased most frequently, enabling them to make informed decisions about store layout and inventory management. This tool addresses the need for data-driven decision-making in retail operations, potentially increasing sales and improving customer experience.

### Strengths of the Implementation
In this project, I particularly excelled at implementing efficient data structures and algorithms. The use of std::map for storing item frequencies allowed for quick lookups and easy updates, which is crucial for processing large datasets. Additionally, the modular design of the ItemTracker class encapsulates the core functionality, making the code organized and easily maintainable. The implementation of a user-friendly menu interface also stands out, providing clear options and easy navigation for users who may not be technically inclined.

### Areas for Enhancement
The code could be enhanced by implementing more robust error handling, particularly for file I/O operations. While the current implementation does check for file opening errors, it could benefit from more detailed error messages and recovery strategies. Another area for improvement would be the addition of data visualization features, such as generating graphical histograms instead of text-based ones. This would provide a more intuitive representation of the data. Additionally, implementing multi-threading for file reading and data processing could significantly improve performance for larger datasets.

### Challenging Aspects
The most challenging part of this project was ensuring case-insensitive item handling while maintaining data integrity. To overcome this, I implemented a lowercase conversion for all items during both input processing and user queries. This required careful consideration of string manipulation in C++ and led me to explore the std::transform function with lambda expressions. I found cppreference.com and Stack Overflow to be invaluable resources for understanding the nuances of string handling and lambda functions in C++.

### Transferable Skills
Key skills from this project that will be transferable include data structure selection and implementation, file I/O handling, and user input validation. The experience of designing a class to encapsulate related functionality (ItemTracker) is directly applicable to object-oriented design in any language. Additionally, the practice of writing clear, well-commented code and creating a user-friendly interface are universal skills in software development.

### Maintainability and Readability
To ensure the program is maintainable, readable, and adaptable, I employed several strategies. First, I used meaningful variable and function names that clearly indicate their purpose. The code is organized into logical sections with comments explaining the purpose and functionality of each major component. The ItemTracker class is designed with clear public and private sections, adhering to encapsulation principles. This modular design allows for easy updates or extensions to the functionality. Furthermore, the use of constants for file names makes it simple to adapt the program to different input sources. The consistent use of C++ best practices, such as using references to avoid unnecessary copying and const correctness, contributes to the overall quality and maintainability of the code.

This reflection demonstrates my ability to not only write functional code but also to critically analyze my work, identify areas for improvement, and understand the broader applications of my programming skills in C++ and software development in general.



## Contributing
Contributions, issues, and feature requests are welcome. Feel free to contact me via linkedin @ https://www.linkedin.com/in/ifeoluwaadewoyin/ if you want to contribute.

## License
N/A

## Author
Ifeoluwa Adewoyin

## Acknowledgments
Southern New Hampshire University

Professor Hecker
