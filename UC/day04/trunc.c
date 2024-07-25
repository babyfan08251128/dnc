//修改文件大小
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    //打开文件
    int fd = open("./trunc.txt",O_WRONLY | O_CREAT | O_TRUNC,0664);
    if (fd == -1){
        perror("open error");
        return -1;
    }

    //写入数据 abcde
    char* buf = "HELLO WORD";
    if (write(fd,buf,strlen(buf)) == -1){
        perror("write error");
        return -1;
    }

    //修改文件大小
    if (truncate("./trunc.txt",3)){
        perror("truncate error");
        return -1;
    }

    //再次修改文件大小为5
    if(ftruncate(fd,5)){
        perror("truncate error");
        return -1;
    }

    buf = "xyz";
    if (write(fd,buf,strlen(buf)) == -1){
        perror("write error");
        return -1;
    }

    //关闭文件
    close(fd);
    return 0;

}