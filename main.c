#include <stdio.h>

#define DIAS_SEMANA 7
#define MESES_ANO 12

void mostrar_calendario(int calendario[MESES_ANO][DIAS_SEMANA]) {
    char *meses[MESES_ANO] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *dias_semana[DIAS_SEMANA] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};

    printf("\n*** CALENDÁRIO ***\n");

    for (int mes = 0; mes < MESES_ANO; mes++) {
        printf("%s\n", meses[mes]);
        for (int i = 0; i < DIAS_SEMANA; i++) {
            printf("%s ", dias_semana[i]);
        }
        printf("\n");

        int dia = 1;
        int dia_semana = calendario[mes][0];
        for (int i = 0; i < DIAS_SEMANA; i++) {
            if (i < dia_semana) {
                printf("    ");
            } else {
                printf("%3d ", dia);
                dia++;
            }
        }
        printf("\n");
    }
}

void inserir_agendamento(int calendario[MESES_ANO][DIAS_SEMANA]) {
    int dia, duracao;
    printf("\nInsira a data de início do agendamento (mês e dia): ");
    scanf("%d", &dia);
    printf("Insira a duração do agendamento (em dias): ");
    scanf("%d", &duracao);

    // Verifica se há espaço disponível no dia para o agendamento
    int mes = 0;
    while (dia > 0) {
        dia -= calendario[mes][0];
        mes++;
    }

    if (calendario[mes - 1][dia + duracao - 1] < 5) {
        for (int i = dia; i < dia + duracao; i++) {
            calendario[mes - 1][i]++;
        }
        printf("Agendamento realizado com sucesso!\n");
    } else {
        printf("Não é possível agendar para este dia.\n");
    }
}

void mostrar_calendario_agendamentos(int calendario[MESES_ANO][DIAS_SEMANA]) {
    char *meses[MESES_ANO] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *dias_semana[DIAS_SEMANA] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};

    printf("\n*** CALENDÁRIO DE AGENDAMENTOS ***\n");

    for (int mes = 0; mes < MESES_ANO; mes++) {
        printf("%s\n", meses[mes]);
        for (int i = 0; i < DIAS_SEMANA; i++) {
            printf("%3d ", calendario[mes][i]);
        }
        printf("\n");
    }
}

int main() {
    int calendario[MESES_ANO][DIAS_SEMANA] = {0}; // Inicializa o calendário com zeros

    int dia_semana_primeiro_janeiro;
    printf("Informe o dia da semana em que 1º de janeiro cai (0 - Dom, 1 - Seg, ..., 6 - Sab): ");
    scanf("%d", &dia_semana_primeiro_janeiro);

    int ano_bissexto;
    printf("O ano é bissexto? (1 - Sim, 0 - Não): ");
    scanf("%d", &ano_bissexto);

    // Definição do dia da semana de 1º de janeiro
    calendario[0][dia_semana_primeiro_janeiro] = 1;

    // Definição do número de dias em cada mês
    int dias_meses[MESES_ANO] = {31, 28 + ano_bissexto, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Preenchimento do calendário
    int dia_semana_atual = dia_semana_primeiro_janeiro;
    for (int mes = 0; mes < MESES_ANO; mes++) {
        for (int dia = 1; dia <= dias_meses[mes]; dia++) {
            calendario[mes][dia_semana_atual] = dia;
            dia_semana_atual = (dia_semana_atual + 1) % DIAS_SEMANA;
        }
    }

    int opcao;
    do {
        printf("\nMENU:\n");
        printf("(1) Mostrar calendário\n");
        printf("(2) Inserir agendamento\n");
        printf("(3) Mostrar calendário com agendamentos\n");
        printf("(4) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrar_calendario(calendario);
                break;
            case 2:
                inserir_agendamento(calendario);
                break;
            case 3:
                mostrar_calendario_agendamentos(calendario);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}