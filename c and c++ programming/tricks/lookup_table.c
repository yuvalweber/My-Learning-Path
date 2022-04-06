#include <stdio.h>

enum Keys {
    Right,
    Left,
    Up,
    Down
};

int main(int argc, char* argv[])
{
    // initialize table
    char* strKeys[4];
    strKeys[Right] = "Right";
    strKeys[Left] = "Left";
    strKeys[Up] = "Up";
    strKeys[Down] = "Down";

    int key;
    printf("enter a key to show output to([Right=0,Left=1,Up=2,Down=3]): ");
    scanf("%d",&key);
    printf("the key that was entered is: %s",strKeys[key]);
    return(0);
}