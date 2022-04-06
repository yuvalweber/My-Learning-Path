// The credit for this genious idea goes to Andreas Kling 
#include <stdio.h>
#define FOR_EACH_TYPE        \
        __CUSTOM_FUNC(Right) \
        __CUSTOM_FUNC(Left)  \
        __CUSTOM_FUNC(Up)    \
        __CUSTOM_FUNC(Down)

enum Key
{
#define __CUSTOM_FUNC(x) x,
    FOR_EACH_TYPE   
#undef __CUSTOM_FUNC
};


int main(int argc, char* argv[])
{
    enum Key key_type;
    printf("enter a key to show output to([Right=0,Left=1,Up=2,Down=3]): ");
    scanf("%d",&key_type);
    switch (key_type)
    {
#define __CUSTOM_FUNC(x) case x: \
                         printf("key that chose was %s\n",#x); \
                         break;
                         FOR_EACH_TYPE
#undef __CUSTOM_FUNC
    default:
        printf("unkown key was chosen\n");
        break;
    }
    return(0);
}
