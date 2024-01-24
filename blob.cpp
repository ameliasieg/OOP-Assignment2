#include "blob.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

Blob::Blob() // Default constructor
{
    Health = 100;
    Power = 10;
    XCoord = YCoord = 0;
    Color = '0'; // Color is not set to anything yet
}

Blob::Blob(int _XCoord, int _YCoord)
{
    Health = 100;
    Power = 10;
    XCoord = _XCoord;
    YCoord = _YCoord;
    Color = '0';
}

Blob::Blob(int _XCoord, int _YCoord, int _Health, int _Power, char _Color)
{
    XCoord = _XCoord;
    YCoord = _YCoord;
    Color = _Color;
    Health = _Health;
    Power = _Power;
}

ostream& operator<<(ostream& o, Blob b)
{
    o << "Position: (" << b.GetXCoord() << ", " << b.GetYCoord() << ")" << endl;
    o << "Health: " << b.Health << endl;
    o << "Power: " << b.Power << endl;
    return o;
}

bool Blob::Move(char D, Blob arr[]) // D for Direction
{
    if(D != 'n' && D != 'N' && D != 'e' && D != 'E' && D != 's' && D != 'S' && D != 'w' && D != 'W')
    {
        return false;
    }

    if(D == 'n' || D == 'N')
    {
        // Move North (UP)
        for (int i = 0; i < 8; i++)
        {
            if(XCoord == arr[i].XCoord && YCoord + 1 == arr[i].YCoord) //finds a blob that is one above calling object
            {
                if(Color == arr[i].Color) //if that blob is on the same team
                {
                    *this = *this + arr[i];
                    arr[i].Health = 0;
                    return true;
                }
                return false;
            }
        }
        YCoord++;
        return true;
    }

    else if(D == 'e' || D == 'E')
    {
        // Move East (RIGHT)
        for (int i = 0; i < 8; i++)
        {
            if(YCoord == arr[i].YCoord && XCoord + 1 == arr[i].XCoord)
            {
                if(Color == arr[i].Color) //if that blob is on the same team
                {
                    *this = *this + arr[i];
                    arr[i].Health = 0;
                    return true;
                }
                return false;
            }
        }
        XCoord++;
        return true;
    }

    else if(D == 's' || D == 'S')
    {
        // Move South (DOWN)
        for (int i = 0; i < 8; i++)
        {
            if(XCoord == arr[i].XCoord && YCoord - 1 == arr[i].YCoord)
            {
                if(Color == arr[i].Color) //if that blob is on the same team
                {
                    *this = *this + arr[i];
                    arr[i].Health = 0;
                    return true;
                }
                return false;
            }
        }
        YCoord--;
        return true;
    }

    else if(D == 'w' || D == 'W')
    {
        // Move West (LEFT)
        for (int i = 0; i < 8; i++)
        {
            if(YCoord == arr[i].YCoord && XCoord - 1 == arr[i].XCoord)
            {
                if(Color == arr[i].Color) //if that blob is on the same team
                {
                    *this = *this + arr[i];
                    arr[i].Health = 0;
                    return true;
                }
                return false;
            }
        }
        XCoord--;
        return true;
    }
}

Blob::Blob(char C)
{
    Color = C;
    Health = 100;
    Power = 10;
}

Blob operator+(Blob lhs, Blob rhs)
{
    int maxPower = lhs.Power;
    if(rhs.Power > maxPower)
    {
        maxPower = rhs.Power;
    }

    return Blob(rhs.GetXCoord(), rhs.GetYCoord(), lhs.Health + rhs.Health, maxPower + 2, rhs.Color);
}

void Blob::Attack(Blob& target)
{
    target.Health -= Power;

    if(target.Health <= 0)
    {
        Color = 'X';
    }
}

// Getters and Setters for X and Y
int Blob::GetXCoord()
{
    return XCoord;
}

void Blob::SetXCoord(int x)
{
    XCoord = x;
}

int Blob::GetYCoord()
{
    return YCoord;
}

void Blob::SetYCoord(int y)
{
    YCoord = y;
}

int Blob::GetHealth()
{
    return Health;
}

int Blob::GetPower()
{
    return Power;
}