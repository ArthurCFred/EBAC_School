#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco de memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel pela string
#include <conio.h>

int registro()// funcao responsavel por cadastrar usaurios no sistema
{
	
	//inicio de variaveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final das variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s", cpf); //%s e para salvar na string; scanf le o que foi digitado
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo w =write
	fprintf(file, "CPF: ");
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo com a variavel
	
	file = fopen(arquivo, "a"); //abriu o arquivo e "a" e pra atualizar a informacao
	fprintf(file, "\nNOME: "); //para dar espaco e nao salvar tudo seguido por exemplo arthurcantofrederico14356107764
	fclose(file);
	
	printf("Digite o  nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, "\n");
	fclose(file);
	
	system("pause");

	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" = read; abre o arquivo cpf e leia 
		
	if(file == NULL)
	{
		printf("Nao foi possivel abrir, pois o CPF nao foi localizado! \n");
	}
	
	printf("\nEssas sao as informacoes do usuario: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL) //while=enquanto; enquanto fgets(vai buscar o conteudo no arquivo), que tem 200 caracteres e dentro do arquivo file
	//enquanto tiver conteudo dentro desse arquivo(variavel conteudo), com 200 caracteres, caso seja diferente dessa informacao (!=) nao existe (NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O CPF do usuario nao se encontra no sistema! \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variaveis
	int x=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	prinf("Login de administrador!\n\nDigite a senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
			system ("cls");	
			for(x=1;x=1;)
		{
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Programa\n\n");
			printf("Digite o numero da opção desejada:\n\n"); //Fim do menu
	
			scanf("%d", &opcao); //armazenando escolha do usuario
	
			system("cls"); //Limpeza de tela apos a escolha do usuario
		
			switch(opcao)//Inicio da selecao do menu
			{
			//Chamada de funcoes
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
				printf("\n\n################################################\nObrigado por utilizar o programa, volte sempre!\n################################################\n\n\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponível!! \nObrigado, deseja tentar novamente?\n");
				system("pause");
				break;
			}

			printf("\n\n\n\n--> Esse Software é de livre uso dos alunos <--\n");
		}
	}
	
	else
		prinf("Senha Incorreta!");
}
