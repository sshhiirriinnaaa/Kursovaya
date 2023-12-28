#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>
#include <Windows.h>


#define SIZE 100
#define MAX_VERTICES 100

void create_matrix(int arr[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }
        }
    }
}

void print_matrix(int arr[SIZE][SIZE], int size) {
    printf("     ");
    for (int i = 0; i < size; i++) {
        printf("%4d  ",i );
    }
    printf("\n");
    printf("\n");


    for (int i = 0; i < size; i++) {
        printf("%4d ", i);
        for (int j = 0; j < size; j++) {
            printf("%4d  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



void fillMatrixRandomNeor(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            else {

                if (rand() % 5 == 0) {
                    matrix[i][j] = 0;
                    matrix[j][i] = 0;
                }
                else {
                    int randomValue = (rand() % 111) - 10;
                    matrix[i][j] = randomValue;
                    matrix[j][i] = randomValue;
                }
            }
        }
    }
}

void fillMatrixRandom(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 0; // �� ��������� ������ 0
            }
            else {
                // ���������� ����������� ��� �������� ��������, ����� ������� ���� ����� ���������
                if (rand() % 5 == 0) {
                    matrix[i][j] = 0;
                }
                else {
                    matrix[i][j] = (rand() % 111) - 10;
                }
            }
        }
    }
}
void floydWarshall(int matrix[SIZE][SIZE], int size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][k] != 0 && matrix[k][j] != 0) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }

    printf("��������� ������� ���������� ���������� ���������� ����� ������ ����� ������ \n");
    printf("\n");
    printf("\n");
    printf("     ");
    for (int i = 0; i < size; i++) {
        printf("%4d  ", i);
    }
    printf("\n");
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%4d ", i);
        for (int j = 0; j < size; j++) {
                printf("%4d  ", matrix[i][j]);
            }
        printf("\n");
    }
    printf("\n");

}


void saveGraphToFile(int matrix[SIZE][SIZE], int size) {

    char vibor;
    re: 
    printf("������ �� �� ��������� ���� � ����? (y/n): ");
    scanf(" %c", &vibor);  

    if (vibor == 'y' || vibor == 'Y') {
        char filename[100];  // ������� ������ ��� �������� ����� �����
        printf("������� ��� ����� ��� ����������: ");
        scanf("%s", filename);

        FILE* file = fopen(filename, "w");
        if (file == NULL) {
            perror("�� ������� ������� ����");
            goto re;
        }

        // ���������� ������� ����� � ����
        fprintf(file, "%d\n", size);


        fprintf(file, "\n");

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fprintf(file, "%d ", matrix[i][j]);
            }
            fprintf(file, "\n");  
        }

        fclose(file);
        printf("���� ������� �������� � ����� '%s'.\n", filename);
    }
    else if(vibor == 'n' || vibor == 'N') {
        printf("���� �� ��� �������� � ����.\n");
    }
    else {
        printf("�������� �����. ������� y ��� n\n");
        goto re;
    }
}


void readGraphFromFile(int matrix[SIZE][SIZE], int* size) {
    char filename[100];
    za:
    printf("������� ��� ����� ��� ������ �����: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ ��� �������� �����.\n");
        goto za;
    }

    if (fscanf(file, "%d", size) != 1) {
        printf("������: �� ������� ������� ������ ����� �� �����\n");
        fclose(file);
        goto za;
        
    }

    if (*size <= 0 || *size > SIZE) {
        printf("������: ������������ ������ ����� � �����\n");
        fclose(file);
        goto za;
       
    }

    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("������: �� ������� ������� ������� ��������� �� �����\n");
                fclose(file);
                goto za;
              
            }
        }
    }
    fclose(file);
    printf("���� ������� �������� �� ����� %s.\n", filename);
}



