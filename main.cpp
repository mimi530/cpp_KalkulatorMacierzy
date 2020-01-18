#include<iostream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
void wczytaj_macierz()
{
  int x,y;
  cin>>x>>y;
  int macierz[x][y];
  for(int i=0; i<x; i++)
  {
    cout<<"Podaj liczby z "<<i<<" wiersza: ";
    for(int j=0; j<y; j++)
    {
      cin>>macierz[i][j];
    }
  }

}

class Macierz
{
  public:
    int a, b;
    int *tab;
    Macierz(int x, int y)
    {
      a=x;
      b=y;
      int tab2[a][b];
      tab2[0][0]=38;
      tab=&tab2;
    }
    void wczytaj()
    {
        cout<<"jestem obiektem klasy macierz"<<endl;
    }
};
void dodawanie()
{
  //cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): ";
  //wczytaj_macierz();
  // int tab[2][3] = {{1,5,3},{7,8,6}};
  // int* wsk[0] = tab;
  Macierz m1(3,3);
  cout<<m1.tab[0][0]<<endl;
  system("PAUSE");
  //cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): ";
}
// void dodawanie2()
// {
//   int x1,x2,y1,y2;
//   cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): ";
//   cin>>x1>>y1;
//   int macierz1[x1][y1];
//   for(int i=0; i<x1; i++)
//   {
//     cout<<"Podaj liczby z "<<i<<" wiersza: ";
//     for(int j=0; j<y1; j++)
//     {
//       cin>>macierz1[i][j];
//     }
//   }
//   cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): ";
//   cin>>x2>>y2;
//   if(x1!=x2 || y1!=y2)
//   {
//     cout<<"Nie mozna wykonac takiej operacji!";
//     system("PAUSE");
//   }
//   else
//   {
//     int macierz2[x2][y2];
//     for(int i=0; i<x2; i++)
//     {
//       cout<<"Podaj liczby z "<<i<<" wiersza: ";
//       for(int j=0; j<y2; j++)
//       {
//         cin>>macierz2[i][j];
//       }
//     }
//     int wynik[x1][y1];
//     for(int i=0; i<x1; i++)
//     {
//       for(int j=0; j<y1; j++)
//       {
//         wynik[i][j]=0;
//         wynik[i][j]+=macierz1[i][j]+macierz2[i][j];
//       }
//     }
//     cout<<"Wynikowa macierz to: "<<endl;
//     for(int i=0; i<x1; i++)
//     {
//       for(int j=0; j<y1; j++)
//       {
//         cout<<wynik[i][j]<<" ";
//       }
//       cout<<endl;
//     }
//     system("PAUSE");
//   }
// }
void mnozenie()
{
  int x1,x2,y1,y2;
  cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): ";
  cin>>x1>>y1;
  int macierz1[x1][y1];
  for(int i=0; i<x1; i++)
  {
    cout<<"Podaj liczby z "<<i<<" wiersza: ";
    for(int j=0; j<y1; j++)
    {
      cin>>macierz1[i][j];
    }
  }
  cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): ";
  cin>>x2>>y2;
  if(y1!=x2)
  {
    cout<<"Nie mozna wykonac takiej operacji!";
    system("PAUSE");
  }
  else
  {
    int macierz2[x2][y2];
    for(int i=0; i<x2; i++)
    {
      cout<<"Podaj liczby z "<<i<<" wiersza: ";
      for(int j=0; j<y2; j++)
      {
        cin>>macierz2[i][j];
      }
    }
    int wynik[x1][y2];
    for(int i=0; i<x1; i++)
    {
      for(int j=0; j<y2; j++)
      {
        wynik[i][j]=0;
        for(int k=0; k<x2; k++)
        {
          wynik[i][j]+=macierz1[i][k]*macierz2[k][j];
        }
      }
    }
    cout<<"Wynikowa macierz to: "<<endl;
    for(int i=0; i<x1; i++)
    {
      for(int j=0; j<y2; j++)
      {
        cout<<wynik[i][j]<<" ";
      }
      cout<<endl;
    }
    system("PAUSE");
  }
}
void wyznacznik()
{
  int x,y;
  cout<<"Podaj rozmiar macierzy(wiersze, kolumny): ";
  cin>>x>>y;
  int macierz1[x][y];
  for(int i=0; i<x; i++)
  {
    cout<<"Podaj liczby z "<<i<<" wiersza: ";
    for(int j=0; j<y; j++)
    {
      cin>>macierz1[i][j];
    }
  }

}
void odwrotna()
{

}
void rownanie()
{

}
int main()
{
  while(true)
  {
    system ("CLS");
    cout<<"Kalkulator Macierzy by Michal Domzalski"<<endl;
    cout<<"1. Dodawanie macierzy."<<endl;
    cout<<"2. Mnozenie macierzy"<<endl;
    cout<<"3. Wyznacznik macierzy."<<endl;
    cout<<"4. Wyznacz macierz odwrotna."<<endl;
    cout<<"5. Rozwiaz rownanie."<<endl;
    cout<<"6. Wyjdz."<<endl;
    cout<<"Wybierz opcje: ";
    int opcja;
    cin>>opcja;
    switch(opcja)
    {
      case 1: dodawanie(); break;
      case 2: mnozenie(); break;
      case 3: wyznacznik(); break;
      case 4: odwrotna(); break;
      case 5: rownanie(); break;
      case 6: return 0; break;
      default: return 0;
    }
  }
}
