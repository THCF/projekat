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

/*
	
 
 */


void writeFile(person root, FILE *fp)
{	

	
	fprintf(fp, "%s  [%s] ->  %s  [%s]", root.name, root.sex, root.father->name, root.father->sex);
	writeFile(*root.father, fp);
	fprintf(fp, "%s  [%s] ->  %s [%s]", root.name, root.sex, root.mother->name, root.mother->sex);
	writeFile(*root.mother, fp);
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
	writeFile(child, fp);

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
