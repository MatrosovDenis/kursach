#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char atr[6][4] = {
"STR",
"DEX",
"CON",
"INT",
"WIS",
"CHA"};

 typedef struct pers{
    char name[50];
    char Class[20];
    char race[50];
    char eye[20];
    char skin[20];
    char heir[20];
    char character[20];
    int Age;
    int height;
    int weight;
    int LEVEL;
    int XP;
    int atribute[6];
    char skills[6][20];
    int AS[6];
    int HP;
} per;

typedef struct LNode{
    per* data;
    struct LNode* next;
}LN;

void(*func[2])(LN* l, int N);

per *getP(FILE *input){
    per* result;
    result = (per*)malloc(sizeof(per));
    if(result!=NULL){
        fscanf(input, "%s %s %s %d %d",
                &result->name, &result->Class, &result->race, &result->LEVEL, &result->XP);
        fscanf(input, "%d %d %d %s %s %s %s",
               &result->Age, &result->weight, &result->height, &result->eye, &result->skin, &result->heir, &result->character);
        fscanf(input, "%d %d %d %d %d %d",
               &result->atribute[0], &result->atribute[1], &result->atribute[2], &result->atribute[3], &result->atribute[4], &result->atribute[5]);
        fscanf(input, "%s %d %s %d %s %d %s %d %s %d %s %d",
               &result->skills[0], &result->AS[0], &result->skills[1], &result->AS[1], &result->skills[2], &result->AS[2], &result->skills[3],&result->AS[3], &result->skills[4],&result->AS[4], &result->skills[5], &result->AS[5]);

    }
    return result;
}

LN* getL(FILE* f){
    LN* l;
    l = (LN*)malloc(sizeof(LN));
    if(l!=NULL){
        l->data = getP(f);
        l->next = NULL;
    }
    return l;
}

LN* createnewNode(){
    LN* newNode;
    per* result;
    result = (per*)malloc(sizeof(per));
    if(result!=NULL){
        printf("Enter name, class and race: ");
        scanf("%s %s %s", &result->name, &result->Class, &result->race);
        result->LEVEL = 0;
        result->XP = 0;
        printf("Enter age, weight and height: ");
        scanf("%d %d %d", &result->Age, &result->weight, &result->height);
        printf("Describe eyes, skin, heir and character of your personage: ");
        scanf("%s %s %s %s", &result->eye, &result->skin, &result->heir, &result->character);
        result->atribute[0] = 3;
        result->atribute[1] = 3;
        result->atribute[2] = 3;
        result->atribute[3] = 3;
        result->atribute[4] = 3;
        result->atribute[5] = 3;
        printf("Please choose your skills! And write this with number of skill atribute bonus (1 - STR, 2 - DEX, 3 - CON, 4 - INT, 5 - WIS, 6 - CHA, EXAMPLE: Acrobatics 2 Athletics 1 ... Animal_Handling 5).  Your must give only 6 skills!: \n");
        scanf("%s %d %s %d %s %d %s %d %s %d %s %d",
            &result->skills[0], &result->AS[0], &result->skills[1], &result->AS[1], &result->skills[2], &result->AS[2], &result->skills[3],&result->AS[3], &result->skills[4],&result->AS[4], &result->skills[5], &result->AS[5]);
    }
    newNode = (LN*)malloc(sizeof(LN));
    if(newNode!=NULL){
        newNode->data = result;
        newNode->next = NULL;
    }
    return newNode;
}

