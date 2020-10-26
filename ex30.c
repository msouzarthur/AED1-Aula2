#include <stdio.h>
#include <stdlib.h>

//shift alt f - identação

void imprimeMatriz(int **mat, int m, int n);
int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
void liberaMatriz(int **mat, int nlinha);
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
                matriz = (int **)realloc(matriz,linha * sizeof(int *));
                for (i = 0; i < linha; i++)
                {
                    matriz[i] = (int *)realloc(matriz[i],coluna * sizeof(int));
                }
                //matriz = (int **)realloc(matriz, (sizeof(coluna)*sizeof(int)) * (sizeof(linha)*sizeof(int)));
                printf("Matriz redimensionada!\nDimensoes: %d x %d\n", coluna, linha);
            }
            break;
        case 2:
            leiaMatriz(matriz, coluna, linha);
            printf("Valores lidos\n");
            break;
        case 3:
            printf("Calculando soma...\n");
            soma = somaMatriz(matriz, coluna, linha);
            printf("Soma da matriz: %d\n", soma);
            break;
        case 4:
            printf("Imprimir coluna:\n");
            if (cont != 0)
            {
                do
                {
                    printf("Digite o numero da coluna: ");
                    scanf("%d", &ncoluna);
                    if (ncoluna == -1)
                        break;
                } while ((ncoluna <= 0) || (ncoluna > coluna));
                vet=colunaMatriz(matriz, coluna, linha, ncoluna);
                imprimeVetor(vet, coluna);
                free(vet);
            }
            break;
        case 5:
            printf("Imprimindo matriz:\n");
            imprimeMatriz(matriz, coluna, linha);
            break;
        case 6:
            printf("Liberando memoria\n");
            liberaMatriz(matriz, linha);
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
    matriz = (int **)malloc(linha * sizeof(int *));
    for (i = 0; i < linha; i++)
    {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
    }
    return matriz;
}
void imprimeMatriz(int **mat, int coluna, int linha)
{
    printf("Matrix %d x %d\n", coluna, linha);
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
    printf("Matrix %d x %d\n", coluna, linha);
    int i, j, aux = 1;
    printf("Ler valores para Matriz:\n");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d/%d : ", aux, linha * coluna);
            scanf("%d", &mat[i][j]);
            aux++;
        }
    }
    return;
}
int somaMatriz(int **mat, int coluna, int linha)
{
    int i, j;
    int acumulador;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            acumulador = acumulador + mat[i][j];
        }
    }
    return acumulador;
}
void liberaMatriz(int **mat, int nlinha)
{
    int i = 0;
    for (i = 0; i < nlinha; i++)
        free(mat[i]);
    free(mat);
}
int *colunaMatriz(int **mat, int coluna, int linha, int ncoluna)
{
    int i, j, controle;
    int *aux;
    aux = (int *)malloc(sizeof(int) * linha);
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (j == ncoluna - 1)
            {
                aux[controle] = mat[i][j];
                controle++;
            }
        }
    }
    return aux;
}
void imprimeVetor(int *vet, int coluna)
{
    int i = 0;
    for (i = 0; i < coluna; i++)
    {
        printf("%d\n", vet[i]);
    }
    return;
}
