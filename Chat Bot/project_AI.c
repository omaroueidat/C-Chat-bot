#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define N 50


char * Create_String(int n){
    char *str = (char*)malloc(n * sizeof(char));
    return str;
}

void Fill_String(char *str,char string[]){
    strcpy(str,string);
}

void GET_DATEandTIME(char *dat){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strcpy(dat,asctime(&tm));
}

int random_number(min_range,max_range){
    srand(time(NULL));

    int random_no_within_range = rand() % (max_range - min_range + 1) + min_range;

    return random_no_within_range;
}

char * REPLY_TO_HI(){
    char **str;
    int str_strings = 6;
    str = (char **)malloc(str_strings * sizeof(char *));

    //Creating strings inside the rows of str
    for (int i=0;i<str_strings;i++){
        str[i] = Create_String(N);
    }

    Fill_String(str[0],"Hi! How can I Assest You Today?");
    Fill_String(str[1],"Hi! How are you doing today?");
    Fill_String(str[2],"Hello! How can I Assest You Today?");
    Fill_String(str[3],"Hello! How are you doing today? ");
    Fill_String(str[4],"Hello! What do you want me to Assest you with?");
    Fill_String(str[5],"Hi! What do you want me to Assest you with?");

    int min_range = 0;
    int max_range = str_strings - 1;

    int random_NO_within_range = random_number(min_range,max_range);

    return str[random_NO_within_range];    
}

char * REPLY_TO_LOVE(){
    char **str;
    int str_strings = 7;
    str = (char **)malloc(str_strings * sizeof(char *));

    //Creating strings inside the rows of str
    for (int i=0;i<str_strings;i++){
        str[i] = Create_String(N);
    }

    Fill_String(str[0],"awww! ^-^ that's Nice!");
    Fill_String(str[1],"Happy to hear that! I wish you a good day!");
    Fill_String(str[2],"I appreciate your sentiment, but as an AI, I'm not capable of feeling love in the same way as humans.");
    Fill_String(str[3],"That's very kind of you to say. I value our friendship.");
    Fill_String(str[4],"I'm glad to have a positive impact on your life. Let me know how I can help you further.");
    Fill_String(str[5],"Thank you for sharing your feelings with me. Is there anything else you'd like to talk about?");
    Fill_String(str[6],"I may not be able to love you back, but I'm here to support you in any way I can.");
    int min_range = 0;
    int max_range = str_strings - 1;

    int random_NO_within_range = random_number(min_range,max_range);

    return str[random_NO_within_range]; 
}

char * REPLY_TO_JOKE(){
    char **str;
    int str_strings = 7;
    str = (char **)malloc(str_strings * sizeof(char *));

    //Creating strings inside the rows of str
    for (int i=0;i<str_strings;i++){
        str[i] = Create_String(N);
    }
    Fill_String(str[0],"Why did the golfer wear two pairs of pants? In case he got a hole in one!");
    Fill_String(str[1],"Why did the cookie go to the doctor? Because it felt crummy!");
    Fill_String(str[2],"Why did the computer go to the doctor? Because it had a virus!");
    Fill_String(str[3],"What did the left eye say to the right eye? Between us, something smells!");
    Fill_String(str[4],"Why did the chicken join a band? Because it already had drumsticks!");
    Fill_String(str[5],"Why did the bike fall over? Because it was two-tired!");
    Fill_String(str[6],"Why did the banana go to the doctor? Because it wasn't peeling well!");
    int min_range = 0;
    int max_range = str_strings - 1;

    int random_NO_within_range = random_number(min_range,max_range);

    return str[random_NO_within_range]; 
}

char * REPLY_TO_DONTUNDERSTAND(){
    char **str;
    int str_strings = 7;
    str = (char **)malloc(str_strings * sizeof(char *));

    //Creating strings inside the rows of str
    for (int i=0;i<str_strings;i++){
        str[i] = Create_String(N);
    }

    Fill_String(str[0],"I\'m sorry, I did\'t quite catch that. Can you please rephrase your question?");
    Fill_String(str[1],"I\'m not sure I understand what you\'re asking. Can you please provide more context?");
    Fill_String(str[2],"I\'m having trouble processing your input. Can you please try again?");
    Fill_String(str[3],"I\'m not programmed to understand that request. Can you please ask me something else?");
    Fill_String(str[4],"That\'s not within my realm of knowledge. Can you please ask me a different question?");
    Fill_String(str[5],"I\'m afraid I don\'t have an answer to that. Can you please ask me something else?");
    Fill_String(str[6],"I\'m sorry, I don\'t know what you mean. Can you please provide more information?");

    int min_range = 0;
    int max_range = str_strings - 1;

    int random_NO_within_range = random_number(min_range,max_range);

    return str[random_NO_within_range];    
}


//This function returns 1 if the string conatins a substring entered as input
int strstr_ignored(char *str,char *substring){
    if (!str || !substring)   //check if there is no NULL string
        return 0;

    //create copy of the strings to not lose access of the input strings
    char *str_copy = strdup(str);     
    char *substring_copy = strdup(substring);

    //transform the input strings_copy to lower case to make the comparision with ignored case
    for (int i=0;i<strlen(str_copy);i++)
        str_copy[i] = tolower(str[i]);
    
    for (int i=0;i<strlen(substring_copy);i++)
        substring_copy[i] = tolower(substring[i]);

    //return true(1) if there exist a substring in a given string and false(0) if not
    if (strstr(str_copy,substring_copy))
        return 1;
    else
        return 0;
}


