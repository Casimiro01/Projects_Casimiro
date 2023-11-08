#include <stdio.h>
#include <sys/time.h> // para utilizar a hora do sistema
#include <math.h>
#include <windows.h>

#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


/// 1 //////////////////////////////////////////////////////
// =-=-=-=-=-=-=-=-=-=-=-=-= (1.1)
void bubbleSort(long *v, int tam, int *transfer)
{
    int troca, aux;
    int t, i;

    troca = 1;   // utilizando o 1 como verdadeiro
    t = tam - 1; // tamanho da parte não ordenada do vetor

    while (t > 0 && troca == 1)
    {
        troca = 0; // utilizando o 0 como verdadeiro

        for (i = 0; i < t; i++)
        {
            
            if (v[i] > v[i + 1])
            {
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
        
        if (troca == 1)
        {
            *transfer = *transfer + 1;
        }

        t--;
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-= (1.2)
void selectionSort(long *v, int tam, int *transfer)
{
    int i, j;
    int menor, aux;

    for (i = 0; i < tam; i++)
    {
        menor = i;

        for (j = i + 1; j < tam; j++)
        {
            
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }
        
        if (menor != i){
            *transfer = *transfer + 1;
        }
        
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-= (1.3)
void insertionSort(long *v, int tam, int *transfer)
{
    int i, j;
    int aux;
    int verify;

    for (j = 1; j < tam; j++)
    {
        aux = v[j];
        i = j - 1;S
        verify = 0;

        while (i >= 0 && v[i] > aux)
        {
            
            v[i + 1] = v[i];
            i--;
            verify = 1;
        }
        
        if (verify == 1)
        {
            *transfer = *transfer + 1;
        }
        
        v[i + 1] = aux;
        
    }
}

/// 2 //////////////////////////////////////////////////////
// =-=-=-=-=-=-=-=-=-=-=-=-= (2.1)
void preenche_vetor(long *v, int tam, int disp) 
{
    int mid_tam = 0;

    switch (disp) 
    {

    case 1: // crescente
        for (int C=0; C<tam; C++)
        {
            v[C] = C + 1;
        }
        break;
    
    case 2: // decrescente
        for (int C=0; C<tam; C++) // para Coluna
        {
            v[C] = tam - C;
        }
        break;

    case 3: // aleatório
        srand(time(NULL));

        for (int C=0; C<tam; C++) 
        {
            v[C] = rand() %5000;
        }
        break;

    case 4: // côncavo
        srand(time(NULL));
        mid_tam = trunc(tam / 2);

        for (int C=0; C<mid_tam; C++) 
        { 
            v[C] = C + 1;

        }
    
        for (int C=mid_tam; C<tam; C++) 
        {
            v[C] = tam - C;
 
        }
        break;

    case 5: // convexo
        srand(time(NULL));
        mid_tam = trunc(tam / 2);

        for (int C=0; C<mid_tam; C++) 
        { 
            v[C] =  mid_tam - C;

        }
    
        for (int C=mid_tam; C<tam; C++) 
        {
            v[C] = C + 1 - mid_tam;
 
        }
        break;
    }
    
}

// =-=-=-=-=-=-=-=-=-=-=-=-= (2.2)
void imprime_vetor(long *v, int tam)
{
    int i, j , limite, limite2;

    if (tam > 10)
    {
        limite = 10;
        limite2 = tam - limite;
    } 

    else
    {
        limite = tam;
    }

    for (i = 0; i < limite; i++)
    {
        printf("%d ", v[i]);
    }

    printf("...");

    for(j = limite2; j < tam; j++)
    {
        printf(" %d", v[j]);
    }

    printf("\n");
}

/// Main //////////////////////////////////////////////////////
int main()
{   
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();

  SetConsoleOutputCP(CPAGE_UTF8);
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.1) 
    system("cls");
    int QTDE, disposicao;

    printf("Escolha a forma de preenchimento dos vetores\n");
    printf("1- Crescente | 2- Decrescente | 3- Aleatório | 4- Concavo | 5- Convexo\n");
    scanf("%d", &disposicao);

    printf("\nInsira a quantidade de ordenações por algoritmos: ");
    scanf("%d", &QTDE);
    SetConsoleOutputCP(CPAGE_DEFAULT);
    int sizes[QTDE];
    int size_maior;

    struct timeval T1[QTDE*2], T2[QTDE*2], T3[QTDE*2]; // T = timer
    int start, end;

    long interval1[QTDE][2]; 
    long interval2[QTDE][2];
    long interval3[QTDE][2];

    long transfer1[QTDE], transfer2[QTDE], transfer3[QTDE];
{
    
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();

   SetConsoleOutputCP(CPAGE_UTF8);
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.2)
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Para o preenchimento dos vetores, ");

    for (int i = 0; i < QTDE; i++)
    {
        printf("digite o tamanho do espaço %d: ", i+1);
        printf(" 1000 | 5000 | 10000 | 100000 | outro valor\n");
        scanf("%d", &sizes[i]);
        
    }
    printf("\n");
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.3)
    for (int i = 0; i < QTDE; i++) 
    {
        if (QTDE == 1) 
        {
            size_maior = sizes[i];
        }

        else if (i+1 < QTDE)
        {
            if (sizes[i] > sizes[i+1])
            {
                size_maior = sizes[i];
            }

            else
            {
                size_maior = sizes[i+1];
            }
        }
    }

    long insertion[QTDE][size_maior];
    long selection[QTDE][size_maior];
    long bubble[QTDE][size_maior];

    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.4)
    for (int L=0; L<QTDE; L++)
    {
        transfer1[L]=0;
        transfer2[L]=0;
        transfer3[L]=0;

        preenche_vetor(insertion[L], sizes[L], disposicao);
        preenche_vetor(selection[L], sizes[L], disposicao);
        preenche_vetor(bubble[L], sizes[L], disposicao);
    }

    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.5) ***
   {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();

   SetConsoleOutputCP(CPAGE_UTF8);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int L=0; L<QTDE; L++)
    {
        printf("Antes da ordenção (linha %d): ", L+1);
        imprime_vetor(insertion[L], sizes[L]);
    }
    printf("\n");
    SetConsoleOutputCP(CPAGE_DEFAULT);
   }
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.6) 
    for (int a=1; a<=3; a++) // p/ processar os três algoritmos 
    {
        for (int L=0; L<QTDE;L++)
        {
            start = L*2;
            end = start+1;
            
            if (a==1) // Ordenação/Medição do Insertion Sort
            {
                gettimeofday( &T1[start], NULL ); // START TIMER
                insertionSort(insertion[L], sizes[L], &transfer1[L]);
                gettimeofday( &T1[end], NULL ); // END TIMER

                interval1[L][0] = T1[end].tv_sec - T1[start].tv_sec;
                interval1[L][1] = ( (interval1[L][0] * 1000000) + T1[end].tv_usec) - T1[start].tv_usec;
            }

            else if (a==2) // Ordenação/Medição do Selection Sort
            {
                gettimeofday( &T2[start], NULL ); // START TIMER
                selectionSort(selection[L], sizes[L], &transfer2[L]);
                gettimeofday( &T2[end], NULL ); // END TIMER

                interval2[L][0] = T2[end].tv_sec - T2[start].tv_sec;
                interval2[L][1] = ( (interval2[L][0] * 1000000) + T2[end].tv_usec) - T2[start].tv_usec;
            }

            else // Ordenação/Medição do Bubble Sort
            {
                gettimeofday( &T3[start], NULL ); // START TIMER
                bubbleSort(bubble[L], sizes[L], &transfer3[L]);
                gettimeofday( &T3[end], NULL ); // END TIMER

                interval3[L][0] = T3[end].tv_sec - T3[start].tv_sec;
                interval3[L][1] = ( (interval3[L][0] * 1000000) + T3[end].tv_usec) - T3[start].tv_usec;
            }
        }
    }

{ 
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();

   SetConsoleOutputCP(CPAGE_UTF8);
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.7) ***
    for (int L=0; L<QTDE;L++)
    {
        printf("Depois da ordenção (linha %d): ", L+1);
        imprime_vetor(insertion[L], sizes[L]);
        SetConsoleOutputCP(CPAGE_DEFAULT);
        //imprime_vetor(selection[L], sizes[L]);
        //imprime_vetor(bubble[L], sizes[L]);
    }
}
    // =-=-=-=-=-=-=-=-=-=-=-=-= (Main.8) ***
    /*
    interval1 & transfer1 --> p/ INSERTION
    interval2 & transfer2 --> p/ SELECTION
    interval3 & transfer3 --> p/ BUBBLE

    interval1[<espaço>][<0 ou 1>] onde 0 coleta os segundos e 1 coleta os microsegundos
    transfer1[<espaço>]
    */

  
    for (int a=1; a<=3; a++) // p/ processar os três algoritmos

    {
        {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();

   SetConsoleOutputCP(CPAGE_UTF8);
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        for (int L=0; L<QTDE; L++)
        {
            if (a==1) // printa resultados do Insertion Sort
            {
                printf("\n      %dº INSERTION\n'%d' microssegundos (%ds)\n", L+1, interval1[L][1], interval1[L][0]);
                printf("'%d' transferências\n", transfer1[L]);
                SetConsoleOutputCP(CPAGE_DEFAULT);
            }
            
            else if (a==2) // printa resultados do Selection Sort
            {
                printf("\n      %dº SELECTION\n'%d' microssegundos (%ds)\n", L+1, interval2[L][1], interval2[L][0]);
                printf("'%d' transferências\n", transfer2[L]);
                SetConsoleOutputCP(CPAGE_DEFAULT);
            }

            else // printa resultados do Bubble Sort
            {
                printf("\n      %dº BUBBLE\n'%d' microssegundos (%ds)\n", L+1, interval3[L][1], interval3[L][0]);
                printf("'%d' transferências\n", transfer3[L]);
                SetConsoleOutputCP(CPAGE_DEFAULT);
            }
            Sleep(500);
        }
        Sleep(1000);
    }
}

    return 0;
}

