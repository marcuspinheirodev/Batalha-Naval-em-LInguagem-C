#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main(){
    int linha_navio, coluna_navio, menu, inc = 0;
    int tabuleiro[LINHAS][COLUNAS];

    /*
      LEGENDA DO TABULEIRO:
      0 = Água
      3 = Navio posicionado
      5 = Área atingida por habilidade
      1 = Navio atingido por habilidade 
    */
    for(int i = 0 ; i < LINHAS ; i++){ 			                                   
        for(int j = 0 ; j < COLUNAS ; j++){         
            tabuleiro[i][j] = 0;    
            
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }                      

    /*
    Estrutura de repetição para que o usuário possa inserir 2 navios na matriz, executando a estrutura dentro do bloco de comando 2 vezes.
    */
    while (inc < 2 && menu != 5)
    {
        /*
        Menu interativo para o usuário selecionar a direção de posicionamento do navio,
        ao selecionar algum dos valores a variável "menu" tem esse valor atribuido ela.
        */
        printf("SELECIONE A DIRECAO QUE DESEJA POSICIONAR O NAVIO...\n");                 
        printf("1. Vertical\n");
        printf("2. Horizontal\n");
        printf("3. Diagonal direita\n");
        printf("4. Diagonal esquerda\n");
        printf("5. Sair do jogo.\n");
        scanf("%d", &menu);

        if(menu == 5){
            printf("Saindo do jogo...\n");
            return 0;
        }
        /*
        Estrutura de entrada de dados onde o usuário irá inserir dois valores de coordenadas entre 1 e 10,
        obedecendo a regra de não ultrapassar as bordas do tabuleiro por meio de excessões em cada case.
        */
        printf("INSIRA AS COORDENADAS ONDE O NAVIO SERA POSICIONADO(LINHA COLUNA...\n"); 
        scanf("%d %d", &linha_navio, &coluna_navio);

        if(menu == 1 && linha_navio < 9 && linha_navio > 0 && coluna_navio > 0 && coluna_navio <= 10 && tabuleiro[linha_navio - 1][coluna_navio - 1] != 3 && tabuleiro[linha_navio][coluna_navio - 1] != 3 && tabuleiro[linha_navio + 1][coluna_navio - 1] != 3){ 
            tabuleiro[linha_navio - 1][coluna_navio - 1] = 3;
            tabuleiro[linha_navio][coluna_navio -1] = 3;
            tabuleiro[linha_navio + 1][coluna_navio - 1] = 3;

        }else if(menu == 2 && coluna_navio < 9 && coluna_navio > 0 && linha_navio > 0 && linha_navio <= 10 && tabuleiro[linha_navio - 1][ coluna_navio - 1] != 3 && tabuleiro[linha_navio - 1][coluna_navio] != 3 && tabuleiro[linha_navio - 1][coluna_navio + 1] != 3){
            tabuleiro[linha_navio - 1][coluna_navio - 1] = 3;
            tabuleiro[linha_navio - 1][coluna_navio] = 3;
            tabuleiro[linha_navio - 1][coluna_navio + 1] = 3;
  
        }else if(menu == 3 && linha_navio > 1 && linha_navio < 10 && coluna_navio > 1 && coluna_navio < 10 && tabuleiro[linha_navio - 2][coluna_navio] != 3 && tabuleiro[linha_navio - 1][coluna_navio - 1] != 3 && tabuleiro[linha_navio][coluna_navio - 2] != 3){ 
            tabuleiro[linha_navio - 2][coluna_navio] = 3;
            tabuleiro[linha_navio - 1][coluna_navio - 1] = 3;
            tabuleiro[linha_navio][coluna_navio - 2] = 3;

        }else if(menu == 4 &&  linha_navio > 0 && linha_navio < 9 && coluna_navio > 0 && coluna_navio < 9 && tabuleiro[linha_navio - 1][coluna_navio - 1] != 3 && tabuleiro[linha_navio ][coluna_navio] != 3 && tabuleiro[linha_navio + 1][coluna_navio + 1] != 3){
            tabuleiro[linha_navio - 1][coluna_navio - 1] = 3;
            tabuleiro[linha_navio ][coluna_navio] = 3;
            tabuleiro[linha_navio + 1][coluna_navio + 1] = 3;

        }else{
            printf("Opção inválida...\n");
            inc -= 1;
        }
        
        //Laço para exibir a matriz preenchida com os 2 navio posicionados.
        for(int i = 0 ; i < LINHAS ; i++){ 			                                   
            for(int j = 0 ; j < COLUNAS ; j++){         
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        } 

        inc++;
    }

    /*
    Bloco de código referente às habilidades
    */
    int inc2 = 0;
    int menu_hab;
    int linha_hab, coluna_hab;

    while(inc2 < 2)
    {
        printf("SELECIONE A A HABILIDADE...\n");                 
        printf("1. Cone\n");
        printf("2. Cruz\n");
        printf("3. Octaedro\n");
        printf("4. Sair do jogo.\n");
        scanf("%d", &menu_hab);

        if(menu_hab == 4){
            return 0;

        }

        printf("INSIRA AS COORDENADAS ONDE O DESEJA USAR A HABILIDADE...\n"); 
        scanf("%d %d", &linha_hab, &coluna_hab);

        if(menu_hab == 1 && linha_hab > 0 && linha_hab < 9 && coluna_hab > 2 && coluna_hab < 9){
            for(int i = linha_hab ; i < linha_hab + 3; i++){
                for(int j = coluna_hab ; j < coluna_hab + 5 ; j++){
                    
                    if (i == linha_hab && j == coluna_hab){
                       
                        if (tabuleiro[i - 1][j - 1] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 1] = 5;

                        }else if(tabuleiro[i - 1][j - 1] == 3){
                            tabuleiro[i - 1][j - 1] = 1;
                        }

                    }else if(i == linha_hab + 1 && (j == coluna_hab || j == coluna_hab + 1 || j == coluna_hab + 2)){
                        
                        if (tabuleiro[i - 1][j - 2] != 3 && tabuleiro[i - 1][j - 2] != 5){
                            tabuleiro[i - 1][j - 2] = 5;

                        }else if(tabuleiro[i - 1][j - 2] == 3){
                            tabuleiro[i - 1][j - 2] = 1;
                        }

                    }else if(i == linha_hab + 2){
                       
                        if (tabuleiro[i - 1][j - 3] != 3 && tabuleiro[i - 1][j - 3] != 5){
                                tabuleiro[i - 1][j - 3] = 5;
                        }else if(tabuleiro[i - 1][j - 3] == 3){
                                tabuleiro[i - 1][j - 3] = 1;
                        }
                    }
                }
            }

        }else if(menu_hab == 2 && linha_hab > 0 && linha_hab < 10 && coluna_hab > 2 && coluna_hab < 9){
            for(int i = linha_hab ; i < linha_hab + 3; i++){
                for(int j = coluna_hab ; j < coluna_hab + 5 ; j++){
                    
                    if(i == linha_hab && j == coluna_hab){
                        if(tabuleiro[i - 1][j - 1] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 1] = 5;
                        }else if(tabuleiro[i - 1][j - 1] == 3){
                            tabuleiro[i - 1][j - 1] = 1;
                        }

                    }else if(i == linha_hab + 1){
                        if(tabuleiro[i - 1][j - 3] != 3 && tabuleiro[i - 1][j - 3] != 5){
                            tabuleiro[i - 1][j - 3] = 5;
                        }else if(tabuleiro[i - 1][j - 3] == 3){
                            tabuleiro[i - 1][j - 3] = 1;
                        }
                    }else if(i == linha_hab + 2 && j == coluna_hab){
                        if(tabuleiro[i - 1][j - 1] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 1] = 5;
                        }else if(tabuleiro[i - 1][j - 1] == 3){
                            tabuleiro[i - 1][j - 1] = 1;
                        }
                    }
                }
            }

        }else if(menu_hab == 3 && linha_hab > 0 && linha_hab < 10 && coluna_hab > 1 && coluna_hab < 9){
            for(int i = linha_hab ; i < linha_hab + 3; i++){
                for(int j = coluna_hab ; j < coluna_hab + 3 ; j++){
                   
                    if(i == linha_hab && j == coluna_hab){
                        if(tabuleiro[i - 1][j - 1] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 1] = 5;
                        }else if(tabuleiro[i - 1][j - 1] == 3){
                            tabuleiro[i - 1][j - 1] = 1;
                        }
                    }else if(i == linha_hab + 1){
                        if(tabuleiro[i - 1][j - 2] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 2] = 5;
                        }else if(tabuleiro[i - 1][j - 2] == 3){
                            tabuleiro[i - 1][j - 2] = 1;
                        }
                    }else if(i == linha_hab + 2 && j == coluna_hab){
                        if(tabuleiro[i - 1][j - 1] != 3 && tabuleiro[i - 1][j - 1] != 5){
                            tabuleiro[i - 1][j - 1] = 5;
                        }else if(tabuleiro[i - 1][j - 1] == 3){
                            tabuleiro[i - 1][j - 1] = 1;
                        }
                    }
                }
            }
        }else{
            printf("Opção inválida...\n");
            inc2--;
        }
        inc2++;
    }

    for(int i = 0 ; i < LINHAS ; i++){ 			                                   
        for(int j = 0 ; j < COLUNAS ; j++){         
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