int Check_HI(char *user){
    if (strstr_ignored(user,"hi") || strstr_ignored(user,"greetings") || strstr_ignored(user,"hello") || strstr_ignored(user,"hey")
        || strstr_ignored(user,"hola") || strstr_ignored(user,"good ") || strstr_ignored(user,"yo") || strstr_ignored(user,"salam") 
        || strstr_ignored(user,"ayo") || strstr_ignored(user,"marhaba") || strstr_ignored(user,"merhaba")
    )
        return 1;
    return 0;
}

void AI_Commands(char *user){
    char *respond;
    respond = Create_String(N);
    
    if (strstr_ignored(user,"date") || strstr_ignored(user,"hour") || strstr_ignored(user,"day") || strstr_ignored(user,"week")
        || strstr_ignored(user,"month") || strstr_ignored(user,"year") || strstr_ignored(user,"today") || strstr_ignored(user,"time")
    ){
        GET_DATEandTIME(respond);
        printf("AI: The date today is %s",respond);
        return;
    }
    else if(strstr_ignored(user,"calc") || strstr_ignored(user,"plus") || strstr_ignored(user,"divide") || strstr_ignored(user,"times")
            || strstr_ignored(user,"minus") || strstr_ignored(user,"sum") || strstr_ignored(user,"product") || strstr_ignored(user,"remainder")
            || strstr_ignored(user,"remaining") || strstr_ignored(user,"+") || strstr_ignored(user,"-") ||  strstr_ignored(user,"*") ||
                 strstr_ignored(user,"/")
    ){
        printf("AI: Opening Calculator...\n");
        system("calc");
        return;
    }
    else if(strstr_ignored(user,"how are you") || strstr_ignored(user,"how do you feel") || strstr_ignored(user,"you feel")
            || strstr_ignored(user,"are you fine") || strstr_ignored(user,"are you good") || strstr_ignored(user,"are you happy")
            || strstr_ignored(user,"are you nice") || strstr_ignored(user,"are you angry") || strstr_ignored(user,"are you hungry")
            || strstr_ignored(user,"are you in love") || strstr_ignored(user,"are you pretty") || strstr_ignored(user,"are you optimistic")
    ){
        printf("AI: I'm AI so I don't have feelings!\n");
        return;
    }
    else if(strstr_ignored(user,"love you") || strstr_ignored(user,"like you") || strstr_ignored(user,"great friend")
            || strstr_ignored(user,"when i talk to you") || strstr_ignored(user,"romantic relationships") || strstr_ignored(user,"comfort for you")
    ){
        respond = REPLY_TO_LOVE();
        printf("AI: %s\n",respond);
        return;
    }
    else if(strstr_ignored(user,"joke") || strstr_ignored(user,"make me laugh") || strstr_ignored(user,"make me happy")
            || strstr_ignored(user,"make me smile") || strstr_ignored(user,"tell me a jo") || strstr_ignored(user,"feeling sad")
            || strstr_ignored(user,"not okay")
    ){
        respond = REPLY_TO_JOKE();
        printf("AI: %s\n",respond);
        return;
    }
    else if(strstr_ignored(user,"open") || strstr_ignored(user,"run")

    ){
        char reply = 'n';
        do{
            printf("AI: Enter the full path of the application you want to open...\n");
            char *app = Create_String(N);
            scanf("%s",app);
            char command[50];
            sprintf(command, "start %s", app);

            if(!system(command)){
                printf("AI: Opening...\n");
            }
            else{
                printf("AI: The Provided Path is Incorrect!\n");
                getchar();
                printf("Press Y|y to continue: \n");
                scanf("%c",&reply);
                getchar();
            }
            
        } while ( (reply == 'y' || reply == 'Y') );
        return;
    }
    
    respond = REPLY_TO_DONTUNDERSTAND();
    printf("AI: %s\n",respond);
}


void Talk_With_AI(char *name){

    char *user;
    user = Create_String(N);
    int get_input_from_user=1; //to check if we get input from user or not
    
    printf("\t\t\t**********************\n\t\t\t  Enter exit to exit\n\t\t\t**********************\n");

    //while the user didnt input exit...
    do{   
        if (get_input_from_user){
            printf("%s: ",name);
            gets(user);
        }
        get_input_from_user = 1;

        //if the user entered any of hi's sentences then
        if (Check_HI(user)){

            //reply to hi 

            char *reply;
            reply = REPLY_TO_HI();
            printf("AI: %s\n",reply);


            //we have random reply
            //==> we have to check for the reply
                //--> if it conatins assest ==>we have directly to get the command from the user
                //--> if it doesnt contain assest ==> we have to chat with the user then get the commands

            if (strstr_ignored(reply,"assest")){
                continue;
            }
            else{

            //get the answer of how youre doing today

            printf("%s: ",name);
            gets(user);

            //reply to the previous answer
                if(strstr_ignored(user,"good") || strstr_ignored(user,"fine") || strstr_ignored(user,"well") || strstr_ignored(user,"nice")
                    || strstr_ignored(user,"happy") || strstr_ignored(user,"mood") || strstr_ignored(user,"woo")
                ){
                    printf("AI: Glad to hear that! What you want me to assest you with?\n");
 
                    continue;
                }
                else{
                    get_input_from_user=0;
                    continue;
                }
            }
            if (strstr_ignored(u))
        }
        else{
            AI_Commands(user);
            continue;
        }
        
    } while (!strstr_ignored(user,"exit"));
}







int main(){

    printf("\t\t\t**********************************************************************\n");

    printf("\t\t\t\t\tWelcome to AI, Enter /help for more help\n");

    printf("\t\t\t**********************************************************************\n");

    printf("Enter any key to continue: ");

    getch();

    printf("\n\n");

    char *name;
    name = Create_String(N);
    printf("Enter your name: ");
    gets(name);


    Talk_With_AI(name);


    return 0;
}