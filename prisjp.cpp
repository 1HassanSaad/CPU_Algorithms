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
    int sec=0,test,id;
    for(int i=0;i<sum;i++){
        test=1000000;
        for(int j=0;j<numofproc;j++){
            if(sec>=array[j].arrive){
                if(test>=array[j].burst){
                    test=array[j].burst;
                    id=array[j].id;
                    }
                else {}
                }
            }
        array[id-1].burst=array[id-1].burst-1;
        if(array[id-1].burst==0){array[id-1].burst=1000;}
        cout<<"|"<<sec<<" p"<<array[id-1].id<<" "<<sec+1;
        sec++;
        }
    cout<<"|"<<endl;
    return 0;
}

