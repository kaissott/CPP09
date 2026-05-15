#include "RPN.hpp"
#include <cctype>
#include <cstddef>



RPN::RPN(char *args) {

    std::string   expression(args);
    bool                isSpace = false;

    for (size_t i = 0; i < expression.size() ; ++i) {
        if (std::isdigit(expression[i]) && isSpace == false) {
            this->numbers.push(expression[i] - '0');
            isSpace = true;
        }
        else if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') && isSpace == false) {
            if (this->numbers.size() < 2) {
                std::cout << "ERROR" << std::endl;
                return;
            }
            stockResult(expression[i]);
            isSpace = true;
        }
        else if (isSpace == true && expression[i] == ' '){
            isSpace = false;
        }
        else {
            std::cout << "Error\nBad token = " << expression[i] << std::endl;
            return;
        }
    }
    std::cout << "FINAL RESULT = " << this->numbers.top() << std::endl;
}

void    RPN::stockResult(char &oper) {

    const int right = this->numbers.top();
    this->numbers.pop();
    const int left = this->numbers.top();
    this->numbers.pop();

        switch (oper) {
            case('+') :
                std::cout << "Calcul is : " << left << " " << oper << " " << right << std::endl;
                this->numbers.push(left + right);
                break;
            case('-') :
                std::cout << "Calcul is : " << left << " " << oper << " " << right << std::endl;
                this->numbers.push(left - right);
                break;
            case('*') :
                std::cout << "Calcul is : " << left << " " << oper << " " << right << std::endl;
                this->numbers.push(left * right);
                break;
            case('/') :
                std::cout << "Calcul is : " << left << " " << oper << " " << right << std::endl;
                if (right == 0) {
                    std::cout << "Error\nCan't divide by 0" << std::endl;
                    return;
                }
                this->numbers.push(left / right);
                break;
            default:
                break;
        }
}

RPN& RPN::operator=(const RPN &other) {

    if (this != &other)
        *this = other;
    return *this;
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN::~RPN(){}