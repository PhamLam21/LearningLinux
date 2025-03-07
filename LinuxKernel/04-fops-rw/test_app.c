#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio_ext.h>

#define CDEV_PATH "/dev/m-device"

int fd, option;
char write_buf[1024];
char read_buf[1024];

void printMenu() {
    printf("****Please Enter the option*****\n");
    printf("            1.Write             \n");
    printf("            2.Read              \n");
    printf("            3.Exit              \n");
    printf("********************************\n");
    printf(">>> ");
}
int main() {
    printf("*********************************\n");
    printf("********Linux From Scratch*******\n");

    fd = open(CDEV_PATH, O_RDWR);
    if(fd < 0) {
        printf("Cannot open device file:%s...\n", CDEV_PATH);
        return -1;
    }

    while(1) {
        printMenu();

        scanf("%d%*c", &option);
        switch(option) {
            case 1:
                printf("Enter the string to write into driver: ");
                scanf("%[^\t\n]s%*c", write_buf);
                printf("Data writing...");
                lseek(fd, 0, SEEK_SET);
                write(fd, write_buf, strlen(write_buf));
                printf("DONE!\n\n");
                break;
            case 2:
                printf("Data reading ...");
                lseek(fd, 0, SEEK_SET);
                read(fd, read_buf, 1024);
                printf("DONE!\n");
                printf("Data: %s\n\n", read_buf);
                break;
            case 3:
                close(fd);
                exit(1);
                break;
            default:
                printf("Enter valid option\n");
                break;
        }
    }

    close(fd);
    return 0;
}