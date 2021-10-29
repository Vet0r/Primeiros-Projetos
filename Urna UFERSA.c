#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#define qtdInscritos 11
//Boa Tarde, sejam bem vindos a mais um explendoroso encontro da nossa disciplina de Laboratório de Algoritmos.
int somapresidente=0,somarepresentante=0,somatotal=0,qtdVotos=0/*Quantidade de pessoas a votar*/,vetorVotos[qtdInscritos]/*armazena a QUANTIDADE de votos a cada candidato*/;
bool VerificadorDeVotantes=0;
char senha[7];
char numeroCandidatos[qtdInscritos][6]={"08","04","48444","43210","98765","67890","12345","00000","00"};
char nomeCandidatos[qtdInscritos][60]={"Lavínia Scanf      ","Hadija Printf      ","Dyego Main         ","Karla Float        ","Pollyana Return    ","Vinicius While     ","David Else         ","BRANCO             ","BRANCO             ","NULO               ","NULO               "};/*armazena o NOME dos inscritos*/

void gotoxy(int x, int y){//função que move o cursor para efeito visual
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}               

int digitarSenha(){
	int i;
	for ( i = 0; i < 7; i++){
		senha[i]='\0';
	}
	system("cls");
	while (strcmp(senha,"UFERSA")!=0){//senha = UFERSA
		printf("\n\t██████████████████████████████████████████████████████████████████");
		printf("\n\t███╔═════════════════════════════╗████████╔═══════════════════╗███");
		printf("\n\t███║    SENHA -->                ║████████║     CONFIRMAR     ║███");
		printf("\n\t███╚═════════════════════════════╝████████╚═══════════════════╝███");
		printf("\n\t██████████████████████████████████████████████████████████████████");
		gotoxy(27,4);
		//executar a escrita da senha como caractere "░"
		for ( i = 0; i < 6; i++){
			senha[i]=getch();
			while (senha[i]=='\b'){
				printf("\b \b");
				i--;
				if (i<0){
					i=0;
					printf(" ");
				}
				senha[i]=getch();
			}
			printf("░");
		}
		strupr(senha);//deixar senha maiuscula para comparação
		gotoxy(0,0);
		if (strcmp(senha,"DYEGO.")==0){ //ISSO NÃO É UM EASTER EEG!!! 
			contabilizarVotos();//Facilita a verificação de voto durante teste
		}
		if(strcmp(senha,"UFERSA")!=0){//verificar a senha, fazer um loop até estar correta e cuidar do "dyego."
			gotoxy(0,0);
			system("cls");
			Beep(200,300);
			printf("Senha Incorreta, tente novamente\n");
			system("pause");
			system("cls");
			digitarSenha();
		}
	}
	system("cls");
}

int Menu(int escolha){
	while (escolha<=0||escolha>=5){//tema basico do menu
		escolha=0;
		printf("\n\t╔═════════════════════════════════════════════════════════════════════════════════════════╗");
		printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
		printf("\n\t║█████████████████╔═════════════════════════════╗█████████████████████████████████████████║");
		printf("\n\t║█████████████████║     ELEIÇÕES ESTUDANTIS     ║█████████████████████████████████████████║");
		printf("\n\t║█████████████████╚═════════════════════════════╝█████████████████████████████████████████║");
		printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
		printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
		printf("\n\t║███║ 1 ║ ║         Difinir Quantidade de Votantes         ║██████████████████████████████║");
		printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
		printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
		printf("\n\t║███║ 2 ║ ║              Iniciar Votação                   ║██████████████████████████████║");
		printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
		printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
		printf("\n\t║███║ 3 ║ ║              Contabilizar Votos                ║██████████████████████████████║");
		printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████╔═════════╗ ╔═══╗███║");
		printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████║  OPÇÃO  ║ ║   ║███║");
		printf("\n\t║███║ 4 ║ ║                    Sair                        ║██████████╚═════════╝ ╚═══╝███║");
		printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
		printf("\n\t║██████████████████████████████████████████████████████████████████████████████████v1.0███║");
		printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
		printf("\n\t╚═════════════════════════════════════════════════════════════════════════════════════════╝\n");
		
		gotoxy(93,17);
		scanf("%i",&escolha);//se digitar uma letra aqui buga tudo
		gotoxy(0,0);
		system("Cls");
	}
	switch (escolha){
	case 1: //Definir quantidade de votantes
		digitarSenha();
		qtdVotos=definirVotantes();
		break;
	case 2: //Iniciar votação
		digitarSenha();
		iniciarVotacao();
		escolha=-1;
		break;
	case 3: //Contabilizar votos
		digitarSenha();
		contabilizarVotos();
		break;
	case 4: //Sair
		sair();
		return(escolha=4);
		break;
	default:

		break;
	}
	return(escolha=0);
}

