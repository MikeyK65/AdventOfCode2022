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
                    case 'X': // Need to lose
                        
                        switch (playOne)
                        {
                            case 'A':  // They close rock so I pick scissors
                                shapeScore += 3; 
                                break;
                            case 'B':   // They chose paper so i pick Rock
                                shapeScore += 1; 
                                break;
                            case 'C':   // They chose scissors so I pick paper
                                shapeScore += 2; 

                                break;
                            
                        } 
                        roundScore = shapeScore + 0;

                        break;
                    case 'Y': // Now means need to draw
                        //shapeScore += 2;
                        switch (playOne)
                        {
                            case 'A':
                                shapeScore += 1;
                                break;
                            case 'B': // Paper
                                shapeScore += 2;
                                break;
                            case 'C':
                                shapeScore += 3;
                                break;
                            
                        }  
                        roundScore = shapeScore + 3;
                       
                        break;
                    case 'Z':  // Now need to win
                        
                        switch (playOne)
                        {
                            case 'A':   // They chose rock so I pick paper
                                shapeScore += 2;
                                
                                break;
                            case 'B':   // They chose paper so I pick scissors
                                shapeScore += 3;
                                break;
                            case 'C':   // They chose scissors so Pick Rock
                                shapeScore += 1;
                                break;
                          
                        } 
                        roundScore = shapeScore + 6;
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


