#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum command {ADD, DRAW, DRAWALL, RELATIONSHIP, LIST, QUIT, EnOF};
enum err{ ADD1=EnOF+1, ADD2, ADD3, ADD4, DRAWA1, DRAWA2, DRAWA3, DRAW1, DRAW2, DRAW3, REL1, REL2, REL3, LI1, LI2};
enum msg{msgDRAWA1=LI2+1, msgDRAW1, msgREL1, msgREL2, msgQUIT};
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

void writeFile(person root, FILE* file)
{

}
int eval(char* str)
{
    char * pch;
    char command[10];
    int test22 = 200;

    pch = strtok (str," ");
    pch = strtok (NULL, " ");
    person* persons[2];
    persons[0] = malloc(sizeof(person));
    persons[1] = malloc(sizeof(person));
    strcpy(command,pch);
    int personNr = 0;
    test22 = test22+ 2222;


    while (pch != NULL)
    {
        pch = strtok (NULL," ");
        if((!strcmp(command, "list") && pch!=NULL))
        {
            //Error list + arguments
            return -100;
        }
        if(!strcmp(command, "add"))
        {
            if(!strcmp(pch, "m"))
            {

            }else if (!strcmp(pch, "f"))
            {

            }else if (!strcmp(pch, "[f]"))
            {

            }else if (!strcmp(pch, "[m]"))
            {

            }else if (!strcmp(pch, "mgf"))
            {
                personNr = 1;
            }else if (!strcmp(pch, "fgf"))
            {
                personNr = 1;
            }else if (!strcmp(pch, "mgm"))
            {
                personNr = 1;
            }else if (!strcmp(pch, "fgm"))
            {
                personNr = 1;
            }else
            {
                strcat(persons[personNr]->name, pch);
            }

        }
    }

    if(!strcmp(pch, "add"))
    {
        printf("%s", pch);
    }else if(!strcmp(pch, "draw"))
    {

    }else if(!strcmp(pch, "draw-all"))
    {

    }else if(!strcmp(pch, "draw-all"))
    {

    }else if(!strcmp(pch, "list"))
    {

    }else if(!strcmp(pch, "quit"))
    {

    }else if(!strcmp(pch, "EOF"))
    {

    } else{

    }


    return 0;
}
int main(int argc, char** argv)
{

    char buffer[1024]="";
    char args[5][256];
    args[0][0] = ' ';

    while(1)
    {
        fflush(stdin);
        printf("esp> ");
        scanf("%s", buffer);
        eval(buffer);

        if (!strcmp(args[1], "add"))
        {

        }
        else if(!strcmp(args[1], "quit"))
            break;

    }
    return 0;
}