int sair(){
	int i;

    printf("\n");
    printf("\n\t\t\t\t █████████████████████████████████████████████████████████");
    printf("\n\t\t\t\t █████████████████████████████████████████████████████████");
    printf("\n\t\t\t\t ██┌───────────────────────────────────────────────────┐██");  
    printf("\n\t\t\t\t ██│Finalizando Aplicação                              │██");
	printf("\n\t\t\t\t ██│                                                   │██");
    printf("\n\t\t\t\t███│                                                   │███");                       
    printf("\n\t\t\t\t███│                                                   │███");
    printf("\n\t\t\t\t███│Salvando os dados                                  │███");
    printf("\n\t\t\t\t███│                                                   │███");
    printf("\n\t\t\t\t███│                                                   │███");
    printf("\n\t\t\t\t ██│                                                   │██");
	printf("\n\t\t\t\t ██│Obrigado por usar nossa urna eletrônica            │██");
    printf("\n\t\t\t\t ██└───────────────────────────────────────────────────┘██");
    printf("\n\t\t\t\t █████████████████████████████████████████████████████████");
    printf("\n\t\t\t\t █████████████████████████████████████████████████████████");
    printf("\n\n");
	gotoxy(54,10);
	for (i = 0; i < 3; i++){
        Sleep(rand()%2000);
        printf(".");
    }
	gotoxy(37,13);
	system("pause");

}

