#include <iostream>
#include <fstream>
#include <vector>

bool is_number(std::string& expr)
{
    for (unsigned i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] > '9' || expr[i] < '0')
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> lexer(std::string line)
{
    auto *tokens = new std::vector<std::string>();
    std::string token;
    for (unsigned i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == ' ')
        {
            tokens.push_back(token);
            token.clear();
            continue;
        }
        token.append(line[i]);
    }
    return tokens;
}

int parsing(std::vector<std::string> tokens)
{
    std::string token;
    std::vector<std::string>::iterator it = tokens.begin();
    for(unsigned i = 0; it != tokens.end(); ++i, ++it)
    {
        cout << *it << "\n";

        /*
        if (is_number(tokens[i]))
        {
            std::cout << *it << "\n";
        }
        */
    }
    return 0;
}

int compute(std::string tokens)
{
    return parsing(lexer(tokens));
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