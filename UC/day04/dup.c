//文件描述符的复制
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER 1024

//dup复制出一个文件描述符，通过旧文件描述符打开写入数据，新文件描述符修改读写位置，在用旧文件描述符写入数据，查看数据内容，判断新旧描述符是否操作同一文件；
int main(){
    int oldfd = open("1.txt",O_RDWR);
    if (oldfd == -1){
        perror("open File error");
        return -1;
    }
    printf("oldfd = %d\n",oldfd);

    /*
    STDIN_FILENO 为 0，表示标准输入。
    STDOUT_FILENO 为 1，表示标准输出。
    STDERR_FILENO 为 2，表示标准错误
    */
   
    //int newfd = dup(oldfd);//文件描述符的复制
    int newfd = dup2(oldfd,STDOUT_FILENO);
    if(newfd == -1){
        perror("dum error");
        return -1;
    }
    printf("newfd = %d\n",newfd);

    //通过oldfd写入数据
    char* buf = "Hello Word";
    ssize_t size = write(oldfd,buf,strlen(buf));
    if(size == -1){
        perror("write error");
    }

    //通过newfd改变文件的读写位置
    off_t lseek1 = lseek(newfd,6,SEEK_SET);
    if(lseek1 == -1){
        perror("lseek error");
        return -1;
    }

    //用oldfd写入数据
    buf = "hahahahaha";
    ssize_t size1 = write(oldfd,buf,strlen(buf));
    if (size1 == -1){
        perror("write error");
        return -1;
    }
    char buf_read[BUFFER];
    ssize_t size2 = read(newfd,buf_read,BUFFER);
    if (size2 == -1){
        perror("read error");
        return -1;
    }

    close(oldfd);

    close(newfd);

    return 0;


}