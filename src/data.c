// Funções à manipulação de dados dentro das tabelas
// Created by dio on 25/11/23.
// Ainda não sei o que vai precisar pra cada função, na dúvida tudo

#include "data.h"
#include "table.h"
#include "database.h"
#include "aux_functions.h"
#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void create_row(Table vetorTabelas[10], const char *filename) {

    
    char nomeTabela[50];
    Table tabelaAtual;
    printf("Digite o nome da tabela para adicionar a linha: ");
    fgets(nomeTabela, 50, stdin);

    for (int i = 0; i < 10; i++) {
        if (strcmp(nomeTabela, vetorTabelas[i].name) == 0) {
            tabelaAtual = vetorTabelas[i];
            break;
        }
    }

    printf("Digite os valores que terão na linha: ");

    tabelaAtual.columns->entries = malloc(sizeof(void*) * 100);

    for (int i = 0; i < tabelaAtual.num_columns; i++) {
        if (tabelaAtual.columns[i].type == INT) {
            int *entrada = malloc(sizeof(int));
            scanf("%d", entrada);
            tabelaAtual.columns->entries[i] = entrada;
        } else if (tabelaAtual.columns[i].type == FLOAT) {
            float *entrada = malloc(sizeof(float));
            scanf("%f", entrada);
            tabelaAtual.columns->entries[i] = entrada;
        } else if (tabelaAtual.columns[i].type == DOUBLE) {
            double *entrada = malloc(sizeof(double));
            scanf("%lf", entrada);
            tabelaAtual.columns->entries[i] = entrada;
        } else if (tabelaAtual.columns[i].type == CHAR) {
            getchar(); // Consumir o caractere de nova linha anterior
            char *entrada = malloc(sizeof(char));
            scanf("%c", entrada);
            tabelaAtual.columns->entries[i] = entrada;
        } else if (tabelaAtual.columns[i].type == STRING) {
            char *entrada = malloc(50 * sizeof(char));
            fgets(entrada, 50, stdin);
            tabelaAtual.columns->entries[i] = entrada;
        }
    }

    save_tables_to_file(filename);

    // Liberar memória alocada para entradas
    for (int i = 0; i < tabelaAtual.num_columns; i++) {
        free(tabelaAtual.columns->entries[i]);
    }

    // Liberar o array de entradas
    free(tabelaAtual.columns->entries);
}

/* Implementação de função que cria uma nova linha na tabela:
     * 1. Recebe o nome da tabela
     * 2. Recebe os valores de cada uma das colunas
     * 3. Verifica se os valores são válidos
     * 4. Verifica se a linha já existe
     * 6. Verificar a chave primária
     * * 6.1 Em uma tabela deve existir um único valor para a chave primária, se o usuário tentar inserir um valor que já existe, deve retornar um erro
     */
void list_data() {
    /* Implementação de função que lista os dados de uma tabela em formato CSV:
     * 1. Recebe o nome da tabela
     * 2. Verifica se a tabela existe
     * 3. Devem ser obtidos do arquivo que armazena (a gente ja tem um coisa que inicializa e lê os dados)
     * 4. Lista os dados da tabela em formato CSV (mais bonitinho)
     */
}

void delete_data() {
    /* Implementação de função que deleta uma linha (registro, tupla, meu cu, so nome feio) da tabela:
     * 1. Recebe o nome da tabela
     * 2. Recebe o valor da chave primária da linha que deve ser deletada
     */
}

void search_data() {
    /* Implementação de função que procura por uma linha na tabela:
     * 1. Recebe o nome da tabela
     * 2. Sistema deve fornecer as colunas disponíveis para busca
     * 3. Recebe o nome da coluna que deve ser buscada
     * 3. Não entendi muito bem o que ele quer aqui, mas ele pede umas informações extras
     */
}

// Última atualização 2023-11-25 -- dio