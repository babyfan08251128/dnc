//打开关闭文件

#include <stdio.h>
#include <fcntl.h>//open()
#include <unistd.h>//close()
#include <sys/stat.h> //umask()
int main(){
    int fd = open("./open.txt",O_RDONLY);//open打开文件，设置为只读
    if(fd == -1){//判断是否打开失败，打开失败返回-1
        perror("open error");//open error: No such file or directory
        return -1;
    }
    printf("%d\n",fd);

    close(fd);//关闭打开的文件；

    mode_t old_umask = umask(0022);//获取当前的umask,并设置新的umask为0022
    printf("old umask : %o\n",old_umask);
    umask(old_umask);
    return 0;


}