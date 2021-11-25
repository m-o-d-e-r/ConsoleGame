#include<iostream>
#include<string>
#include <cstring>

using namespace std;


void sort ( int *mas, int begin, int end, string *name);

void printMas (string name[], int hight[], int size)
{
    for(int i = 0; i < size; i++ )
    {
        cout << i << ") " << name[i] << "  hight = " << hight[i] << endl;
    }
}


int findIndex (string name[], string findName, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(&findName[0], &name[i][0]) >= 0)
            return i;
    }
    return 0;
}

void replace_(int startIndex, int size_, string name[], int hight[])
{
    for (int i = startIndex; i < size_; i++)
    {
        if (hight[i] == hight[i + 1])
        {
            string temp_str = name[i];
            name[i] = name[i + 1];
            name[i + 1] = temp_str;

            int temp_hight = hight[i];
            hight[i] = hight[i + 1];
            hight[i + 1] = temp_hight;
        }
    }
}

int main()
{
    int size = 7;
    string name[size] = {"Arthur", "Sasha", "Pasha", "Masha", "Petya", "Katya", "Vanya"};
    int hight [size] = {176, 169, 165, 173, 167, 183, 176};
    
    sort(hight, 0, size - 1, name);

    string findName = "Arthur";
    int indexArthur = findIndex(name, findName, size);
  
    printMas(name, hight, size);

    replace_(indexArthur, size, name, hight);

    cout << "\n\n";    

    printMas(name, hight, size);

    return 0;
}

void sort( int *mas, int begin, int end, string *name)
{
  int first = begin;
  int last = end;
  int middle=mas[(first+last)/2];
  
  while(first<=last){
    while (mas[first]<middle)
      first++;
    while(mas[last]>middle)
      last--;
    if(first<=last){  
      if(mas[first]>mas[last]){
           int temp = mas[first];
        mas[first]=mas[last];
        mas[last]=temp;
        string temp2 = name[first];
        name[first]=name[last];
        name[last]=temp2;
      }
      first++;
      last--;
    }
    
  }  
    if(begin<end){
      sort(mas, begin, last, name);
      sort(mas, first, end, name);
    }  
}