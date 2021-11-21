char* isInPath(char* program_name)
{
    char* path = getenv("PATH");
    char* splittedPath = strtok(path,":");
    char* path_to_check = malloc(sizeof(char*));
    while(splittedPath != NULL)
    {
        strcpy(path_to_check,splittedPath);
        strcat(path_to_check,"/");
        strcat(path_to_check,program_name);
        if(fopen(path_to_check,"r") != NULL)
        {
            return path_to_check;
        }
        splittedPath = strtok(NULL,":");
    }
    free(path_to_check);
    return NULL;
}

char* syscallName64(int syscallNumber)
{
    
}