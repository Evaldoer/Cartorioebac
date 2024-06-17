#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdio.h>//biblioteca aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
		

int consulta()
{
   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	  }
	  
	  while(fgets(conteudo, 200, file) != NULL)
	  {
	  	printf("\nEssa s�o as informa��es do usuario: ");
	  	printf("%s", conteudo);
	  	printf("\n\n");
      }
		 system("pause");   


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.");
		system("pause");
	 }
	  
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cart�rio da EBEC ###\n\n"); //inicio do menu
		printf("Escolha aop��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("op��o: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	system("cls");
	
	switch(opcao)
	{
	   case 1:
	   registro();
	   break;
	   
	   case 2:
	   consulta();
	   break;
	   
	   case 3:
	   deletar();
	   break;
	   
	   case 4:
	   printf("Obrigado por utilizar o sistema!\n");
	   return 0;
	   break;
	   
	   default:
	   printf("Essa op��o n�o est� disponival!\n");
	   system("pause");
	   	
	}
}
}
	


