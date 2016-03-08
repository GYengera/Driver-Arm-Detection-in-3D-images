#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
unsigned short x, depth[240][320];
float val[240][320], center_x = 179.5, center_y = 119.5, focal = 285.63;/* Camera Parameters used for calculating real depth*/
/* Real depth values are not being computed however as this code showcases the example of only raw data*/
int i,j;

FILE *infile = fopen("<path>/001000.depth","rb"); /*Path to the depth image needs to be specified*/

fseek(infile, 28, SEEK_SET); /* Skipping the Header File*/
printf("Reading data from depth file");

for (i=0; i < 240; i++)
{
    for (j=0; j < 320; j++)
{
        fread(&x, sizeof (x), 1, infile);
        depth[i][j] = x/8;
}
}
ofstream outfile;
outfile.open("2Darray.dat");
for (int i = 0; i< 240;i++)
    {
           for(int j=0;j<320;j++)
           {
               outfile << depth[i][j] << " ";
           }
           outfile << "\n";
    }
outfile.close();
fclose(infile);
printf("\nprocess complete");
getch();
return(0);
}
