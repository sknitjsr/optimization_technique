



#include<stdio.h>

int main()
{
    int nv , nc , i , j , kr ,k, kc ,t=1 , check ;
    float sum , min , min1 , key , R2 ,res=0 ;
         float a[10][10] = {0};
printf("\n SIMPLEX METHOD\n\n");
printf("\n NUMBER OF VARIABLES OF THE FUNCTION ? ");
scanf("%d", &nv);

printf("\n NUMBER OF CONSTRAINTS ? ");
scanf("%d", &nc);


printf("\n INPUT COEFFICIENTS OF THE FUNCTION:\n");
for (j = 2; j<=nv+1; j++)
    {
           scanf("%f", &R2);
           a[0][j] = R2 ;
    }

for (i = 1; i<=nc; i++)
    {
        printf("\n CONSTRAINT #%d:\n", i);
        for (j = 2; j<=nv+1
         ; j++)
        {

          scanf("%f", &R2);
            a[i][j] = R2;
        }
       printf(" Right hand side ? ");
       scanf("%f", &R2);
       a[i][0] = R2;
     }

// pivot element

for(i = 1 , j = nv+2 , k=0 ; k<nc ; i++ , j++ , k++ )
        a[i][j] = 1 ;

        
while(1)
{
check=1;

// to calculate zj- cj
for(i=2 ; i<nc+nv+2 ; i++)
{
    sum=0;
    for(j=1 ; j<=nc ; j++)
    {
    sum=sum+a[j][1]*a[j][i];
    }
    a[nc+1][i] = sum - a[0][i];
}

printf("\n\n\n Table %d " , t++);
for(i=0 ; i<nc+2 ; i++)
{
printf("\n");
for(j=0 ; j<(nv+nc+3) ; j++)
    printf("%.1f\t", a[i][j]);
}
min = 1000;

    for(i=2 ; i<nc+nv+2 ; i++)
{
	if(a[nc+1][i]<0)
	check=0;
}
if(check)
break;

// to calculate key column
for(i=2 ; i<nv+nc+2 ; i++)
{
    if(a[nc+1][i]<min)
{
 min = a[nc+1][i];
 kc=i;
}
}
//to calculate ratio
for(i=1 ; i<=nc ; i++)

{
	if(a[i][kc]<=0)
	a[i][nv+nc+2]=1000;
	else
	a[i][nv+nc+2] = a[i][0] / a[i][kc];
}
//to calculate key row
min1=1000;
for(j=1 ; j<=nc ; j++)
{
    if(a[j][nv+nc+2]<min1)
    {
        min1= a[j][nv+nc+2];
        kr= j ;
    }
}

printf("\n Key column : %d" , kc);
printf("\nKey row : %d" , kr);
printf("\nKey element : %.2f" ,a[kr][kc]);

float pivot = a[kr][kc] ;
//new key row

for(i=0 ; i<nv+nc+2 ; i++)
{
if(i==1)
{
}
else
      a[kr][i]/=pivot;

}
//other rows
for(i=1 ; i<=nc ; i++)
{
float temp1 = a[i][kc] ; 
    if(i==kr)
      {

       }
    else
             {


                    for(j=0 ; j<nc+nv+3 ; j++)
    {

                  if(j==1)
                   {

                   }
        else
           { float temp= a[i][j] - temp1 * a[kr][j] ;
                   a[i][j] = temp ; }

   }
   }


}

 a[kr][1] =  a[0][kc];

}

for(i=1 ; i<=nc ; i++)
res+=a[i][0] * a[i][1];

printf("\nValue of Z = %.1f " , res );
}

