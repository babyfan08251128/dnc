//文件锁
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

 //加锁
int wlock(int fd,int w){
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_CUR;//锁区偏移起点 SEEK_SET/SEEK_CUR/SEEK_END
    lock.l_start = 0;
    lock.l_len = 0;//锁到文件结尾
    lock.l_pid = -1;
    int m = w ? F_SETLK : F_SETLKW;
    printf("m = %d\n",m);
    return fcntl(fd,w ? F_SETLK : F_SETLKW,&lock);
}

//解锁
int unlock(int fd){
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = -1;
    return fcntl(fd,F_SETLK,&lock);
}

int main(int argc,char* argv[]){

    //打开文件
    int fd = open("write.txt",O_RDWR);
    if (fd == -1){
        perror("open error");
        return -1;
    }
    //阻塞方式加锁
    //int lock_i = wlock(fd,0);
    //非阻塞方式加锁

    while (wlock(fd,1) == -1){
        if(errno == EACCES || errno == EAGAIN){
            printf("文件已被锁定,干点别的去\n");
            sleep(1);
        }else{
            perror("fcntl error");
            return -1;
        }
        
    }

    printf("加锁成功\n");

    //写入
    for (int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i])) == -1){
            perror("write error");
            return -1;
        }
    sleep(2);
    }

    //解锁
    if(unlock(fd) == -1){
        perror("unlock error");
        return -1;
    }

    //关闭文件
    close(fd);
    return 0;


}