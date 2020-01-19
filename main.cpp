#include<iostream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

int **wczytaj_macierz(int x, int y)
{
  int **macierz=0;
  macierz = new int *[x];
  for(int i=0; i<x; i++)
  {
    macierz[i] = new int[y];
    cout<<"Podaj liczby z "<<i<<" wiersza: ";
    for(int j=0; j<y; j++)
    {
      cin>>macierz[i][j];
    }
  }
  return macierz;
}
void wypisz_macierz(int **macierz, int x, int y)
{
  for(int i=0; i<x; i++)
  {
    for(int j=0; j<y; j++)
    {
      cout<<macierz[i][j]<<" ";
    }
    cout<<endl;
  }
  system("PAUSE");
}

void dodawanie()
{
  int x1,x2,y1,y2;
  cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): "; cin>>x1>>y1;
  int **macierz1 = wczytaj_macierz(x1,y1);
  cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): "; cin>>x2>>y2;
  if(x1!=x2 || y1!=y2)
  {
    cout<<"Nie mozna wykonac takiej operacji!";
    system("PAUSE");
  }
  else
  {
    int** macierz2 = wczytaj_macierz(x2,y2);
    int **wynik;
    wynik = new int *[x1];
    for(int i=0; i<x1; i++)
      wynik[i] = new int[y1];
    for(int i=0; i<x1; i++)
    {
      for(int j=0; j<y1; j++)
      {
        wynik[i][j]=0;
        wynik[i][j]+=macierz1[i][j]+macierz2[i][j];
      }
    }
    cout<<"Wynikowa macierz to: "<<endl;
    wypisz_macierz(wynik, x1, y1);
  }
}
void mnozenie()
{
  int x1,x2,y1,y2;
  cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): ";
  cin>>x1>>y1;
  int **macierz1 = wczytaj_macierz(x1,y1);
  cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): ";
  cin>>x2>>y2;
  if(y1!=x2)
  {
    cout<<"Nie mozna wykonac takiej operacji!";
    system("PAUSE");
  }
  else
  {
    int **macierz2 = wczytaj_macierz(x2,y2);
    int **wynik;
    wynik = new int *[x1];
    for(int i=0; i<x1; i++)
      wynik[i] = new int[y2];
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
    wypisz_macierz(wynik, x1, y2);
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
// for (  h = 0; h < height; h++)
//           {
//             delete [] my2DArray[h];
//           }
//           delete [] my2DArray;
