#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//NOTAS:
//Função ideal: f(x*) = -0,3 + 0,1x - 0,5x^2 + 0,4x^3

int main()
{
    //VARIAVEIS
    float a_ideal = -0.3; //conjunto ideal
    float b_ideal = 0.1;
    float c_ideal = -0.5;
    float d_ideal = 0.4;

    float a_variavel; //fatores que irão variar
    float a_variavel;
    float a_variavel;
    float a_variavel;

    int x; // faixa de valores

    FILE* file; //ponteiro apontando para o arquivo

    file = fopen_s(&file, "Dados.txt", "w"); // Abre o arquivo;


    if (file == NULL) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }


    return 0;
}
