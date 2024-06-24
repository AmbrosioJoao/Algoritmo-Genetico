#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//****************************************************//
//NOTAS:
//Função ideal: f(x*) = -0,3 + 0,1x - 0,5x^2 + 0,4x^3





//****************************************************//

//VARIAVEIS GLOBAIS



void comparar(float a_variavel = -5, float b_variavel = -5, float c_variavel = -5, float d_variavel = -5) {

    float RMSE = 2, RMSE_atual = 2; //Erro médio quadrático
    int n = 160; //Número de Amostras

    FILE* file; //Ponteiro apontando para o arquivo
    errno_t err; //Variavel compativel com fopen_s

    err = fopen_s(&file, "Dados.txt", "w"); // Abre o arquivo;



    if (err != 0) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }

    //Essa variável x seria a faixa de valores do eixo.
    for (int x = -10; x < 10; x++) {

        fprintf(file, "Geração %d\n", x + 81);//escrever string

        //Numero de Gerações
        for (int i = 0; i < 160; i++) {
            RMSE_atual = sqrt(pow((-0.3) + (0.1) * x + (-0.5) * pow(x, 2) + (0.4) * pow(x, 3) -
                a_variavel - b_variavel * x - c_variavel * pow(x, 2) - d_variavel * pow(x, 3), 2) / n);
            if (RMSE_atual < RMSE) {
                RMSE = RMSE_atual;
            }

            fprintf(file, "%d RMSE: %f \n", i + 1, RMSE);

            a_variavel = a_variavel + 1.5; //Incrementa os valores
            b_variavel = b_variavel + 1.5;
            c_variavel = c_variavel + 1.5;
            d_variavel = d_variavel + 1.5;
        }
        a_variavel = -5; //Reseta os valores para a próxima geracao
        b_variavel = -5;
        c_variavel = -5;
        d_variavel = -5;
    }

    fflush(file); // Garante que os dados sejam escritos no arquivo
    fclose(file); // Fecha o arquivo
}


int main() {
    //VARIAVEIS
    float a_ideal = -0.3; //Conjunto ideal
    float b_ideal = 0.1;
    float c_ideal = -0.5;
    float d_ideal = 0.4;

    float a_variavel = -5; //Fatores que irão variar
    float b_variavel = -5;
    float c_variavel = -5;
    float d_variavel = -5;


    // comparar(a_variavel,b_variavel,c_variavel,d_ideal);

    return 0;

}
