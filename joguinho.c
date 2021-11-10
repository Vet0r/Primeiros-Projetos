#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

//**********Declaração de Variaveis Globais**********
int tamanhoDoTabuleiroY=21;
int tamanhoDoTabuleiroX=45;
bool verificadorDeAsterisco=false;
int asteriscoX,asteriscoY;
int pontuacao=1000, backuppontuacao=1000;
int asteriscos=10;
char opcaoDoMenu=0;

//**********Inicialização de funções**********
void desenharTabuleiro();
void moverX();
void gotoxy();
void criarAsterisco();

//**********inicio do programa**********
int main(){
    UINT CPAGE_UTF8 = 65001;//Forçando o compilador a entender acentos e acracteres especiais
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    verificadorDeAsterisco=false;//deixa como false para evitar bug de não ter asterisco após loop
    printf("\t\t\t\tJOGUINHO\n\n\n\n\n\n");
    printf("Use W A S D para mover pelo menu e ESPAÇO para selecionar\n");
    system("pause");
    system("cls");
    menu();
    srand(time(NULL));//inicialização do time.h par usar a função de randomizar 
}
char boneco='x';
char texturatabuleiro='.';

int menu(){
    int y=4,i,opcaoDiff;
    opcaoDoMenu=1;
    pontuacao=backuppontuacao;
    system("cls");
    printf("use W ou S para mocer a seta\n");
    printf("\tJogar\n");
    printf("\tDificuldade\n");
    printf("\tSom\n");
    printf("\tGráficos\n");
    gotoxy(2,y);
    printf("->");
    while (opcaoDoMenu!=32){
        opcaoDoMenu=getch();
            switch (opcaoDoMenu){
        case 's':
            y++;
            break;
        case 'w':
            y--;
            break;
        default:
            break;
        }
        if (y<2||y>5){
            y=i;
        }
        else{
            i=y;
            printf("\b\b\b   ");
            gotoxy(4,y);
            printf("->");
        }
    }
    if (y==2){//iniciar o jogo
        opcaoDoMenu=1;
        system("cls");
        desenharTabuleiro();
        moverX();
        system("cls");
        main();
    }
    if (y==3){//modificações da difuculdade
        inicio:
        system("cls");
        printf("\n\n\t\t");
        printf("Digite a dificuldade \n0-Reino Encantado\n1-Tranquilaço\n2-Muito Fácil\n3-Fácil de Mais\n4-Fácil\n5-Médio\n6-Difícil\n7-Muito Difícil\n8-Psicopatia\n9-Insano\n10-Impossível\n");
        scanf("%i",&opcaoDiff);
        switch (opcaoDiff)
        {
        case 0:
            system("cls");
            printf("Você Ganhou!!!\n");
            system("pause");
            menu();
            break;
        case 1:
            boneco='x';
            texturatabuleiro='.';
            backuppontuacao=pontuacao;
            break;
        case 2:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=700;
            backuppontuacao=pontuacao;
            break;
        case 3:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=650;
            backuppontuacao=pontuacao;
            break;
        case 4:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=600;
            backuppontuacao=pontuacao;
            break;
        case 5:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=500;
            backuppontuacao=pontuacao;
            break;
        case 6:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=400;
            tamanhoDoTabuleiroX=62;
            tamanhoDoTabuleiroY=31;
            backuppontuacao=pontuacao;
            break;
        case 7:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=300;
            tamanhoDoTabuleiroX=62;
            tamanhoDoTabuleiroY=31;
            backuppontuacao=pontuacao;
            break;
        case 8:
            boneco='x';
            texturatabuleiro='.';
            pontuacao=300;
            tamanhoDoTabuleiroX=62;
            tamanhoDoTabuleiroY=31;
            backuppontuacao=pontuacao;
            break;
        case 9:
            pontuacao=300;
            tamanhoDoTabuleiroX=62;
            tamanhoDoTabuleiroY=31;
            texturatabuleiro='*';
            backuppontuacao=pontuacao;
            break;
        case 10:
            pontuacao=100;
            tamanhoDoTabuleiroX=62;
            tamanhoDoTabuleiroY=31;
            texturatabuleiro='*';
            backuppontuacao=pontuacao;
            break;
        default:
            printf("Não trole a dificuldade\n");
            system("pause");
            system("cls");
            goto inicio;
            break;
        }
        menu();
    }
    if (y==4){//definicoes de som
    system("cls");
    printf("\n\n\tNunca vou terminar isso, desculpa :/\n");
    system("pause");
    system("cls");
    //nunca vou terminar isso e pronto
    menu();
        
    }
    int escolhaDoTamanho=21;
    if (y==5){//modificar aparencia 
        system("cls");
        printf("Escolha o caractere que irá aparecer no tabuleiro: ");
        scanf(" %c",&texturatabuleiro);
        printf("Escolha o caractere que irá aparecer no boneco: ");
        scanf(" %c",&boneco);
        printf("Defina o tamanho do tabuleiro(Padrao: 21): ");
        scanf("%i",&escolhaDoTamanho);
        tamanhoDoTabuleiroX=(escolhaDoTamanho*2)+3;
        tamanhoDoTabuleiroY=escolhaDoTamanho;
        menu();
    }
}

