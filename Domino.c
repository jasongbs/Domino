#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct peca{
	int id;
	int numeroEsq;
	int numeroDir;
}Peca;

typedef struct Peca peca;

typedef struct jogador{
	char jogador[20];
	int tipo;
	Peca pack[28];
	int qtdPecas;
	int vitorias;
}Jogador;

typedef struct Jogador jogador;

typedef struct game{
	int id;
	Peca *pecas;
	Peca pecasEmJogo[28];
	Jogador *jogadores; 
	int NJogadores;
	int NPecas;
	int NPecasEmJogo;
	int JogadorJogando;
}Game;

typedef struct Game game;

void criarPecas(Peca pecas[28]){
	int aux=7,i=0,j=0;
	
	int x,y,cont=0;

	for(x=0; x<=6; x++)
	{
		for(y=x;y<=6;y++)
		{
			pecas[cont].id = cont;
			pecas[cont].numeroEsq = x;
			pecas[cont].numeroDir = y;
			cont++;
		}		
	}	
}

int selecionaJogadorInicial(Game *game){
	int njg=0,i,IdMelhorPeca;
	int max[game->NJogadores];
	int maxId[game->NJogadores];
	bool stop;

	for(i=0; i<=game->NJogadores;i++){
		max[i]=-1;
	}
	
	do{
		stop=false;
		for(i=game->jogadores[njg].qtdPecas-1;  i>=0;i--){

			if( game->jogadores[njg].pack[i].id == 0 || game->jogadores[njg].pack[i].id == 7 || game->jogadores[njg].pack[i].id == 13 ||	game->jogadores[njg].pack[i].id == 18 ||
			game->jogadores[njg].pack[i].id == 22 ||	game->jogadores[njg].pack[i].id == 25 ||	game->jogadores[njg].pack[i].id == 27){
			if(max[njg]<game->jogadores[njg].pack[i].id){
			max[njg]=game->jogadores[njg].pack[i].id;
			maxId[njg]=i;
		}
		}
	}
	njg++;
	}while(njg!=game->NJogadores);
	
	int maiorPontos=-1,maiorCod=-1,somaTemp=-1;

	for(i=0;i<game->NJogadores;i++){
	
		if(max[i]>maiorPontos){
			
			maiorPontos=max[i];
			maiorCod = i;
			IdMelhorPeca=maxId[i];
			
		}
	}
	
	njg=0;
	
	if(maiorCod==-1){

		maiorPontos=0;
		maiorCod=0;
		
	do{
		for(i=game->jogadores[njg].qtdPecas; i<=0;i--){
		somaTemp=game->jogadores[njg].pack[i].numeroDir+game->jogadores[njg].pack[i].numeroEsq;
	if(somaTemp > somaTemp ){
			maiorPontos=game->jogadores[njg].pack[i].id;
			maiorCod=njg;
			IdMelhorPeca=i;
		}
	}
	}while(njg!=game->NJogadores && njg++);	
}
	game->JogadorJogando=maiorCod;
return IdMelhorPeca;
}

void mostrarPecas(Peca pecas[], int quantidadePecas){
	int cont=0;
	//printf("\nQuantidade de Pecas: %d\n",quantidadePecas);
	for(cont=0;cont<quantidadePecas && cont<20;cont++)
		{
			//printf("%d (%d ,%d )",pecas[cont].id,pecas[cont].numeroEsq,pecas[cont].numeroDir);
			//printf("%d = (%d ,%d )",cont+1,pecas[cont].numeroEsq,pecas[cont].numeroDir);
			//desenharNumeros(pecas[cont].numeroEsq,pecas[cont].numeroDir);
			printf("%d",cont+1);
			desenharPeca(pecas[cont].numeroEsq,pecas[cont].numeroDir);
			printf("\n");
		}	
}

