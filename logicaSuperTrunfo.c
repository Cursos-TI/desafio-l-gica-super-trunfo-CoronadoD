#include <stdio.h>

#define MAX_CIDADES 100
// Desafio Super Trunfo - Países

// Estrutura para armazenar informações da cidade
typedef struct {

    // Gerar código da carta
    char estado; // Exemplo: "A", "B"
    int cidade; // Exemplo: "1", "3"
    char codigo[3]; // Exemplo: "A1", "B3"

    // Informações da cidade
    char nome[20]; // Exemplo: São Paulo
    int populacao; // Exemplo: 12325000
    float area; // Exemplo: 1521.11
    float densidade_populacional; // Exemplo: Tem que gerar como resultado 8101.19
    float pib; // Exemplo: 699.28
    float pib_per_capita; // Exemplo: Tem que gerar como resultado 56749
    int pontosturisticos; // Exemplo: 50
    float super_poder // Exemplo: Comparação das cartas
} Cidade;

void calcularDados(Cidade *cidade) {
    if (cidade->area > 0) {
        cidade->densidade_populacional = cidade->populacao / cidade->area;
    } else {
        cidade->densidade_populacional = 0;
    }
    
    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / cidade->populacao;
    } else {
        cidade->pib_per_capita = 0;
    }

    if (cidade->super_poder > 0 ){
        cidade->populacao + cidade->area + cidade->pib + cidade->pontosturisticos + cidade->densidade_populacional + cidade->pib_per_capita;
    } else {
        cidade->super_poder = 0;

    }

}

void cadastrarCidade(Cidade cidades[], int *total) {
    if (*total >= MAX_CIDADES) {
        printf("\nLimite de cidades atingido!\n");
        return;
    }
    
    printf("\nCadastro da cidade %d:\n", *total + 1);

            // Leitura do estado
    printf(" Digite a letra do estado (A-H): ");
    scanf(" %c", &cidades[*total].estado);
            // Leitura do número da cidade
    printf(" Digite o número da cidade (1-4): ");
    scanf(" %d", &cidades[*total].cidade);  

            // Leitura do nome da cidade
    printf(" Digite o nome da cidade: ");
    scanf(" %s", cidades[*total].nome);
         // Leitura da população
    printf(" Digite a população(em milhões): ");
    scanf("%d", &cidades[*total].populacao);
        // Leitura da área
    printf(" Digite a área em milhões de km²: ");
    scanf("%f", &cidades[*total].area);
         // Leitura do PIB
    printf(" Digite o PIB em bilhões: ");
    scanf("%f", &cidades[*total].pib);
         // Leitura do número de pontos turísticos
    printf(" Digite o número de pontos turísticos:: ");
    scanf("%d", &cidades[*total].pontosturisticos);
    
    calcularDados(&cidades[*total]);
    (*total)++;
}

void listarCidades(Cidade cidades[], int total) {
    if (total == 0) {
        printf("\nNenhuma cidade cadastrada ainda!\n");
        return;
    }
    
    printf("\nLista de cidades cadastradas:\n");
    for (int i = 0; i < total; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Código da carta: %c%d \n", cidades[i].estado ,cidades[i].cidade);
        printf("Nome: %s\n", cidades[i].nome);
        printf("População: %d\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos turisticos: %d\n", cidades[i].pontosturisticos);
        printf("Densidade Populacional: %.2f habitantes/km²\n", cidades[i].densidade_populacional);
        printf("PIB per Capita: %.2f bilhões/habitante\n", cidades[i].pib_per_capita);
        printf("Super Poder: %.2f\n", cidades[i].super_poder);
    }
}

void CompararCidades(Cidade Cidade[], int total){
    if (total < 2){
        printf("\nNecessário ter pelo menos duas cidades cadastradas para comparar!\n");
        return;
    }

    int c1, c2;
    printf("\nDigite os indices das duas cidades (1 a %d): ", total);
    scanf("%d %d", &c1, &c2);

    if (c1 < 1 || c1 > total || c2 < 1 || c2 > total || c1 == c2){
        printf("\nIndices inválidos!\n");
        return;
    }

    c1--; c2--;
printf("\nComparação entre %s e %s: \n", Cidade[c1].nome, Cidade[c2].nome);
printf("Super Poder de %s: %.2f\n", Cidade[c1].nome, Cidade[c1].super_poder);
printf("Super Poder de %s: %.2f\n", Cidade[c2].nome, Cidade[c2].super_poder);

if (Cidade[c1].super_poder > Cidade[c2].super_poder){
    printf("%s Vence a comparação!\n", Cidade[c1].nome);
} else
if (Cidade[c2].super_poder > Cidade[c2].super_poder){
    printf("%s Vence a comparação!\n", Cidade[c2].nome);
} else {
    printf("A comparação terminou em empate!\n");
}
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int total = 0, opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar cidade\n");
        printf("2 - Listar cidades\n");
        printf("3 - Comparar duas cidades\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarCidade(cidades, &total);
                break;
            case 2:
                listarCidades(cidades, total);
                break;
            case 3:
                CompararCidades(cidades, total);
                break;    
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
    
    return 0;
}
