#include <iostream>
using namespace std;

bool is_number(string& expr)
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

int parsing(string& expr)
{
    string token;
    while(expr >> token)
    {

    }
}

int compute(string& expr)
{
    parsing(expr);
}

void tty()
{
    string in;
    while (in != "exit")
    {
        cout << ">";
        cin >> in;
        cout << compute(in) << "\n";
    }
}

int main(void)
{
    tty();
    return 0;
}