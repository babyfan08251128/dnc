//向文件中写入数据
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    //打开文件
    int fd = open("./write.txt",O_RDWR);
    if (fd == -1){
        perror("open error");
        return -1;
    }

    printf("%d\n",fd);

    //写入数据
    char* buf = "hello word";
    //将字符串buf写入到fd中，写入字节数为strlen(buf)
    ssize_t size = write(fd,buf,strlen(buf));
    if (size == -1){
        perror("write error");
        return -1;
    }

    printf("实际写入%ld个字节的数据\n",size);
    close(fd);
    return 0;


}