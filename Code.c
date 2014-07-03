#include<stdio.h>
#include<conio.h>
int findv(int[]);
void main()
{
int i,j,c,r,x,y,count;
int mat[100][100];
int mat1[100][100];
int arr[256];

printf("Enter the number of Rows and Columns of the input matrix:\n");
printf("\n Rows:");
scanf("%d",&r);
printf("\n Columns:");
scanf("%d",&c);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\n Enter element [%d][%d]:",i,j);
scanf("%d",&mat[i][j]);
}
}
printf("\n \n The Input Matrix:\n\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\t %d",mat[i][j]);
}
printf("\n");
}
for(i=1;i<=255;i++)
{
arr[i]=0;
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
count=mat[i][j];                 //Calculating frequency of each element in a matrix in a single scan and storing them in a separate array
arr[count]=arr[count]+1;
}
}
printf("\n \n Frequency of elements in the Matrix are : \n \n");
printf("Element: \t Frequency:\n");
for(i=1;i<=255;i++)
{
if(arr[i]!=0)
{
printf("%d",i);
printf(" \t             %d",arr[i]);
printf("\n");
}
}
printf("\n The mean v= %d",findv(arr));
printf("\n\n The corresponding two-tone matrix is:\n\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(mat[i][j]<=findv(arr))
{
mat[i][j]=1;
}
else
{
mat[i][j]=0;                    //Thresholding: Creation of two-tone matrix using the mean of the most frequent two values...one <=127 and other <127 and <=255 
}
printf("\t %d",mat[i][j]);
}
printf("\n");
}
printf("\n\n");
mat[-1][-1]=mat[0][0];
mat[-1][c]=mat[0][c-1];
mat[r][-1]=mat[r-1][0];        //creation of Auxillary matrix by cloning the binary values of the border cells to their outer adjacent cells 
mat[r][c]=mat[r-1][c-1];
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(i==0)
mat[-1][j]=mat[i][j];
if(j==0)
mat[i][-1]=mat[i][j];
if(i==r-1)
mat[r][j]=mat[i][j];
if(j==c-1)
mat[i][c]=mat[i][j];
}
}
printf("\n Auxillary Matrix:\n");
for(i=-1;i<=r;i++)
{
for(j=-1;j<=c;j++)
{
printf("\t %d",mat[i][j]);
}
printf("\n");
}
printf("\n\n The smoothened matrix:\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
count=0;
for(x=i-1;x<=i+1;x++)
{
for(y=j-1;y<=j+1;y++)
{
if(!(x==i && y==j)&&(mat[x][y]==mat[i][j]))  
count++;
}
}
if(count>=5)
{
mat1[i][j]=mat[i][j];                        //Smoothing: Checking the 8 neighbours in order to retain or invert the binary value of a particular cell
}
else
{
mat1[i][j]=mat[i][j]^1;
}
printf("\t %d",mat1[i][j]);
}
printf("\n");
}
getch();
}

int findv(int a[])
{
int max1=0,max2=0,v1=0,v2=0,v,i;
for(i=1;i<=127;i++)
{
if(a[i]>max1)
{
max1=a[i];
v1=i;
}                                  //Finding the two elements,one in the range 0 to 127,other in the range 128 to 255, that have the highest frequency of occurence and finding their mean 
}
for(i=128;i<=255;i++)
{
if(a[i]>max2)
{
max2=a[i];
v2=i;
}
}
v=(v1+v2)/2;
return v;
}


