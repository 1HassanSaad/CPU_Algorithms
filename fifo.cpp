#include <iostream>
#include <fstream>
using namespace std;

int main()
{
typedef struct{int id,arrive,burst;}process;
int numofproc,quantum,sum=0;
   ifstream infile("file.txt");
   int a, b ;
   for(int i=0;i<2;i++){
      infile >> a;
      if(i==0){numofproc=a;}
      else {quantum=a;}           
   }
   process array[numofproc];
   for(int i=0;i<numofproc;i++)
   {
      infile >> a >> b;
      array[i].id=i+1;
      array[i].arrive=a;
      array[i].burst=b;
      sum+=array[i].burst;   
   }
   int su=0;
   for(int i=0;i<numofproc;i++){
       cout<<"|";
       su+=array[i].burst;
       if(array[i].id == 1)
       {
           cout<<array[i].arrive;
           cout<<" p"<<array[i].id;
           cout<<" "<<array[i].burst;
       }
       else
       {
           cout<<su - array[i].burst;
           cout<<" p"<<array[i].id;
           cout<<" "<<su;
       }
   }
   cout<<"|";
   cout<<endl;
   return 0;
}

