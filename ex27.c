#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    /*
    aux[i]=lista[i];
    lista=(int *) malloc(6*sizeof(int));
    memcpy(lista,aux,(sizeof(int)*3));
    */
    int *lista;
    int *aux;
    int i;
    lista=(int *) malloc(3*sizeof(int));
    //aux=(int *) malloc(3*sizeof(int));
    if(!lista)
    {
        printf("ERRO MEMORIA\n");
        return;
    }
    for(i=0;i<3;i++)
    {
        printf("Digite um numero: ");
        scanf("%d",&lista[i]);
    }
    for(i=0;i<3;i++) printf("Numero armazenado: %d\n",lista[i]);
    
    printf("\nAumentando tamanho...\n\n");
    for(i=0;i<3;i++) aux[i]=lista[i];

    lista=(int *) malloc(6*sizeof(int));
    memcpy(lista,aux,(sizeof(int)*3));
    for(i=3;i<6;i++)
    {
        printf("Digite um numero: ");
        scanf("%d",&lista[i]);
    }
    for(i=0;i<6;i++) printf("Numero armazenado: %d\n",lista[i]);
    
    free(lista);
    free(aux);
    return 0;
}