void printP(per* person){
    printf("%s\t|\t%s\t|\t%s\t|\t%d\t|\t%d\t|\t\n", person->name, person->Class, person->race, person->LEVEL, person->XP);
    for(int i = 0; i< 120; i++){
        printf("-");
    }
    printf("\nAGE:%d\t|\tWeight:%d\t|\tHeight:%d\t|\tEye: %s\t|\tSkin: %s\t|\t\n", person->Age, person->weight, person->height, person->eye, person->skin);
    for(int i = 0; i< 120; i++){
        printf("-");
    }
    printf("\nHeir: %s\t|\tCharacter: %s\t|\r\n", person->heir, person->character);
    for(int i = 0; i< 120; i++){
        printf("-");
    }
    printf("\nSTR: %d\t  SKILLS:\t ATTRIBUTE:\t SIZE:", person->atribute[0]);
    printf("\nDEX: %d\t  %s\t %s\t\t %d", person->atribute[1], person->skills[0], atr[person->AS[0]-1], person->atribute[person->AS[0]-1]);
    printf("\nCON: %d\t  %s\t %s\t\t %d", person->atribute[2], person->skills[1], atr[person->AS[1]-1], person->atribute[person->AS[1]-1]);
    printf("\nINT: %d\t  %s\t %s\t\t %d", person->atribute[3], person->skills[2], atr[person->AS[2]-1], person->atribute[person->AS[2]-1]);
    printf("\nWIS: %d\t  %s\t %s\t\t %d", person->atribute[4], person->skills[3], atr[person->AS[3]-1], person->atribute[person->AS[3]-1]);
    printf("\nCHA: %d\t  %s\t %s\t\t %d", person->atribute[5], person->skills[4], atr[person->AS[4]-1], person->atribute[person->AS[4]-1]);
    printf("\nHP : %d\t  %s\t %s\t\t %d\n", person->atribute[2]*10, person->skills[5], atr[person->AS[5]-1], person->atribute[person->AS[5]-1]);
}

void fprintP(FILE* f, per* p){
    fprintf(f, "%s %s %s %d %d\n",
            p->name, p->Class, p->race, p->LEVEL, p->XP);
    fprintf(f, "%d %d %d %s %s %s %s\n",
            p->Age, p->weight, p->height, p->eye, p->skin, p->heir, p->character);
    fprintf(f, "%d %d %d %d %d %d\n",
            p->atribute[0], p->atribute[1], p->atribute[2], p->atribute[3], p->atribute[4], p->atribute[5]);
    fprintf(f, "%s %d %s %d %s %d %s %d %s %d %s %d\n",
            p->skills[0], p->AS[0], p->skills[1], p->AS[1], p->skills[2], p->AS[2], p->skills[3],p->AS[3], p->skills[4],p->AS[4], p->skills[5], p->AS[5]);
}

void printNode(LN* l){
    printP(l->data);
}

void fprintNode(FILE* f, LN* l){
    fprintP(f, l->data);
}

void deleteNode(LN* l, int ID, int N){
    LN* prew, *tmp;
    LN* now = l;
    if(ID == N){
        for(int i = 0; i < N-2; i++){
            now = now->next;
        }
        free(now->next->data);
        free(now->next);
        now->next = NULL;
    }
    else if(ID == 1){
        free(now->data);
        now->data = NULL;
        for(int i = 0; i< N-1; i++){
            now->data = now->next->data;
            now = now->next;
        }
        now->next = NULL;
    }
    else if(ID < N){
        for(int i = 1 ; i < ID; i++){
            prew = now;
            now = now->next;
        }
        prew->next = now->next;
        free(now->data);
        free(now);
    }
}

int more(char* a, char* b){
    int result;
    int i = 0, flag = 1;
    while(a[i]!='\0' && b[i]!='\0' && flag == 1){
        if(a[i] > b[i]){
            result = 1;
            flag = 0;
        }
        else if(a[i] > b[i]){
            result = 2;
            flag = 0;
        }
        else{
            result = 0;
            i++;
        }
    }
    return result;
}

void swap(LN* l, LN* n){
    per* tmp;
    tmp = l->data;
    l->data = n->data;
    n->data = tmp;
}

float everage(LN* l){
    float a = 0;
    for(int i = 0; i< 6; i++){
        a+=l->data->atribute[i];
    }
    return a/6;
}

LN* copy(LN* n){
    LN* l;
    l = (LN*)malloc(sizeof(LN));
    l->data = n->data;
    l->next = NULL;
    return l;
}