void desenharNumeros(int numeroEsquerda, int numeroDireita){
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,187);
	
	printf("%c",186);
	
	//Primeira Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==2 || numeroEsquerda==0 || numeroEsquerda==1 || numeroEsquerda==4){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==3){
	printf(" %c %c %c",32,32,254);
	}

	printf(" %c",186);
	
	//Primeira Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroDireita==2 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==3){
	printf(" %c %c %c",32,32,254);
	}
	printf(" %c\n%c",186,186);
	
	//Segunda Linha Esquerda
	if(numeroEsquerda==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroEsquerda==5 || numeroEsquerda==3 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==2){
	printf(" %c %c %c",32,32,254);
	}
	printf(" %c",186);
	
	//Segunda Linha Direita
	if(numeroDireita==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroDireita==5 || numeroDireita==3 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==2){
	printf(" %c %c %c",32,32,254);
	}
	
	printf(" %c\n%c",186,186);
	
	//Terceira Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==4 || numeroEsquerda==2){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5 || numeroEsquerda==1 || numeroEsquerda==3) {
	printf(" %c %c %c",32,254,32);
	}else if(numeroEsquerda==0){
	printf(" %c %c %c",32,45,32);
	}
	printf(" %c",186);
	
	//Terceira Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroEsquerda==2){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5 || numeroDireita==1 || numeroDireita==3){
	printf(" %c %c %c",32,254,32);
	}else if(numeroDireita==0){
	printf(" %c %c %c",32,45,32);
	}
	printf(" %c\n%c",186,186);
	
	//Quarta Linha Esquerda
	if(numeroEsquerda==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroEsquerda==5 || numeroEsquerda==3 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==2){
	printf(" %c %c %c",254,32,32);
	}
	printf(" %c",186);
	
	//Quarta Linha Direita
	if(numeroDireita==6){
	printf(" %c %c %c",254,254,254);
	}else if(numeroDireita==5 || numeroDireita==3 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==4){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita==2){
	printf(" %c %c %c",254,32,32);
	}
	printf(" %c\n%c",186,186);
	
	//Quinta Linha Esquerda
	if(numeroEsquerda==6 || numeroEsquerda==4 || numeroEsquerda==2 || numeroEsquerda==1 || numeroEsquerda==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroEsquerda==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroEsquerda==3){
	printf(" %c %c %c",254,32,32);
	}
	
	printf(" %c",186);
	
	//Quinta Linha Direita
	if(numeroDireita==6 || numeroDireita==4 || numeroDireita==2 || numeroDireita==1 || numeroDireita==0){
	printf(" %c %c %c",32,32,32);
	}else if(numeroDireita==5){
	printf(" %c %c %c",254,32,254);
	}else if(numeroDireita == 3){
	printf(" %c %c %c",254,32,32);
	}
	
	printf(" %c",186);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188);
}

