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
    char playOne;
    char playTwo;
    int shapeScore = 0;
    int totalScore = 0;
    int roundScore = 0;

    // Read from the text file
    ifstream day2InputFile("day2 input.txt");

    if (day2InputFile.is_open()) 
    {
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (day2InputFile, myText)) 
        {
            // DEBUG - Output the text from the file
            //cout << myText;   

            //do  {
                // DEBUG - Output the text from the file
//                cout << myText << endl;

                playOne = myText.at(0);
                playTwo = myText.at(2);

                roundScore = 0;
                shapeScore = 0;

                // DEBUG
                //cout << "Player 1 = " << playOne << endl;
                //cout << "Player 2 = " << playTwo << endl;

                switch (playTwo)
                {
                    case 'X': // Rock
                        shapeScore += 1;
                        switch (playOne)
                        {
                            case 'A':
                                roundScore = shapeScore + 3;
                                break;
                            case 'B':
                                roundScore = shapeScore + 0;
                                break;
                            case 'C':
                                roundScore = shapeScore + 6;
                                break;
                            
                        } 
                        break;
                    case 'Y': // Paper
                        shapeScore += 2;
                        switch (playOne)
                        {
                            case 'A':
                                roundScore = shapeScore + 6;
                                break;
                            case 'B':
                                roundScore = shapeScore + 3;
                                break;
                            case 'C':
                                roundScore = shapeScore + 0;
                                break;
                            
                        }                         
                        break;
                    case 'Z':  // Scissors
                        shapeScore += 3;
                        switch (playOne)
                        {
                            case 'A':
                                roundScore = shapeScore + 0;
                                break;
                            case 'B':
                                roundScore = shapeScore + 6;
                                break;
                            case 'C':
                                roundScore = shapeScore + 3;
                                break;
                          
                        } 
                        break;

                }
                
                cout << endl << "Round " << playOne << " against " << playTwo << " = " << roundScore;

                totalScore += roundScore;

                //getline (day2InputFile, myText);
            //} while (!day2InputFile.eof() && !myText.empty());
        }
        // Close the file
        day2InputFile.close();

        cout << endl << "Finished file" << endl;

        cout << endl << "Total Score = " << totalScore << endl;

    }
    
    return 0;
}