int definirVotantes(){//definir a quantidade de votantes na variaval qtdVotos
	int escolha=0;
	system("Cls");
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║██████████████████████████████████████████████████████████████████║\n");
	printf("║████ Digite a quantidade de pessoas que vão votar nessa seção ████║\n");
	printf("║██████████████████████████████████████████████████████████████████║\n");
	printf("║████ ATENÇÃO: o numero de participantes deve ser no mínino31  ████║\n");
	printf("║██████████████████████████████████████████████████████████████████║\n");
	printf("║███████████████████████████████╔═══╗██████████████████████████████║\n");
	printf("║███████████████████████████████║   ║██████████████████████████████║\n");
	printf("║███████████████████████████████╚═══╝██████████████████████████████║\n");
	printf("║██████████████████████████████████████████████████████████████████║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n");
	gotoxy(34,8);
	scanf("%i",&qtdVotos);
	gotoxy(0,0);
	if (qtdVotos<31){
		printf("o numero de discentes votantes deve ser no minimo 31.\n tente novamente.\n");
		system("Pause");
		system("Cls");
		Menu(escolha);
	}
	VerificadorDeVotantes=1;
	system("Cls");
	return (qtdVotos);
}
//Variaveis para funções de Votar. estão mais a baixo para facilitar o acesso
int i=0,n,salvanumero=0;
int medidorStr;
char c,numeroDigitado[6];
bool verifica=false;
//as funções de votarRepresentante e votarPresidente tem a mesma lógica, a diferença é a interfaçe
int votarRepresentante(){
	gotoxy(0,0);
	numeroDigitado[1]="";
	system("cls");
	salvanumero=0;
	i=0;
	printf("\n\t╔═══════════════════════════════════════════════════════════╗");
	printf("\n\t║███████████████████████████████████████████████████████████║");
	printf("\n\t║██████████████████████████████╔══════════════════════╗█████║");
	printf("\n\t║██████████████████████████████║  Justiça Estudantil  ║█████║");
	printf("\n\t║███╔═══════════════════════╗██╚══════════════════════╝█████║");
	printf("\n\t║███║     REPRESENTANTE     ║███████████████████████████████║");
	printf("\n\t║███╚═══════════════════════╝███████████████████████████████║");
	printf("\n\t║████████████████████████████████╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║██╔═════════════════════════╗███║ 1 ║  ║ 2 ║  ║ 3 ║████████║");
	printf("\n\t║██║┌───┐┌───┐┌───┐┌───┐┌───┐║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║██║│   ││   ││   ││   ││   │║███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║██║└───┘└───┘└───┘└───┘└───┘║███║ 4 ║  ║ 5 ║  ║ 6 ║████████║");
	printf("\n\t║██║Nome:                    ║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║██╚═════════════════════════╝███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║████████████████████████████████║ 7 ║  ║ 8 ║  ║ 9 ║████████║");
	printf("\n\t║██╔══════╗ ╔═══════╗ ╔════════╗ ╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║██║BRANCO║ ║CORRIGE║ ║CONFIRMA║████████╔═══╗███████████████║");
	printf("\n\t║██╚══════╝ ╚═══════╝ ╚════════╝████████║ 0 ║███████████████║");
	printf("\n\t║███████████████████████████████████████╚═══╝███████████████║");
	printf("\n\t║███████████████████████████████████████████████████████████║");
	printf("\n\t╚═══════════════════════════════════════════════════════════╝\n");
	gotoxy(15,12);
	for ( i = 0; i < 5; i++){//beep do teclado e pulo do cursor com gotoxy
		numeroDigitado[i]=getch();
		printf("%c",numeroDigitado[i]);
		Beep(2217,100);
		switch (i){
		case 0:
			gotoxy(20,12);
			break;
		case 1:
			gotoxy(25,12);
			break;
		case 2:
			gotoxy(30,12);
			break;
		case 3:
			gotoxy(35,12);
			break;
		
		default:
			break;
		}
	}
	gotoxy(0,0);
	system("Cls");
	//comparação meio do vetor de candidatos por com numero digitado previamente para mostrar o nome na tela
	for (i = 0; i <= qtdInscritos; i++){
		if(strcmp(numeroDigitado,numeroCandidatos[i])==0){
			salvanumero=i;
			verifica=true;
		}
	}
	if (verifica==false){
		salvanumero=9;
	}
	verifica=false;
	printf("\n\t╔═══════════════════════════════════════════════════════════╗");
	printf("\n\t║███████████████████████████████████████████████████████████║");
	printf("\n\t║██████████████████████████████╔══════════════════════╗█████║");
	printf("\n\t║██████████████████████████████║  Justiça Estudantil  ║█████║");
	printf("\n\t║███╔═══════════════════════╗██╚══════════════════════╝█████║");
	printf("\n\t║███║     REPRESENTANTE     ║███████████████████████████████║");
	printf("\n\t║███╚═══════════════════════╝███████████████████████████████║");
	printf("\n\t║████████████████████████████████╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║██╔═════════════════════════╗███║ 1 ║  ║ 2 ║  ║ 3 ║████████║");
	printf("\n\t║██║┌───┐┌───┐┌───┐┌───┐┌───┐║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║██║│ %c ││ %c ││ %c ││ %c ││ %c │║███╔═══╗  ╔═══╗  ╔═══╗████████║",numeroDigitado[0],numeroDigitado[1],numeroDigitado[2],numeroDigitado[3],numeroDigitado[4]);
	printf("\n\t║██║└───┘└───┘└───┘└───┘└───┘║███║ 4 ║  ║ 5 ║  ║ 6 ║████████║");
	printf("\n\t║██║Nome: %s║███╚═══╝  ╚═══╝  ╚═══╝████████║",nomeCandidatos[salvanumero]);
	printf("\n\t║██╚═════════════════════════╝███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║████████████████████████████████║ 7 ║  ║ 8 ║  ║ 9 ║████████║");
	printf("\n\t║██╔══════╗ ╔═══════╗ ╔════════╗ ╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║██║BRANCO║ ║CORRIGE║ ║CONFIRMA║████████╔═══╗███████████████║");
	printf("\n\t║██╚══════╝ ╚═══════╝ ╚════════╝████████║ 0 ║███████████████║");
	printf("\n\t║███████████████████████████████████████╚═══╝███████████████║");
	printf("\n\t║███████████████████████████████████████████████████████████║");
	printf("\n\t╚═══════════════════════════════════════════════════════════╝\n");
	printf("\nDigite 0 para corrigir ou pressione quaquer tecla para confirmar. ");
	c=getch();
	if(c=='0'){
		votarRepresentante();
	}
	else{
		vetorVotos[salvanumero]++;
	}
}

