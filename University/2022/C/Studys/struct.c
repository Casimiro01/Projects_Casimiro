#include <stdio.h>
int main (void)
{
    typedef struct ficha_aluno
    {
        char nome[40];
        int num;
        float nota;

    };

    struct ficha_aluno aluno;

    printf("\n ---- Cadastro de aluno  ----\n");

    printf("Nome do aluno ......: ");
    fgets(aluno.nome, 40, stdin);

    printf("DIgite o número do aluno: ");
    scanf("%d", &aluno.num);

    printf("Informe a nota do aluno: ");
    scanf("%f", &aluno.nota);

    printf("\n\n ---- Lendos os dados da struct ---- \n\n");
    printf("Nome........: %s", aluno.nome);
    printf("Numero......: %d \n", aluno.num);
    printf("Nota........: %2.f \n", aluno.nota);

    
    return(0);
}
