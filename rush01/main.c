#include <unistd.h>

# define printError write(1, "Error\n", 6)

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
       if (!process_input(argv[1]))
            printError;
       rush(process_input(argv[1]));
    }
    else
        printError;
    return 0;
}
