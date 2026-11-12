#include <iostream>
#include <fstream>
#include <array>
#include <cmath>

using namespace std;

void zadanie1()
{
    int rzedy[10];
    int linie[10];
    int helper;
    fstream file("tabliczka.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            file >> helper;
            rzedy[i] = helper;
            linie[i] = helper;
        }
        cout << 'x' << "\t";
        for(int i = 0; i < 10; ++i)
        {
            cout << linie[i] << "\t";
        }
        cout << '\n' << "-----------------------------------------------------------------------------------" << '\n';
        for(int r = 0; r < 10; ++r)
        {
            cout << rzedy[r] << " \| \t";
            for(int l = 0; l < 10; ++l)
            {
                cout << rzedy[r] * linie[l] << "\t";
            }
            cout << '\n';
        }
    }
}

void zadanie2()
{
    string gospo[8];
    string goscie[8];
    string helper;
    fstream file("druzyny.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 8; ++i)
        {
            file >> helper;
            gospo[i] = helper;
            goscie[i] = helper;
        }
        cout << 'x' << "\t";
        for(int i = 0; i < 8; ++i)
        {
            cout << "  " << gospo[i][0] << gospo[i][1] << gospo[i][2] << "\t \t";
        }
        cout << '\n' << " --------------------------------------------------------------------------------------------------------------------------------" << '\n';
        for(int i = 0; i < 8; ++i)
        {
            cout << goscie[i][0] << goscie[i][1] << goscie[i][2] << "\| \t";
            for(int j = 0; j < 8; ++j)
            {
                if(i == j)
                {
                    cout << "   --   ";
                }
                else
                {
                    cout << gospo[i][0] << gospo[i][1] << gospo[i][2]<< "--" << goscie[j][0] << goscie[j][1] << goscie[j][2];
                }
                cout << "\t";
            }
            cout << '\n';
        }
    }
}

void zadanie3()
{
    array<string, 10> kolumny;
    array<string, 10> linie;
    string help;
    fstream file("tancerze.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            file >> help;
            kolumny.at(i) = help;
            linie.at(i) = help;
        }
        cout << "x     ";
        for(int i = 0; i < 10; ++i)
        {
            cout << "   " << kolumny.at(i)[0] << kolumny.at(i)[1] << kolumny.at(i)[2] << "    ";
        }
         cout << '\n' << "   -----------------------------------------------------------------------------------------------------";
        for(int i = 0; i < 10; ++i)
        {
            cout << '\n' << linie.at(i)[0] << linie.at(i)[1] << linie.at(i)[2] << "\|   ";
            for (int j = 0; j < 10; ++j)
            {
                if(i <= j)
                {
                    cout << "-------   ";
                }
                else
                {
                    cout << kolumny.at(i)[0] << kolumny.at(i)[1] << kolumny.at(i)[2] << "-" << linie.at(j)[0] << linie.at(j)[1] << linie.at(j)[2] << "   ";
                }
            }
            cout << "   ";
        }
        cout << '\n';
    }
}

void zadanie4a()
{
    array<double ,50> tab;
    array<int ,9999> ilosc = {{0}};
    double help;
    fstream file("ulamki.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 50; ++i)
        {
            file >> tab.at(i);
        }
        for(int i = 0; i < 50; ++i)
        {
            help = tab.at(i) * 100;
            ilosc.at(help) += 1;
        }
        for(int i = 0; i < 50; ++i)
        {
            cout << i << '\t' << tab.at(i) << "\tilosc: " << ilosc.at(tab.at(i) * 100) - 1 << '\n';
        }
    }
}

void zadanie4b()
{
    array<double ,50> tab;
    array<int ,9999> ilosc;
    for(int i = 0; i < 9999; ++i)
    {
        ilosc.at(i) = 0;
    }
    fstream file("ulamki.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 50; ++i)
        {
            file >> tab.at(i);
        }
        for(int j = 0; j < 50; ++j)
        {
            for(int d = 0; d < 50; ++d)
            {
                if(tab.at(j) < tab.at(d))
                {
                    ilosc.at(tab.at(j) * 100) += 1;
                }
            }
            cout << j << '\t' << tab.at(j) << "\tilosc: " << ilosc.at(tab.at(j) * 100) << '\n';
        }
    }
}

void zadanie4c()
{
    array<double ,50> tab;
    double help;
    fstream file("ulamki.txt");
    if(!file.is_open())
    {
        cout << "nope";
    }
    else
    {
        for(int i = 0; i < 50; ++i)
        {
            file >> tab.at(i);
        }
        for(int j = 0; j < 50; ++j)
        {
            for(int d = 0; d < 50; ++d)
            {
                if(fabs(tab.at(j) - tab.at(d)) < 5.00)
                {
                    help += 1;
                }
            }
            cout << j << '\t' << tab.at(j) << "\tilosc: " << help - 1 << '\n';
            help = 0;
        }
    }
}
int main()
{
    zadanie3();
    return 0;
}
