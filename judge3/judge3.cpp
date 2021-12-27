#include<iostream>

using namespace std;

int match(int balls[6], int winballs[7])
{
    int score = 0, sp = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (winballs[i] == balls[j]) {
                score++;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        if (balls[i] == winballs[6]) {
            sp = 1;
        }
    }
    switch (score)
    {
    case 6:
        return 1;
    case 5:
        if (sp == 1) {
            return 2;
        }
        else
            return 3;
    case 4:
        if (sp == 1) {
            return 4;
        }
        else
            return 5;
    case 3:
        if (sp == 1) {
            return 6;
        }
        else
            return 7;
    case 2:
        if (sp == 1)
            return 8;
    default:
        return 0;
    }
}

int main()
{
    int n = 0, balls[6] = {}, winballs[7] = {}, prizes[8] = {};
    for (int i = 0; i < 6; ++i)
    {
        cin >> balls[i];
        //We just view input string as 6 numbers.
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            cin >> winballs[j];
            //We just view input string as 7 numbers.
        }
        int temp = match(balls, winballs);
        if (temp)  //temp != 0
        {
            ++prizes[temp - 1];
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        cout << prizes[i];
        if (i != 7)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}