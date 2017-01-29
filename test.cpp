#include <iostream>
#include <fstream>
using namespace std;
typedef struct{int id,arrive,burst;}process;
void firstinfirstout();
void roundrobin();
void preemtiveshortestjobfirst();
void nonpreemtiveshortestjobfirst(); 
int main()
{
int choice;
while(true){
cout<<"1-first in first out algorithm."<<endl;;
cout<<"2-round robin algorithm."<<endl;;
cout<<"3-preemtive shortest job first algorithm."<<endl;
cout<<"4-non preemtive shortest job first algorithm."<<endl;
cin>>choice;
if(choice == 1){
   firstinfirstout();}
else if(choice == 2){
   roundrobin();}
else if(choice == 3){
   preemtiveshortestjobfirst();}
else if(choice == 4){
   nonpreemtiveshortestjobfirst();}
else{
cout<<"invalid option."<<endl;
}
cout<<"to continue press 1   |	 to exit press 0"<<endl;
cin>>choice;
if(choice == 0){break;}
if(choice != 0 && choice != 1){cout<<"invalid option."<<endl; break;}
}
   return 0;
}
void firstinfirstout(){
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
}

void roundrobin(){   
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
}
void preemtiveshortestjobfirst(){
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
}
void nonpreemtiveshortestjobfirst(){ 
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
}
