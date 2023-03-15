#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

class calc {
    char* expression;   //要计算的表达式

    enum token { OPAREN, ADD, SUB, MULTI, DIV, EXP, CPAREN, VALUE, EOL };

    /*取出运算符栈中的两个元素*/
    void BinaryOp(token op, stack<int>& dataStack);

    /*从当前位置取出一个合法的符号*/
    token getOp(int& value);

public:
    calc(const char* s) {
        /*构造函数*/
        expression = new char[strlen(s) + 1];
        strcpy(expression, s);
    }

    ~calc() {
        if (expression) delete[] expression;
    }

    int result(); //计算结果

};

int calc::result() {
    token lastOp, topOp;
    stack<int> dataStack;  //数据栈
    stack<token> opStack;  //运算符栈
    int currentValue, result_value;
    char* str = expression; //记录初始位置
    while ((lastOp = getOp(currentValue)) != EOL) {
        /*尚未扫描完--必须加个括号，先进行前面的赋值，在进行bool运算*/
        switch (lastOp) {
        case VALUE: dataStack.push(currentValue); break;
        case CPAREN: //开闭括号间均可运算
            while (!opStack.empty() && (topOp = opStack.top()) != OPAREN) {
                BinaryOp(topOp, dataStack);
                opStack.pop();
            }
            if(topOp == OPAREN) opStack.pop(); //将OPAREN弹出
            if ((topOp != OPAREN)) cerr << "缺少左括号!" << endl;
            break;
        case OPAREN: opStack.push(OPAREN); break;
        case EXP: opStack.push(EXP); break;
        case MULTI:case DIV:
            while (!opStack.empty() && (opStack.top() >= MULTI)) {
                /*>=MULTI是使用枚举变量的性质*/
                BinaryOp(opStack.top(), dataStack);
                opStack.pop();
            }
            opStack.push(lastOp);
            break;
        case ADD:case SUB:
            while (!opStack.empty() && opStack.top() != OPAREN) {
                /*之前的运算符均可运算*/
                BinaryOp(opStack.top(), dataStack);
                opStack.pop();
            }
            opStack.push(lastOp);
            break;
        }
    }

    while (!opStack.empty()) {
        BinaryOp(opStack.top(), dataStack);
        opStack.pop();
    }
    if (dataStack.empty()) {
        cout << "无结果!" << endl;
    }

    result_value = dataStack.top();
    dataStack.pop();
    if (!dataStack.empty()) {
        cout << "缺少操作符!" << endl;
        return 0;
    }

    expression = str;
    return result_value;
}

void calc::BinaryOp(token op, stack<int>& dataStack) {
    int num1, num2;
    if (dataStack.empty()) {
        cerr << "缺少右操作数!" << endl;
        exit(1);
    }
    else {
        num2 = dataStack.top();
        dataStack.pop();
    }
   
    if (dataStack.empty()) {
        cerr << "缺少左操作数!" << endl;
        exit(1);
    }
    else {
        num1 = dataStack.top();
        dataStack.pop();
    }
    

    switch (op) {
        case ADD: dataStack.push(num1 + num2); break;
        case SUB: dataStack.push(num1 - num2); break;
        case MULTI: dataStack.push(num1 * num2); break;
        case DIV: dataStack.push(num1 / num2); break;
        case EXP: dataStack.push(pow(num1, num2)); break;
    }
}

calc::token calc::getOp(int& value) {
    /*先删除多余的空格*/
    while (*expression && *expression == ' ') {
        ++expression;
    }

    /*数字*/
    if (*expression >= '0' && *expression <= '9') {
        value = 0;
        while (*expression >= '0' && *expression <= '9') {
            value = value * 10 + *expression - '0';
            ++expression;
        }
        return VALUE;
    }

    /*其他运算符*/
    switch (*expression) {
        case '(': ++expression; return OPAREN;
        case ')': ++expression; return CPAREN;
        case '+': ++expression; return ADD;
        case '-': ++expression; return SUB;
        case '*': ++expression; return MULTI;
        case '/': ++expression; return DIV;
        case '^': ++expression; return EXP;
        default: return EOL;
    }
}


int main()
{
    calc exp1("(14+1*4) / (2*3^2)");
    cout << exp1.result() << endl;
    return 0;
}