int votarPresidente(){
	gotoxy(0,0);
	for ( i = 0; i < 5; i++){
		numeroDigitado[i]='\0';//
	}
	system("cls");
	salvanumero=0;
	i=0;
	printf("\n\t╔════════════════════════════════════════════════════════════╗");
	printf("\n\t║████████████████████████████████████████████████████████████║");
	printf("\n\t║███████████████████████████████╔══════════════════════╗█████║");
	printf("\n\t║███████████████████████████████║  Justiça Estudantil  ║█████║");
	printf("\n\t║███╔════════════════════════╗██╚══════════════════════╝█████║");
	printf("\n\t║███║  PRESIDENTE DO GREMIO  ║███████████████████████████████║");
	printf("\n\t║███╚════════════════════════╝███████████████████████████████║");
	printf("\n\t║█████████████████████████████████╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║███╔═════════════════════════╗███║ 1 ║  ║ 2 ║  ║ 3 ║████████║");
	printf("\n\t║███║       ┌───┐ ┌───┐       ║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║███║       │   │ │   │       ║███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║███║       └───┘ └───┘       ║███║ 4 ║  ║ 5 ║  ║ 6 ║████████║");
	printf("\n\t║███║Nome:                    ║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║███╚═════════════════════════╝███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║█████████████████████████████████║ 7 ║  ║ 8 ║  ║ 9 ║████████║");
	printf("\n\t║███╔══════╗ ╔═══════╗ ╔════════╗ ╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║███║BRANCO║ ║CORRIGE║ ║CONFIRMA║████████╔═══╗███████████████║");
	printf("\n\t║███╚══════╝ ╚═══════╝ ╚════════╝████████║ 0 ║███████████████║");
	printf("\n\t║████████████████████████████████████████╚═══╝███████████████║");
	printf("\n\t║████████████████████████████████████████████████████████████║");
	printf("\n\t╚════════════════════════════════════════════════════════════╝\n");
	gotoxy(23,12);
	for ( i = 0; i<2; i++){//beep do teclado
		numeroDigitado[i]=getch();
		printf("%c",numeroDigitado[i]);
		Beep(2217,100);
		switch (i){
		case 0:
			gotoxy(29,12);
			break;
		}
	}

	gotoxy(0,0);
	system("cls");
	for (i = 0; i <= qtdInscritos; i++){
		if(strcmp(numeroDigitado,numeroCandidatos[i])==0){
			salvanumero=i;
			verifica=true;
		}
	}
	if (verifica==false){
		salvanumero=10;
	}
	verifica=false;

	printf("\n\t╔════════════════════════════════════════════════════════════╗");
	printf("\n\t║████████████████████████████████████████████████████████████║");
	printf("\n\t║███████████████████████████████╔══════════════════════╗█████║");
	printf("\n\t║███████████████████████████████║  Justiça Estudantil  ║█████║");
	printf("\n\t║███╔════════════════════════╗██╚══════════════════════╝█████║");
	printf("\n\t║███║  PRESIDENTE DO GREMIO  ║███████████████████████████████║");
	printf("\n\t║███╚════════════════════════╝███████████████████████████████║");
	printf("\n\t║█████████████████████████████████╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║███╔═════════════════════════╗███║ 1 ║  ║ 2 ║  ║ 3 ║████████║");
	printf("\n\t║███║       ┌───┐ ┌───┐       ║███╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║███║       │ %c │ │ %c │       ║███╔═══╗  ╔═══╗  ╔═══╗████████║",numeroDigitado[0],numeroDigitado[1]);
	printf("\n\t║███║       └───┘ └───┘       ║███║ 4 ║  ║ 5 ║  ║ 6 ║████████║");
	printf("\n\t║███║Nome: %s║███╚═══╝  ╚═══╝  ╚═══╝████████║",nomeCandidatos[salvanumero]);
	printf("\n\t║███╚═════════════════════════╝███╔═══╗  ╔═══╗  ╔═══╗████████║");
	printf("\n\t║█████████████████████████████████║ 7 ║  ║ 8 ║  ║ 9 ║████████║");
	printf("\n\t║███╔══════╗ ╔═══════╗ ╔════════╗ ╚═══╝  ╚═══╝  ╚═══╝████████║");
	printf("\n\t║███║BRANCO║ ║CORRIGE║ ║CONFIRMA║████████╔═══╗███████████████║");
	printf("\n\t║███╚══════╝ ╚═══════╝ ╚════════╝████████║ 0 ║███████████████║");
	printf("\n\t║████████████████████████████████████████╚═══╝███████████████║");
	printf("\n\t║████████████████████████████████████████████████████████████║");
	printf("\n\t╚════════════════════════════════════════════════════════════╝\n");
	printf("\nDigite 0 para corrigir ou pressione quaquer tecla para confirmar. ");
	c=getch();
	if(c=='0'){
		votarPresidente();
	}
	else{
		vetorVotos[salvanumero]++;
	}
}

