#include <iostream>
#include <getopt.h>
#include <set>
#include <string>
#include "calculator.h"

// Фіктивні обробники для кожного аргумента
void handleHelp() {
    std::cout << "Arg: Help\n";
}

void handleVersion() {
    std::cout << "Arg: Version\n";
}

void handleList() {
    std::cout << "Arg: List\n";
}

// Обробник для виклику функцій калькулятора
void handleCalc() {
    std::cout << "Arg: Calc\n";
    Calculator calc;
    std::cout << "  [Calc] 10.5 + 2.5 = " << calc.Add(10.5, 2.5) << "\n";
    std::cout << "  [Calc] 10.5 - 2.5 = " << calc.Sub(10.5, 2.5) << "\n";
}

int main(int argc, char* argv[]) {
    // Короткі форми ключів (додано 'c' для калькулятора)
    const char* const short_opts = "hvlc";

    // Довгі форми ключів
    const option long_opts[] = {
        {"help", no_argument, nullptr, 'h'},
        {"version", no_argument, nullptr, 'v'},
        {"list", no_argument, nullptr, 'l'},
        {"calc", no_argument, nullptr, 'c'},
        {nullptr, no_argument, nullptr, 0}
    };

    std::set<char> seen_args; // Відстеження вже оброблених ключів (ігнорування дублікатів)
    int opt;

    while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) != -1) {
        // Обробка невідомих параметрів
        if (opt == '?') {
            std::cerr << "Попередження: Виявлено невідомий параметр!\n";
            continue;
        }

        // Якщо аргумент вже був переданий раніше, ігноруємо його
        if (seen_args.count(opt)) {
            continue;
        }
        seen_args.insert(opt);

        // Виклик відповідного обробника
        switch (opt) {
        case 'h': handleHelp(); break;
        case 'v': handleVersion(); break;
        case 'l': handleList(); break;
        case 'c': handleCalc(); break;
        default: break;
        }
    }

    return 0;
}