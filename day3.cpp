#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include<list>

using namespace std;

bool SortPredicate_Descending (const int& lsh, const int& rsh)
{
    return (rsh < lsh);
}

int main()
{
    // Create a text string, which is used to output the text file
    string myText;
    string bagOne;
    string bagTwo;
    int stringLength = 0;
    int halfWay = 0;
    char c;
    int ascii = 0;

    int priority = 0;
    int duplicates = 0;

    // Read from the text file
    ifstream InputFile("day3 input.txt");

    if (InputFile.is_open()) 
    {
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (InputFile, myText)) 
        {
            // DEBUG - Output the text from the file
            //cout << myText;   

            // Split line into 2 equal halves
            stringLength = myText.length();
            halfWay = stringLength / 2;
            bagOne = myText.substr(0, halfWay);
            bagTwo = myText.substr(halfWay, stringLength - halfWay);

            // Debug line
            cout << endl << myText << " " << stringLength << " " << "Half = " << halfWay << " " << bagOne << " " << bagTwo << endl;

            // reset count
            duplicates = 0;

            for (int i = 0; i < bagOne.length(); i++)
            {
                c = bagOne[i];
                if (bagTwo.find (c) != string::npos)
                {
                    ascii = int(c);
                    if (ascii < 97) // Upper case
                    {
                        priority += ascii - 38;
                    }
                    else
                    {
                        priority += ascii - 96;
                    }
                    duplicates ++;
                    cout << endl << c << " " << ascii << endl;

                    bagTwo.erase(remove(bagTwo.begin(), bagTwo.end(), bagTwo.find (c)));
                }
            }
            cout << endl << "Duplicates = " << duplicates << endl;
        }
        // Close the file
        InputFile.close();

        cout << endl << "Priority = " << priority << endl;

        cout << endl << "Finished file" << endl;


    }
    
    return 0;
}


