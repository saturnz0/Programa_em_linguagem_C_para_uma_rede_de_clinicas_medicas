#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <new> 
#include <string.h>
#include <locale.h>
#include <time.h>
#include <fstream>
#include <iomanip>
int opcao; 

using namespace std; 
void login_user();
void cadastro();
void voltar();
void login ();
void voltar_inicio();
void limpa_tela(){
	
	system("CLS");
}
void login_funcionario_efetuado ();

void escrever_notxt(){
	
using namespace std;

struct TPessoa{
   string nome;
   string cpf;
   string data;
   string especialidade;
   string sobrenome;
   string horario;
};
		printf("Especialidades disponives\n\n");
		printf(" - Cardiologia\n");
		printf(" - Clínica Médica\n");
		printf(" - Dermatologia\n");
		printf(" - Endocrinologia\n");
		printf(" - Gastroenterologia\n");
		printf(" - Ginecologia\n\n");
		printf("\n\n - Deseja prosseguir com o agendamento da conssulta? 1 - Sim, 2 - Não"); 
		scanf("%d", &opcao); 
			if(opcao == 1){
				printf(" - Para efetuar o registro de sua consulta digite uma das especialidades acima: ");

			    ofstream pessoas; 
			    TPessoa dados;
			    cin >> dados.especialidade;
			    cout << "\nPor favor, Digite o seu primeiro nome: "<< endl;
			    cin >> dados.nome;
			    cout << "\nDigite o seu sobrenome: "<< endl; 
			    cin >> dados.sobrenome;
			    cout << "\nAgora Digite o seu cpf: "<< endl;
			    cin >> dados.cpf;
			    cout << "\nDigite a data desejada para consulta DD/MM/AAAA: "<< endl;
			    cin >> dados.data;
			    cout << "\nE por ultimo, digite um horario disponivel (ex: 13:00)" << endl;
			    cin >> dados.horario; 
			
				cout << "\n\nConsulta Agendada com sucesso!!! \n\n"; 
			 pessoas.open ("pessoas.txt",ios::app); //abre o arquivo    
			 //ofstream ("pessoas.txt", ios::app);
			    
			  pessoas << " - Nome: " << dados.nome << " " << dados.sobrenome << endl;
			  pessoas << " - CPF: " << dados.cpf << endl;
			  pessoas << " - Data: " << dados.data << " às " << dados.horario << " - Especialidade: " << dados.especialidade << endl << "\n";
			  pessoas.close();
				cout << "\n";
				voltar();
			}

	
}
void chama_lista(); 



void horario(){
	
	printf("Horarios Disponiveis: \n\n");
	printf(" - 8:00 - 9:00 Dentista, Pediatria, Endocrinologia, Ginecologia\n");
	printf(" - 9:00 - 10:00 Endocrinologia, Ginecologia, Urologia, Cardiologia, Clinica Medica\n");
	printf(" - 10:00 - 12:00 Ginecologia, Urologia, Cardiologia, Clinica Medica, Gastroenterologia, Psicologia, Psquiatria\n");
	printf(" - Obs: Apartir das 12:00 horas é o horario geral de almoço podendo alterar o funcionamento das consultas.\n");
	printf(" - 13:00 - 16:00 Ginecologia, Urologia, Cardiologia, Clinica Medica, Gastroenterologia, Psicologia, \n - Psquiatria, Tumografia e Radiologia\n\n");

	printf("Os horarios de funcionamento podem váriar, para melhores informações acesse o nosso site \npelo link: http://RedeMedicaTGG.com.br/unip/pim \n\n");
	
	voltar();
}
void horario_da_consulta(){
	
	
			
 //necessário para usar localtime() e struct tm

  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;     
  
  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);  
  

  printf("%d:",data_hora_atual->tm_hour);//hora   
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d",data_hora_atual->tm_sec);//segundo  

										
}
void remover(){
	
	 FILE * file = fopen ( "pessoas.txt", "r" );
    
    if ( file ) {
        fclose(file);
        limpa_tela();
        printf("Removidos");    
        remove("pessoas.txt");
       
        
    
    }else{ 
        printf("Erro");
        voltar();
    }
}
void login_funcionario_efetuado (){
				
					int opcao, cpf, i, opcao2; 
					
						limpa_tela();
						
						
								limpa_tela();
								printf("O que deseja fazer?\n\n");
								
								printf("1 - Ver tabelas de horarios disponiveis\n");
								printf("2 - Visualizar especialidades disponiveis\n");
								printf("3 - Visualisar Agendamentos de consultas\n");
								printf("4 - Remover cadastros ");
							
								
									scanf("%d", &opcao2);
										
										switch(opcao2){
											case 1:
												limpa_tela();
												
												 horario();
											break;
											case 2:
												 limpa_tela(); 
												 escrever_notxt();
											break;
											case 3: 
												limpa_tela();
												chama_lista();
											break; 
											case 4:
												remover(); 
												voltar();
											break; 
										}
											
}
void login_funcionario(){
	horario_da_consulta();
	printf("\n");
	
	int re, senha, cpf; 
		printf("Digite o seu R.E: ");
				scanf("%d", &re);
				printf("\nDigite sua senha: ");
				
				scanf("%d", &senha);
						if(re == 5200 && senha == 10){
						limpa_tela();
						login_funcionario_efetuado();

					}else{
						limpa_tela();
						printf("Login ou senha inválida, tente novamente\n\n");
						login_funcionario();
						
					}
}