void reading(LN* l, int N){
    int flag = 1;
    if(N>0){
        int id = 1;
        int t = 1;
        LN* now = l;
        while(flag){
            system("cls");
            printNode(now);
            if(id == 1 && N!=1){
                printf("1 - next\n2 - back to menu\n");
                scanf("%d", &t);
                switch(t){
                    case 1:
                        id++;
                        now = now->next;
                    break;
                    case 2:
                        flag = 0;
                        break;
                }
            }
            else if(N == 1){
                printf("1 - back to menu\n");
                scanf("%d", &t);
                switch(t){
                    case 1:
                        flag = 0;
                    break;
                }
            }
            else if (id == N){
                printf("1 - previous\n2 - back to menu\n");
                scanf("%d", &t);
                switch(t){
                    case 1:
                        id--;
                        now = l;
                        for(int i = 0; i < id-1; i++) now = now->next;
                    break;
                    case 2:
                        flag = 0;
                        break;
                    }
            }
            else{
                printf("1 - next\n2 - previous\n3 - back to menu\n");
                scanf("%d", &t);
                switch(t){
                    case 1:
                        id++;
                        now = now->next;
                    break;
                    case 2:
                        id--;
                        now = l;
                        for(int i = 0; i < id-1; i++) now = now->next;
                        break;
                    case 3:
                        flag = 0;
                        break;
                }
            }
        }


    }
    else{
        printf("You have no one character!!!Pres any key to back to menu!!!");
        scanf("%d", &flag);
    }
}

void addLast(LN* l, LN* n){
    LN* now = l;
    while(now->next!=NULL){
        now = now->next;
    }
    now->next = copy(n);
}

void editNode(LN* l, int ID){
    LN* now = l;
    for(int i = 0; i < ID; i++){
        now = now->next;
    }
    int flag = 1, t = 0;
    while(flag == 1){
        system("cls");
        printNode(now);
        printf("What do you want to edit:\n1 - description (name, race etc.)\n2 - atributes (STR, CON etc.)\n3 - skills\n4 - nothing(exit)\n");
        scanf("%d", &t);
         switch(t){
                    case 1:
                        printf("Enter new description (name, class, race, age, weight, height, eyes, skin, heir, character)! \nEXAMPlE: denver rogue DarkElf 21 5 2 blue dark blonde ChaoticNeoutral\n");
                        scanf("%s %s %s %d %d %d %s %s %s %s", &now->data->name, &now->data->Class, &now->data->race, &now->data->Age, &now->data->weight, &now->data->height, &now->data->eye, &now->data->skin, &now->data->heir, &now->data->character);
                        break;
                    case 2:
                        printf("Enter new atributes (STR, CON, DEX, INT, WIS, CHA)! EXAMPLE: 4 5 6 7 8 9\n");
                        for(int i = 0; i< 6; i++) scanf("%d", &now->data->atribute[i]);
                        break;
                    case 3:
                        printf("Please choose your skills! And write this with number of skill atribute bonus (1 - STR, 2 - DEX, 3 - CON, 4 - INT, 5 - WIS, 6 - CHA)! EXAMPLE: Acrobatics 2 Athletics 1 ... Animal_Handling 5\n");
                        for(int i = 0; i< 6; i++){
                            scanf("%s %d", &now->data->skills[i], &now->data->AS[i]);
                        }
                        break;
                    case 4:
                        flag = 0;
                        break;
                }
        }
}

void findStr(LN* l, char* str, int N){
    LN* result;
    result = (LN*)malloc(sizeof(result));
    result->next = NULL;
    LN* now = l;
    LN* now2 = result;
    int count = 0, ent = 0;
    for(int i = 0; i < N; i++){
        ent = 0;
        if(strstr(&now->data->name, str) != NULL){
            ent = 1;
        }
        else if(strstr(&now->data->skin, str) != NULL){
            ent = 1;
        }
        else if(strstr(&now->data->eye, str) != NULL){
            ent = 1;
        }
        else if(strstr(&now->data->race, str) != NULL){
            ent = 1;
        }
        else if(strstr(&now->data->character, str) != NULL){
            ent = 1;
        }
        else if(strstr(&now->data->heir, str) != NULL){
            ent = 1;
        }
        else {
                for(int i = 0; i < 6; i++){
                    if(strstr(&now->data->skills[i], str) != NULL){
                        ent = 1;
                        i = 6;
                    }
                }
        }
        if(ent == 1){
            if(count == 0){
                result = copy(now);
            }
            else{
                addLast(result, now);
            }
            count++;
        }
        now = now->next;
    }
    system("cls");
    reading(result, count);
}
void sortName(LN* l, int N){
    LN* now  = l;
    for(int i = 0; i < N; i++){
        LN* now  = l;
        for(int j = 0; j < N - 1; j++){
            if(more(&now->data->name, &now->next->data->name) == 1)
            {
                swap(now, now->next);
            }
            now = now->next;
        }
    }
}