int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int nomer1;
    int nomer2;
    int nomer3;
    int size;
 //   printf("�������� ������\n");
  //  printf("�� �����\"������ � ������ �������������� � ���������� �������\"\n");
    //printf("�� ����\"���������� ��������� ������\"\n");
   // Sleep(5000);
   // system("cls");
    //printf("���������: �������� ����� ����������\n");
   // printf("������: 22���2\n");
    //Sleep(5000);
   // system("cls");


    while (1) {
        
        printf("����\n");
        printf("1. �������� ������\n");
        printf("2. �����\n");
        printf("������� ����� ������ ��������:");

        if (scanf("%d", &nomer1) != 1) {
            printf("������: ������� ���������� ����� ������ ����\n");
            while (getchar() != '\n'); // ������� ����� �����
            continue;
        }

        if (nomer1 < 1 || nomer1 > 3) {
            printf("������: ������ ������������ ����� ����\n");
            while (getchar() != '\n'); // ������� ����� �����
            continue; 
        }

        system("cls");

        switch(nomer1) {
        case 1: {

            printf("1.������������� �������������\n");
            printf("2.������ �������� �������\n");
            printf("3.��������� �� �����\n");
            printf("������� ����� ������ ��������:");
            if (scanf("%d", &nomer2) != 1) {
                printf("������: ������� ���������� ����� ������ ����\n");
                while (getchar() != '\n');
                continue;
            }

            if (nomer2 < 1 || nomer2 > 3) {
                printf("������: ������ ������������ ����� ����\n");
                while (getchar() != '\n'); 
                continue; 
            }
            system("cls");

            switch (nomer2) {

            case 1: {

                printf("1.��������������� ����\n");
                printf("2.����������������� ����\n");
                printf("������� ����� ������ ��������:");
                if (scanf("%d", &nomer3) != 1) {
                    printf("������: ������� ���������� ����� ������ ����\n");
                    while (getchar() != '\n'); 
                    continue;
                }

                if (nomer3 < 1 || nomer3 > 2) {
                    printf("������: ������ ������������ ����� ����\n");
                    while (getchar() != '\n'); 
                    continue; 
                }
                system("cls");

                switch (nomer3) {
                case 1: {
                    
                    printf("������� ������ ������� ��������� �� 1 �� 100:");
                    scanf("%d", &size);
                    if (size <= 0 || size > SIZE) {
                        printf("������: ���������� ������ ������ ���� � �������� �� 1 �� 100\n");
                        continue;
                    }
                    system("cls");


                    int adjacencyMatrix[SIZE][SIZE];

                    create_matrix(adjacencyMatrix, size);
                    fillMatrixRandom(adjacencyMatrix, size);
                    print_matrix(adjacencyMatrix, size);

                    floydWarshall(adjacencyMatrix, size);

                    saveGraphToFile(adjacencyMatrix, size);


                    break;
                }
                case 2: {
                    printf("������� ������ ������� ��������� �� 1 �� 100:");
                    scanf("%d", &size);
                    if (size <= 0 || size > SIZE) {
                        printf("������: ���������� ������ ������ ���� � �������� �� 1 �� 100\n");
                        continue;
                    }
                    system("cls");

                int adjacencyMatrix[SIZE][SIZE];

                create_matrix(adjacencyMatrix, size);
                fillMatrixRandomNeor(adjacencyMatrix, size);
                print_matrix(adjacencyMatrix, size);

                floydWarshall(adjacencyMatrix, size);
                saveGraphToFile(adjacencyMatrix, size);

   

                    break;
                }
                }

                break;
            }
            case 2: {

                printf("������� ������ ������� ��������� �� 1 �� 100:");
                scanf("%d", &size);
                if (size <= 0 || size > SIZE) {
                    printf("������: ���������� ������ ������ ���� � �������� �� 1 �� 100\n");
                    continue;
                }
                system("cls");
                int adjacencyMatrix[SIZE][SIZE];

                create_matrix(adjacencyMatrix, size);
                for (int i = 0; i < size; i++) {
                    printf("������� �������� %d ������ ������� ���������:\n", i);
                    for (int j = 0; j < size; j++) {
                        scanf("%d", &adjacencyMatrix[i][j]);
                    }
                }
                system("cls");
                printf("���� �������:\n ");
                print_matrix(adjacencyMatrix, size);

                floydWarshall(adjacencyMatrix, size);
                saveGraphToFile(adjacencyMatrix, size);

                break;
            }
            case 3: {
                int adjacencyMatrix[SIZE][SIZE];
                int size;
                readGraphFromFile(adjacencyMatrix, &size);
                print_matrix(adjacencyMatrix, size);
                floydWarshall(adjacencyMatrix, size);
                saveGraphToFile(adjacencyMatrix, size);
                break;
            }

            }
            break;
            }

        case 2: {

        break;
        }
         
        }
    }
    return 0;
}