void moverX(){
    asteriscos=10;
    pontuacao=backuppontuacao;
    int i,posicaoX,posicaoY;
    posicaoX=(tamanhoDoTabuleiroX/2)+8;
    posicaoY=(tamanhoDoTabuleiroY/2)+2;
    char teclaPressionada='a';

    gotoxy(posicaoX,posicaoY);//inicia o jogo no meio do tabuleiro
    printf("%c",boneco);

    while (posicaoY>3 && posicaoX>8 && posicaoY<tamanhoDoTabuleiroY+4 && posicaoX<tamanhoDoTabuleiroX+9 && pontuacao>0 && asteriscos>0){
        if (verificadorDeAsterisco==false){
            criarAsterisco(posicaoX,posicaoY);
        }
        teclaPressionada=getch();//movimwntação do x
        switch (teclaPressionada){
        case 'a':
            posicaoX--;
            break;
        case 'd':
            posicaoX++;
            break;
        case 'w':
            posicaoY--;
            break;
        case 's':
            posicaoY++;
            break;
        
        default:
            break;
        }
        printf("\b");//apaga a letra anterior para desenhar o quadrado em cima e dar o efeito de movimento
        printf("%c",texturatabuleiro);
        atualizarPontos();
        gotoxy(posicaoX,posicaoY);
        printf("%c",boneco);
        if (posicaoX==asteriscoX && posicaoY==asteriscoY){
            verificadorDeAsterisco=false;
            asteriscos--;
            atualizarPontos();
        }
    }
    system("cls");
    gotoxy(1,1);
    if(posicaoY<1 || posicaoX<7 || posicaoY>tamanhoDoTabuleiroY+2 || posicaoX>tamanhoDoTabuleiroX+8){
        printf("\tFIM DO JOGO \nVoce saiu dos limites do jogo.");
    }
    else if(pontuacao==0){
        printf("\t FIM DO JOGO\n Sua pontuação zerou");
    }
    else{
        printf("\tFIM DO JOGO \nSua pontuação foi de: %i",pontuacao);
    }
    printf("\n");
    system("pause");
    system("cls");
}

void gotoxy(int x, int y){//função que move o cursor para efeito visual
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
} 

void atualizarPontos(){
    pontuacao--;
    gotoxy(9,1);
    printf("    \b\b\b\b%i",pontuacao);
    gotoxy(12,2);
    printf("    \b\b\b%i",asteriscos);

}

void criarAsterisco(int posicao_do_X_X,int posicao_do_X_Y){//desenha o * em um lugar aleatorio do tabuleiro
    int x = 9+rand()% tamanhoDoTabuleiroX;   
    asteriscoX=x;
    Sleep (100);
    int y = 4+rand()% tamanhoDoTabuleiroY;
    asteriscoY=y;//gera uma posição randomica apra x e y no asterisco 
    Beep(200,100);
    gotoxy(asteriscoX,asteriscoY);//move o cursor para a futura posicao do asterisco
    printf("*");//desenha o asterisco
    gotoxy(posicao_do_X_X,posicao_do_X_Y);//move o cursor para a antida posição do x
    printf("%c",boneco);//por garantia desenha novamente o x
    //pontuacao++;
    verificadorDeAsterisco=true;//o verificador fica veradeiro para indicar que existe um * no mapa
}

void desenharTabuleiro(){
    char tabuleiro[tamanhoDoTabuleiroX][tamanhoDoTabuleiroY];//criação do tabuleiro com caracteres especiais;
    int x,y;
    printf("Passos: %i\n",pontuacao);
    printf("Asteriscos: %i",asteriscos);
    printf("\n\n");
    for (y = 0; y < tamanhoDoTabuleiroY; y++){
        printf("\t");
        for ( x = 0; x < tamanhoDoTabuleiroX; x++){
            printf("%c",texturatabuleiro);
        }
        printf("\n");
    }
    return('\0');
}