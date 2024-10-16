#include <stdio.h>
#include <stdbool.h>

int dinheiro[7] = {100, 50, 20, 10, 5, 2, 1};

void exibirCedulas(int soma[]) {
    printf("Cédulas disponíveis no caixa:\n");
    for (int i = 0; i < 7; i++) {
        printf("R$ %d: %d\n", dinheiro[i], soma[i]);
    }
    printf("\n");
}

bool realizarSaque(int valor, int soma[]) {
    int usadas[7] = {0};  
    int dinheiroRestante = valor;

    for (int i = 0; i < 7; i++) {
        while (dinheiroRestante >= dinheiro[i] && soma[i] > 0) {
            usadas[i]++;
            soma[i]--;
            dinheiroRestante -= dinheiro[i];
        }
    }

    if (dinheiroRestante != 0) {
        printf("Saque de R$ %d não pode ser realizado. Cedulas insuficientes.\n", valor);
        

        for (int i = 0; i < 7; i++) {
            soma[i] += usadas[i];
        }
        return false;
    }

    printf("Saque realizado com sucesso! Cédulas utilizadas:\n");
    for (int i = 0; i < 7; i++) {
        if (usadas[i] > 0) {
            printf("R$ %d: %d\n", dinheiro[i], usadas[i]);
        }
    }
    return true;
}

void realizarDeposito(int soma[]) {
    printf("Digite a soma de cédulas a depositar:\n");
    for (int i = 0; i < 7; i++) {
        int qtd;
        printf("R$ %d: ", dinheiro[i]);
        scanf("%d", &qtd);
        soma[i] += qtd;
    }
    printf("Depósito realizado com sucesso!\n");
}

int main() {
    int soma[7];  

    printf("Digite a soma inicial de cédulas no caixa:\n");
    for (int i = 0; i < 7; i++) {
        printf("R$ %d: ", dinheiro[i]);
        scanf("%d", &soma[i]);
    }

    int operacao;
    while (1) {
        printf("\nEscolha a operação: 0 - Saque, 1 - Depósito, -1 - Encerrar\n");
        scanf("%d", &operacao);

        if (operacao == -1) {
            printf("Encerrando o programa...\n");
            break;
        } else if (operacao == 0) {
            int valor;
            printf("Digite o valor a ser sacado: ");
            scanf("%d", &valor);
            if (valor <= 0) {
                printf("Valor inválido para saque.\n");
            } else {
                realizarSaque(valor, soma);
            }
        } else if (operacao == 1) {
            realizarDeposito(soma);
        } else {
            printf("Operação inválida. Tente novamente.\n");
        }

        
        exibirCedulas(soma);
    }

    return 0;
}