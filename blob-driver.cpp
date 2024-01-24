#include "blob.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Initialize an array of type Blob
    Blob pieces[8];

    // Seeding the random number generator 
    srand(time(0));

    // For each of the positions within the Blob array
    for(int i = 0; i < 8; i++)
    {
        // Assume there is no matching coordinates
        int match = 0;
        do
        {
            // Generate a new XCoord and YCoord
            int XCoord = rand() % 10;
            int YCoord = rand() % 10;

            // For each of the previous Blobs
            for(int j = 0; j < i; j++)
            {
                // Check to see if that Blob has the same X and Y Coords we just generated
                if(XCoord == pieces[j].GetXCoord() && YCoord == pieces[j].GetYCoord())
                {
                    // If they do, then set the flag to match and stop searching for a match (you found it!)
                    match = 1;
                    break;
                }
            }

            // Check to see if you found a match
            if (match == 0)
            {
                // If you didn't, then create a new Blob with those coordinates and put it into the array
                pieces[i] = Blob(XCoord, YCoord);
            }

        }while (match == 1); // Post check because you always want to go through to check for a match once
    }
    
    int playerTurn = 0;
   
    while((pieces[0].GetHealth() > 0 && pieces[1].GetHealth() > 0 && pieces[2].GetHealth() > 0 && pieces[3].GetHealth() > 0) || 
    (pieces[4].GetHealth() > 0 && pieces[5].GetHealth() > 0 && pieces[6].GetHealth() > 0 && pieces[7].GetHealth() > 0))
    {   
        // Print resulting coordinates - place 4 Blobs at random positions within a 10x10 square grid
        cout << '\n' << "IT IS PLAYER "<< playerTurn + 1 << "'S TURN" << endl;
        cout << "Positions of Blobs: " << endl;
        cout << "NOTE: Blobs 0 - 3 are Player 1 and Blobs 4 - 7 are Player 2." << '\n' << endl;

        for(int i = 0; i < 8; i++)
        {
            if(pieces[i].GetHealth() > 0)
                cout << i << '\n' << pieces[i];
                //cout << "\t[" << i << "]: (" << pieces[i].GetXCoord() << ", " << pieces[i].GetYCoord() << ")" << endl;
        }

        cout << '\n' << "Which blob would you like to use for your turn?" << endl;
        int blobChoice;
        cin >> blobChoice;
        
        while(playerTurn == 0 && (blobChoice > 3 || blobChoice < 0))
        {
            cout << "Invalid choice - not your Blob. Please try again." << endl;
            cin >> blobChoice;
        }

        while(playerTurn == 1 && (blobChoice < 4))
        {
            cout << "Invalid choice - not your Blob. Please try again." << endl;
            cin >> blobChoice;
        }
        
        cout << "Would you like to move (M) that blob or attack (A) with that blob?" << endl;
        
        char actionChoice;
        cin >> actionChoice;
        
        while(actionChoice != 'm' && actionChoice != 'M' && actionChoice != 'a' && actionChoice != 'A')
        {
            cout << "Invalid action choice. Please try again." << endl;
            cin >> actionChoice;
        }
        
        // If choose move...
        if(actionChoice == 'm' || actionChoice == 'M')
        {
            char direction;
            cout << "Please enter a cardinal direction (N, E, S, W) in which you would like to move your blob." << endl;
            cin >> direction;
            
            // Do I need to re-print out my points?
            //bool merge = false;

            while(pieces[blobChoice].Move(direction, pieces) == false)
            {
                cout << "Please choose another direction: ";
                cin >> direction;
            }

            cout << "(" << pieces[blobChoice].GetXCoord() << ", " << pieces[blobChoice].GetYCoord() << ")" << endl; // add the parentheses for the coordinates
            cout << "Health: " << pieces[blobChoice].GetHealth() << " Power: " << pieces[blobChoice].GetPower() << endl;

        }

        // If choose attack...
        else if(actionChoice == 'a' || actionChoice == 'A')
        {            
            int target;

            cout << "Which blob would you like to attack? NOTE: Player 1 must choose 4-7 and Player 2 must choose 0-3" << endl;
            cin >> target;
            pieces[blobChoice].Attack(pieces[target]);
        }

    playerTurn = (playerTurn + 1) % 2;

    }

};