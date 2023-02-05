#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Projeto calculadora em C.
//Estudante Rafaell Marques Spindola.

//Protótipo da função.
float RecebeNum1(int y,float num3);//Função que recebe o numero 1.
int EscolhaTipo(float num1, float num2);//Função que recebe o tipo da operação matemática.
float CalculoTotal(int OP,float num1,float num2);//Função que distribui valores para realizar a conta.
int DecisaoCalc(void);//Função de decisão, encerrar ou continuar o programa.

int main(){//Função principal main.
//Numero 1 - Armazena o primeiro valor digitado pelo usuario.
//Numero 2 - Armazena o segundo valor digitado pelo usuario.
//Numero 3 - Armazena o resultado da operação.
float num1,num2,num3=0;
// 'OP' Recebe o número correspondente ao tipo de operação matematica.
// 'Y' Informa pra função como armazenar o numero 1.
// 'X' Diz pra função main quando continuar/terminar o programa.
// 'Sinal' É o simbolo da operação em decimal, tabela(ASCII).
int OP=0,X=0,y=1,sinal=0;

do{
	system("cls");
	puts("\t CALCULADORA VERSAO 1.0 \t\n\n");
	//Função que recebe o primeiro numero.
	num1=RecebeNum1(y,num3);
	num2=0;
	num3=0;
	puts("\t Informe o 2 numero: \n");
	scanf(" %f",&num2);
	system("cls");//Limpa tela.
	//OP recebe o tipo de operação matemática, numero inteiro.
	OP=EscolhaTipo(num1,num2);
	//Função que recebe o sinal de operação pelo valor de OP.
	sinal=SinalOP(OP);
	//Função do calculo matemático, retorna resultado em 'num3'float.
	num3=CalculoTotal(OP,num1,num2);
    //Resultado da operação.
    puts("\t  CALCULADORA VERSAO 1.0 \t\n\n");
    printf("\t Num1 %.2f %c Num2 %.2f \t\n",num1,sinal,num2);
    printf("\t O resultado e: %.2f \n\n",num3);
    //Função que decide finalizar ou continuar operação.
    X=DecisaoCalc();
    switch(X){
	case 1: 
    y=2;
	break;
	case 2:
    y=1;
	break;}
	}while(X!=0);
puts("FIM CALCULADORA");
return 0;
}
//Função que recebe o numero 1.
float RecebeNum1(int y,float num3)
{
	float num1=0;
	switch(y){
		case 1: 
		puts("\t Informe o 1 numero: \n");
		scanf(" %f",&num1);
		break;
		case 2: 
		printf("Numero 1 = %.2f \n",num3);
		num1=num3;
		break;
	}
		return num1;
}
//Função que recebe o tipo da operação matemática.
int EscolhaTipo(float num1, float num2)
{
  int OP,X=0;
  do{
  	puts("\t CALCULADORA VERSAO 1.0 \t\n\n");
	printf("\t Num1 %.2f\t   Num2 %.2f \n",num1,num2);
	puts("\t Digite o numero da operacao: \n");
	puts("\t Numeros de 1 a 4\t\n");
	puts("\t1 '+' (SOMA)\n \t2 '-' (SUBTRACAO)\n");
	puts("\t3 'x' (MULTIPLICACAO) \n \t4 '/' (DIVISAO) \n");
	scanf("%d",&OP);
	switch(OP)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			X=1;
		break;
		default:
		system("cls");//Limpa tela.
	}
  }while(X!=1);
  system("cls");//Limpa tela.
	return OP;
}
//Recebe o tipo de operação e tranforma em decimal.
int SinalOP(int OP)
{
    int sinal=0;
	switch(OP)
	{
		case 1:
			sinal=43;
			break;
		case 2:
			sinal=45;
			break;
		case 3:
			sinal=88;
			break;
		case 4:
			sinal=47;
			break;
	}
//Retorna tipo de operação em decimal.
	return sinal;
}

//Função que realiza o cálculo total.
float CalculoTotal(int OP,float num1,float num2){
	float res=0;
	switch(OP){
	case 1:
		res = num1 + num2;
	break;
	case 2:
		res = num1 - num2;
	break;
	case 3:
	res = num1 * num2;
	break;
	case 4:
	res = num1 / num2;
	break;
	}
	//Retorna o resultado da operação.
	return res;
}

//Finalizar ou continuar operação.
int DecisaoCalc(void)
{
    int X,Y;
    do{
    printf("0- Para finalizar operacao. \n");
    printf("1- Para continuar operacao com o resultado armazenado. \n");
    printf("2- Para realizar uma operacao do zero. \n");
    scanf("%d",&X);
    switch(X)
	{
		case 0:
		case 1:
		case 2:
			Y=1;
			break;
			default:
		system("cls");
	}
    }while(Y!=1);
    return X;}