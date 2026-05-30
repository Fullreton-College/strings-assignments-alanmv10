#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void parseCSV(const string& filename)
{
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cout << "Error: Could not open file \"" << filename << "\"" << endl;
        return;
    }

    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string field;

        while (getline(ss, field, ','))
        {
            int colonPos = field.find(':');
            string key   = field.substr(0, colonPos);
            string value = field.substr(colonPos + 1);

            cout << key << ": " << value << endl;
        }

        cout << endl;  
    }

    inputFile.close();
}

int main()
{
    parseCSV("students.csv");
    return 0;
}