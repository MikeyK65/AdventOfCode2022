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
    
    int currentCalories = 0;
    list<int> currentCaloriesList;
    string temp;
    int totalCalories = 0;

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

            do
            {
                // DEBUG - Output the text from the file
                cout << myText << '/n';

                currentCalories += stoi (myText);

                getline (day1InputFile, myText);
            } while (!day1InputFile.eof() && !myText.empty());
            
            currentCaloriesList.push_back(currentCalories);

        }
        // Close the file
        day1InputFile.close();

        cout << "\nFinished file/n";

        currentCaloriesList.sort(SortPredicate_Descending);

        //DEBUG
        cout << endl << currentCaloriesList.front();
        cout << endl << currentCaloriesList.back();

        totalCalories = currentCaloriesList.front();
        currentCaloriesList.pop_front();
        totalCalories += currentCaloriesList.front();
        currentCaloriesList.pop_front();
        totalCalories += currentCaloriesList.front();

        cout << endl << "Total calories of top 3 = " << totalCalories;

    }
    
    return 0;
}


