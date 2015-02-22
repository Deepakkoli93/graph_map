#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <sstream>


using namespace std;


vector< pair<int,int> > g;
vector< pair<int,int> > gd;
	

int glength =0;
int gdlength=0;	
//int max_in_g=0 ;
//int max_in_gd = 0;



pair<int,int> readfile(ifstream& infile, int& max_in_g, int& max_in_gd){

	//std::ifstream infile ("test.graphs");
/*for(int i=0; i< 10000; i++)
		
	{
		g.push_back(make_pair(0,0));
		gd.push_back(make_pair(0,0));
	}*/
int max1,max2;
max1 =0; max2=0;
if(infile){
	int a,b;
	


while (infile >> a >> b)
{
    //cout<<"a = "<<a<<"and b = "<<b<<"\n";
    //if(a==0) cout<<"a is a zero\n";
    if((a==0) && (b==0))
    {   //cout<<"we have zeroes!!!!!!!!!!@#@$@#$((((((((((((((((((((((((((((*#@@@@@@@@@@@@@@@@@@@@@@";
    	break;
        //goto here;
    }
    else
    {
       //g[glength++] = make_pair(a,b);
       g.push_back(make_pair(a,b));;
       glength++;
       int x = (a>b)?a:b;
       if(x>max1) {max1 = x;}
    }

} 
//cout<<"came out of this loop----------------------xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
int c,d;

while(infile >> c >> d)
{
	
//cout<<"got in this loop \n";
//cout<<"c = "<<c<<"and d = "<<d<<"\n";
   //gd[gdlength++] = make_pair(a,b);
 
   	gd.push_back(make_pair(c,d));
	  gdlength++;  
    int y = (c>d)?c:d;
    


    if(y>max2) {max2 = y;}
}
//cout<<"out of the second!!";
infile.close();
//cout<<"files read!!!!";

}
else
{
	cout<<"no file is there";
}
return (make_pair(max1,max2));

}




/*void condition1(string* thestr, int max_in_g, int max_in_gd){
	int m = max_in_g;
int n = max_in_gd;
	string str = "";
int count = 1;
int z=0;
for(int j=1;j<=n;j++)
{for(int i=1;i<=m;i++)
    {
	//file<<count++<<" ";
	ostringstream convert;
	convert <<count++;
	//cout<<"count = "<<count<<endl;
	//cout<<"convert = "<<convert<<endl;
	string s1;
	s1 = convert.str();
	//cout<<"s1 = "<<s1<<endl;
	str.append(s1);
	str.append(" ");  
	}

str.append("0"); 
//cout<<"str is "<<str;
thestr[z++] = str;
str="";
}
}*/


/*void condition2(string* thestr2,int max_in_g, int max_in_gd){
		int m = max_in_g;
int n = max_in_gd;
	int z=0;

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		for(int k=j+1;k<=m;k++)
		{
			//cout<<-(m*(i-1)+j) <<" "<<-(m*(i-1)+k)<<" 0\n" ;
            ostringstream  convert1;
            convert1<<(-(m*(i-1)+j));
            string s1;
            s1 = convert1.str();
            thestr2[z++].append(s1);
            thestr2[z-1].append(" "); 
            ostringstream convert2;
            convert2<<(-(m*(i-1)+k));
            s1 = convert2.str();
            thestr2[z-1].append(s1);
            thestr2[z-1].append(" 0");

		}
	 
           

	}

}
}*/

/*void condition3(string* thestr3, int max_in_g, int max_in_gd){
	int m = max_in_g;
int n = max_in_gd;
int z=0;
for(int i=1;i<=m;i++)
{
	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{
			//cout<<-(m*(j-1)+i) <<" "<<-(m*(k-1)+i)<<" 0\n" ;
            ostringstream  convert1;
            convert1<<(-(m*(j-1)+i));
            string s1;
            s1 = convert1.str();
            thestr3[z++].append(s1);
            thestr3[z-1].append(" "); 
            ostringstream convert2;
            convert2<<(-(m*(k-1)+i));
            s1 = convert2.str();
            thestr3[z-1].append(s1);
            thestr3[z-1].append(" 0");

		}
	 
           

	}

}}*/



