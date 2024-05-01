/*
Subject: DSA Laboratory
Practical No: 11
Title: A C++ Program to i a Sequential Access file to maintain the data.
 Write data to file.
 Read data from file Sequentially.
*/

#include <iostream>
#include <fstream> // Include the necessary header for file handling

using namespace std;

int main() {
    // Open the file for writing (create if not exists)
    ofstream fout("example.txt");

    // Check if the file is successfully opened
    if (!fout.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // Write data to the file
    fout<< "Hello, this is some data written to the file." << endl;
    fout<< "You can add more lines here." << endl;

    // Close the file
    fout.close();

    // Open the file for reading
    ifstream fin("example.txt");

    // Check if the file is successfully opened
    if (!fin.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;
    cout << "File Content:" << endl;

    // Read each line from the file and print it
    while (getline(fin, line)) {
        cout << line << endl;
    }

    // Close the file
   fin.close();

    return 0;
}



