//文件读写位置
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024
int main(){
    //打开文件
    int fd = open("1.txt",O_RDWR);
    if (fd == -1){
        perror("open file error");
        return -1;
    }

    char* buf = "Hello Word";
    ssize_t size = write(fd,buf,strlen(buf));
    if (size == -1){
        perror("write file error");
        return -1;
    }
    printf("文件的写入字节数是%ld\n",size);

    //修改文件读写位置
    off_t lseek1 = lseek(fd,5,SEEK_SET);
    if(lseek1 == -1){
        perror("lseek errer");
        return -1;
    }

    buf = "public";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write error");
        return -1;
    }

    if(lseek(fd,-8,SEEK_END) == -1){
        perror("lessk error");
        return -1;
    }

    buf = "nihao";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write error");
        return -1;
    }

    return 0;



}
