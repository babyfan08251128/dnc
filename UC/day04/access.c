//访问测试
#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    if(argc < 2){
        fprintf(stderr,"用法:./a.out <文件名>\n");
        return -1;
    }

    printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);

    char* filename = argv[1];

    if (access(filename,F_OK) == -1){ //判断是否存在，存在返回0，不存在返回-1
        printf("%s : 不存在\n",filename);
    }else{
        printf("%s : 存在\n",filename);

        if (access(filename,R_OK) == -1){
            printf("%s : 不可读\n",filename);
        }else{
            printf("%s : 可读\n",filename);
        }

        if (access(filename,W_OK) == -1){
            printf("%s : 不可写\n",filename);
        }else{
            printf("%s : 可写\n",filename);
        }

        if (access(filename,X_OK) == -1){
            printf("%s : 不可执行\n",filename);
        }else{
            printf("%s : 可执行\n",filename);
        }
    }

    return 0;

}