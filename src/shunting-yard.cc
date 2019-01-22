#include "shunting-yard.hh"

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int parsing(Lex& str)
{
    char c;
    std::vector<int> values;
    std::vector<char> ops;

    while (!str.at_end())
    {
        c = str.eat_tkn();

        if (c == ' ')
        {
            continue;
        } else if (c == '(')
        {
            ops.push_back(c);
        } else if (isdigit(c))
        {
            int val = 0;
            while (!str.at_end() && isdigit(c))
            {
                val = (val * 10) + (c - '0');
                c = str.eat_tkn();
            }
            if (!isdigit(c))
            {
                str.undo();
            }
            values.push_back(val);
        } else if (c == ')')
        {
            while (!ops.empty() && ops.back() != '(')
            {
                int val2 = values.back();
                values.pop_back();

                int val1 = values.back();
                values.pop_back();

                char op = ops.back();
                ops.pop_back();

                values.push_back(applyOp(val1, val2, op));
            }
            ops.pop_back();
        } else
        {
            while (!ops.empty() && precedence(ops.back()) >= precedence(c))
            {
                int val2 = values.back();
                values.pop_back();

                int val1 = values.back();
                values.pop_back();

                char op = ops.back();
                ops.pop_back();

                values.push_back(applyOp(val1, val2, op));
            }
            ops.push_back(c);
        }
    }
    while (!ops.empty())
    {
        int val2 = values.back();
        values.pop_back();

        int val1 = values.back();
        values.pop_back();

        char op = ops.back();
        ops.pop_back();

        values.push_back(applyOp(val1, val2, op));
    }
    return values.back();
}
