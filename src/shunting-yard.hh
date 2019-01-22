#ifndef SHUNTING_YARD_HH
#define SHUNTING_YARD_HH

#include <iostream>
#include <string>
#include <vector>

class Lex
{
public:
    Lex(std::string expr)
        : curs_{0}
        , expr_{expr}
    {}
    char eat_tkn()
    {
        return expr_[curs_++];
    }
    bool at_end()
    {
        return expr_[curs_] == '\0';
    }
    void undo()
    {
        curs_--;
    }

private:
    unsigned curs_;
    std::string expr_;
};

int parsing(Lex& str);

#endif /* ! SHUNTING_YARD_HH */
