/************************************/
/* Aluno: Robson Santana Soares     */
/* ADS: Linguagem de Programação    */
/* Profa. Eliane                    */
/************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void visualizacaoDeOpcoesParaPrefeito(); // mostra os candidatos a prefeito
void visualizacaoDeOpcoesParaVereador(); // mostra os candidatos a vereador

void contagemDeVotos(int *, int); // conta os votos de candidatos a prefeito e a vereador

void totalizacao(int, int); // totaliza os votos, mostra informações da eleição e quem venceu

int confirmacaoDeVoto(char *, char *, char *); 
int verificacaoDoVoto(char *);

int candidatoParaPrefeitoVencedor(); 
int candidatoParaVereadorVencedor();

int candidatoParaPrefeito[6]; // variavel global
int candidatoParaVereador[6]; 

int main(void)
{
    
    int numeroDeEleitores;
    int votoParaPrefeito, votoParaVereador;
    int codigo;
    int confirma;
    int confirmaV, confirmaP;
    int continua;

    char Sim;
    char verificacaoDeOutroEleitor;
    char votoPrefeito;
    char votoVereador;

    for(int i = 0; i <= 6; i++)
    {
        candidatoParaPrefeito[i] = 0;
        candidatoParaVereador[i] = 0;
    }

    printf("Urna para votacao em candidatos a prefeito e a vereador");

    printf("\n\n\t\tIDENTIFICACAO DA URNA ELETRONICA");
    
    printf("\n\nCodigo de Identificacao da Urna Eletronica......................: ");
    scanf("%d", &codigo);

    printf("\nPor favor, insira o numero de eleitores desta zona eleitoral....: ");
    scanf("%d", &numeroDeEleitores);
    
    do
    {
        do
        {
            visualizacaoDeOpcoesParaPrefeito();

            printf("\n Caro eleitor, por favor, digite a sigla do candidato a prefeito no qual deseja votar: ");       
            scanf(" %s", &votoPrefeito); 
            votoParaPrefeito = verificacaoDoVoto(&votoPrefeito);

            visualizacaoDeOpcoesParaVereador();

            printf("\n Caro eleitor, por favor, digite a sigla do candidato a vereador no qual deseja votar: ");       
            scanf(" %s", &votoVereador);

            votoParaVereador = verificacaoDoVoto(&votoVereador);

            switch (votoParaPrefeito)
            {
                case 1:
                    confirma = confirmacaoDeVoto("Joao", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 0);
                    break;
                case 2:
                    confirma = confirmacaoDeVoto("Flavio", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 1);
                    break;
                case 3:
                    confirma = confirmacaoDeVoto("Claudio", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 2);
                    break;
                case 4:
                    confirma = confirmacaoDeVoto("Josefa", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 3);
                    break;
                case 5:
                    confirma = confirmacaoDeVoto("Branco", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 4);
                    break;
                case 6:
                    confirma = confirmacaoDeVoto("Nulo", &Sim, "Prefeito");
                    if(confirma == 1)
                        contagemDeVotos(candidatoParaPrefeito, 5);
                    break;
            }      
            
            switch (votoParaVereador)
            {
                case 1: 
                    confirma = confirmacaoDeVoto("Jose", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 0);
                    break;
                case 2:
                    confirma = confirmacaoDeVoto("Ronaldo", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 1);
                    break;
                case 3:
                    confirma = confirmacaoDeVoto("Renata", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 2);
                    break;
                case 4:
                    confirma = confirmacaoDeVoto("Mauricio", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 3);
                    break;
                case 5:
                    confirma = confirmacaoDeVoto("Branco", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 4);
                    break;
                case 6:
                    confirma = confirmacaoDeVoto("Nulo", &Sim, "Vereador");
                    if(confirma == 1)
                    contagemDeVotos(candidatoParaVereador, 5);
                    break;
            }      
        } while (Sim != 's');
        printf("\nComecar outra votacao? (s/n)..........................................: ");
        scanf(" %c", &verificacaoDeOutroEleitor);
        
    } while(verificacaoDeOutroEleitor != 'n');
    
    totalizacao(codigo, numeroDeEleitores);

    return 0;
}


void visualizacaoDeOpcoesParaPrefeito()
{
    printf("\n\n\n\t   |Lista de candidatos a prefeito|");
    printf("\n_____________________________________________________\n");
    printf("\n| Partido - PSD   | Candidato 1: Joao    | Sigla: C1 |");
    printf("\n| Partido - PTB   | Candidato 2: Flavio  | Sigla: C2 |");
    printf("\n| Partido - PP    | Candidato 3: Claudio | Sigla: C3 |");
    printf("\n| Partido - Verde | Candidato 4: Josefa  | Sigla: C4 |");
    printf("\n|         -       |       5 - Branco     | Sigla: VB |");
    printf("\n|         -       |       6 - Nulo       | Sigla: VN |");
    printf("\n_____________________________________________________\n");
}

void visualizacaoDeOpcoesParaVereador()
{
    printf("\n\n\n\t   |Lista de candidatos a vereador|");
    printf("\n_______________________________________________________\n");
    printf("\n| Partido - PT    | Candidato 1: Jose      | Sigla: C1 |");
    printf("\n| Partido - PCB   | Candidato 2: Ronaldo   | Sigla: C2 |");
    printf("\n| Partido - PSL   | Candidato 3: Renata    | Sigla: C3 |");
    printf("\n| Partido - Verde | Candidato 4: Mauricio  | Sigla: C4 |");
    printf("\n|         -       |       5 - Branco       | Sigla: VB |");
    printf("\n|         -       |       6 - Nulo         | Sigla: VN |");
    printf("\n_______________________________________________________\n");
}

int confirmacaoDeVoto(char *nome, char *resposta, char *cargo)
{
    char confirmacao;
    int saida;
    
    printf("\nVoce votou em \"%s\" para %s, deseja confirmar? (s/n).....: ", nome, cargo);
    
    scanf(" %c", &confirmacao);
    if(tolower(confirmacao) == 's')
    {
        *resposta = 's';
        saida = 1;
    }
    else
    {
        *resposta = 'n';
        saida = 0;
    }
    
    return saida;
}

int verificacaoDoVoto(char *sigla)
{
    int voto;

    if((strcmp(sigla, "C1") == 0))
        voto = 1;
    else if(strcmp(sigla, "C2") == 0) 
        voto = 2;
    else if(strcmp(sigla, "C3") == 0)  
        voto = 3;
    else if(strcmp(sigla, "C4") == 0)
        voto = 4;
    else if(strcmp(sigla, "VB") == 0)  
        voto = 5;
    else if(strcmp(sigla, "VN") == 0)  
        voto = 6;
            
    return voto;
}


void contagemDeVotos(int *voto, int indice)
{  
    voto[indice] += 1;
}

void totalizacao(int codigo, int numeroDeEleitores)
{
    int soma = 0, somaT;
    int prefeitoVencedor, vereadorVencedor;
    char *nomeDoPrefeito[25];
    char *nomeDoVereador[25];


    system("pause");
    system("cls");

    for (int i = 0; i < 6; i++)
        soma += candidatoParaPrefeito[i];
    
    somaT = (soma > numeroDeEleitores) ? 0 : abs(soma - numeroDeEleitores);

    prefeitoVencedor = candidatoParaPrefeitoVencedor();    
    switch(prefeitoVencedor)
    {
        case 0:
            *nomeDoPrefeito = "Joao";
            break;
        case 1:
            *nomeDoPrefeito = "Flavio";
            break;
        case 2:
            *nomeDoPrefeito = "Claudio";
            break;
        case 3:
            *nomeDoPrefeito = "Josefa";
            break;
        default:
            *nomeDoPrefeito = "ERRO";
            break;
    }
    
    vereadorVencedor = candidatoParaVereadorVencedor();
    switch(vereadorVencedor)
    {
        case 0:
            *nomeDoVereador = "Jose";
            break;
        case 1:
            *nomeDoVereador = "Ronaldo";
            break;
        case 2:
            *nomeDoVereador = "Renata";
            break;
        case 3:
            *nomeDoVereador = "Mauricio";
            break;
        default:
            *nomeDoVereador = "ERRO";
            break;
    }


    printf("\n\n\n\t\t\t   | Informacoes da eleicao |");
    printf("\n_______________________________________________________________________________________\n");
    printf("\n Identificacao da Secao e Zona Eleitoral...: A                                       ");
    printf("\n Codigo da Urna Eletronica.................: %d                                       ", codigo);
    printf("\n Numero de eleitores presentes.............: %d                                       ", soma);
    printf("\n Numero de eleitores que faltaram..........: %d                                       ", somaT);
    printf("\n_______________________________________________________________________________________\n");

    printf("\n\n\n\t\t  | Lista de votos de candidatos a prefeito |");
    printf("\n_______________________________________________________________________________________\n");
    printf("\n Partido - PSD           | Candidato 1: Joao     | Sigla: C1 | Numero de votos: %d ", candidatoParaPrefeito[0]);
    printf("\n Partido - PTB           | Candidato 2: Flavio   | Sigla: C2 | Numero de votos: %d ", candidatoParaPrefeito[1]);
    printf("\n Partido - PP            | Candidato 3: Claudio  | Sigla: C3 | Numero de votos: %d ", candidatoParaPrefeito[2]);
    printf("\n Partido - Verde         | Candidato 4: Josefa   | Sigla: C4 | Numero de votos: %d ", candidatoParaPrefeito[3]);
    printf("\n         -               |       5 - Branco      | Sigla: VB | Numero de votos: %d ", candidatoParaPrefeito[4]);
    printf("\n         -               |       6 - Nulo        | Sigla: VN | Numero de votos: %d ", candidatoParaPrefeito[5]);
    printf("\n_______________________________________________________________________________________\n");
  
    printf("\n\n\n\t\t   | Lista de votos de candidatos a vereador |");
    printf("\n_______________________________________________________________________________________\n");
    printf("\n Partido - PT            | Candidato 1: Jose      | Sigla: C1 | Numero de votos: %d ", candidatoParaVereador[0]);
    printf("\n Partido - PCB           | Candidato 2: Ronaldo   | Sigla: C2 | Numero de votos: %d ", candidatoParaVereador[1]);
    printf("\n Partido - PSL           | Candidato 3: Renata    | Sigla: C3 | Numero de votos: %d ", candidatoParaVereador[2]);
    printf("\n Partido - Verde         | Candidato 4: Mauricio  | Sigla: C4 | Numero de votos: %d ", candidatoParaVereador[3]);
    printf("\n         -               |        5 - Branco      | Sigla: VB | Numero de votos: %d ", candidatoParaVereador[4]);
    printf("\n         -               |        6 - Nulo        | Sigla: VN | Numero de votos: %d ", candidatoParaVereador[5]);
    printf("\n_______________________________________________________________________________________\n");

    printf("\n\n\n\t\t   | Total de votos por partido |");
    printf("\n_______________________________________________________________________________________\n");
    printf("\n Partido - PT                                     | Numero de votos: %d ", candidatoParaVereador[0]);
    printf("\n Partido - PCB                                    | Numero de votos: %d ", candidatoParaVereador[1]);
    printf("\n Partido - PSL                                    | Numero de votos: %d ", candidatoParaVereador[2]);
    printf("\n Partido - Verde                                  | Numero de votos: %d ", candidatoParaVereador[3] + candidatoParaPrefeito[3]);
    printf("\n Partido - PP                                     | Numero de votos: %d ", candidatoParaPrefeito[2]);
    printf("\n Partido - PTB                                    | Numero de votos: %d ", candidatoParaPrefeito[1]);
    printf("\n Partido - PSD                                    | Numero de votos: %d ", candidatoParaPrefeito[0]);
    printf("\n_______________________________________________________________________________________\n");

    printf("\n\n\n\t\t\t\t   | Candidatos vencedores |");
    printf("\n_______________________________________________________________________________________\n");
    printf("\n Candidato a prefeito vencedor: %s                                        ", *nomeDoPrefeito);
    printf("\n Candidato a vereador vencedor: %s                                        ", *nomeDoVereador);
    printf("\n_______________________________________________________________________________________\n");
}


int candidatoParaPrefeitoVencedor()
{
    int vencedor = 0;

    for(int j = 0; j < 6; j++)
        if(candidatoParaPrefeito[j] >= candidatoParaPrefeito[vencedor])
            vencedor = j;

    return vencedor;
}

int candidatoParaVereadorVencedor()
{
    int vencedor = 0;
    int i = 0;

        
  for(int i = 0; i < 6; i++)
    if(candidatoParaVereador[i] > candidatoParaVereador[vencedor])
      vencedor = i;

    return vencedor;
}