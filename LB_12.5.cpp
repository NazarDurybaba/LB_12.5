#include <iostream>
#include <stack>
#include <sstream>

// Функція для додавання чисел у стек
void pushNumbers(std::stack<int>& stack, int num) {
    stack.push(num);
}

// Функція для виведення значень елементів стеку на екран
void printStack(std::stack<int>& stack) {
    std::stack<int> tempStack = stack; // Копіюємо стек, щоб не втратити дані
    std::cout << "Stack elements: ";
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

// Функція для об'єднання двох стеків у третій
std::stack<int> concatenateStacks(std::stack<int>& stack1, std::stack<int>& stack2) {
    std::stack<int> resultStack;

    // Перенесення елементів першого стеку в результат
    while (!stack1.empty()) {
        resultStack.push(stack1.top());
        stack1.pop();
    }

    // Перенесення елементів другого стеку в результат
    while (!stack2.empty()) {
        resultStack.push(stack2.top());
        stack2.pop();
    }

    return resultStack;
}

int main() {
    std::stack<int> stack1, stack2;

    // Зчитування чисел для стеку 1
    std::string input;
    int num;
    std::cout << "Enter numbers for stack 1 (enter 0 to stop): ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> num && num != 0) {
        pushNumbers(stack1, num);
    }

    // Зчитування чисел для стеку 2
    std::cout << "Enter numbers for stack 2 (enter 0 to stop): ";
    std::getline(std::cin, input);
    std::istringstream iss2(input);
    while (iss2 >> num && num != 0) {
        pushNumbers(stack2, num);
    }

    // Виведення значень елементів обох стеків на екран
    std::cout << "Stack 1: ";
    printStack(stack1);
    std::cout << "Stack 2: ";
    printStack(stack2);

    // Об'єднання стеків
    std::stack<int> concatenatedStack = concatenateStacks(stack1, stack2);

    // Виведення значень елементів об'єднаного стеку на екран
    std::cout << "Concatenated Stack: ";
    printStack(concatenatedStack);

    return 0;
}
