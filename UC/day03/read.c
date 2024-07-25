// 文件的读写
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
#define BUFFER_SIZE 6
int main(void){
    int fd = open("./open.txt",O_RDONLY);
    if (fd == -1){
        perror("open error");
        return -1;
    }

    printf("fd : %d\n",fd);

    //读取文件
    char buffer[BUFFER_SIZE];//读取数据后存放数据的内存
    ssize_t bytesRead;
    bytesRead = read(fd,buffer,BUFFER_SIZE);//从fd这个文件中读取BUFFER_SIZE个字节的数据，并将这个数据存放到buffer这个内存空间中。返回读取的字节数
    if(bytesRead == -1){
        perror("read ");
        return -1;
    }

    printf("从文件中读取到了%ld个字节的数据\n",bytesRead);
    printf("%s\n",buffer);
    close(fd);
    return 0;



}
