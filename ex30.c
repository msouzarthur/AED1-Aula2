#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **mat, int m, int n);
int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
void liberaMatriz(int **mat, int ncoluna);
int *colunaMatriz(int **mat, int m, int n, int ncoluna);
void imprimeVetor(int *vet, int n);

int main()
{
    int opcao, linha, i, coluna, ncoluna, cont = 0;
    int **matriz, *vet;
    int soma;

    while (1)
    {
        do
        {
            printf("1 - Criar matriz\n");
            printf("2 - Ler valores\n");
            printf("3 - Soma dos elementos\n");
            printf("4 - Vetor da coluna\n");
            printf("5 - Imprimir\n");
            printf("6 - Sair\n");
            scanf("%d", &opcao);
        } while ((opcao < 0) && (opcao > 6));
        switch (opcao)
        {
        case 1:
            cont = cont + 1;
            printf("Digite o numero de colunas: ");
            scanf("%d", &coluna);
            printf("Digite o numero de linhas: ");
            scanf("%d", &linha);

            if (cont == 1)
            {
                matriz = criaMatriz(coluna, linha);
                printf("Matriz criada!\nDimensoes: %d x %d\n", coluna, linha);
            }
            else
            {
                matriz = (int **)realloc(matriz, sizeof(coluna) * sizeof(linha));
                printf("Matriz redimensionada!\nDimensoes: %d x %d\n", coluna, linha);
            }
           break;
        case 2:
            leiaMatriz(matriz, coluna, linha);
            printf("Valores lidos\n");
            break;
        case 3:
            soma = somaMatriz(matriz, coluna, linha);
            printf("Soma da matriz: %d\n", soma);
            break;
        case 4:
            if (cont != 0)
            {
                do
                {
                    printf("Digite o numero da coluna: ");
                    scanf("%d", &ncoluna);
                    if (ncoluna == -1)
                        break;
                } while ((ncoluna < 0) || (ncoluna > coluna));
                imprimeVetor(colunaMatriz(matriz, coluna, linha, ncoluna),linha);
            }
            break;
        case 5:
            imprimeMatriz(matriz, coluna, linha);
            break;
        case 6:
            printf("Liberando memoria\n");
            liberaMatriz(matriz, coluna);
            printf("Sair\n");
            return;
            break;
        default:
            printf("ERRO!\n");
            break;
        }
    }
}
int **criaMatriz(int coluna, int linha)
{
    int i;
    int **matriz;
    matriz = (int **)malloc(coluna * sizeof(int *));
    for (i = 0; i < linha; i++)
    {
        matriz[i] = (int *)malloc(linha * sizeof(int));
    }
    return matriz;
}
void imprimeMatriz(int **mat, int coluna, int linha)
{
    printf("\nNumero de colunas: %d", coluna);
    printf("\nNumero de linhas: %d\n", linha);
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return;
}
void leiaMatriz(int **mat, int coluna, int linha)
{
    printf("%d %d\n", coluna, linha);
    int i, j;
    printf("Ler valores para Matriz:\n");
    for (i = 0; i < coluna; i++)
    {
        for (j = 0; j < linha; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    return;
}
int somaMatriz(int **mat, int coluna, int linha)
{
    int i, j;
    int acumulador;
    for (i = 0; i < coluna; i++)
    {
        for (j = 0; j < linha; j++)
        {
            acumulador = acumulador + mat[i][j];
        }
    }
    return acumulador;
}
void liberaMatriz(int **mat, int ncoluna)
{
    int i = 0;
    for (i = 0; i < ncoluna; i++)
        free(mat[i]);
    free(mat);
    return;
}
int *colunaMatriz(int **mat, int coluna, int linha, int ncoluna)
{
    int i,j;
    int *aux,*comeco;
    aux = (int *) malloc(sizeof(int)*linha);
    comeco=aux;
    for(i=0;i<coluna;i++)
    {
        for(j=0;j<linha;j++)
        {
            if(j==ncoluna-1)
            {
                *aux=mat[i][j];
                aux++;
            }
        }
    }
    aux=comeco;
    return aux;
}
void imprimeVetor(int *vet, int linha)
{
    int i = 0;
    for (i = 0; i < linha; i++)
    {
        printf("%d\n", vet[i]);
    }

    return;
}
