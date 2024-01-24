#include <iostream>
using namespace std;

class Blob {

friend Blob operator+(Blob, Blob);
friend ostream& operator<<(ostream&, Blob);

public:

Blob(); // Default constructor
Blob (int, int);
Blob(int, int, int, int, char); // Constructor for the blob features
bool Move(char, Blob []);
Blob (char); // Constructor for blob color

void Attack(Blob&);
Blob Move (char, Blob&);

int GetXCoord();
void SetXCoord(int);

int GetYCoord();
void SetYCoord(int);

char GetColor();
void SetColor(char);

int GetHealth();
int GetPower();

private:

int Health; // int value that starts at 100. Once health of a blob reaches <= 0, blob is removed from board
int Power; // amount of damage a blob does when it attacks another blob. Should default to 10.
char Color; // char value determines what "team" blob is on. During any one game there should be two legal values for this variable. You can use the same two values for all games.
int XCoord; // int value expressing the blob's current x position
int YCoord; // int value expressing the blob's current y position

};