void sortRace(LN* l, int N){
    LN* now  = l;
    for(int i = 0; i < N; i++){
        LN* now  = l;
        for(int j = 0; j < N - 1; j++){
            if(more(&now->data->race, &now->next->data->race) == 2)
            {
                swap(now, now->next);
            }
            now = now->next;
        }
    }
}

void sortAtribute(LN* l, int N){
    LN* now  = l;
    for(int i = 0; i < N; i++){
        LN* now  = l;
        for(int j = 0; j < N - 1; j++){
            if(everage(now) < everage(now->next));
            {
                swap(now, now->next);
            }
            now = now->next;
        }
    }
}

void sortLevel(LN* l, int N){
    LN* now  = l;
    for(int i = 0; i < N; i++){
        LN* now  = l;
        for(int j = 0; j < N-1; j++){
            if(now->data->LEVEL > now->next->data->LEVEL)
            {
                swap(now, now->next);
            }
            now = now->next;
        }
    }
}

void sort(LN* l, int N){
    printf("Choose:\n1 - sort by name\n2 - sort by level\n3 - sort by atribute\n4 - sort by race\n5 - back to menu\n");
    int t = 0, flag = 1;;
    while((t < 1) || (t > 5)){
        scanf("%d", &t);
        if(t < 5){
            func[t-1](l , N);
        }
    }
}


void entryintheend(LN* header, LN* node, int N){
    int t;
    LN* now = header;
    for(int i = 0; i < N-1; i++) now = now->next;
    printNode(now);
    now->next = node;
}

int menu(LN* l, int N){
    int flag = 1;
    int flag2 = 1;
    char str[50];
    while(flag){
        system("cls");
        printf("Now you have %d character sheets!\nWhat we should do:\n1 - read\n2 - delete one\n3 - create one\n4 - sort\n5 - search\n6 - edit one\n7 - close\n", N);
        int t, k;
        scanf("%d", &t);
        switch(t){
    case 1:
        reading(l, N);
        break;
    case 2:
        system("cls");
        printf("Please enter ID of Node: ");
        scanf("%d", &k);
        if(k <= N){
            deleteNode(l, k, N);
            N--;
        }
        break;
    case 3:
        system("cls");
        entryintheend(l, createnewNode(), N);
        N++;
        break;
    case 4:
        system("cls");
        sort(l, N);
        break;
    case 5:
        flag2 = 1;
        while(flag2>0){
            system("cls");
            printf("Please enter request: ");
            scanf("%s", &str);
            findStr(l, str, N);
            system("cls");
            printf("0 - exit to menu\nAnother one - try again\n");
            scanf("%d", &flag2);
        }
        break;
    case 6:
        system("cls");
        printf("Please enter ID of Node: ");
        scanf("%d", &k);
        if(k <= N){
            editNode(l, k);
        }
        break;
    case 7:
        flag = 0;
        system("cls");
        printf("Thank you for using our programm!!!");
        break;
    default:
        system("cls");
        break;
        }
    }
    return N;
}

void reWrite(FILE* f, LN* l, int N){
    LN* now = l;
    fprintf(f, "%d\n", N);
    for(int i = 0; i< N; i++){
        fprintNode(f, now);
        now = now->next;
    }
};



int main()
{
    func[0] = sortName;
    func[1] = sortLevel;
    func[2] = sortRace;
    func[3] = sortAtribute;
    FILE* input;
    input = fopen("input.txt", "r");
    int N;
    fscanf(input, "%d", &N);
    LN* header;
    LN* now;
    header = getL(input);
    if(header!=NULL){
        now = header;
        for(int i = 1; i< N; i++){
            now->next = getL(input);
            now = now->next;
        }
        N = menu(header, N);
    }
    fclose(input);
    input = fopen("input.txt", "w");
    reWrite(input, header, N);
    fclose(input);
    free(header);
    free(now);
    return 0;
}
