#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char isbn[20];
    float preco;
    int score;
    char editora[100];
} Livro;

typedef Livro* pLivro;

// Função para alocar memória para um vetor de structs Livro
pLivro livro_aloc(int qtde) {
    return (pLivro)malloc(qtde * sizeof(Livro));
}

// Função para ler os dados de um vetor de structs Livro
void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        // printf("Livro %d:\n", i + 1);

        // printf("Nome: ");
        getchar(); // Para consumir o caractere de nova linha deixado pelo scanf
        fgets(livros[i].nome, 100, stdin);
        livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0'; // Remove o '\n'

        // printf("ISBN: ");
        fgets(livros[i].isbn, 20, stdin);
        livros[i].isbn[strcspn(livros[i].isbn, "\n")] = '\0';

        // printf("Preço: ");
        scanf("%f", &livros[i].preco);

        // printf("Score (0-10): ");
        scanf("%d", &livros[i].score);

        // printf("Editora: ");
        getchar(); // Consumir o '\n' restante
        fgets(livros[i].editora, 100, stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';

        // printf("\n");
    }
}

// Função para exibir os dados de um vetor de structs Livro
void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
         printf("Livro %d:\n", i + 1);
         printf("Nome: %s\n", livros[i].nome);
         printf("ISBN: %s\n", livros[i].isbn);
         printf("Preço: R$ %.2f\n", livros[i].preco);
         printf("Score: %d\n", livros[i].score);
         printf("Editora: %s\n", livros[i].editora);
         printf("\n");
    }
}

// Função para liberar memória alocada para um vetor de structs Livro
void livro_desaloca(pLivro livros) {
    free(livros);
}

// Função principal
int main() {
    int qtde;

    // printf("Digite a quantidade de livros: ");
    scanf("%d", &qtde);

    if (qtde <= 0) {
        // printf("Nenhum livro a ser processado.\n");
        return 0;
    }

    // Aloca memória para os livros
    pLivro livros = livro_aloc(qtde);

    if (!livros) {
        // printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Lê os dados dos livros
    livro_ler(livros, qtde);

    // Exibe os dados dos livros
    // printf("\n--- Livros Cadastrados ---\n");
    livro_exibe(livros, qtde);

    // Libera a memória alocada
    livro_desaloca(livros);

    return 0;
}
