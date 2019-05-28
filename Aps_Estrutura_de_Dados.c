#include <stdio.h>
#include <stdlib.h>
#define NOME_DISC "Estrutura de Dados - 862"
#define NOME_ALUNO "Thiago da Silva Pereira Gomes"
#define MATRICULA_ALUNO 2017201840

            typedef struct EnoArvore{
             int chave;
             struct EnoArvore *esq;
             struct EnoArvore *dir;
             struct EnoArvore *interno;
            }Arvore;

            void showSubArvore(Arvore* t);
            void showArvore(Arvore* t);
            void inserirArvore(Arvore** t, int chave);
            int arvoreIsEmpty(Arvore* t);
            Arvore* createArvore();
            
            Arvore* createArvore(){
                return NULL;
            }

            int arvoreIsEmpty(Arvore* t){
                return t == NULL;
            }

            void showSubArvore(Arvore* t){

                if(!arvoreIsEmpty(t)){

                    printf("%d", t->chave);

                    showArvore(t->esq);
                    showArvore(t->dir);
                }

            }

            void showArvore(Arvore* t){
                if(arvoreIsEmpty(t)){
                  printf("[]");
                }

                if(!arvoreIsEmpty(t)){
                    if(t->chave % 10 == 0){
                        printf("[");
                    }else {
                        printf("(");
                    }

                    printf("%d", t->chave);
                    if(t->chave % 10 == 0){
                        printf("{");
                        showSubArvore(t->interno);
                        printf("}");
                    }

                    showArvore(t->esq);
                    showArvore(t->dir);

                    if(t->chave % 10 == 0){
                        printf("]");
                    }else {
                        printf(")");
                    }
                }
            }

            void inserirArvore(Arvore** t, int chave){

                if(*t == NULL){
                    *t = (Arvore*)malloc(sizeof(Arvore));
                    (*t)->esq = NULL;
                    (*t)->dir = NULL;
                    (*t)->interno = NULL;
                    (*t)->chave = chave;
                } else {

                    if(chave < (*t)->chave && chave%10 == 0){
                        inserirArvore(&(*t)->esq, chave);
                    }

                    if(chave > (*t)->chave && chave%10 == 0){
                        inserirArvore(&(*t)->dir, chave);
                    }

                     if((chave - (*t)->chave > 0) && (chave - (*t)->chave < 10)){
                        if((*t)->interno == NULL){
                            (*t)->interno = (Arvore*)malloc(sizeof(Arvore));
                            (*t)->interno->esq = NULL;
                            (*t)->interno->dir = NULL;
                            (*t)->interno->chave = chave;
                        }else {

                            if(chave < (*t)->interno->chave){
                                inserirArvore(&(*t)->interno->esq, chave);
                            }

                            if(chave > (*t)->interno->chave){
                                inserirArvore(&(*t)->interno->dir, chave);
                            }
                        }
                    return;
                    }

                    if(chave - (*t)->chave < 0){
                        inserirArvore(&(*t)->esq, chave);
                    }

                    if(chave - (*t)->chave > 0){
                        inserirArvore(&(*t)->dir, chave);
                    }
                }
            }

            int main() {

                int tecla = 0;
                while(tecla != 27){

                    Arvore* arv = createArvore();

                    printf("%s\n%s\n%d\n", NOME_DISC, NOME_ALUNO, MATRICULA_ALUNO);

                    printf("\n______Tecle 'ESC' para sair.\n______Tecle 'ESPAÇO' para escolher os valores.\n______Tecle 'QUALQUER OUTRA TECLA' para executar o modo predefinido.");
                    tecla = getchar();

                    if(tecla==32){
                       
                        int i;
                        int qtValores = 0;

                        printf("Digite a quantidade de valores desejada: ");
                        scanf("%d", &qtValores);

                        int valor[qtValores];
      
                        for(i = 0; i<qtValores; i++){
                            printf("Digite o valor: ");
                            scanf("%d", &valor[i]);
                        }

                        for(i = 0; i<qtValores; i++){
                            inserirArvore(&arv, valor[i]);
                        }

                        printf("\n\n");

                        showArvore(arv);                 
                        printf("\n\n");
                        getchar();
                    } else if(tecla != 27) {         
                        printf("Resultado Gerado:\n\n");
                        inserirArvore(&arv, 10);
                        inserirArvore(&arv, 60);
                        inserirArvore(&arv, 30);
                        inserirArvore(&arv, 50);
                        inserirArvore(&arv, 37);
                        inserirArvore(&arv, 64);
                        inserirArvore(&arv, 11);
                        inserirArvore(&arv, 62);
                        inserirArvore(&arv, 39);
                        inserirArvore(&arv, 58);
                        showArvore(arv);

                        printf("\n\n");
                        getchar();
                    }
                }
                printf("\n\nFinalizando. . .\n\n");
                return 0;
            }