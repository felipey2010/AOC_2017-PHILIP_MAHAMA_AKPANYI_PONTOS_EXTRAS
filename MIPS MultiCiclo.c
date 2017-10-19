#include <stdio.h>
#include <math.h>
#include <string.h>
#include<windows.h>

/*
    ALUNO: PHILIP MAHAMA AKPANYI
    DESCRICAO: UM PROGRAMA PARA MOSTRAR O FUNCIONAMENTO DE MULTI CICLO NO MIPS. O PROGRAMA PERMITE A ENTRADA DE DECIMAL E BINARIO
    DISCIPLINA: ARQUITETURA E ORGANIZACAO DE COMPUTADORES
    PROFESSOR: PROF. HERBERT OLIVEIRA ROCHA
*/



//Instrucoes de tipo R: 1
//Instrucoes do tipo J: 2
//Instrucoes do lw: 3
//Instrucoes de sw: 4
//Instrucoes de beq: 5

int opcode; // codigo de instrucoes de 1 a 5
int tipoEntrada; //Opcao de entrada binaria ou decimal
long long bin; //Entrada de numero binario

int inputOption(){
    printf("********ESCOLHE A ENTRADA********\n1-Binario\n2-Decimal\n0-Sair\nDigite:_");
    scanf("%d", &tipoEntrada);
    if(tipoEntrada == 1 || tipoEntrada == 2 || tipoEntrada == 0){
        return 1;
    }
    else{
        system("cls");
        printf("Escolha errada. Tente de novo!");
        Sleep(1000);
        inputOption();
    }
}

void menu(){
    if(tipoEntrada == 1){ //Entrada binaria do usuario
        printf("********ENTRADA BINARIA********\n");
        printf("0001-TIPO R\n0010-Tipo J\n0011-LW\n0100-SW\n0101-BEQ\n0110-Limpar tela\n0000-Sair\n");
        printf("ENTRADA:__");
        scanf("%lld", &bin);
        if(!verifiqueBin(bin))
            opcode = convBinDec(bin); //Chamando a funcao para converter o numero binario para decimal
        else
            printf("Numero nao binario!\n");
    }
    else if(tipoEntrada == 2){ //Entrada decimal do usuario
        printf("********ENTRADA DECIMAL********\n");
        printf("1-TIPO R\n2-Tipo J\n3-LW\n4-SW\n5-BEQ\n6-Limpar tela\n0-Sair\n");
        printf("ENTRADA:__");
        scanf("%d", &opcode);
    }
}

void buscaIns(){
    printf("\nBUSCA DA INSTRUCAO\n");
    printf("UALFonteA=0\nlouD=0\nUALFonteB=01\nUALOp=00\nFontPC=00\n");
}

void buscaReg(){
    printf("\nBUSCA EM REGISTRADORES\n");
    printf("UALFonteA=0\nUALFonteB=11\nUALOp=00\n");

    if(opcode == 1 || opcode == 2 || opcode ==5){
        if(opcode == 1)
            printf("\nTIPO R\nExecucao\nUALFonteA=1\nUALFonteB=00\nUALOp=10\nTermino de instrucao de tipo R\nRegDst=1\nEscReg\nMemParaReg=0\n");
        else if(opcode == 2)
            printf("TIPO J\nTermino de desvio incondicional\nPCEsc\nFontePC=10\n");
        else if(opcode == 5)
            printf("\nBEQ\nTermino de desvio condicional\nUALFonteA=1\nUALFonteB=00\nUALOp=01\nPCEscCond\nFontePC=01\n");
    }

    if(opcode == 3 || opcode == 4){
        printf("\nCALCULO DO ENDERECO DE MEMORIA\n");
        printf("UALFonteA=1\nUALFonteB=10\nUALOp=00\n");

        printf("\nACESSO A MEMORIA\n");

        if(opcode == 3)
            printf("Op-LW\nLerMem\nlouD=1\n\nPASSO DE ESCRITA\nEscReg\nRegDst=0\nMemParaReg=1");
        else if(opcode == 4)
            printf("Op-SW\nEscMem\nlouD=1\n");
    }
}

void check(){
    switch(opcode){
    case 1:
        buscaIns();
        buscaReg();
        break;
    case 2:
        buscaIns();
        buscaReg();
        break;
    case 3:
        buscaIns();
        buscaReg();
        break;
    case 4:
        buscaIns();
        buscaReg();
        break;
    case 5:
        buscaIns();
        buscaReg();
        break;
    case 6:
        system("cls");
        break;
    case 0:
        printf("\nSaindo...\n\n");
        break;
    }
    opcode = -1;
    printf("\n");
}
//Funcao para converter binarion em decimal
int convBinDec(long long n){
    int dec = 0, i = 0, resto;
    while (n!=0)
    {
        resto = n%10;
        n /= 10;
        dec += resto*pow(2,i);
        ++i;
    }
    return dec;
}

//Verificacao de numero binario
int verifiqueBin(long long n){
    int i;
    char str[8];

    itoa(n, str, 10); //Converter o numero binario para string

    for (i = 0; i < strlen(str); i++){
        if ((str[i] - '0' != 1 ) && (str[i] - '0' != 0)){
            return 1;
        }
    }
    return 0;
}

int main(){
    while(1){
        int n = inputOption();
        if(n){
            menu();
            check();
            if(opcode == 0 || tipoEntrada == 0){
                break;
            }
        }
    }
    return 0;
}
