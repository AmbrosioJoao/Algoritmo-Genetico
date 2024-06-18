#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//NOTAS:
//Função ideal: f(x*) = -0,3 + 0,1x - 0,5x^2 + 0,4x^3

int main()
{
    //VARIAVEIS
    float a_ideal = -0.3; //Conjunto ideal
    float b_ideal = 0.1;
    float c_ideal = -0.5;
    float d_ideal = 0.4;

    float a_variavel= -5; //Fatores que irão variar
    float b_variavel= -5;
    float c_variavel= -5;
    float d_variavel= -5;

    int n = 160; //Número de Amostras
    float RMSE; //Erro médio quadrático

    char geracao[15];

    FILE *file; //Ponteiro apontando para o arquivo
    errno_t err; //Variavel compativel com fopen_s

    err = fopen_s(&file, "Dados.txt", "w"); // Abre o arquivo;


    if (err != 0) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }

  
    //Essa variável x seria a faixa de valores do eixo.
    for (int x = -80 ; x < 80; x++) {


        fprintf(file, "Geração %d\n", x + 81);//escrever string
   
        for (int i = 0; i < 160; i++) { 


            RMSE = sqrt(pow(a_ideal + b_ideal * x + c_ideal * pow(x, 2) + d_ideal * pow(x, 3) -
            a_variavel - b_variavel * x - c_variavel * pow(x, 2) - d_variavel * pow(x, 3), 2) / n);

            fprintf(file, "%d RMSE: %f \n",i+1,RMSE); //escreve teste no arquivo
            
            a_variavel + 0.1; //Incrementa os valores
            b_variavel + 0.1;
            c_variavel + 0.1;
            d_variavel + 0.1;
        }
        a_variavel = 0; //Reseta os valores para a próxima geracao
        b_variavel = 0;
        c_variavel = 0;
        d_variavel = 0;

    }


    //TESTE ARTHUR
    return 0;
}
