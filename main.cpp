#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<algorithm>
using namespace std;

double **wczytaj_macierz(int x, int y)
{
  double **macierz=0;
  macierz = new double *[x];
  for(int i=0; i<x; i++)
  {
    macierz[i] = new double[y];
    cout<<"Podaj liczby z "<<i<<" wiersza: ";
    for(int j=0; j<y; j++)
    {
      cin>>macierz[i][j];
    }
  }
  return macierz;
}
void wypisz_macierz(double **macierz, int x, int y)
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
  double **macierz1 = wczytaj_macierz(x1,y1); //deklaracja pierwszej macierzy
  cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): "; cin>>x2>>y2;
  if(x1!=x2 || y1!=y2) //walidacja dodawania
  {
    cout<<"Nie mozna wykonac takiej operacji!";
    system("PAUSE");
  }
  else
  {
    double** macierz2 = wczytaj_macierz(x2,y2); //deklaracja drugiej macierzy
    double **wynik;              //
    wynik = new double *[x1];    //
    for(int i=0; i<x1; i++)   // deklaracja macierzy wynikowej
      wynik[i] = new double[y1]; //
    for(int i=0; i<x1; i++)
    {
      for(int j=0; j<y1; j++)
      {
        wynik[i][j]=0;
        wynik[i][j]+=macierz1[i][j]+macierz2[i][j]; //dodawanie odpowiadajacych sobie elementow
      }
    }
    cout<<"Wynikowa macierz to: "<<endl;
    wypisz_macierz(wynik, x1, y1); //wypisywanie macierzy wynikowej
    for (int i=0; i<x1; i++) //usuwanie zaalokowanych zasobow
    {
     delete [] macierz1[i];
     delete [] macierz2[i];
     delete [] wynik[i];
    }
    delete [] macierz1;
    delete [] macierz2;
    delete [] wynik;
  }
}
double **odejmowanie(double **macierz1, double **macierz2, int stopien)
{
    double **wynik;
    wynik = new double *[stopien];
    for(int i=0; i<stopien; i++)
      wynik[i] = new double[stopien];
    for(int i=0; i<stopien; i++)
    {
      for(int j=0; j<stopien; j++)
      {
        wynik[i][j]=0;
        wynik[i][j]+=macierz1[i][j]-=macierz2[i][j];
      }
    }
    return wynik;
    for (int i=0; i<stopien; i++)
     delete [] wynik[i];
    delete [] wynik;
}
void mnozenie()
{
  int x1,x2,y1,y2;
  cout<<"Podaj rozmiar pierwszej macierzy(wiersze, kolumny): ";
  cin>>x1>>y1;
  double **macierz1 = wczytaj_macierz(x1,y1);
  cout<<"Podaj rozmiar drugiej macierzy(wiersze, kolumny): ";
  cin>>x2>>y2;
  if(y1!=x2) //walidacja mnozenia
  {
    cout<<"Nie mozna wykonac takiej operacji!";
    system("PAUSE");
  }
  else
  {
    double **macierz2 = wczytaj_macierz(x2,y2);
    double **wynik;
    wynik = new double *[x1];
    for(int i=0; i<x1; i++)
      wynik[i] = new double[y2];
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
    for (int i=0; i<x1; i++)
    {
     delete [] macierz1[i];
     delete [] macierz2[i];
     delete [] wynik[i];
    }
    delete [] macierz1;
    delete [] macierz2;
    delete [] wynik;
  }
}
double wyznacznik(int stopien, int w, int *kolumny, double **macierz)
{
  double wynik=0;
  if(stopien==1)
  {
    return macierz[w][kolumny[0]];
  }
  else
  {
    int *wk;
    wk = new int [stopien-1];
    int mnoznik = 1;
    for(int i=0; i<stopien; i++)
    {
      int k=0;
      for(int j=0; j<stopien-1; j++)
      {
        if(k==i) k++;
        wk[j] = kolumny[k++];
      }
      wynik += mnoznik * macierz[w][kolumny[i]]*wyznacznik(stopien-1, w+1, wk, macierz);
      mnoznik = -mnoznik;
    }
    delete [] wk;
    return wynik;
  }
}

