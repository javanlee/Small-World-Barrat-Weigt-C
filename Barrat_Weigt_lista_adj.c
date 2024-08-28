#include <stdio.h>
#include <stdlib.h>


int main()
{

int N = 200;
int kmed=6;

double p=0.9;
double r;

int i,j,edge_ij,posicao_i,l,k,m;
int multi_conect;


int **edge;
int lista[N];

for (i=0;i<N;i++) lista[i]=kmed;

edge = (int **)malloc(N*sizeof(int*));
if (!edge){
printf ("** Erro 1 : Memoria Insuficiente **");
exit(0);
}
for (i=0;i<N;i++) 
  {
  edge[i] =(int *)malloc(lista[i]*sizeof(int));
  if (!edge[i])
     {
     printf ("** Erro 2 : Memoria Insuficiente **");
     exit(0);
     }
  }
for (i=0;i<N;i++)
  {
  for (j=0;j<kmed/2;j++)
     {
     edge[i][j]= (i+j+1)%N;
     edge[i][kmed/2+j]= (i-(1+j)+N)%N;
     }
  }
     


printf("\n");
for (i=0;i<N;i++)
  {
  printf("||%d||",i);
  for (j=0;j<lista[i];j++) printf("%d ",edge[i][j]);
  printf("\n");
  }
printf("\n");











//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

for (i=0; i<N; i++)
{
 for (m=0;m<kmed/2;m++)
 {
 j=m;
      r = rand();
      r /= RAND_MAX;
      if (r<p)
        { //IF   



///////////

          edge_ij=edge[i][j];//   edge_ij É um sitio

      do
      {
             printf("%d",edge_ij);
       do 
       {
       l=rand()%N; // i DIFERENTE l
       printf("*");
       }
       while (i==l);
       multi_conect=0;
       for (k=0;k<lista[l];k++) 
         {
         if (i==edge[l][k]) 
              {
              multi_conect=1;
              printf("\n i=%d \n edge_ij=%d \n l=%d DEU RUIM\n",i,edge_ij,l);
              break;
              }
          }
              printf("o");       
       }
      while (multi_conect==1);   
      printf("\n i=%d \n edge_ij=%d \n l=%d \n",i,edge_ij,l);
//****************************************************************//
//***************************************************************// 
  
      /////////////////////////////////////////////////////
      //////////   R E W I R I N G   //////////////////////
      /////////////////////////////////////////////////////
   
      edge[i][j]=l;//QUEBRANDO a ligação entre i e edge_ij
      ///////////////CONECTANDO i com l
      
	/////////////////////////////////////////////////
	///                              ////////////////
	///  A D I C I O N A R   NO FINAL   /////////////
	///                              ////////////////
	/////////////////////////////////////////////////

	lista[l]++;
	edge[l] = realloc (edge[l], lista[l]*sizeof(int));
	edge[l][lista[l]-1]=i;//CONECTANDO l com i
	/////////////////////////////////////////////////
	/////////////////////////////////////////////////
      

      /////////////////////////////////////////////////////
      //////////   R E W I R I N G   //////////////////////
      /////////////////////////////////////////////////////
      
      
//=============================================================//

      /////////////////////////////////////////////////////
      //////////   Q U E B R A N D O  /////////////////////
      /////////////////////////////////////////////////////
   
/////////////////////////////////////////////////
/////////////////////////////////////////////////
///                              ////////////////
///  R E M O V E R     -->>>   j ////////////////
///                              ////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/////////////////////////////////////////////////
int *p;
for (k=0;k<lista[edge_ij];k++) if (i==edge[edge_ij][k])
              {
              posicao_i=k;
              break;
              }
p=(int *)malloc((lista[edge_ij]-1)*sizeof(int));
	if (!p)
        {
        printf ("** Erro: Memoria Insuficiente **");
        exit(0);
        }
for (k=0; k<posicao_i ; k++) p[k] = edge[edge_ij][k];
for (k=posicao_i; k<lista[edge_ij]-1 ; k++) p[k] = edge[edge_ij][k+1];
free(edge[edge_ij]);
lista[edge_ij]--;
  edge[edge_ij] =(int *)malloc(lista[edge_ij]*sizeof(int));
  if (!edge[edge_ij])
     {
     printf ("** Erro 2 : Memoria Insuficiente **");
     exit(0);
     }
for (k=0;k<lista[edge_ij];k++) edge[edge_ij][k]=p[k];
free (p);
/////////////////////////////////////////////////
/////////////////////////////////////////////////

      /////////////////////////////////////////////////////
      //////////   Q U E B R A N D O  /////////////////////
      /////////////////////////////////////////////////////


        
        } //FI
}//m      
}  


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv      
      


printf("\n");
for (i=0;i<N;i++)
  {
  printf("||%d||",i);
  for (j=0;j<lista[i];j++) printf("%d ",edge[i][j]);
  printf("\n");
  }
printf("\n");



for (i=0; i<N; i++) free (edge[i]); /* libera as linhas da matriz */
free (edge); /* libera a matriz (vetor de ponteiros) */


return(0);
}