int desenharPeca(int numeroCima, int numeroBaixo){
	
		if(numeroCima!=numeroBaixo){
		printf("\n    %c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,187);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		desenharPecasVericais( numeroCima);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		printf("\n    %c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,185);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		desenharPecasVericais( numeroBaixo);
		printf("\n    %c%c%c%c%c%c%c%c%c",186,32,32,32,32,32,32,32,186);
		printf("\n    %c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,188);
	}else{
		desenharNumeros(numeroCima,numeroBaixo);
	}
	
}

int desenharPecasVericais(int numero){

	printf("\n    %c",186);
	//Primeira Linha 
	if(numero==0 || numero==1)
	printf(" %c %c %c",32,32,32);
	if(numero==2)
	printf(" %c %c %c",254,32,32);
	if(numero==3)
	printf(" %c %c %c",32,32,254);
	if(numero==4 || numero==5 || numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c\n    %c",32,186,186);
	
	//Segunda Linha 
	if(numero==0 )
	printf(" %c %c %c",32,196,32);
	if(numero==2 || numero==4 )
	printf(" %c %c %c",32,32,32);
	if(numero==1 || numero==3 || numero==5)
	printf(" %c %c %c",32,254,32);
	if(numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c\n    %c",32,186,186);	
	
	//Terceira Linha 
	if(numero==0 || numero==1)
	printf(" %c %c %c",32,32,32);
	if(numero==2)
	printf(" %c %c %c",32,32,254);
	if(numero==3)
	printf(" %c %c %c",254,32,32);
	if(numero==4 || numero==5 || numero==6)
	printf(" %c %c %c",254,32,254);
	
	printf("%c%c",32,186);
	
}

int sortear(Peca pecas[28], int tamanhoVetor, Jogador *jogador){

	int sorteados[28];
	int sorteado;
	int nSorteados=0;
	int i,j;
	
	if(tamanhoVetor<=7){		
		for( i=0; i<7; i++){
			jogador->pack[i].id = pecas[i].id;	
			jogador->pack[i].numeroDir=pecas[i].numeroDir;
			jogador->pack[i].numeroEsq=pecas[i].numeroEsq;
			jogador->qtdPecas=i+1;
			tamanhoVetor--;
		}
		return tamanhoVetor;
		pecas = NULL;
	}
	
	for(i=0;i<28 ;i++){
		sorteados[i]=-1;
	}

	srand(time(NULL));
	for( i=0; nSorteados<7 && tamanhoVetor!= 0; i++){
		sorteado = rand() % tamanhoVetor;
		if(indexof(sorteados, sorteado)==0){
			if(pecas[sorteado].id!=-1){
			jogador->pack[nSorteados].id = pecas[sorteado].id;	
			jogador->pack[nSorteados].numeroDir=pecas[sorteado].numeroDir;
			jogador->pack[nSorteados].numeroEsq=pecas[sorteado].numeroEsq;
			nSorteados++;
			jogador->qtdPecas=nSorteados;
			sorteados[nSorteados]=sorteado;
			removePeca(pecas,sorteado,tamanhoVetor);
			tamanhoVetor--;
			}
		}		
	}			
	return tamanhoVetor;
}

int indexof( int sorteados[28], int sorteado){
	int status=0,i;
	for(i=0;i<28 && status == 0;i++){
		if(sorteados[i]==sorteado){
			status=1;
		}
	}
	return status;
}

int removePeca( Peca vetor[28], int posicao, int tamanhoAtual){
	int i;
	for(i=posicao;i<tamanhoAtual;i++){
		vetor[i]=vetor[i+1];
		}
	} 
	
int inserePeca(Peca vetor[28], int tamanhoAtual){
	int i,x;
	Peca temp;
	temp=vetor[tamanhoAtual];
	for(i=tamanhoAtual;i>=0;i--){
		vetor[i+1]=vetor[i];
	}
		vetor[0]=temp;
}
	


void jogarPeca(Game *game, Jogador *jogador, int PosicaoPeca, int sentido){	
	if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroDir ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroDir || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir || 
	 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ||
	 jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq || 
	 game->NPecasEmJogo == 0){
	
		int NPecasEmJogo = game->NPecasEmJogo;
		
		if(game->NPecasEmJogo==0){
			game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
			game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
			game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;
		}
		
		if(sentido==0){
			if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroDir ||
		 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq ||
				 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq ||
		 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroDir){
		 			if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[0].numeroEsq){	
						game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
						game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
					}else if(jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[0].numeroEsq){
						game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroDir;
						game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroEsq;	
				}
			game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;
			}
		}else{
				if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ||
		 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
				 jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroEsq ||
		 		jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
		 			
		 			if(jogador->pack[PosicaoPeca].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
	
						game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroEsq;
						game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroDir;
					}else if(jogador->pack[PosicaoPeca].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir){
						game->pecasEmJogo[NPecasEmJogo].numeroDir = jogador->pack[PosicaoPeca].numeroDir;
						game->pecasEmJogo[NPecasEmJogo].numeroEsq = jogador->pack[PosicaoPeca].numeroEsq;	
				}
			game->pecasEmJogo[NPecasEmJogo].id = jogador->pack[PosicaoPeca].id;
		}
	}
	
	
		
		if(sentido==0){
		inserePeca(game->pecasEmJogo,NPecasEmJogo);
		}
		removePeca(jogador->pack,PosicaoPeca,jogador->qtdPecas-1);
		jogador->qtdPecas--;
		game->NPecasEmJogo++;
	}else{
		printf("\n     AVISO! Essa peca nao pode ser utilizada ai!\n");
	}
}