int beepar(){//beep do fim da votação e entre as votações
	time_t t;
	for ( i = 0; i < 3; i++){//podem acontecer bugs de audio dependendo do hardware
		Sleep(50);
		Beep(2217,100);
		Sleep(50);
		Beep(2093,100);
	}
}

int finalizarVotacao(){//escrita grafica em Ascii da palavra FIM
	system("color 0F");
    printf("\n\n");
    printf("\n\t\t\t\t\t┌─────────────┐   ┌───┐   ┌───          ───┐ ");
    printf("\n\t\t\t\t\t|      	      |   |   |   |   \\        /   |   ");
    printf("\n\t\t\t\t\t|   ┌─────────┘   |   |   |    \\      /    |  " );
    printf("\n\t\t\t\t\t|   |             |   |   |     \\    /     |         ");
    printf("\n\t\t\t\t\t|   └───────┐     |   |   |      \\  /      | ");
    printf("\n\t\t\t\t\t|      	    |     |   |   |       \\/       |");
    printf("\n\t\t\t\t\t|   ┌───────┘     |   |   |    |\\    /|    |");
    printf("\n\t\t\t\t\t|   |             |   |   |    | ──── |    |     ");
    printf("\n\t\t\t\t\t|   |             |   |   |    |      |    |    ");
    printf("\n\t\t\t\t\t|   |             |   |   |    |      |    |     ");
    printf("\n\t\t\t\t\t└───┘	          └───┘   └────┘      └────┘ ");
    printf("\n\n");
	beepar();
	system("pause");
	system("Cls");
}

int iniciarVotacao(){ 
	if (VerificadorDeVotantes){
		for (n = 0; n < qtdVotos; n++){
			votarRepresentante();
			beepar();
			votarPresidente();
			system("Cls");
			finalizarVotacao();
			digitarSenha();
		}
		VerificadorDeVotantes=false;
	}
	else{//caso não tenha sido definido o numero de votantes ou ele seja <31
		printf("Defina o numero de votantes no menu inicial antes de iniciar a votação.\n");
		system("pause");
		system("Cls");
	}
}

