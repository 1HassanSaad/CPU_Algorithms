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
for(int i=0;i<sum;i++){
if(array[0].burst>quantum){
array[0].burst=array[0].burst-quantum;
cout<<"|"<<su<<" p"<<array[0].id<<" "<<su+quantum;
su+=quantum;
process temp;
temp.id=array[0].id;
temp.arrive=array[0].arrive;
temp.burst=array[0].burst;
for(int j=0;j<numofproc-1;j++){
array[j].id=array[j+1].id;
array[j].arrive=array[j+1].arrive;
array[j].burst=array[j+1].burst;
}
array[numofproc-1].id=temp.id;
array[numofproc-1].arrive=temp.arrive;
array[numofproc-1].burst=temp.burst;
}
else{
if(array[0].burst==0){
process temp;
temp.id=array[0].id;
temp.arrive=array[0].arrive;
temp.burst=array[0].burst;
for(int j=0;j<numofproc-1;j++){
array[j].id=array[j+1].id;
array[j].arrive=array[j+1].arrive;
array[j].burst=array[j+1].burst;
}
array[numofproc-1].id=temp.id;
array[numofproc-1].arrive=temp.arrive;
array[numofproc-1].burst=temp.burst;
}
else{
cout<<"|"<<su<<" p"<<array[0].id<<" "<<su+array[0].burst;
su+=array[0].burst;
array[0].burst=0;
process temp;
temp.id=array[0].id;
temp.arrive=array[0].arrive;
temp.burst=array[0].burst;
for(int j=0;j<numofproc-1;j++){
array[j].id=array[j+1].id;
array[j].arrive=array[j+1].arrive;
array[j].burst=array[j+1].burst;
}
array[numofproc-1].id=temp.id;
array[numofproc-1].arrive=temp.arrive;
array[numofproc-1].burst=temp.burst;
}
}
}
cout<<"|"<<endl;
return 0;
}
