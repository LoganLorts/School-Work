// Programer:	Logan Lorts
// Student ID:	12580684
// Section:	102
// Date:	2/17/23
// File:	fishbomb.cpp
// Purpose:	Uses a dynamically allocated array to find how many fish will be blown up in a grid

#include <iostream>
using namespace std;

int main()
{
    int h_sonar, w_sonar;
    int dynamite1_1, dynamite1_2;
    int dynamite2_1, dynamite2_2;
    int dynamite3_1, dynamite3_2;
    int fish_total = 0;
    int test_cases = 0; //initialize variables

    cin >> test_cases;

    for(int t = 0; t < test_cases; t++)
    {
        fish_total = 0;
        cin >> h_sonar >> w_sonar;
        //creating a 2d array of size h_sonar by w_sonar
        int **array = new int*[h_sonar];
        for (int i = 0; i < h_sonar; i++)
        {
            array[i] = new int[w_sonar];
        }

        //fill the array
        for (int i = 0; i < h_sonar; i++)
        {
            for (int k = 0; k < w_sonar; k++)
            {
                cin >> array[i][k];
            }
        }

        // takes in dynamite locations
        cin >> dynamite1_1 >> dynamite1_2 >> dynamite2_1 >> dynamite2_2 >> dynamite3_1 >> dynamite3_2;


        // checks in a 5x5 grid around the given dynamite locations and removes caught fish
        for (int i = 0; i < h_sonar; i++)
        {
            if((i >= (dynamite1_1 - 2)) && (i <= (dynamite1_1 + 2)))
            {
                for (int k = 0; k < w_sonar; k++)
                {
                    if((k >= (dynamite1_2 - 2) && (k <= (dynamite1_2 + 2))))
                    {
                    fish_total += array[i][k];
                    array[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < h_sonar; i++)
        {
            if((i >= (dynamite2_1 - 2)) && (i <= (dynamite2_1 + 2)))
            {
                for (int k = 0; k < w_sonar; k++)
                {
                    if((k >= (dynamite2_2 - 2) && (k <= (dynamite2_2 + 2))))
                    {
                    fish_total += array[i][k];
                    array[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < h_sonar; i++)
        {
            if((i >= (dynamite3_1 - 2)) && (i <= (dynamite3_1 + 2)))
            {
                for (int k = 0; k < w_sonar; k++)
                {
                    if((k >= (dynamite3_2 - 2) && (k <= (dynamite3_2 + 2))))
                    {
                    fish_total += array[i][k];
                    array[i][k] = 0;
                    }
                }
            }
        }


        cout << "#" << t << ": Bender catches " << fish_total << " fish" << endl;

        for (int i = 0; i < h_sonar; i++) //deallocate array
        {
            delete [] array[i];
        }
        delete [] array;
    }

    return 0;
}