int contabilizarVotos(){
	int i;
	Beep(222208, 600);
	for (i = 0; i <10; i++){
		somatotal=vetorVotos[i]+somatotal;
	}
	somapresidente=vetorVotos[0]+vetorVotos[1]+vetorVotos[8]+vetorVotos[10];
	somarepresentante=somatotal-somapresidente;
	
	printf("\n\t\t\t\t\t\t\t RELATÓRIO \t\t\t\t\t\t\t\n\n");
    printf("\n ___________________________________________________  __________________");
	printf("\n|******* VOTOS DOS REPRESENTANTES DO GRÊMIO ********||  TOTAL DE VOTOS ||");
	printf("\n| David Else - 12345 -------------------------------||_________%i_______||",vetorVotos[6]);
	printf("\n| Vinícius While - 67890 ---------------------------||_________%i_______||",vetorVotos[5]);
	printf("\n| Pollyana Return - 98765 --------------------------||_________%i_______||",vetorVotos[4]);
	printf("\n| Karla Float - 43210 ------------------------------||_________%i_______||",vetorVotos[3]);
	printf("\n| Dyego Main - 48444 -------------------------------||_________%i_______||",vetorVotos[2]);
	printf("\n| Votos Brancos ------------------------------------||_________%i_______||",vetorVotos[7]);
	printf("\n| Votos Núlos --------------------------------------||_________%i_______||",vetorVotos[9]);
    printf("\n| Total de votos representante do grêmio estudantil-||_________%i_______||",somarepresentante);
	printf("\n|********* VOTOS A PRESIDENTE DO GRÊMIO ************||  TOTAL DE VOTOS ||");
	printf("\n| Hadija Printf - 04 -------------------------------||_________%i_______||",vetorVotos[1]);
	printf("\n| Lavínia Scanf - 08 -------------------------------||_________%i_______||",vetorVotos[0]);
	printf("\n| Votos Brancos ------------------------------------||_________%i_______||",vetorVotos[8]);
	printf("\n| Votos Núlos --------------------------------------||_________%i_______||",vetorVotos[10]);
	printf("\n| Total de votos presidente do grêmio estudantil----||_________%i_______||",somapresidente);
	printf("\n ___________________________________________________  _________________\n");
	printf("\nTotal de votos da eleiçõo: %i ",somatotal);
	system("color F0");
	system("pause");
	system("color 07");
	system("cls");
	somatotal=0;
	somapresidente=0;
	somarepresentante=0;
	return(0);
}

int introducao(){
	int b;
	printf("\n\n");
    printf("\t ┌────────────────┐");
    printf("\n\t │                │");
    printf("\n\t │                │                                              ____");
    printf("\n\t │     ┌──────────┘                                             /____/   ");
    printf("\n\t │     │            ┌──┐       ┌───────┐  ┌──┐  ┌────────┐  ┌───────────┐  ┌───────────┐");
    printf("\n\t │     │            │  │       │  ┌────┘  │  │  │  ┌─────┘  │  ┌─────┐  │  │ ┌───────┐ │");
    printf("\n\t │     │            │  │       │  │       │  │  │  │        │  │     │  │  │ │       │ │");
    printf("\n\t │     │            │  │       │  └────┐  │  │  │  │        │  │     │  │  │ │       │ │");
    printf("\n\t │     │            │  │       │  ┌────┘  │  │  │  │        │  └─────┘  │  │ │       │ │");
    printf("\n\t │     │            │  │       │  │       │  │  │  │        │  ┌─────┐  │  │ │       │ │");
    printf("\n\t │     └────────┐   │  └────┐  │  └────┐  │  │  │  └─────┐  │  │     │  │  │ └───────┘ │");
    printf("\n\t │              │   └───────┘  └───────┘  └──┘  └────────┘  └──┘     └──┘  └───────────┘");
    printf("\n\t │              │                                  \\ \\ ");
    printf("\n\t │     ┌────────┘                                  / /");
    printf("\n\t │     │                                           ── ");
    printf("\n\t │     │");
    printf("\n\t │     │                                              E S T U D A N T I L  ");
    printf("\n\t │     │                                                  U F E R S A  ");
    printf("\n\t │     │                                                    2 0 2 1 ");
    printf("\n\t │     │");
    printf("\n\t │     └──────────┐");
    printf("\n\t │                │");
    printf("\n\t │                │");
    printf("\n\t └────────────────┘");
    printf("\n\n");
	printf("Iniciando.");
	for (b = 0; b < 3; b++)
	{
		printf(".");
		Sleep(1000);
	}
	Sleep(0);
	system("cls");
}

int main(){

	int escolha;
	UINT CPAGE_UTF8 = 65001;//essa linha e as 2 linhas a baixo são como uma especie de "locale" de forma bruta(só funciona em windows).
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
	introducao();
	while (escolha!=4){
		escolha=Menu(escolha);
	}
	return (0);
}