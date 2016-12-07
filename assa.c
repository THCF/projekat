#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum command {ADD, DRAW, DRAWALL, RELATIONSHIP, LIST, QUIT, EnOF};
enum err{ ADD1=EnOF+1, ADD2, ADD3, ADD4, DRAWA1, DRAWA2, DRAWA3, DRAW1, DRAW2, DRAW3, REL1, REL2, REL3, LI1, LI2};
enum msg{msgDRAWA1=LI2+1, msgDRAW1, msgREL1, msgREL2, msgQUIT};

typedef struct person
{
    char name[256];
    char sex[256];
    struct person* mother;
    struct person* father;

}person;

//typedef struct listItem
//{
//   char name[256];
//   person* address;
//    struct listItem* nextItem;
//
//}listItem;

void messageControl(int code)
{
    switch(code)
    {
        case ADD1:
            printf("[ERR] Wrong usage - add <namePerson1> [m/f] <relation> <namePerson2> [m/f].\n");
            break;
        case ADD2:
            printf("[ERR] Sex does not match with relation.\n");
            break;
        case ADD3:
            printf("[ERR] Both people are the same.\n");
            break;
        case DRAW1:
            printf("[ERR] Wrong usage - draw <name> [m/f] <file-name>.\n");
            break;
        case DRAW2:
            printf("[ERR] This person does not exist.\n");
            break;
        case DRAW3:
            printf("[ERR] Could not write file.\n");
            break;
        case DRAWA1:
            printf("[ERR] Wrong usage - draw-all <file-name>.\n");
            break;
        case DRAWA2:
            printf("[ERR] No entries available.\n");
            break;
        case DRAWA3:
            printf("[ERR] Could not write file.\n");
            break;

    }

}
void writeFile(person root, FILE *fp)
{	

	
	fprintf(fp, "%s  [%s] ->  %s  [%s]", root.name, root.sex, root.father->name, root.father->sex);
	writeFile(*root.father, fp);
	fprintf(fp, "%s  [%s] ->  %s [%s]", root.name, root.sex, root.mother->name, root.mother->sex);
	writeFile(*root.mother, fp);
}
int eval(char* str, person *persons[2])
{
    char * pch;
    char command[10];

    pch = strtok (str," ");
    //char arrayBuffer[10][256];
    persons[0] = malloc(sizeof(person));
    persons[1] = malloc(sizeof(person));
    strcpy(command,pch);
    int personNr = 0;
    char relation[10] = "";
    int multiNames = 0;

    while (pch != NULL)
    {
        pch = strtok (NULL," ");
        if((!strcmp(command, "list") && pch!=NULL))
        {
            //Error list + arguments
            return -100;
        }
        if(pch == NULL)
            break;
        if(!strcmp(command, "add"))
        {
            if(!strcmp(pch, "mother"))
            {
                personNr = 1;
                multiNames = 0;
            }else if (!strcmp(pch, "father"))
            {
                personNr = 1;
                multiNames = 0;
            }else if (!strcmp(pch, "[f]"))
            {
                strcpy(persons[personNr]->sex, pch);
            }else if (!strcmp(pch, "[m]"))
            {
                strcpy(persons[personNr]->sex, pch);
            }else if (!strcmp(pch, "mgf"))
            {
                strcpy(relation, pch);
                personNr = 1;
                multiNames = 0;
            }else if (!strcmp(pch, "fgf"))
            {
                strcpy(relation, pch);
                personNr = 1;
                multiNames = 0;
            }else if (!strcmp(pch, "mgm"))
            {
                strcpy(relation, pch);
                personNr = 1;
                multiNames = 0;
            }else if (!strcmp(pch, "fgm"))
            {
                strcpy(relation, pch);
                personNr = 1;
                multiNames = 0;
            }else
            {
                if(multiNames == 0)
                    strcat(persons[personNr]->name, pch);
                else{
                    strcat(persons[personNr]->name, " ");
                    strcat(persons[personNr]->name, pch);
                }
                multiNames = 1;
            }

        }

        if(!strcmp(command, "draw")) {


        }
    }

    if(!strcmp(command, "add"))
    {
        printf("%s\n", persons[0]->name);
        printf("%s\n", persons[0]->sex);
        printf("----\n");
        printf("%s\n", persons[1]->name);
        printf("%s\n", persons[1]->sex);
        //if(relation == mother)



        //if(firstPerson.address == NULL)
        //{
        //   strcpy(firstPerson.name, persons[0]->name);
        //   firstPerson.address = persons[0];
        //  nextPerson = malloc(sizeof(listItem));
        //  nextPerson->address = persons[1];
        //  strcpy(nextPerson->name, persons[1]->name);
        //  firstPerson.nextItem = nextPerson;
        //  lastPerson = nextPerson;
        //
        //  } else{
        //  nextPerson = malloc(sizeof(listItem));
        //  lastPerson->nextItem = nextPerson;
        //  strcpy(nextPerson->name, persons[0]->name);
        //  strcpy(nextPerson->address, persons[0]);
        //  lastPerson = nextPerson;
        //  nextPerson = malloc(sizeof(listItem));
        //  lastPerson->nextItem = nextPerson;
        //  strcpy(nextPerson->name, persons[1]->name);
        //  strcpy(nextPerson->address, persons[1]);
        //  lastPerson = nextPerson;
        //}
        //seekedNode = rundownTree(..., "name","sex")

        //person *newPerson = malloc(sizeof(Person));
        //strcpy(newPerson->name, name)
        //seekedNode.father = newPerson;
        return ADD;

    }else if(!strcmp(command, "draw"))
    {

    }else if(!strcmp(command, "draw-all"))
    {

    }else if(!strcmp(command, "draw-all"))
    {

    }else if(!strcmp(command, "list"))
    {

    }else if(!strcmp(command, "quit"))
    {
        return QUIT;
    }else if(!strcmp(command, "EOF"))
    {

    } else{

    }


    return 0;
}

person* rundownTree(person* root, char* name, char* sex)
{
    if(!strcmp(root->name,name) && !strcmp(root->sex, sex))
        return root;

    person* fatherside;
    person* motherside;

    if(root->father != NULL)
        fatherside = rundownTree(root->father, name, sex);
    if(root->mother != NULL)
        motherside = rundownTree(root->mother, name, sex);

    if(fatherside) {
        return fatherside;
    }
    else if(motherside)
    {
        return motherside;
    }
    else
        return NULL;
}

int main(int argc, char** argv)
{

    char buffer[1024]="";
    //char args[5][256];
    //args[0][0] = ' ';

    FILE *fp;
     fp= fopen("FamilyTree.dot", "w");
    person child;
    person father;
    person mother;
    strcpy(child.name, "Otto");
    strcpy(child.sex,  "m");
    strcpy(father.name, "FOtti");
    strcpy(father.sex, "m");
    strcpy(mother.name, "MOtto");
    strcpy(mother.sex, "f");
    child.father = &father;
    child.mother = &mother;
	//writeFile(child, fp);
    fclose(fp);
    person* persons[2];

    //listItem firstPerson;
    //firstPerson.address = NULL;
    //listItem *nextPerson;
    //listItem *lastPerson;
    int code;
    while(1)
    {
        printf("esp> ");
        scanf("%[^\t\n]", buffer);
        code = eval(buffer,persons);
        messageControl(code);
        if(code == QUIT)
        {
            break;
        }
        getchar();
    }
    return 0;
}