void ComprarPeca(Game *game, Peca pecas[28], Jogador *jogador){
//	printf("\nCOMPRANDO!!!\n");

	int sorteado;
	if(game->NPecas>0){
	srand(time(NULL));
	sorteado = rand() % game->NPecas;
	jogador->pack[jogador->qtdPecas].id = pecas[sorteado].id;	
	jogador->pack[jogador->qtdPecas].numeroDir = pecas[sorteado].numeroDir;
	jogador->pack[jogador->qtdPecas].numeroEsq = pecas[sorteado].numeroEsq;
	removePeca(pecas,sorteado,game->NPecas);
	jogador->qtdPecas++;
	game->NPecas--; 
	}else{
		printf("\n   AVISO! Não possui mais pecas para serem compradas!");
	}
}

int mudarJogador(Game *game){
	if(game->JogadorJogando < game->NJogadores-1){
		return ++game->JogadorJogando;
	}else{
		return game->JogadorJogando=0;
	}
}

int vericaPecas(Game *game, Jogador *jogador){
	int i,sorteio;	
		srand(time(NULL));
		sorteio = rand() % 2;

	if(sorteio==0){
		for(i=0;i<jogador->qtdPecas;i++){
	
		if(jogador->pack[i].numeroDir == game->pecasEmJogo[0].numeroEsq || 
		 jogador->pack[i].numeroEsq == game->pecasEmJogo[0].numeroEsq ){
		 	return (1+(i*1));
		 	
		 }else if(jogador->pack[i].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir || 
		 jogador->pack[i].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ){
		 	return ((i*-1)-1);
		 }
		}
} else{
			for(i=i<jogador->qtdPecas;i>=0;i--){
	
		if(jogador->pack[i].numeroDir == game->pecasEmJogo[0].numeroEsq || 
		 jogador->pack[i].numeroEsq == game->pecasEmJogo[0].numeroEsq ){
		 	return (1+(i*1));
		 	
		 }else if(jogador->pack[i].numeroDir == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir || 
		 jogador->pack[i].numeroEsq == game->pecasEmJogo[game->NPecasEmJogo-1].numeroDir ){
		 	return ((i*-1)-1);
		 }
		}
}
	return -100;
	
}
	
int verificarGanhador(Game *game){
	int i,j,ganhador=-1,pontos=-1, maiorPontuacao=-1, menorPontuacao=-1,pontuacao, maiorVitorias=0;
	printf("\n%c----------------------------------------------------------------------",204);
	printf("\n%c                           PLACAR:  ",204);
	for(i=0;i<=game->NJogadores-1;i++){
		pontuacao=0;

			if(game->NPecas!=0){
				if(game->jogadores[i].qtdPecas == 0){
					ganhador=i;
			}else if(pontos<game->jogadores[i].qtdPecas){
				pontos=game->jogadores[i].qtdPecas;
			}
		}else{

			for(j=0;j<game->jogadores[i].qtdPecas;j++){
				
			   pontuacao=game->jogadores[i].qtdPecas;
			
				if(pontuacao > maiorPontuacao){
					maiorPontuacao=pontuacao;
					pontos=pontuacao;
				}
				if(pontuacao < menorPontuacao || menorPontuacao ==-1){
					menorPontuacao = pontuacao;
					ganhador=i;
				}
			}
		}

			printf("\n%c Secao %d - Jogador %d Pecas = %d ",204,game->id,i+1,game->jogadores[i].qtdPecas);
	}
	printf("\n%c----------------------------------------------------------------------",204);
		
		game->jogadores[ganhador].vitorias++;	
		printf("\n%c     Ganhador da sessao atual: %d",204,ganhador);
		printf("\n%c----------------------------------------------------------------------",204);
		ganhador=-1;
		for(i=0;i<=game->NJogadores-1 && game->id>3;i++){
		if(game->jogadores[i].vitorias>= maiorVitorias){
		maiorVitorias=game->jogadores[i].vitorias;
		ganhador=i;
	
	}
	printf("\n%c     Secao %d - Jogador %d Possui = %d Vitorias",204,game->id,i+1,game->jogadores[i].vitorias);
	
	}

		getch();
	printf("\n%c-------------- PRECIONE ENTER PARA IR PARA PROXIMA SECAO ------------------",204);
return ganhador;
}
	
