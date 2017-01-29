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
   int sec = array[0].arrive;
   int id = array[0].id;
   int burst = array[0].burst;
   int su=0;
   for(int i=0;i<numofproc;i++){
	int test = 1000000;
       for(int j=0;j<numofproc;j++){
           if(sec == array[j].arrive && array[i].id != array[j].id)
           {
               if(burst <= array[j].burst)
               {}
               else
               {
                   id = array[j].id;
                   burst = array[j].burst;
               }
           }
	   if(sec > array[j].arrive)
           {
		if(test > array[j].burst)
		{
		   test = array[j].burst;
                   id = array[j].id;
                   burst = array[j].burst;
		}
           }
         }
           if(i==0){
                cout<<"|"<<array[id-1].arrive<<" p"<<array[id-1].id<<" "<<array[id-1].burst;
		su+=array[id-1].burst;       
		sec=array[id-1].burst;
       		id=array[id-1].id;
       		burst=array[id-1].burst;
       		array[id-1].burst=1000;
		} 
	   else{
		su+=array[id-1].burst;
		cout<<"|"<<su-array[id-1].burst<<" p"<<array[id-1].id<<" "<<su;
       		sec=su;
       		array[id-1].burst=1000;
		}   
}
   cout<<"|";
   cout<<endl;
   return 0;
}

