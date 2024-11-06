static char ADM[10] = "112233", funcionario[10] = "12345", cliente[10] = "54321"; // define as senhas internas para o acesso ao programa

struct conta
{
	char agencia[6], numero_da_conta[10], nome[45], cpf[16];
	char data_nascimento[12], telefone[15], endereco[27], cep[20];
	char cidade[27], estado[27], senha_cliente[27], data_vencimento[12];
	float saldo; // saldo da conta
	int tipo;	 // tipo da conta
};

struct conta_f
{
	char codigo_f[6], cargo_f[25], nome_f[25], cpf_f[16], data_nascimento_f[12], telefone_f[15];
	char endereco_f[27], cep_f[16], cidade_f[25], estado_f[25], senha_f[27];
};

void receber_texto(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]);

void receber_texto_numero(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]);

void receber_numeros(int tamanho, char numeros[20]);

void receber_telefone(char numero[13]);

void receber_cpf(char cpf[14]);

void receber_cep(char cep[9]);

void receber_data(char data[10]);