int main(int argc, char *argv[])
{
	
int max_in_g=0 ;
int max_in_gd = 0;
//string xyz="";
//xyz=argv[1];
std::ifstream infile (argv[1]);
//cout<<"sendin to read";
pair<int,int> res = readfile(infile,max_in_g,max_in_gd);
//cout<<"came back";
max_in_g = res.first;
max_in_gd = res.second;
/*****graphs read***/

/*cout<<"\nprinting g....\n";
for(int i=0;i<glength;i++)
{
	cout<<g[i].first<<" "<<g[i].second<<"\n";
}
cout<<"\nprinting gd....\n";
for(int i=0; i<gdlength; i++)
{
	cout<<gd[i].first<<" "<<gd[i].second<<"\n";
}
cout<<"max in g = "<<max_in_g<<"\n";
cout<<"max in gd = "<<max_in_gd<<"\n";*/

int arr1[max_in_g+1][max_in_g+1];
for(int i=0;i<=max_in_g;i++)
for(int j=0;j<=max_in_g;j++)
arr1[i][j] = 0;

for(int i=0;i<=max_in_g;i++)
	for(int j=0; j<=max_in_g; j++)
	{
      for(int z=0;z<glength;z++)
      {  //cout<<i<<" "<<j<<endl;
         //cout<<g[z].first<<" "<<g[z].second<<endl;
         if((g[z].first==i) && (g[z].second==j))
         	{arr1[i][j] = 1;
             break;}
      }
	}

int arr2[max_in_gd+1][max_in_gd+1];
for(int i=0;i<=max_in_gd;i++)
for(int j=0;j<=max_in_gd;j++)
arr2[i][j] = 0;


for(int i=0;i<=max_in_gd;i++)
	for(int j=0; j<=max_in_gd; j++)
	{
      for(int z=0;z<gdlength;z++)
      {
         if((gd[z].first==i) && (gd[z].second==j))
         	{arr2[i][j] = 1;
             break;}
      }
	}


// arr1 = larger graph
// arr2 = smaller graph


/*cout<<"adjacency for first graph...\n" ;
for(int i=0;i<=max_in_g;i++)
{for(int j=0;j<=max_in_g;j++)
cout<<arr1[i][j];
cout<<"\n";
}


cout<<"adjacency for second graph...\n" ;
for(int i=0;i<=max_in_gd;i++)
{for(int j=0;j<=max_in_gd;j++)
cout<<arr2[i][j];
cout<<"\n";
}
cout<<"glength"<<glength<<"\n";
cout<<"gdlength"<<gdlength<<"\n";*/
/* in an out degrees of the two graphs */
//largein
//largeout
//smallin
//smallout


int largein[max_in_g+1] ;
for(int i=0;i<=max_in_g;i++) largein[i]=0;
int largeout[max_in_g+1] ;
for(int i=0;i<=max_in_g;i++) largeout[i]=0;
int smallin[max_in_gd+1];
for(int i=0;i<=max_in_gd;i++) smallin[i]=0;
int smallout[max_in_gd+1] ;
for(int i=0;i<=max_in_gd;i++) smallout[i]=0;

for(int i=0;i<glength;i++)
{
	largeout[g[i].first]++;
    largein[g[i].second]++;
}
for(int i=0;i<gdlength;i++)
{
	smallout[gd[i].first]++;
	smallin[gd[i].second]++;
}
int m = max_in_g;
int n = max_in_gd;
/*cout<<"largein\n";
for(int i=1;i<=m;i++)
cout<<largein[i]<<endl;

cout<<"largeout\n";
for(int i=1;i<=m;i++)
cout<<largeout[i]<<endl;

cout<<"smallout\n";
for(int i=1;i<=n;i++)
cout<<smallout[i]<<endl;

cout<<"smallin\n";
for(int i=1;i<=n;i++)
cout<<smallin[i]<<endl;*/


int validmaps[n+1][m+1];
int number_of_variables=0;
int number_of_clauses=0;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
if((largein[j]<smallin[i]) || (largeout[j]<smallout[i]))
{validmaps[i][j]=0;} 
else 
	{validmaps[i][j]=1; }
}
}
/*cout<<"valid maps....\n";
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
	cout<<validmaps[i][j];
	cout<<"\n";}*/
/* in and out degrees calculated */

// m = number of nodes in larger graph
// n = number of nodes in smaller graph

//cout<<"max in g"<<max_in_g<<"\n";
//cout<<"max in gd"<<max_in_gd;
ofstream file;
file.open("test.satinputhelper");

//condition 1

//string thestr[n];
 //m = max_in_g;
 //n = max_in_gd;
	//string str = "";
int count = 0;
int z=0;
for(int j=1;j<=n;j++)
{for(int i=1;i<=m;i++)
    {
	//file<<count++<<" ";
    	count++;
    	if(validmaps[j][i]==1){/*
	ostringstream convert;
	convert <<count++;
	//cout<<"count = "<<count<<endl;
	//cout<<"convert = "<<convert<<endl;
	string s1;
	s1 = convert.str();
	//cout<<"s1 = "<<s1<<endl;
	str.append(s1);
	str.append(" ");  */
     file<<count<<" ";number_of_variables++;}
	}

//str.append("0"); 
//cout<<"str is "<<str;
//thestr[z++] = str;
//str="";
	file<<"0\n";
	number_of_clauses++;
}



//condition1(thestr,max_in_g,max_in_gd);

//condition 2

//string thestr2[(n*(m*(m-1)/2))+1];
//string thestr2[n*m*m+1];
//condition2(thestr2,max_in_g,max_in_gd);
 m = max_in_g;
 n = max_in_gd;
	 z=0;

