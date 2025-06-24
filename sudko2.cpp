#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int x, f, i, j, k, p = 0, e, r;

    int a[4][4] = {{0, 0, 0, 3}, {0, 4, 0, 0}, {1, 0, 0, 4}, {0, 0, 3, 0}};

    cout << "\t\t\t\tLET'S PLAY SUDOKU" << endl;
    cout << "\tRULES\n\t1-Each row must contain the numbers 1-4 without repetition\n\t2-Each column must contain the numbers 1-4 without repetition\n\t3-Each 2x2 box must contain the numbers 1-4 without repetition\n";

    cout << "\t\t_________________________\n";
    cout << "\t\t|     |     ||     | 3  |\n";
    cout << "\t\t_________________________\n";
    cout << "\t\t|     |  4  ||     |    |\n";
    cout << "\t\t_________________________\n";
    cout << "\t\t  CHOOSE THE BLOCK\n";
    cout << "\t\t_________________________\n";
    cout << "\t\t|  1  |     ||     |  4 |\n";
    cout << "\t\t_________________________\n";
    cout << "\t\t|     |     ||  3 |     |\n";
    cout << "\t\t_________________________\n\n";

    cout << "COMPLETE THE TASK\n";

    while (true)
    {
        cin >> x;

        switch (x)
        {
        case 1:
            cin >> a[0][0];
            break;
        case 2:
            cin >> a[0][1];
            break;
        case 3:
            cin >> a[0][2];
            break;
        case 4:
            cout << "Can't modify this block\n";
            break;
        case 5:
            cin >> a[1][0];
            break;
        case 6:
            cout << "Can't modify this block\n";
            break;
        case 7:
            cin >> a[1][2];
            break;
        case 8:
            cin >> a[1][3];
            break;
        case 9:
            cout << "Can't modify this block\n";
            break;
        case 10:
            cin >> a[2][1];
            break;
        case 11:
            cin >> a[2][2];
            break;
        case 12:
            cout << "Can't modify this block\n";
            break;
        case 13:
            cin >> a[3][0];
            break;
        case 14:
            cin >> a[3][1];
            break;
        case 15:
            cout << "Can't modify this block\n";
            break;
        case 16:
            cin >> a[3][3];
            break;
        }

        // Step 1: Input Validation (1-4)
        bool validInput = true;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (a[i][j] < 1 || a[i][j] > 5)
                {
                    validInput = false;
                    break;
                }
            }
            if (!validInput) break;  // Break outer loop if invalid input is found
        }

        if (!validInput)
        {
            cout << "Please write numbers between 1-4 only!\n";
            continue;  // Skip further checks if invalid input
        }

        // Step 2: Print the Sudoku Grid
        cout << "\t\t____1______2______3_______4____\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t|   " << a[0][0] << "  |   " << a[0][1] << "  ||  " << a[0][2] << "   |   " << a[0][3] << "  |\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t____5______6______7_______8_______\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t|   " << a[1][0] << "  |   " << a[1][1] << "  ||  " << a[1][2] << "   |   " << a[1][3] << "  |\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t______________________________\n";
        cout << "\t\t____9____10_______11_____12___\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t|   " << a[2][0] << "  |  " << a[2][1] << "   ||  " << a[2][2] << "   |   " << a[2][3] << "  |\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t___13_____14______15_____16___\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t|   " << a[3][0] << "  |   " << a[3][1] << "  ||  " << a[3][2] << "   |   " << a[3][3] << "  |\n";
        cout << "\t\t|      |      ||      |      |\n";
        cout << "\t\t______________________________\n";

        // Step 3: Check for duplicates in rows
        p = 0;  // Reset error flag
        for (i = 0; i < 4; i++)
        {
            bool foundRowDuplicate = false;
            for (j = 0; j < 4; j++)
            {
                for (k = j + 1; k < 4; k++)
                {
                    if (a[i][j] == a[i][k] && a[i][j] != 0)
                    {
                        foundRowDuplicate = true;
                        break;
                    }
                }
                if (foundRowDuplicate)
                {
                    p = 1;
                    break;
                }
            }
            if (p == 1) break;  // Break outer loop if duplicate found
        }

        // Step 4: Check for duplicates in columns
        if (p == 0)  // Only check columns if no row duplicates found
        {
            for (i = 0; i < 4; i++)
            {
                bool foundColDuplicate = false;
                for (j = 0; j < 4; j++)
                {
                    for (k = j + 1; k < 4; k++)
                    {
                        if (a[j][i] == a[k][i] && a[j][i] != 0)
                        {
                            foundColDuplicate = true;
                            break;
                        }
                    }
                    if (foundColDuplicate)
                    {
                        p = 1;
                        break;
                    }
                }
                if (p == 1) break;  // Break outer loop if duplicate found
            }
        }

        // Final Result
        if (p == 1)
        {
            cout << "Error: Duplicate numbers found in rows or columns.\n";
        }
        else
        {
            cout << "Pass: No duplicates in rows or columns.\n";
        }
    }

    return 0;
}