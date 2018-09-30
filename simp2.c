#include<stdio.h>

int main()
{
    int nv , nc , i , j , kr , kc , check ;
    float sum , min , min1 , key , R2 ;
    float a[5][8]={ 0 , 0 ,1 , 1.5 , 0 , 0 , 0 , 0 ,400 , 0 , 1 ,0 ,1 ,0 , 0 , 0, 200 , 0 , 0 ,1 ,0 , 1 ,0 , 0 ,960 , 0 ,1 , 3 ,0 , 0 ,1 , 0 ,0 , 0 ,0 ,0 ,0 , 0 ,0 ,0 ,0};
double R1,R2;
char R;


printf("\n SIMPLEX METHOD\n\n");
printf(" MAXIMIZE (Y/N) ? "); scanf("%c", &R);
printf("\n NUMBER OF VARIABLES OF THE FUNCTION ? ");
scanf("%d", &nv);

printf("\n NUMBER OF CONSTRAINTS ? "); scanf("%d", &nc);

//if minimize change it to maximize
if (R == 'Y' || R=='y')
R1 = 1.0;
else
R1 = -1.0;

printf("\n INPUT COEFFICIENTS OF THE FUNCTION:\n");
for (j = 1; j<=nv; j++)
    {
          printf(" #%d ? ", j); scanf("%lf", &R2);
           a[0][J] = R2 * R1;
    }

while(1)
{
check=1;

// to calculate zj- cj
for(i=2 ; i<nv+2 ; i++)
{
    sum=0;
    for(j=1 ; j<=nc ; j++)
    {
    sum=sum+a[j][1]*a[j][i];
    }
    a[nc+1][i] = sum - a[0][i];
}
min = 1000;

    for(i=2 ; i<nv+2 ; i++)
{
	if(a[nc+1][i]<0)
	check=0;
}
if(check)
break;

// to calculate key column
for(i=2 ; i<nv+2 ; i++)
{ 
    if(a[nc+1][i]<min)
{
 min = a[nc+1][i];
 kc=i;
}
}
//to calculate ratio
for(i=2 ; i<=nc ; i++)

{
	if(a[i][kc]<=0)
	a[i][nv+2]=1000;
	else
	a[i][nv+2] = a[i][0] / a[i][kc];
}
//to calculate key row
min1=1000;
for(j=2 ; j<=nc ; j++)
{  
    if(a[j][nv+2]<min1)
    {
        min1= a[j][nv+2];
        kr= j ;
    }
}

printf("\n Key column : %d" , kc);
printf("\nKey row : %d" , kr);
printf("\nKey element : %.2f" ,a[kr][kc]);

//new key row
for(i=0 ; i<nv+2&&i!=1 ; i++)
      a[kr][i]/=a[kr][kc];
//other rows
for(i=1 ; i<=nc ; i++)
{
    if(i==kr)
    {

    }
    else
    {


    for(j=0 ; j<nv+2 ; j++)
    {

       if(j==1)
    {

    }
        else
            a[i][j] = a[i][j] - a[i][kc]*a[kr][j] ;}
}}

 a[kr][1] =  a[0][kc];



}

for(i=0 ; i<5 ; i++)
{
printf("\n");
for(j=0 ; j<8 ; j++)
    printf("%.1f\t", a[i][j]);
}
}
