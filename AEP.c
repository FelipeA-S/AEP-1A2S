//Bibliotecas usadas
#include<stdio.h>
#include<locale.h>
#include<string.h>

//Variaveis globais
int temperatura;

//faz o menu
void menu(){
	//Declarando a linguagem que o sistema vai funcionar
	setlocale(LC_ALL,"Portuguese");
	char enter[50];
	printf("\n===================================");
	printf("\n            BEM - VINDO            ");
	printf("\n===================================");
	printf("\n\nPressione ENTER para realizar o diagnóstico ");
	gets(enter);
}
//Função principal
void main(){
	int primeiras=0,gripe=0,dengue=0,conjutivite=0;
	//chamando o menu
	menu();
	
	//perguntas essenciais
	primeiras+=pergunta01();
	primeiras+=pergunta02();
	primeiras+=pergunta03();
	
	//perguntas respiratórias
	gripe+=pergunta04();
	gripe+=pergunta05();
	
	//perguntas dengue
	dengue+=pergunta06();
	dengue+=pergunta07();
	dengue+=pergunta08();
	
	//perguntas conjutivite
	conjutivite+=pergunta09();
	conjutivite+=pergunta10();
	
	//chamando função que analisará os resultados
	analisar(primeiras,gripe,dengue,conjutivite);
}

//Demais funções
//perguntas gerais
int pergunta01(){
	int resposta;
	printf("\nVocê está apresentando Febre?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		qualtmp();
		return 1;
	}else{
		return 0;
	}
}
void qualtmp(){
	printf("Quanto Graus está a sua febre? ");
	scanf("%d",&temperatura);
	getchar();
}
int pergunta02(){
	char resposta[10];
    printf("\nVocê sente Dores no Corpo, Mal-Estar ou Fraqueza intensa?");
    printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}

//perguntas sobre gripe	
int pergunta03(){
	int resposta;
	printf("\nSeus sintomas surgiram de forma rápida e repentina?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}
int pergunta04(){
	int resposta;
	printf("\nVocê está com Tosse ou Dor de Garganta?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}
int pergunta05(){
	int resposta;
	printf("\nVocê tem Coriza(nariz escorrendo) ou Congestão Nasal(nariz entupido)?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}

//perguntas sobre dengue
int pergunta06(){
	int resposta;
	printf("\nVocê sente Dor atrás dos Olhos ou uma Dor de Cabeça muito forte, especialmente na testa?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}
int pergunta07(){
	int resposta;
	printf("\nVocê notou Manchas Vermelhas na pele?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}
int pergunta08(){
	int resposta;
	printf("\nVocê sente Dor nas Articulações?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}

//perguntas sobre conjutivite
int pergunta09(){
	int resposta;
	printf("\nVocê está com os Olhos Avermelhados e/ou com Irritação/Coceira?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}
int pergunta10(){
	int resposta;
	printf("\nVocê notou a presença de Secreção ou 'Remela' nos olhos, ou eles estão Lacrimejando muito?");
	printf("\nResponda 1-sim ou 2-não: ");
	scanf("%d",&resposta);
	if(resposta==1){
		return 1;
	}else{
		return 0;
	}
}

//aqui analisa
void analisar(int p,int g,int d,int c){
	//caso todas as perguntas sejam verdadeiras
	if(p==3 && g==2 && d==3 && c==2){
		printf("Indico fortemente uma ida ao médico para o diagnóstico,");
		printf("Pois não foi capaz de deduzir o que poderia ser.");
	}else{
		if((p==2 && g==2)||(p==3 && g==1)){
			printf("\nDado as respostas, possivelmente pode ser uma gripe.");
			printf("\nMas lembre-se esse sistema não substitui um ida ao médico, ainda menos um diagnóstico!");
			printf("\nEntão quando possivel procure um médico para um diagnóstico mais certeiro.");
		}
		if((p==2 || p==3) && (d==2 || d==3)){
			printf("\nDado as respostas, possivelmente pode ser dengue.");
			printf("\nMas lembre-se esse sistema não substitui um ida ao médico, ainda menos um diagnóstico!");
			printf("\nEntão quando possivel procure um médico para um diagnóstico mais certeiro.");
		}
		if(c==2){
			printf("\nDado as respostas, possivelmente pode ser conjutivite.");
			printf("\nMas lembre-se esse sistema não substitui um ida ao médico, ainda menos um diagnóstico!");
			printf("\nEntão quando possivel procure um médico para um diagnóstico mais certeiro.");
		}
		if((p==0 || p==1)&&(g==0)&&(d>=0 && d<=2)&&(c==0 || c==1)){
			printf("\nDado as respostas, possivelmente pode ser nada.");
			printf("\nMas em qualquer mudança pode me consultar novamente.");
		}
	}
	
}
