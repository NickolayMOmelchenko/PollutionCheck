#include "pollution.h"

void enterFactoryNames(string *factoryNames)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Name of Factory: ";
        getline(cin, factoryNames[i]);
        cout << endl;
    }
}

float* makeArray(int years)
{
    float* arr = new float[years];
    return arr;
}
void enterCOData(float* array, int year)
{
    cout << "\nCarbon Monoxide (CO) average level per hour (in parts per million)" << endl; 
    for (int i = 0; i < year; i++)
    {
        cout << "\tYEAR " << i + 1 << ": " ;
        cin >> array[i];
    }
}
void enterNO2Data(float* array, int year)
{
    cout << "\nNitrogen Dioxide (NO2) average level per hour (in parts per billion)" << endl;    
    for (int i = 0; i < year; i++)
    {
        cout << "\tYEAR " << i + 1 << ": ";
        cin >> array[i];
    }
    
}
void enterO3Data(float* array, int year)
{
    cout << "\nOzone (O3) average level per 8 hours (in parts per million)" << endl; 
    for (int i = 0; i < year; i++)
    {
        cout << "\tYEAR " << i + 1 << ": ";
        cin >> array[i];
    }
    
}
void printOverLimit(string* factoryNames, float** arrays, int years, float limit)
{
    bool yayORnay = true;
    for (int i = 0; i < SIZE; i++)
    {
        for(int y = 0; y < years; y++) 
       {
            if (limit < arrays[i][y])
            {
                cout << factoryNames[i] << endl;
                yayORnay = false;
                break;
            }
        }
    }
    if (yayORnay == true)
    {
        cout << "Yay! There are no factories over the limit! " << endl;
    }
}
void getLargest(string *factoryNames, float** arrays, int years, float& largest, string& hightestFactoryNames, int& hightestYear)
{
    hightestYear = 0;
    largest = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for(int y = 0; y < years; y++) 
       {
            if (largest < arrays[i][y])
            {
                largest = arrays[i][y];
                hightestFactoryNames = factoryNames[i];
                hightestYear = y;
            }
        }
    }
    
}