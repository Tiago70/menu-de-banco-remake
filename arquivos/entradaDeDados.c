#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void receber_texto(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]) // colocar um limitador na função
{
	char entrada, nome[25];
	int contador1 = 0, contador2 = 0, contador3 = 0;
	while (1)
	{
		entrada = getch();
		if ((isalpha(entrada) || entrada == ' ') && contador1 < tamanho_max) // verifica se o digito digitado é uma letra
		{
			if (entrada == ' ' && !contador3) // evita do usuario digitar muitos espaços
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3++;
			}
			else if (entrada != ' ') // guarda o valor se tudo estiver de acordo
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3 = 0;
			}
		}
		else if ((contador1 == tamanho_max && !contador2) && isalpha(entrada))
		{
			printf("  Tamanho maximo atingido!");
			sleep(2);
			int i;
			for (i = 0; i <= 25; i++)
				printf("\b \b");
			contador2++;
		}
		if (entrada == '\b' && contador1 > 0) // apaga o digito quando o backspace é precionado
		{
			if (nome[contador1 - 1] == ' ')
			{
				contador3 = 0;
			}
			printf("\b \b");
			contador2 = 0;
			contador1--;
		}
		else if (entrada == '\r' && contador1 >= tamanho_min) // finaliza a entrada de dados
			break;
		else if (entrada == '\r' && contador1 < tamanho_min) // exibe uma mensagem quando o nome é muito curto
		{
			if (!contador2)
			{
				char tamanho[2];
				printf(" %s muito curto, minimo de %d caracteres", nomeDo_dado, tamanho_min);
				sprintf(tamanho, "%d", tamanho_min);
				sleep(2);
				int i;
				for (i = 0; i <= 35 + strlen(tamanho) + strlen(nomeDo_dado); i++)
					printf("\b \b");
				contador2 = 1;
			}
		}
	}
	nome[contador1] = '\0';
	strcpy(dado, nome);
}

void receber_texto_numero(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]) // colocar um limitador na função
{
	char entrada, nome[25];
	int contador1 = 0, contador2 = 0, contador3 = 0;
	while (1)
	{
		entrada = getch();
		if ((entrada == ' ' || isalnum(entrada)) && contador1 < tamanho_max) // verifica se o digito digitado é uma letra
		{
			if (entrada == ' ' && !contador3) // evita do usuario digitar muitos espaços
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3++;
			}
			else if (entrada != ' ') // guarda o valor se tudo estiver de acordo
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3 = 0;
			}
		}
		else if ((contador1 == tamanho_max && !contador2) && isalnum(entrada))
		{
			printf("  Tamanho maximo atingido!");
			sleep(2);
			int i;
			for (i = 0; i <= 25; i++)
				printf("\b \b");
			contador2++;
		}
		if (entrada == '\b' && contador1 > 0) // apaga o digito quando o backspace é precionado
		{
			if (nome[contador1 - 1] == ' ')
			{
				contador3 = 0;
			}
			printf("\b \b");
			contador2 = 0;
			contador1--;
		}
		else if (entrada == '\r' && contador1 >= tamanho_min) // finaliza a entrada de dados
			break;
		else if (entrada == '\r' && contador1 < tamanho_min) // exibe uma mensagem quando o nome é muito curto
		{
			if (!contador2)
			{
				char tamanho[2];
				printf(" %s muito curto, minimo de %d caracteres", nomeDo_dado, tamanho_min);
				sprintf(tamanho, "%d", tamanho_min);
				sleep(2);
				int i;
				for (i = 0; i <= 35 + strlen(tamanho) + strlen(nomeDo_dado); i++)
					printf("\b \b");
				contador2 = 1;
			}
		}
	}
	nome[contador1] = '\0';
	strcpy(dado, nome);
}

void receber_numeros(int tamanho, char numeros[20])
{
	char entrada;
	int contador1 = 0;

	while (contador1 < tamanho)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			numeros[contador1] = entrada;
			printf("%c", entrada);
			contador1++;
		}
		else if (entrada == '\b' && contador1 > 0)
		{
			printf("\b \b");
			contador1--;
		}
	}
	numeros[contador1] = '\0';
}

void receber_telefone(char numero[13])
{
	char entrada;
	int contador = 0;

	while (contador < 13)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			numero[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 3)
			{
				printf("\b %c", entrada);
				numero[contador - 1] = ' ';
				numero[contador] = entrada;
				contador++;
			}
			if (contador == 9)
			{
				printf("\b-%c", entrada);
				numero[contador - 1] = '-';
				numero[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 4 || contador == 9)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	numero[13] = '\0';
}

void receber_cpf(char cpf[14])
{
	char entrada;
	int contador = 0;

	while (contador < 14)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			cpf[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 4 || contador == 8)
			{
				printf("\b.%c", entrada);
				cpf[contador - 1] = '.';
				cpf[contador] = entrada;
				contador++;
			}
			if (contador == 12)
			{
				printf("\b-%c", entrada);
				cpf[contador - 1] = '-';
				cpf[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 5 || contador == 9 || contador == 13)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	cpf[14] = '\0';
}

void receber_cep(char cep[9])
{
	char entrada;
	int contador = 0;

	while (contador < 9)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			cep[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 6)
			{
				printf("\b-%c", entrada);
				cep[contador - 1] = '-';
				cep[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 7)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	cep[9] = '\0';
}

void receber_data(char data[10])
{
	char entrada;
	int contador = 0;

	while (contador < 10)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			data[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 3 || contador == 6)
			{
				printf("\b/%c", entrada);
				data[contador - 1] = '/';
				data[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 4 || contador == 7)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	data[10] = '\0';
}
