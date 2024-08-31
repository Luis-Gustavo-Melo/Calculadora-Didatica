//Luis Gustavo Melo Freire
//1 Questao inicializada em 19:30 letra a b c terminadas em 20:13, depois de uma pausa voltei para tentar fazer a de BCD so consegui terminar de 22:00, que foi quando criei o github e fiz 1 commit
//2 Questão inicalizada em 22:00, terminada em 22:30,


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converterParaBinario(int num);
void converterParaOctal(int num);
void converterParaHexadecimal(int num);
void converterParaBCD(int num);
void converterParaComplemento2(int num);

int main() {
    int num, opcao;

    printf("Calculadora\n");
    printf("Digite um número decimal: ");
    scanf("%d", &num);

    printf("\nEscolha o tipo de conversão:\n");
    printf("1. Converter para Binário\n");
    printf("2. Converter para Octal\n");
    printf("3. Converter para Hexadecimal\n");
    printf("4. Converter para BCD\n");
    printf("5. Converter para Complemento a 2 (16 bits)\n");
    printf("Digite a opção desejada (1-5): ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            converterParaBinario(num);
            break;
        case 2:
            converterParaOctal(num);
            break;
        case 3:
            converterParaHexadecimal(num);
            break;
        case 4:
            converterParaBCD(num);
            break;
        case 5:
        converterParaComplemento2(num); 
        break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}

void converterParaBinario(int num) {
    printf("Passo 1: Convertendo %d para binário:\n", num);
    printf("Dividindo sucessivamente %d por 2 e anotando os restos:\n", num);

    int binario[64];
    int i = 0;

    while (num > 0) {
        binario[i] = num % 2;
        printf("%d / 2 = %d com resto %d\n", num, num / 2, binario[i]);
        num = num / 2;
        i++;
    }

    printf("Número em binário: ");
    for (int j = 0; j < i; j++) {
        printf("%d", binario[i - j - 1]);
    }
    printf("\n");
}

void converterParaOctal(int num) {
    printf("Passo 2: Converte %d para octal:\n", num);
    printf("Dividindo sucessivamente o %d por 8 e anotando os restos:\n", num);

    if (num == 0) {
        printf("Número em octal: 0\n");
        return;
    }

    int octal[64];
    int i = 0;

    while (num > 0) {
        octal[i] = num % 8;
        printf("%d / 8 = %d com resto %d\n", num, num / 8, octal[i]);
        num = num / 8;
        i++;
    }
    printf("Inverte a ordem dos restos:\n");
    printf("Número em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void converterParaHexadecimal(int num) {
    printf("Passo 3: Converte %d para hexadecimal:\n", num);
    printf("Dividindo sucessivamente por 16 e anotando os restos:\n");

    if (num == 0) {
        printf("Número em hexadecimal: 0\n");
        return;
    }

    char hexa[64];
    int i = 0;

    while (num > 0) {
        int resto = num % 16;
        if (resto < 10)
            hexa[i] = resto + 48; 
        else
            hexa[i] = resto + 55; 
        printf("%d / 16 = %d com resto %d (%c)\n", num, num / 16, resto, hexa[i]);
        num = num / 16;
        i++;
    }
    printf("Inverte a ordem dos restos:\n");
    printf("Número em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

void converterParaBCD(int num) {
    printf("Passo 4: Converte %d para BCD:\n", num);
    printf("Convertendo cada dígito do número para sua representação BCD:\n");

    if (num == 0) {
        printf("0000\n");
        return;
    }

    int temp = num;
    int numDigits = 0;
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }

    int digits[numDigits];
    int i = 0;
    while (num > 0) {
        digits[i] = num % 10;
        num /= 10;
        i++;
    }

    printf("Número em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        int digit = digits[j];
        for (int k = 3; k >= 0; k--) {
            printf("%d", (digit >> k) & 1);
        }
        if (j > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void converterParaComplemento2(int num) {
    printf("Passo 5: Converte %d para complemento a 2 (16 bits):\n", num);

    int bits = 16;
    unsigned short valor = num;

    if (num < 0) {
        valor = (unsigned short)(~(-num) + 1);
    }

    printf("Número em complemento a 2 (16 bits): ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (valor >> i) & 1);
    }
    printf("\n");
}
