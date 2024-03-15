#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

struct Funcionario {
    char nome[100];
    char cargo[100];
    float salario_base;
    float beneficios;
    float descontos;
};

struct Loja {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios;
};

void cadastrarFuncionario(struct Loja *loja) {
    if (loja->numFuncionarios < MAX_FUNCIONARIOS) {
        struct Funcionario *funcionario = &loja->funcionarios[loja->numFuncionarios];
        printf("Digite o nome do funcionario: ");
        scanf("%s", funcionario->nome);
        printf("Digite o cargo do funcionario: ");
        scanf("%s", funcionario->cargo);
        printf("Digite o salario base do funcionario: ");
        scanf("%f", &funcionario->salario_base);
        printf("Digite os beneficios do funcionario: ");
        scanf("%f", &funcionario->beneficios);
        printf("Digite os descontos do funcionario: ");
        scanf("%f", &funcionario->descontos);
        loja->numFuncionarios++;
    } else {
        printf("Limite de funcionarios atingido.\n");
    }
}

void imprimirFuncionario(const struct Funcionario *funcionario) {
    printf("Nome: %s\n", funcionario->nome);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salario base: %.2f\n", funcionario->salario_base);
    printf("Beneficios: %.2f\n", funcionario->beneficios);
    printf("Descontos: %.2f\n", funcionario->descontos);
    float salario_liquido = funcionario->salario_base + funcionario->beneficios - funcionario->descontos;
    printf("Salario liquido: %.2f\n", salario_liquido);
}

void calcularMediaSalarial(const struct Loja *loja) {
    float total_salarios = 0;
    for (int i = 0; i < loja->numFuncionarios; i++) {
        total_salarios += loja->funcionarios[i].salario_base;
    }
    float media_salarial = total_salarios / loja->numFuncionarios;
    printf("Media Salarial da Loja: %.2f\n", media_salarial);
}

void encontrarMaiorSalario(const struct Loja *loja) {
    float maior_salario = loja->funcionarios[0].salario_base;
    int indice_maior_salario = 0;
    for (int i = 1; i < loja->numFuncionarios; i++) {
        if (loja->funcionarios[i].salario_base > maior_salario) {
            maior_salario = loja->funcionarios[i].salario_base;
            indice_maior_salario = i;
        }
    }
    printf("Funcionario com maior salario:\n");
    imprimirFuncionario(&loja->funcionarios[indice_maior_salario]);
}

int main() {
    struct Loja loja = { .numFuncionarios = 0 };
    int opcao;

    do {
        printf("\n1. Cadastrar Funcionario\n");
        printf("2. Exibir Dados dos Funcionarios\n");
        printf("3. Exibir Media Salarial da Loja\n");
        printf("4. Exibir Funcionario com Maior Salario\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(&loja);
                break;
            case 2:
                for (int i = 0; i < loja.numFuncionarios; i++) {
                    printf("\nFuncionario %d:\n", i + 1);
                    imprimirFuncionario(&loja.funcionarios[i]);
                }
                break;
            case 3:
                calcularMediaSalarial(&loja);
                break;
            case 4:
                if (loja.numFuncionarios > 0) {
                    encontrarMaiorSalario(&loja);
                } else {
                    printf("Nenhum funcionario cadastrado.\n");
                }
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 5);

    return 0;
}
