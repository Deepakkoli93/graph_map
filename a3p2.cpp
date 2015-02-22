#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <string.h>


using namespace std;
int main(int argc, char *argv[])
{
    ifstream helper;
    helper.open("helperfile.txt");
    int m;
    helper>>m;
    helper.close();
    
    //edges will contain the final mappings output 
	vector< pair<int,int> > edges;
	int count=0;
	ifstream file;
	file.open(argv[1],ios::in);

    /* result will have the first word i.e., SAT or UNSAT*/
    string result;
    file>>result;
    /*------------------------------------------------*/
    
    if(result == "SAT"){

	int ch;
	
	do{
    file>>ch;
    if(ch > 0){
    int j= ((ch -1)%m ) +1;
    int i= ((ch-j)/m)+1;
    
    edges.push_back(make_pair(i,j));
    count++;}

	
     }while(ch!=0);

     file.close();

     ofstream file2;
     file2.open(argv[2]);
     for(int i=0;i<count;i++)
     file2<<edges[i].first<<" "<<edges[i].second<<"\n";

     file2.close();
 
}
//if the first word is not SAT then output a zero
else
{
    ofstream file2;
    file2.open(argv[2]);
    file2<<"0";
    file2.close();
}
return 0;
}