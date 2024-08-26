#include <stdint.h>
#include <stdio.h>

///////////////////////
/*   ENTRY POINT      /
/PROGRAMA COMEÇA AQUI*/
///////////////////////
int main() {
  // std::cout << "Hello world!" << "\n"; também podemos substituir std::endl
  // por \n

  printf("TIPOS EM C++:\n");
  // inteiras
  // tipos inteiros assinalados em sistemas 64bits(x86_64 e etc)
  // é sempre bom saber qual é o tamanho de uma inteira da CPU, pois todos
  // os tipos se derivam dela
  // int: 32 bits
  // EX:
  int minhaInt = 190;
  // short: 16 bits; tambem serve como modificador para inteiros e caracteres.
  // EX:
  short minhaShort = 255;
  // EX:
  // long: 64 bits; tambem serve como modificador para inteiros. EX:long long
  // vira 128 bits
  long minhaLong = 122467867;

  // unsigned é o modificador para virar uma inteira não assinalada
  unsigned int minhaIntNaoAssinalada = -190; // overflow

  // print de variaveis. Podemos colocar quase n estruturas e tipos de dados
  // aqui aqui.
  printf(
      "unsigned int: %u |tamanho em bytes: %u\nint: %i |tamanho em bytes: "
      "%u\nshort: %i |tamanho em bytes : %u\nlong: %i |tamanho em bytes: %u\n",
      minhaIntNaoAssinalada, sizeof(minhaIntNaoAssinalada), minhaInt,
      sizeof(minhaInt), minhaShort, sizeof(minhaShort), minhaLong,
      sizeof(minhaLong));

  // tipos de ponto flutuante
  // float: 32 bits
  float minhaFloat = 29.98;
  // double: 64 bits
  double minhaDouble = 1999999.98;

  printf("float: %f"
         "|tamanho em bytes: %i\n"
         "double: %d"
         "|tamanho em bytes: %i\n",
         minhaFloat, sizeof(minhaFloat), minhaDouble, sizeof(minhaDouble));

  // characteres
  // menor representação de um dado que pode conter um caractere ASCII
  // char: 8 bits
  char minhaChar = 'a'; // aspas simples para char
  // por baixo, é apenas uma inteira de 8 bits

  // podemos fazer coisas interessante, já que seu uso pode depender do contexto
  int convercao = minhaChar;
  unsigned char oitoBits =
      255; // usando unsigned como armazenamento de 8 bits não assinalados

  printf("char: %c"
         "|tamanho em bytes: %i\n"
         "convercao: %i\n",
         minhaChar, sizeof(minhaChar), convercao);

  //////////////////////
  /*ESTRUTURAS BASICAS*/
  //////////////////////

  printf("ESTRUTURAS BASICAS DO C:\n");

  // condicionais
  // estilo C com if,else, if else e switch(vamos ver este depois)
  int x = 10;
  short minhaBool = 1;
  // bools não exitem fora do header <stdbool.h>, sua implementação
  // depende da biblioteca padrão sendo utilisada
  if (minhaBool) {
    printf("no if \n");
  } else if (x < 9) {
    printf("no else if \n");
  } else {
    printf("no else \n");
  }

  // arrays
  // arrays em c e em c++ são estruturas lineares estaticas
  // elas representam dados agrupados em memoria de forma sequencial
  int meuArray[5] = {1, 2, 3, 4, 5};
  char minhaString[7] = {
      'g', 'u', 's', 't',
      'a', 'v', 'o'}; // string estilo C, vamos revisitar elas em ponteiros
  printf("string %s\n", minhaString);

  // estruturas de repetição

  // while
  // se repete enquanto a condição for verdadeira
  int i = 0;
  while (1) // comparação
  {
    printf("%i|", meuArray[i]);
    if (meuArray[i] == 5) {
      break; // Sai de uma estrutura de repetição
      // podemos usar a palavra reservada "continue" para pular uma iteração
    }
    i++;
  }
  printf("\n");

  // for
  // se repete até a condição for verdadeira
  // NOTA: tenha cuidado para não passar do indice final de um array, ja que
  // arrays não contem dados que informão seu tamanho. Se você passar de um
  // indice, acontecera um buffer overflow:
  // https://en.wikipedia.org/wiki/Buffer_overflow
  for (int j = 0; j < 7; j++) {
    // iterando uma string
    printf("%c\n", minhaString[j]);
  }
  // ADDEDDUM
  // qualificadores:
  // volatile
  // marca uma variavel para não ser optimizada pelo o compilador
  //"util para mapear hardware" mas implementação dependen do compilador, pode
  // ou não funcionar foi depreciada no C++20
  volatile int v = 90;

  // const
  // marca uma variavel como constante, onde seu valor ou lugar de referencia
  // não pode mudar não funciona direito no C, por causa de ponteiros e
  // comportamento não definido, aqui o compilador consegue capturar usos
  // indevidos
  const int c = v;

  // mutable
  // indica que a variavel pode ser modificada por funções constantes
  // mutable int m = c; -> veremos seu uso em multithreading

  return 0; // fala pro sistema operacional que o programa acabou sem erros,
            // qualquer valor além de zero é considerado um erro
}
