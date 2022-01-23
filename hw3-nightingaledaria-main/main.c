#include <stdio.h>
#include <string.h>

int timeInSeconds(char time[100]) {

    int result = 0;
    result += (time[1] - '0') * 10 * 24 * 3600;
    result += (time[2] - '0') * 24 * 3600;
    result += (time[13] - '0') * 36000;
    result += (time[14] - '0') * 3600;
    result += (time[16] - '0') * 600;
    result += (time[17] - '0') * 60;
    result += (time[19] - '0') * 10;
    result += time[20] - '0';
    return result;
}

int main(int argc, char **argv) {


    int interval = 2;

    int maximum = 1;
    char result[1000][100]; //  строки адреса
    int cnt[1000]; // для каждого адреса сколько ошибок
    for (int i = 0; i < 1000; i++) {
        cnt[i] = 0;
    }
    int numberOfAdress = 0;

    FILE *F = fopen("C:\\Users\\809519\\Downloads\\access_log_Jul95", "r");
    char remote_addr[100];
    char sign1[2];
    char sign2[2];
    char local_time1[100];
    char local_time2[100];
    char request[100];
    //char request2[100];
    //char request3[100];
    char status[100];
    char bytes_send[100];

    int absoluteTime[2000000];
    int numberOfLogs = 0;
    int l;
    int r = 0;

    int flag = 1;
    while ((fscanf(F, "%s", remote_addr) != EOF) && (fscanf(F, "%s", sign1) != EOF)) {
        fscanf(F, "%s", sign2);
        fscanf(F, "%s", local_time1);
        fscanf(F, "%s", local_time2);
        fscanf(F, " \"%[^\"]\"", request);


        fscanf(F, "%s", status);
        while ('0' > status[0] || '9' < status[0]) {
            fscanf(F, "%s", status);
        }
        fscanf(F, "%s", bytes_send);


        flag = 1;
        if (status[0] == '5') {
            for (int i = 0; i < numberOfAdress; i++) {
                if (strcmp(remote_addr, result[i]) == 0) {

                    cnt[i]++;
                    flag = 0;
                    break;
                }
            }
            if (flag != 0) {
                strcpy(result[numberOfAdress], remote_addr);
                numberOfAdress++;
                cnt[numberOfAdress] = 1;
            }
        }
        absoluteTime[numberOfLogs] = timeInSeconds(local_time1);
        numberOfLogs++;


    }
    for (int i = 0; i < numberOfAdress; i++) {
        printf("For adress %s amount of mistakes is %d\n", result[i], cnt[i]);

    }

    for (int i = 0; i < numberOfLogs; i++) {
        l = i;

        r = l;
        while (r + 1 < numberOfLogs && absoluteTime[r + 1] - absoluteTime[l] <= interval) {
            r++;
        }
        if (r - l + 1 > maximum) {
            maximum = r - l + 1;
            printf("Maximum is %d r is %d l is %d \n", maximum, absoluteTime[r], absoluteTime[l]);
        }
    }
    printf("Maximum is %d  \n", maximum);
    printf("Number of logs is %d \n", numberOfLogs);
}
