#include <stdio.h>
#include <string.h>
typedef struct person
{
    char name[257];
    char sex[2];
    struct person* mother;
    struct person* father;

}person;

typedef struct listItem
{
    char name[257];
    person* address;
    struct listItem* nextItem;

}listItem;

void writeFile(person root)
{

}
int eval(char* str)
{

 return 0;
}
int main(int argc, char** argv)
{

    char buffer[1024]="";
    char args[5][256];
    args[0][0] = ' ';
    char* pch;

    while(1)
    {
        printf("esp> ");
        scanf("%s", buffer);
        pch = strtok (buffer," ");

        if (!strcmp(args[1], "add"))
        {

        }
        else if(!strcmp(args[1], "quit"))
            break;
    }
    return 0;
}