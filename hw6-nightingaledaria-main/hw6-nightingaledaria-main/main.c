#include <stdio.h>
#include <string.h>


void create(char *fileArcive, char arrOfFiles[][1000], int amountOfFiles) {
    //printf("hi");
    int cnt = 0;


   // int bufferedNameFile[50][1000];
   char sCurrentFile[10];

   FILE *F = fopen(fileArcive, "w");
    for(int i = 0; i < amountOfFiles; i++){
        char  bufferedFile[10000];
        int k=0;
        int amountOfSymbolsInName = 0;
        while (arrOfFiles[i][k] != 0){
            sCurrentFile[k]=arrOfFiles[i][k];
            k++;
        }
        amountOfSymbolsInName=k;
        FILE *currentFile = fopen(sCurrentFile, "r");
        int character;

        /*while( (character = fgetc(currentFile)) != 0){

            bufferedNameFile[i][amountOfSymbolsInName] = character;
            amountOfSymbolsInName++;

        }*/

        fprintf(F, "%d", amountOfSymbolsInName);
        fprintf(F, "%s"," ");

        for(int j = 0; j < amountOfSymbolsInName; j++){
            fprintf(F, "%c", sCurrentFile[j]);
        }
        //fprintf(F, "%d", filesize());
        fprintf(F, "%s"," ");
        while ((character = fgetc(currentFile)) != EOF){

            bufferedFile[cnt] = character;
            cnt++;

        }
        fprintf(F, "%d", cnt);
        fprintf(F, "%s"," ");
        for(int i = 0; i < cnt; i++){
            fprintf(F, "%c", bufferedFile[i]);
        }
        cnt=0;
        fprintf(F, "%s"," ");
        fclose(currentFile);


    }
    fclose(F);


}

void extract(char *fileArcive) {

    FILE *F = fopen(fileArcive, "r");

    int character[1000];

    int k = 0;

    while ((character[k] = fgetc(F)) != EOF) {
        //число символов в имени файла
        int numberOfBytesOfNameFile = 0;
        numberOfBytesOfNameFile = numberOfBytesOfNameFile * 10 + character[k] - '0';
        k++;

        while ((character[k] = fgetc(F)) != ' ') {
            numberOfBytesOfNameFile = numberOfBytesOfNameFile * 10 + character[k] - '0';
            k++;
        }

        char characterForFileName[1000];
        //char space=fgetc(F);
        //k++;
        //считываем имя файла
        char nameOfFile[1000];
        int cnt = 0;

        for (int i = 0; i < numberOfBytesOfNameFile; i++) {
            characterForFileName[i] = fgetc(F);
            nameOfFile[i] = (char )(characterForFileName[i]);
            cnt++;
            k++;
        }
        nameOfFile[cnt] =0;
        //пропустить пробел
        //пропускаем пробел
        char space=fgetc(F);
        k++;

        //счиытваем количество символов в заархивированных файлов
        FILE *currentFile = fopen(nameOfFile, "w");

        int numberOfBytesInFile = 0;
        char characterForNumberOfBytesInFile;
        while ((characterForNumberOfBytesInFile = fgetc(F)) != ' ') {
            numberOfBytesInFile = numberOfBytesInFile * 10 + characterForNumberOfBytesInFile - '0';
            k++;
        }

        char characterForFileContent[1000];
        for (int j = 0; j < numberOfBytesInFile; j++) {
            characterForFileName[j] = fgetc(F);
            fprintf(currentFile, "%c", (char)characterForFileName[j]);
            k++;
        }
        space=fgetc(F);
        k++;
        fclose(currentFile);

    }
    fclose(F);

}

void list(char *fileArcive) {

    FILE *F = fopen(fileArcive, "r");

    int character[1000];

    int k = 0;

    while ((character[k] = fgetc(F)) != EOF) {
        //число символов в имени файла
        int numberOfBytesOfNameFile = 0;
        numberOfBytesOfNameFile = numberOfBytesOfNameFile * 10 + character[k] - '0';
        k++;

        while ((character[k] = fgetc(F)) != ' ') {
            numberOfBytesOfNameFile = numberOfBytesOfNameFile * 10 + character[k] - '0';
            k++;
        }
        //пропускаем пробел
        char characterForFileName[1000];
        //char space=fgetc(F);
        //k++;
        //считываем имя файла
        char nameOfFile[1000];
        int cnt = 0;

        for (int i = 0; i < numberOfBytesOfNameFile; i++) {
            characterForFileName[i] = fgetc(F);
            nameOfFile[i] = (char )(characterForFileName[i]);
            cnt++;
            k++;
        }
        nameOfFile[cnt] =0;
        //пропустить пробел
        //пропускаем пробел
        char space=fgetc(F);
        k++;
        printf("%s",nameOfFile);
        printf("%s","\n");
        //счиытваем количество символов в заархивированных файлов
        //FILE *currentFile = fopen(nameOfFile, "w");

        int numberOfBytesInFile = 0;
        char characterForNumberOfBytesInFile;
        while ((characterForNumberOfBytesInFile = fgetc(F)) != ' ') {
            numberOfBytesInFile = numberOfBytesInFile * 10 + characterForNumberOfBytesInFile - '0';
            k++;
        }

        char characterForFileContent[1000];
        for (int j = 0; j < numberOfBytesInFile; j++) {
            characterForFileName[j] = fgetc(F);
            //fprintf(currentFile, "%c", (char)characterForFileName[j]);
            k++;
        }
        space=fgetc(F);
        k++;
        //fclose(currentFile);

    }
    fclose(F);

}

void listold(char *fileArcive) {
    FILE *F = fopen(fileArcive, "r");

    int character;


    while ((character = fgetc(F)) != EOF) {
        int numberOfBytesOfNameFile = 0;
        while ((character = fgetc(F)) != ' ') {
            numberOfBytesOfNameFile = numberOfBytesOfNameFile * 10 + character - '0';
        }

        for (int i = 0; i < numberOfBytesOfNameFile; i++) {
            printf("%c", character = fgetc(F));

        }
        printf("\n");


        int numberOfBytesInFile = 0;
        while ((character = fgetc(F)) != ' ') {
            numberOfBytesInFile = numberOfBytesInFile * 10 + character - '0';
        }
        for (int j = 0; j < numberOfBytesInFile; j++) {
            character = fgetc(F);
        }
    }
    fclose(F);
}

int main(int argc, char **argv) {


    if (strcmp(argv[3], "--create") == 0) {
        char arrOfFiles[50][1000];

        //printf("hi");
        for(int i = 4 ; i < argc ; i++){
            for(int j = 0; j < strlen(argv[i]); j++) {
                arrOfFiles[i - 4][j] = argv[i][j];
            }
            arrOfFiles[i-4][strlen(argv[i]) ] = 0;

        }
        //printf("%d", arrOfFiles[0][0]);
        create(argv[2], arrOfFiles, argc-4);
    } else if (strcmp(argv[3], "--extract") == 0) {
        extract(argv[2]);
    } else {
        list(argv[2]);
    }


}
