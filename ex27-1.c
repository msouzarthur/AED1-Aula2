#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *realocar(void *ponteiro, size_t newSize);
int main()
{
    int i;
    int *lista = malloc(sizeof(int)*3);
    if(!lista)
    {
        printf("ERRO MEMORIA - main\n");
        return 0;
    }
    for(i=0;i<3;i++)
    {
        printf("Digite um valor para adicionar (%d/3): ",i+1);
        scanf("%d",&lista[i]);
    }
    printf("Valores adicionados: ");
    
    for(i=0;i<3;i++) printf("%d ",lista[i]);
   
    printf("\nAlocando memoria...\n");
    lista = realocar(lista, sizeof(lista)*2);
    for(i=3;i<6;i++)
    {
        printf("Digite um valor para adicionar (%d/6): ",i+1);
        scanf("%d",&lista[i]);
    }
    printf("Valores salvos: ");
    for(i=0;i<6;i++) printf("%d ",lista[i]);
    free(lista);
    return 0;
}
void *realocar(void *ponteiro, size_t newSize)
{
    void *aux;
    aux = malloc(sizeof(ponteiro)*newSize);
    if(!aux)
    {
        printf("ERRO MEMORIA - realocar\n");
        return ponteiro;
    }
    else
    {
        memcpy(aux,ponteiro,newSize);
        free(ponteiro);
        return aux;
    }
}
