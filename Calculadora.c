// Luis Gustavo Melo Freire
// Email:lgmf@cesar.school
//data 30/08
// 1 Questao inicializada em 19:30
// letra a b c terminadas em 20:13
// letra d terminda de 22:00,
// 2 questao iniciada de 22:01
//2 questao terminada de 22:23,
//3 questao assim como organizar tudo da entrega terminada em 23:34

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcoes de conversao para tipos inteiros
void converterParaBinario(int num);
void converterParaOctal(int num);
void converterParaHexadecimal(int num);
void converterParaBCD(int num);
void converterParaComplemento2(int num);

void converterParaFloat(float num);
void converterParaDouble(double num);
void mostrarBits(unsigned int num, int bits);

int main() {
  int opcao;
  int num;
  float numFloat;
  double numDouble;

  printf("Calculadora\n");
  printf("Digite um numero decimal (int): ");
  if (scanf("%d", &num) != 1) {
    printf("Erro ao ler o numero.\n");
    return 1;
  }

  printf("\nEscolha o tipo de conversao:\n");
  printf("1. Converter para Binario\n");
  printf("2. Converter para Octal\n");
  printf("3. Converter para Hexadecimal\n");
  printf("4. Converter para BCD\n");
  printf("5. Converter para Complemento a 2 (16 bits)\n");
  printf("6. Converter para Float\n");
  printf("7. Converter para Double\n");
  printf("Digite a opcao desejada (1-7): ");
  if (scanf("%d", &opcao) != 1) {
    printf("Erro ao ler a opcao.\n");
    return 1;
  }

  switch (opcao) {
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
  case 6:
    printf("Digite um numero real com decimal (float): ");
    if (scanf("%f", &numFloat) != 1) {
      printf("Erro ao ler o numero float.\n");
      return 1;
    }
    converterParaFloat(numFloat);
    break;
  case 7:
    printf("Digite um numero real com decimal (double): ");
    if (scanf("%lf", &numDouble) != 1) {
      printf("Erro ao ler o numero double.\n");
      return 1;
    }
    converterParaDouble(numDouble);
    break;
  default:
    printf("Opcao invalida!\n");
    break;
  }

  printf("Pressione Enter para sair...");
  getchar(); // Captura o Enter final
  getchar(); // Espera um segundo Enter para evitar o fechamento imediato
  return 0;
}

void converterParaBinario(int num) {
  printf("Passo 1: Convertendo %d para binario:\n", num);
  printf("Dividindo sucessivamente %d por 2 e anotando os restos:\n", num);

  int binario[64];
  int i = 0;

  while (num > 0) {
    binario[i] = num % 2;
    printf("%d / 2 = %d com resto %d\n", num, num / 2, binario[i]);
    num = num / 2;
    i++;
  }

  printf("Numero em binario: ");
  for (int j = 0; j < i; j++) {
    printf("%d", binario[i - j - 1]);
  }
  printf("\n");
}

void converterParaOctal(int num) {
  printf("Passo 2: Converte %d para octal:\n", num);
  printf("Dividindo sucessivamente o %d por 8 e anotando os restos:\n", num);

  if (num == 0) {
    printf("Numero em octal: 0\n");
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
  printf("Numero em octal: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", octal[j]);
  }
  printf("\n");
}

void converterParaHexadecimal(int num) {
  printf("Passo 3: Converte %d para hexadecimal:\n", num);
  printf("Dividindo sucessivamente por 16 e anotando os restos:\n");

  if (num == 0) {
    printf("Numero em hexadecimal: 0\n");
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
  printf("Numero em hexadecimal: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hexa[j]);
  }
  printf("\n");
}

void converterParaBCD(int num) {
  printf("Passo 4: Converte %d para BCD:\n", num);
  printf("Convertendo cada digito do numero para sua representacao BCD:\n");

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

  printf("Numero em BCD: ");
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

  printf("Numero em complemento a 2 (16 bits): ");
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (valor >> i) & 1);
  }
  printf("\n");
}

void mostrarBits(unsigned int num, int bits) {
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
}

void converterParaFloat(float num) {
  unsigned int bits;
  memcpy(&bits, &num, sizeof(bits));

  unsigned int sinal = (bits >> 31) & 1;
  unsigned int expoente = (bits >> 23) & 0xFF;
  unsigned int fracao = bits & 0x7FFFFF;

  int vies = expoente - 127;

  printf("Numero em float: %f\n", num);
  printf("Bits de sinal: %u\n", sinal);
  printf("Bits do expoente (bruto): ");
  mostrarBits(expoente, 8);
  printf("\nExpoente com vies: %d\n", vies);
  printf("Bits da fracao: ");
  mostrarBits(fracao, 23);
  printf("\n");
}

void converterParaDouble(double num) {
  unsigned long long bits;
  memcpy(&bits, &num, sizeof(bits));

  unsigned long long sinal = (bits >> 63) & 1;
  unsigned long long expoente = (bits >> 52) & 0x7FF;
  unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;

  int vies = expoente - 1023;

  printf("Numero em double: %lf\n", num);
  printf("Bits de sinal: %llu\n", sinal);
  printf("Bits do expoente (bruto): ");
  mostrarBits(expoente, 11);
  printf("\nExpoente com vies: %d\n");
  printf("Bits da fracao: ");
  mostrarBits(fracao, 52);
  printf("\n");
}
