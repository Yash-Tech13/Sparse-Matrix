#include <stdio.h>

void display(int n,int a[n+1][3])
{
  printf("Row\t\t");
  for(int i=0;i<=n;i++)
  {
    printf("%d\t",a[i][0]);
  }
  printf("\n");
  printf("Column\t");
  for(int i=0;i<=n;i++)
  {
    printf("%d\t",a[i][1]);
  }
  printf("\n");
  printf("Value\t");
  for(int i=0;i<=n;i++)
  {
    printf("%d\t",a[i][2]);
  }
  printf("\n");
}

void transpose(int n,int a[n+1][3])
{
  int m=a[0][1];
  int total[m],index[m+1];

  for(int i=0;i<m;i++)
  {
    total[i]=0;
    for(int j=1;j<=n;j++)
    {
      if(a[j][1]==i)
        total[i]++;
    }
  }

  index[0]=1;
  for(int i=1;i<m+1;i++)
  {
    index[i]=index[i-1]+total[i-1];
  }

  int ans[n+1][3],location;
  ans[0][0]=a[0][1];
  ans[0][1]=a[0][0];
  ans[0][2]=a[0][2];
  for(int i=1;i<=n;i++)
  {
    location = index[a[i][1]];
    ans[location][0] = a[i][1];
    ans[location][1] = a[i][0];
    ans[location][2] = a[i][2];
    index[a[i][1]]++;
  }
  printf("Transpose:\n");
  display(n, ans);
}

void addition(int n,int m,int a[n][3],int b[m][3])
{
  int c[10][3];
  c[0][0]=a[0][0];
  c[0][1]=a[0][1];
  int i=1,j=1,k=1;
  while(i<=n && j<=m)
  {
    if(a[i][0] < b[j][0])
    {
      c[k][0] = a[i][0];
      c[k][1] = a[i][1];
      c[k][2] = a[i][2];
      i++;
      k++;
    }
    else if(a[i][0] > b[j][0])
    {
      c[k][0] = b[j][0];
      c[k][1] = b[j][1];
      c[k][2] = b[j][2];
      j++;
      k++;
    }
    else if(a[i][1] < b[j][1])
    {
      c[k][0] = a[i][0];
      c[k][1] = a[i][1];
      c[k][2] = a[i][2];
      i++;
      k++;
    }
    else if(a[i][1] > b[j][1])
    {
      c[k][0] = b[j][0];
      c[k][1] = b[j][1];
      c[k][2] = b[j][2];
      j++;
      k++;
    }
    else
    {
      c[k][0] = a[i][0];
      c[k][1] = a[i][1];
      c[k][2] = a[i][2]+b[j][2];
      i++;
      j++;
      k++;
    }
  }
  while(i<=n)
  {
    c[k][0] = a[i][0];
    c[k][1] = a[i][1];
    c[k][2] = a[i][2];
    i++;
    k++;
  }
  while(j<=m)
  {
    c[k][0] = b[j][0];
    c[k][1] = b[j][1];
    c[k][2] = b[j][2];
    j++;
    k++;
  }
  c[0][2]=k-1;
  printf("Addition\n");
  display(k-1,c);
}

int main()
{
  int choice;
  int n,m,r1,c1,r2,c2;
  int ans[10][3];
  int a[10][3],b[10][3];
  do
  {
    printf("Menu\n");
    printf("1.Display a given sparse matrix in Triplet Representation\n");
    printf("2.Addition of two sparse matrices\n");
    printf("3.Transpose of given sparse matrix\n");
    printf("4.Exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      printf("Enter number of rows,columns and non-zero elements of Matrix A: ");
      scanf("%d%d%d",&r1,&c1,&n);
      ans[0][0]=r1;
      ans[0][1]=c1;
      ans[0][2]=n; 
      printf("Enter elements of matrix A(Row,Column,Value):\n");
      for(int i=1;i<=n;i++)
      {
        scanf("%d%d%d",&ans[i][0],&ans[i][1],&ans[i][2]);
      }
      printf("Matrix A:\n");
      display(n,ans);
      break;

      case 2:
      printf("Enter number of rows,columns and non-zero elements of Matrix A: ");
      scanf("%d%d%d",&r1,&c1,&n);
      a[0][0]=r1;
      a[0][1]=c1;
      a[0][2]=n; 
      printf("Enter elements of matrix A(Row,Column,Value):\n");
      for(int i=1;i<=n;i++)
      {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      }
      printf("Enter number of rows,coumns and non-zero elements of Matrix B: ");
      scanf("%d%d%d",&r2,&c2,&m);
      b[0][0]=r2;
      b[0][1]=c2;
      b[0][2]=m; 
      printf("Enter elements of matrix B(Row,Column,Value):\n");
      for(int i=1;i<=m;i++)
      {
        scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
      }
      printf("Matrix A:\n");
      display(n,a);
      printf("Matrix B:\n");
      display(m,b);

      addition(n,m,a,b);
      break;

      case 3:
      printf("Enter number of rows,columns and non-zero elements of Matrix A: ");
      scanf("%d%d%d",&r1,&c1,&n);
      a[0][0]=r1;
      a[0][1]=c1;
      a[0][2]=n; 
      printf("Enter elements of matrix A(Row,Column,Value):\n");
      for(int i=1;i<=n;i++)
      {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      }
      printf("Matrix A:\n");
      display(n,a);
      transpose(n,a);
      break;

      case 4:
      printf("Bye!!!!\n");
      break;

      default:
      printf("Enter valid number\n");
    }
  }while(choice != 4);

  return 0;
}