/*for(int i=1;i<=n;i++)
{
	for(int j=1;j<m;j++)
	{
		for(int k=j+1;k<=m;k++)
		{
			
			if((validmaps[i][j]==1)&&(validmaps[i][k]==1))
			{file<<-(m*(i-1)+j) <<" "<<-(m*(i-1)+k)<<" 0\n" ;
			//cout<<i<<" "<<j<<" "<<i<<" "<<k<<" "<<endl;
            number_of_clauses++;
            }
            /*ostringstream  convert1;
            convert1<<(-(m*(i-1)+j));
            string s1;
            s1 = convert1.str();
            thestr2[z++].append(s1);
            thestr2[z-1].append(" "); 
            ostringstream convert2;
            convert2<<(-(m*(i-1)+k));
            s1 = convert2.str();
            thestr2[z-1].append(s1);
            thestr2[z-1].append(" 0");

		}
	 
           

	}

}

*/

//condition 3
//string thestr3[(m*(n*(n-1)/2))+1];
//string thestr3[m*n*n + 1];
//condition3(thestr3,max_in_g,max_in_gd);
 m = max_in_g;
n = max_in_gd;
z=0;
for(int i=1;i<=m;i++)
{
	for(int j=1;j<n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{  
			//if(j!=k)
			if((validmaps[j][i]==1)&&(validmaps[k][i]))
			{file<<-(m*(j-1)+i) <<" "<<-(m*(k-1)+i)<<" 0\n" ;
		//cout<<j<<" "<<i<<" "<<k<<" "<<i<<" "<<endl;
            number_of_clauses++;
            }
            /*ostringstream  convert1;
            convert1<<(-(m*(j-1)+i));
            string s1;
            s1 = convert1.str();
            thestr3[z++].append(s1);
            thestr3[z-1].append(" "); 
            ostringstream convert2;
            convert2<<(-(m*(k-1)+i));
            s1 = convert2.str();
            thestr3[z-1].append(s1);
            thestr3[z-1].append(" 0");*/

		}
	 
           

	}

}

//larger graph is arr1
//smaller graph is arr2

//condition 4
//string thestr4[n*n*m*m+1];

/*int z=0;
int thestr4_length = 0;
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=m;k++)
		{
			for(int l=1;l<=m;l++)
			{
               if(arr2[i][j]==arr1[k][l])
               {thestr4_length++;
               	//cout<<(-(m*(i-1)+k))<<" "<<(-(m*(j-1)+l))<<" 0\n";
               	ostringstream  convert1;
            convert1<<(-(m*(i-1)+k));
            string s1;
            s1 = convert1.str();
            thestr4[z++].append(s1);
            thestr4[z-1].append(" "); 
            ostringstream convert2;
            convert2<<(-(m*(j-1)+l));
            s1 = convert2.str();
            thestr4[z-1].append(s1);
            thestr4[z-1].append(" 0");
               }
			}
		}
	}
}*/

//writing to file
//thestr => string array for condition 1
//thestr2 => string array for condition 2
//thestr3 => string array for condition 3
//thestr4 => string array for condition 4

/* writing to file 'outputfile.txt' */
//int number_of_clauses = thestr4_length+(n*(m*(m-1)/2))+(m*(n*(n-1)/2))+n;
//int number_of_variables = m*n;

//file<<"p cnf "<<number_of_variables<<" "<<number_of_clauses<<endl;
/*for(int i=0;i<n;i++)
	file<<thestr[i]<<"\n";

for(int i=0;i<(n*(m*(m-1)/2))+1;i++)
	file<<thestr2[i]<<endl;

for(int i=0;i<(m*(n*(n-1)/2))+1;i++)
	file<<thestr3[i]<<"\n";*/

/*for(int i=0;i<thestr4_length;i++)
	file<<thestr4[i]<<"\n";*/
 z=0;int cou=0;
int thestr4_length = 0;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    for(int k=1;k<=m;k++)
    {
      for(int l=1;l<=m;l++)
      {    if((k!=l) &&(i!=j)){
               if(arr2[i][j]==true && false==arr1[k][l]){
               	if((validmaps[i][k])&&(validmaps[j][l]))
               { 
                file<<(-(m*(i-1)+k))<<" "<<(-(m*(j-1)+l))<<" 0\n";
                
                number_of_clauses++;
               
               }}
if(arr2[i][j]==false && arr2[j][i]==false && true==arr1[k][l]){
               	if((validmaps[i][k])&&(validmaps[j][l]))
               { 
                file<<(-(m*(i-1)+k))<<" "<<(-(m*(j-1)+l))<<" 0\n";
                
                number_of_clauses++;
               
               }}



           }
       
   
      

      }
    }
  }
}
//cout<<cou<<endl;
//file.seekg(0,ios::beg);
//file<<"p cnf "<<number_of_variables<<" "<<number_of_clauses<<"\n";
file.close();

/*-------*/
ofstream f;
f.open(argv[2]);
f<<"p cnf "<<number_of_variables<<" "<<number_of_clauses<<"\n";
f.close();
std::ifstream ifile("test.satinputhelper", std::ios::in);
std::ofstream ofile(argv[2], std::ios::out | std::ios::app);
ofile << ifile.rdbuf();
ifile.close();
ofile.close();
/*-------*/
/*--------------------------------*/

/* output m to a file 'helperfile.txt'*/
ofstream helper;
helper.open("helperfile.txt");
helper<<m;
helper.close();
/*------------------------------------*/

return 0;
}