int main(int argc, char *argv[]) {
	
	Game game;
	//game.NPecas = 28;
	Peca pecas[28];
	game.pecas = &pecas;
	game.id = 0;
	int QTDJogadores, i=0, limite,bot=1,finalista;
		

	/** Criando a interface **/
	printf("\n%c================================================%c",201,187);
	printf("\n%c                    DOMINO                      %c",186,186);
	printf("\n%c                                                %c ",186,186);
	printf("\n%c  Quantos Jogadores?                            %c",186,186);
	printf("\n%c  --%c",186,32);
	
	scanf("%d",&QTDJogadores);

	Jogador jogador[QTDJogadores];
	game.NJogadores =QTDJogadores;
	printf("%c",186);
	printf("\n%c",186);
	do{
		
		printf("  (0) Player ou (1) BOT ? : ");
		printf("\n%c  -- ",186);
		scanf("%d",&jogador[i].tipo);
		
		if(jogador[i].tipo==0){
		printf("%c",186);
		printf("\n%c  Nome do Jogador %d: ",186,i+1);
		scanf("%s",&jogador[i].jogador);
		}else{
		snprintf(jogador[i].jogador, 10, "BOT %d",bot++);
		
		}
		printf("%c",186);
		printf("\n%c",186);
		printf("\n%c",186);
		printf("\n%c",186);
		printf("               Usuario Cadastrado!");
		printf("\n%c",186);
		printf("\n%c",186);
		printf("\n%c",186);
		printf("\n%c",186);
		i++;	
	}while(i<game.NJogadores);
	
	game.jogadores = &jogador;
	//system("cls");	
	
	do{
	game.NPecas = 28;
	game.pecas = &pecas;
	game.id++;
	game.NPecasEmJogo = 0;
	limite=0;
	finalista=-1;
	/** Criando as Peças**/
	criarPecas(pecas);
	system("cls");
	i=0;
	printf("\n%c===================================================",204);
	do{
	
	printf("\n%c  Sorteando as pecas do Jogador %d",186,i+1);	
	game.NPecas=sortear(pecas,game.NPecas,&jogador[i]);	
	Sleep(700);
	printf("\n%c  Sorteio concluida...  \n",186);	
	printf("%c===================================================",204);
	Sleep(850);
	i++;
	
	}while(i<game.NJogadores);
	Sleep(1000);
	system("cls");
	int inicio=1;

		/** Início de jogo **/
	int SelecionadaComecar = selecionaJogadorInicial(&game);	

	jogarPeca(&game,&jogador[game.JogadorJogando],SelecionadaComecar,1);//0 = cima 1 = baixo
printf("\n%c======================================================================",204);
	printf("\n%c Quem comecou foi Jogador %d",186,game.JogadorJogando+1);		
printf("\n%c======================================================================",204);
	printf("\n%c",186);
	Sleep(1000);
	int selecao,local;
	bool jogou;
	int  vezJogador;
	do{
		system("cls");
		jogou = false;
		vezJogador = mudarJogador(&game);
		
		do{
		printf("\n%c======================================================================",204);	
		printf("\n%c  Pecas em jogo: ",186);	
		printf("\n%c======================================================================\n",204);
		mostrarPecas(game.pecasEmJogo, game.NPecasEmJogo);
		if(jogador[vezJogador].tipo==0){
			
		
		printf("\n%c======================================================================",204);
		printf("\n%c Vez do Jogador  %d - %s -- Qtd Pecas: %d -- Podem ser compradas: %d",186,vezJogador+1,game.jogadores[vezJogador].jogador,game.jogadores[vezJogador].qtdPecas,game.jogadores[vezJogador].qtdPecas,game.NPecas);
		printf("\n%c----------------------------------------------------------------------",204);
		printf("\n%c Suas pecas: ",186);
		printf("\n%c----------------------------------------------------------------------\n",204);
		mostrarPecas(jogador[vezJogador].pack,jogador[vezJogador].qtdPecas);

		if(vericaPecas(&game,&jogador[vezJogador])>-100){
		printf("\n%c======================================================================",204);
		printf("\n%c  -- Escolha a peca: ",186);
		scanf("%d",&selecao);
		printf("%c%c  --  Qual local deseja inserir essa peca?  (0) Cima  (1) Baixo: ",186);
		scanf("%d",&local);
		printf("\n%c----------------------------------------------------------------------",204);
		jogarPeca(&game,&jogador[vezJogador],selecao-1,local);
		jogou=true;
		//system("cls");
		limite=0;
	}else if(game.NPecas>0){
		printf("\n%c----------------------------------------------------------------------",204);
			printf("\n%c  Jogador %s Precisa Comprar! ",186,jogador[vezJogador].jogador );
			printf("\n%c----------------------------------------------------------------------",204);
			ComprarPeca(&game, pecas, &jogador[vezJogador]);
			Sleep(2000);
			limite=0;
		
	}else{
		printf("\n%d  Passou a vez!! ",186);
		printf("\n%c----------------------------------------------------------------------",204);
		limite++;
		jogou=true;
	}
	
	}else{
		printf("\n%c======================================================================",204);
		printf("\n%c  BOT JOGANDO... %s  -- Qtd Pecas: %d -- Podem ser compradas: %d",186,game.jogadores[vezJogador].jogador,game.jogadores[vezJogador].qtdPecas,game.NPecas);
		printf("\n%c----------------------------------------------------------------------",204);
		
		int posicao=vericaPecas(&game,&jogador[vezJogador]);
		if(posicao!=-100){
			if(posicao<=0){	

				printf("\n%c Jogador Adversario Jogou uma nova peca!",186);	
				printf("\n%c----------------------------------------------------------------------",204);
				jogarPeca(&game,&jogador[vezJogador],(posicao*-1)-1,1);
				
				jogou=true;
			}else{
				
				printf("\n%c Jogador Adversario Jogou uma nova peca!",186);
				printf("\n%c----------------------------------------------------------------------",204);
				jogarPeca(&game,&jogador[vezJogador],posicao-1,0);
				
				jogou=true;
		}
			limite=0;
			Sleep(2000);
		}else if(game.NPecas>0){
			printf("\n%c Jogador Adversario Precisa Comprar! ",186);
			printf("\n%c----------------------------------------------------------------------",204);
			ComprarPeca(&game, pecas, &jogador[vezJogador]);
			jogou=false;
			Sleep(2000);
			limite=0;
	}else{
		printf("\n%d  Passou a vez!! ",186);
		printf("\n%c----------------------------------------------------------------------",204);
		limite++;
		jogou=true;
	}
	
	if(jogador[vezJogador].qtdPecas==0)
	inicio=0;
	

	}
	
	}while(jogou==false);

	if(limite==game.NJogadores)
	inicio=0;
	
	}while(inicio!=0);
	
	finalista=verificarGanhador(&game);
	game.id++;
	}while(finalista==-1);
	
	printf(" \nJogador Vencedor do Jogo: %d\n",finalista+1);
	
	return 0;
	

}


