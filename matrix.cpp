#include <iostream>
#include "matrixClass.h"

using namespace std;

matrixClass::matrixClass()
{

}

void matrixClass::menu()
{
    string selection;
    bool quit = false;

    initialize();



    //printmatrixClass(mtx1);
    //printmatrixClass(mtx2);

    while(!quit)
    {
        cout << "Make a selection\n" << "-Addition\n"
             << "-Subtraction\n" << "-Multiplication\n"
             << "-New matrixClasses\n" << "-Quit\n";

        cin >> selection;

        if((selection.compare("Quit") == 0) || (selection.compare("quit") == 0))
        {
            return;
        }
        else if((selection.compare("Addition") == 0))
        {
            mtxAddition();
        }
        else if((selection.compare("Subtraction")) == 0)
        {
            //TODO
        }
        else if((selection.compare("Multiplication") == 0))
        {
            mtxMultiplication();
        }
        else if((selection.compare("New") == 0))
        {
            initialize();
        }
    }
}

void matrixClass::initialize()
{
    int rows;
    int columns;

    cout << "Please input number of rows in matrixClass 1:  ";
    cin >> rows;

    cout << "Please input number of columns in matrixClass 1:  ";
    cin >> columns;

    mtx1.clear();
    mtx1.resize(rows , vector<int>(columns , 0));
        // make the first matrixClass (2d vector) the specified size

    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < columns; y++)
        {
            cout << "Enter the value for element " << x+1 << "," << y+1 << ":  ";
            cin >> mtx1[x][y];
                // collect input for matrixClass 1
        }
    }



    rows = 0;
    columns = 0;
        // clear just in case

    cout << endl << "Please input number of rows in matrixClass 2:  ";
    cin >> rows;

    cout << "Please input number of columns in matrixClass 2:  ";
    cin >> columns;

    mtx2.clear();
    mtx2.resize(rows, vector<int>(columns, 0));
        // make the second matrixClass (2d vector) the specified size
    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < columns; y++)
        {
            cout << "Enter the value for element " << x+1 << "," << y+1 << ":  ";
            cin >> mtx2[x][y];
                // collect input for matrixClass 2
        }
    }



    return;
}


 void matrixClass::printmatrixClass(vector<vector<int>>& mtx)
 {
    cout << endl;
    for(int x = 0; x < mtx.size(); x++)
    {
        for(int y = 0; y < mtx[0].size(); y++)
        {
            cout << mtx[x][y] << ' ';
        }
        cout << endl;
    }
        // loop through rows and columns to print the referenced matrixClass (2d vector)
 }

 void matrixClass::mtxAddition()
 {
    if((mtx1.size() == mtx2.size()) && (mtx1[0].size() == mtx2[0].size())) // test if we can add the matrixClasses
    {
        result.resize(mtx1.size(), vector<int>(mtx1[0].size(), 0));

        for(int x = 0; x < mtx1.size(); x++)
        {
            for(int y = 0; y < mtx1[0].size(); y++)
            {
                result[x][y] = mtx1[x][y] + mtx2[x][y];
            }
        }

        printmatrixClass(mtx1);
        cout << "\nPlus\n";
        printmatrixClass(mtx2);
        cout << "\nEqual\n";
        printmatrixClass(result);
        cout << endl;
        return;
    }
    else
    {
        cout  << "\nERROR ADDING\n\n";
        return;
    }
 }

 void matrixClass::mtxMultiplication()
 {
    //cout << "\nMULTIPLICATION\n" << endl;
    int tempResult = 0;
    if(mtx1.size() == mtx2[0].size())
    {
        result.resize(mtx1.size(), vector<int>(mtx2[0].size(), 0));
        for(int x = 0; x < mtx1.size(); x++)
        {
            for(int y = 0; y < mtx2[0].size(); y++)
            {
                for(int z = 0; z < mtx2.size(); z++)
                {
                    tempResult += mtx1[x][z] * mtx2[z][y];
                }
                result[x][y] = tempResult;
                tempResult = 0;
            }
        }
        printmatrixClass(mtx1);
        cout << "\nTimes\n";
        printmatrixClass(mtx2);
        cout << "\nEqual\n";
        printmatrixClass(result);
        cout << endl;
        return;
    }
    else
    {
        cout << "\nERROR MULTIPLYING\n\n";
        return;
    }
 }


 void matrixClass::mtxSubtraction()
 {
    if((mtx1.size() == mtx2.size()) && (mtx1[0].size() == mtx2[0].size())) // test if we can add the matrixClasses
    {
        result.resize(mtx1.size(), vector<int>(mtx1[0].size(), 0));

        for(int x = 0; x < mtx1.size(); x++)
        {
            for(int y = 0; y < mtx1[0].size(); y++)
            {
                result[x][y] = mtx1[x][y] - mtx2[x][y];
            }
        }

        printmatrixClass(mtx1);
        cout << "\nMinus\n";
        printmatrixClass(mtx2);
        cout << "\nEqual\n";
        printmatrixClass(result);
        cout << endl;
        return;
    }
    else
    {
        cout  << "\nERROR SUBTRACTING\n\n";
        return;
    }
 }
