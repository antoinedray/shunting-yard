#include <fstream>
#include <iostream>
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

std::vector<std::string>* lexer(std::string line)
{
    std::vector<std::string>* tokens = new std::vector<std::string>();
    std::string token;
    for (unsigned i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == ' ')
        {
            tokens->push_back(token);
            token.clear();
            continue;
        }
        token.push_back(line[i]);
    }
    tokens->push_back(token);
    return tokens;
}

int parsing(std::vector<std::string>* tokens)
{
    std::string token;
    std::vector<std::string>::iterator it = tokens->begin();
    std::vector<std::string>* op_stack = new std::vector<std::string>{};
    for (unsigned i = 0; it != tokens->end(); ++i, ++it)
    {
        if (is_number(*it))
        {
            std::cout << *it << " (number)\n";
        } else
        {
            op_stack->push_back(*it);
            std::cout << *it << " (operator)\n";
        }
    }
    delete tokens;
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
        compute(line);
        // DISPLAY FINAL RESULT: std::cout << compute(line) << "\n";
    }
}

int main(void)
{
    tty();
    return 0;
}