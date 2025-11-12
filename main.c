#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 100
#define LINE_MAX 512

/* ----- Estruturas ----- */
typedef struct {
    int idMat;
    char fullName[NAME_MAX];
    float np1;
    float np2;
    float pim;
    int classId;
} StudentRecord;

typedef struct {
    int id;
    char title[NAME_MAX];
} ClassRecord;

/* ----- Prototipos ----- */
void menu();
void registerStudent();
void listStudents();
void registerClass();
void listClasses();
void linkStudentToClass();
void listStudentClassLinks();
void addSampleStudents();
int nextIdFromFile(const char *filePath);
void saveStudentTXT(const StudentRecord *s);
void pressEnterToContinue();

/* ----- Funções auxiliares ----- */
void pressEnterToContinue() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int nextIdFromFile(const char *filePath) {
    FILE *f = fopen(filePath, "r");
    if (!f) return 1;
    char buf[LINE_MAX];
    int maxid = 0, id;
    while (fgets(buf, sizeof(buf), f)) {
        if (sscanf(buf, "%d", &id) == 1 && id > maxid)
            maxid = id;
    }
    fclose(f);
    return maxid + 1;
}

/* ----- Funções principais ----- */

// Grava dados do aluno em formato texto
void saveStudentTXT(const StudentRecord *s) {
    FILE *f = fopen("students.txt", "a");
    if (!f) {
        printf("Erro ao abrir students.txt para escrita.\n");
        return;
    }
    fprintf(f, "--- Dados do Aluno ---\n");
    fprintf(f, "Matricula: %d\n", s->idMat);
    fprintf(f, "Nome: %s\n", s->fullName);
    fprintf(f, "NP1: %.1f\n", s->np1);
    fprintf(f, "NP2: %.1f\n", s->np2);
    fprintf(f, "PIM: %.1f\n", s->pim);
    fprintf(f, "TurmaID: %d\n\n", s->classId);
    fclose(f);
}

void registerStudent() {
    StudentRecord s;
    s.classId = -1;

    printf("\n--- CADASTRAR ALUNO ---\n");
    printf("Matricula (numero): ");
    if (scanf("%d", &s.idMat) != 1) {
        printf("Entrada inválida.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    printf("Nome completo: ");
    fgets(s.fullName, sizeof(s.fullName), stdin);
    s.fullName[strcspn(s.fullName, "\n")] = '\0';

    printf("Nota NP1: ");
    scanf("%f", &s.np1);
    printf("Nota NP2: ");
    scanf("%f", &s.np2);
    printf("Nota PIM: ");
    scanf("%f", &s.pim);
    getchar();

    saveStudentTXT(&s);
    printf("\nAluno salvo com sucesso no arquivo students.txt!\n");
    pressEnterToContinue();
}

void listStudents() {
    FILE *f = fopen("students.txt", "r");
    if (!f) {
        printf("\nNenhum aluno cadastrado ainda.\n");
        pressEnterToContinue();
        return;
    }

    printf("\n--- LISTA DE ALUNOS ---\n");
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
    pressEnterToContinue();
}

void registerClass() {
    ClassRecord c;
    c.id = nextIdFromFile("classes.txt");

    printf("\n--- CADASTRAR TURMA ---\n");
    printf("Nome da turma: ");
    fgets(c.title, sizeof(c.title), stdin);
    c.title[strcspn(c.title, "\n")] = '\0';

    FILE *f = fopen("classes.txt", "a");
    if (!f) {
        printf("Erro ao abrir classes.txt\n");
        return;
    }
    fprintf(f, "ID: %d | Nome: %s\n", c.id, c.title);
    fclose(f);

    printf("Turma gravada com sucesso (ID %d)\n", c.id);
    pressEnterToContinue();
}

void listClasses() {
    FILE *f = fopen("classes.txt", "r");
    if (!f) {
        printf("\nNenhuma turma cadastrada.\n");
        pressEnterToContinue();
        return;
    }

    printf("\n--- LISTA DE TURMAS ---\n");
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
    pressEnterToContinue();
}

void linkStudentToClass() {
    int mat, classId;
    printf("\n--- VINCULAR ALUNO A TURMA ---\n");
    printf("Matricula do aluno: ");
    if (scanf("%d", &mat) != 1) {
        printf("Entrada invalida.\n");
        while (getchar() != '\n');
        return;
    }
    printf("ID da turma: ");
    scanf("%d", &classId);
    getchar();

    FILE *f = fopen("links.txt", "a");
    if (!f) {
        printf("Erro ao abrir links.txt\n");
        return;
    }
    fprintf(f, "Aluno %d vinculado a Turma %d\n", mat, classId);
    fclose(f);

    printf("Vinculo gravado com sucesso!\n");
    pressEnterToContinue();
}

void listStudentClassLinks() {
    FILE *f = fopen("links.txt", "r");
    if (!f) {
        printf("\nNenhuma associacao encontrada.\n");
        pressEnterToContinue();
        return;
    }

    printf("\n--- VINCULOS ALUNO -> TURMA ---\n");
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
    pressEnterToContinue();
}

void addSampleStudents() {
    StudentRecord s;

    s.idMat = 1001;
    strcpy(s.fullName, "Flavio");
    s.np1 = 8.5; s.np2 = 7.5; s.pim = 7.0; s.classId = -1;
    saveStudentTXT(&s);

    s.idMat = 1002;
    strcpy(s.fullName, "Roberto");
    s.np1 = 8.0; s.np2 = 9.0; s.pim = 7.5; s.classId = -1;
    saveStudentTXT(&s);

    printf("\nExemplos inseridos (Flavio e Roberto)\n");
    pressEnterToContinue();
}

/* ----- Menu Principal ----- */
void menu() {
    int opt;
    do {
        printf("\n=== SISTEMA ACADEMICO (.TXT) ===\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Cadastrar turma\n");
        printf("4 - Listar turmas\n");
        printf("5 - Vincular aluno a turma\n");
        printf("6 - Listar vinculos aluno->turma\n");
        printf("7 - Inserir exemplos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opt) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida.\n");
            continue;
        }
        getchar();

        switch (opt) {
            case 1: registerStudent(); break;
            case 2: listStudents(); break;
            case 3: registerClass(); break;
            case 4: listClasses(); break;
            case 5: linkStudentToClass(); break;
            case 6: listStudentClassLinks(); break;
            case 7: addSampleStudents(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção invalida.\n"); pressEnterToContinue(); break;
        }
    } while (opt != 0);
}

int main() {
    printf("=== SISTEMA ACADEMICO (.TXT) ===\n");
    menu();
    return 0;
}
