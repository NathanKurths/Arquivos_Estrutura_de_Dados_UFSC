#include "lab.h"
#include <stdlib.h>
#include <math.h>
/*resposta de implementacao aqui*/

FILE *abre_arquivo(const char *arquivo)
{
    if(!arquivo) return NULL;
    FILE *arq;
    arq = fopen(arquivo, "r");
    return arq;
}

int fecha_arquivo(FILE *arq)
{
    if(arq == NULL) return 1;
    else
        fclose(arq);
        return 0;
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros)
{
   FILE *arq = abre_arquivo(arquivo);
    if(!qtd_numeros) return NULL;
    if (arq == NULL)
    {
        qtd_numeros = 0;
        return NULL;
    }

    double val;
    int tam = 0;
    while (fscanf(arq, "%lf", &val) != EOF)
    {
        tam++;
    }

    *qtd_numeros = tam;

    double *vetor = (double*)malloc(tam*sizeof(double));
    rewind(arq);

    int i = 0;

    while (fscanf(arq, "%lf", &val) != EOF)
    {
        vetor[i] = val;
        i++;
    }
    fecha_arquivo(arq);
    return vetor;
}

double maior(double* valores, unsigned int qtd_numeros)
{
    if(valores == NULL || qtd_numeros == 0) return HUGE_VAL;

    double maior_v = *valores;

    for (int i = 0; i<qtd_numeros;i++)
    {
        if(valores[i] > maior_v) maior_v = valores[i];
    }

    return maior_v;
}

double menor(double* valores, unsigned int qtd_numeros)
{
    if(valores == NULL || qtd_numeros == 0) return HUGE_VAL;

    double menor_v = *valores;

    for (int i = 0; i<qtd_numeros;i++)
    {
        if(valores[i] < menor_v) menor_v = valores[i];
    }

    return menor_v;
}

double media(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
        return HUGE_VAL;

    double media = 0;

    for (int i = 0; i < qtd_numeros; i++)
    {
        media += valores[i];
    }
    media = media/qtd_numeros;

    return media;
}

double desvio(double *valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
        return HUGE_VAL;

    double aux, quadrado;
    double med = media(valores, qtd_numeros);

    for (int i = 0; i < qtd_numeros; i++)
    {
        aux = valores[i] - med;
        quadrado += aux * aux;
    }
    double desvio = sqrt(quadrado/(qtd_numeros-1));

    return desvio;
}

double amplitude(double* valores, unsigned int qtd_numeros)
{
    if (valores == NULL || qtd_numeros == 0)
        return HUGE_VAL;

    double amplitude = maior(valores, qtd_numeros) - menor(valores, qtd_numeros);

    return amplitude;
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao)
{
    if (valores == NULL || qtd_numeros == 0 || posicao >= qtd_numeros)
        return HUGE_VAL;
    
    return valores[posicao];
}

double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao)
{
    if (valores == NULL)
    {
        *qtd_repeticao = 0;
        return HUGE_VAL;
    }

    int cont = 0;
    int aux = 0;
    double numero = *valores;

    for (int i = 0; i < qtd_numeros; i++)
    {
        for (int j = i + 1; j < qtd_numeros; j++)
        {
            if (valores[i] == valores[j])
                aux++; 
        }

        if (aux > cont)
        {
            cont = aux;
            numero = valores[i];
        }
    }

    *qtd_repeticao = cont;

    return numero;
} 