double **odwrotna(double **macierz, int stopien)
{
  for (int i = 0; i<stopien; i++)
  {
    macierz[i][i] = 1 / macierz[i][i];
    for (int j = 0; j<stopien; j++)
      if (j != i)
      {
        macierz[j][i] = macierz[j][i] * macierz[i][i];
        for (int k = 0; k<stopien; k++)
          if (k != i)
          {
              macierz[j][k] -= macierz[j][i] * macierz[i][k];
              if (j == (stopien - 1))
                  macierz[i][k] = -(macierz[i][k] * macierz[i][i]);
          }
      }
  }
  int st = stopien-1;
  for (int j = 0; j<st; j++) macierz[st][j] = -(macierz[st][j] * macierz[st][st]);
  return macierz;
}
void rownanie()
{
  int stopien;
  cout<<"Podaj stopien macierzy: ";
  cin>>stopien;
  cout<<"Macierz A:"<<endl;
  double **macierzA = wczytaj_macierz(stopien,stopien);
  cout<<"Macierz B:"<<endl;
  double **macierzB = wczytaj_macierz(stopien,stopien);
  cout<<"Macierz C:"<<endl;
  double **macierzC = wczytaj_macierz(stopien,stopien);
  int *kolumny;
  kolumny = new int [stopien];
  for(int i=0; i<stopien; i++)
    kolumny[i] = i;
  double wyznacznik_m = wyznacznik(stopien, 0, kolumny, macierzA);
  if(wyznacznik_m)
  {
    macierzA = odwrotna(macierzA, stopien);
    wypisz_macierz(macierzA, stopien, stopien);
    macierzB = odejmowanie(macierzC, macierzB, stopien);
    wypisz_macierz(macierzB, stopien, stopien);
    double **wynik=0;
    wynik = new double *[stopien];
    for(int i=0; i<stopien; i++)
      wynik[i] = new double[stopien];
    for(int i=0; i<stopien; i++)
    {
      for(int j=0; j<stopien; j++)
      {
        wynik[i][j]=0;
        for(int k=0; k<stopien; k++)
        {
          wynik[i][j]+=macierzB[i][k]*macierzA[k][j];
        }
      }
    }
    wypisz_macierz(wynik, stopien, stopien);
  }
  else
  {
    cout<<"Macierz jest osobliwa!"<<endl;
    system("PAUSE");
  }
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
    cout<<"4. Wyznacz macierz odwrotna (max. 3x3)."<<endl;
    cout<<"5. Rozwiaz rownanie AX + B = C (max. 3x3)."<<endl;
    cout<<"6. Wyjdz."<<endl;
    cout<<"Wybierz opcje: ";
    int opcja; cin>>opcja;
    switch(opcja)
    {
      case 1: dodawanie(); break;
      case 2: mnozenie(); break;
      case 3:
      {
        int x,y;
        cout<<"Podaj rozmiar macierzy(wiersze, kolumny): ";
        cin>>x>>y;
        if(x!=y)
        {
          cout<<"Nie mozna wykonac takiej operacji!";
        }
        else
        {
          double **macierz = wczytaj_macierz(x,y);
          int stopien = x;
          int *kolumny;
          kolumny = new int [stopien];
          for(int i=0; i<stopien; i++)
            kolumny[i] = i;
          cout<<"Wyznacznik tej macierzy to: "<<wyznacznik(stopien, 0, kolumny, macierz)<<endl;
          system("PAUSE");
          for (int i=0; i<stopien; i++)
           delete [] macierz[i];
          delete [] kolumny;
          delete [] macierz;
        }
      } break;
      case 4:
      {
        int stopien;
        cout<<"Podaj stopien macierzy: ";
        cin>>stopien;
        double **macierz = wczytaj_macierz(stopien,stopien);
        int *kolumny;
        kolumny = new int [stopien];
        for(int i=0; i<stopien; i++)
          kolumny[i] = i;
        double wyznacznik_m = wyznacznik(stopien, 0, kolumny, macierz);
        if(wyznacznik_m)
        {
          cout<<"Wynikowa macierz to: "<<endl;
          wypisz_macierz(odwrotna(macierz, stopien),stopien,stopien);
        }
        else
        {
          cout<<"Macierz jest osobliwa!"<<endl;
          system("PAUSE");
        }
      } break;
      case 5: {
        rownanie();
      } break;
      case 6: return 0; break;
      default: return 0;
    }
  }
}