/// Doc //////////////////////////////////////////////////////
/*
  -> Sessão 1 - Referente aos métodos de ordenação
      └ sub-sessão (1.1): Bubble sort;
      └ sub-sessão (1.2): Selection sort;
      └ sub-sessão (1.3): insertion sort.

  -> Sessão 2 - Referente ao preenchimento dos vetores
      └ sub-sessão (2.1): preenche um vetor e disposiciona os valores comforme a indicação;
      └ sub-sessão (2.2): printa os valores de um vetor.
SA
  -> Sessão Main - Método principal
      └ sub-sessão (Main.1): responsável pela criação das variáveis e pelas defições dos seletores ;
      └ sub-sessão (Main.2): loop responsável pelo preenchimento dos vetores;
      └ sub-sessão (Main.3): loop usado para recuperar o maior número de 'sizes' e setor destinado para a criação 
                                das matrizes principais.
      └ sub-sessão (Main.4): responsável por zerar os valores das variáveis transfer e pela impressão dos vetores;
      └ sub-sessão (Main.5): printa um determinado vetor antes da ordenação; 
      └ sub-sessão (Main.6): responsável pelo acionamento de todas as ordenações, contendo
                                um laço de três repetições, onde o mesmo executa outro loop
                                que servirá para selecionar as linhas de cada matriz. 
	                            O mesmo também medirá o tempo e os passos de cada ordenação;
      └ sub-sessão (Main.7): printa um determinado vetor após a ordenação; 
      └ sub-sessão (Main.8): printa os resultados dos processos de todas as ordenações.
  
  -> O simbolo '***' representa trechos que deverão ser atualizados futuramente.
*/