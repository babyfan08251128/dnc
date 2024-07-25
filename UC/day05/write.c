// 写冲突
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
    int fd = open("write.txt",O_WRONLY);
    if (fd == -1){
        perror("open error");
        return -1;
    }

    
    for (int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i])) == -1){
            perror("write error");
            return -1;
        }
        sleep(1);
    }
    close(fd);
    return 0;

    
}