void login(){
	
	int opcao, re, re1 = 5201, re2 = 5203, senha; 
 	
	printf("\n\n");
	printf("1 - Funcionario\n");
	printf("2 - Usuário\n");
	printf("3 - Cadastra-se\n");

	printf("\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				limpa_tela();
				login_funcionario();
					
			
			break; 
			case 2:
				limpa_tela();
				login_user();
			break; 
			case 3:
				limpa_tela();
				cadastro();
			break;

		}
	
}
void menu(){
	horario_da_consulta();
	printf("\n");
	int opcao;
	
	printf("Bem Vindo ao sistema de Gerencimanto da rede TGG. \nEscolha uma opcao para começar: \n\n");
	printf("1 - Quem somos\n"); 
	printf("2 - Novidades\n");
	printf("3 - Fale conosco\n");
	printf("4 - Sac\n");
	printf("5 - Login\n");
	
	scanf("%d", &opcao);
		
		
		switch(opcao){
			case 1:
				limpa_tela();
				printf("Responsável pela rede de clinicas medicas T&G somos os maiores do setor, tendo como principio a meritocracia e \no senso de dono");
				printf("onde cada funcionario é como dono da empresa. \n  Sonhamos em ser os maiores e os mais lucrativos no setor em que atuamos, pois para");
				printf("isso foi criada a nossa empresa.");
				
				cout << "\n";
				
				voltar();
			break; 
			case 2: 
				limpa_tela();
				printf("Print com as novidades\n");
				voltar();
			break;
			case 3:
				limpa_tela();
				printf("Fale conosco pelos telefones xxxx-xxxx ou pelo email xxxxxx@tralala.com.br\n");
				voltar();
			break;
			case 4:
				limpa_tela();
				printf("Sac");
				voltar();
			break;	
			case 5:
				limpa_tela();
				printf("Area de login");
				login();
			break;
		}	
	
		
}
void voltar(){
	
	int opcao; 
	printf("\n1 - Voltar ao menu\n");
	printf("2 - Sair");
	
	scanf("%d", &opcao);
		if(opcao == 1){
			limpa_tela();
			login_funcionario_efetuado (); 
		}else{
			limpa_tela();
			printf("Até logo"); 
		}
	
		
}
void chama_lista(){
	FILE *input;
	char buffer[130];
	input = fopen("pessoas.txt", "r"); //abre o arquivo para leitura
    printf("\n - Consultas agendadas:\n\n");
	while(! feof(input)) {
		fgets(buffer, 130 , input);
		printf("%s", buffer);
	}
	fclose(input); 
	
	voltar();
}
int main(){
	
	
	setlocale(LC_ALL, "Portuguese");
	menu();
	
}


void cadastro(){
	struct TPessoa{
    string nome;

};

    ofstream data; 
    TPessoa dados;

    cout << "\nPor favor, Digite o seu login (cpf, nome ou e-mail) para cadastrarmos no banco de Dados: "<< endl;
    cin >> dados.nome;
   

	cout << "\n\nO Usuário 	" << dados.nome << " foi cadastrado, o aplicativo será encerrado e o seu Login estará pronto para uso na proxima abertura."; 
 	data.open ("data.txt",ios::app); //abre o arquivo    
 //ofstream ("pessoas.txt", ios::app);
    
  data << dados.nome << endl;
	cout << "\n";
  data.close();
	
}

void login_user(){
	

    int i = 0;
    int numPalavras = 0;
    char* palavras[200];
    char line[200];
	char nome[200];
	
    FILE *arquivo;
    arquivo = fopen("data.txt", "r");

    if (arquivo == NULL)
        printf("error"); 

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
	
    int j;
    cout << "Digite o seu login: "; 
	scanf("%s", &nome);
    for (j = 0; j < numPalavras; j++)
		//Minha ideia era comparar os nomes do vetor agora 
			if(strcmp(palavras[j], nome) == 0){
					cout << "Usuário não existe";
				login_user();	
			}
			else{
				login_funcionario_efetuado (); 
			}
    fclose(arquivo);
}

void voltar_inicio(){
	limpa_tela();
	int opcao; 
	printf("\nPressione 1 e aperte ENTER para voltar ao menu ou qualquer tecla para sair... \n");
	
	scanf("%d", &opcao);
		if(opcao == 1){
			limpa_tela();
			menu(); 
		}else{
			limpa_tela();
			printf("Até logo"); 
		}
	
		
}
