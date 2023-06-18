#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Create a text string, which is used to output the text file
    string myText;
    int maxCalories = 0;
    int currentCalories = 0;
    string temp;

    // Read from the text file
    ifstream day1InputFile("day1 input.txt");

    if (day1InputFile.is_open()) 
    {
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (day1InputFile, myText)) 
        {
            // Reset current counter
            currentCalories = 0;

            // DEBUG - Output the text from the file
            cout << myText;
            //cin >> temp;

            do
            {
                // DEBUG - Output the text from the file
                cout << myText << '/n';

                currentCalories += stoi (myText);

                getline (day1InputFile, myText);
            } while (!day1InputFile.eof() && !myText.empty());
            

            if (currentCalories > maxCalories)
            {
                maxCalories = currentCalories;
            }

        }

        // Close the file
        day1InputFile.close();

        cout << "Biggest calories = " << maxCalories;
    }

    cin >> temp;
    return 0;
}

