#include "shunting-yard.hh"

int compute(std::string line)
{
    Lex str(line);
    return parsing(str);
}

void tty(void)
{
    std::string line;
    while (true)
    {
        std::cout << "> ";
        getline(std::cin, line);
        if (line == "exit")
        {
            return;
        }
        std::cout << compute(line) << "\n";
    }
}

int main(void)
{
    tty();
    return 0;
}