#include <iostream>


// [capture_list/introductor](params)->return_value_type{body}
// [=] capture everything by value; default btw
// [&] capture by ref
// end expression (after body) with another '(params)' for immediate execution


int main()
{
    // stored in var, called later
    auto func = [](){ std::cout << "Goodbye world!" << std::endl; };
    func();
    // immediate exec
    [](){ std::cout << "Goodbye world!1" << std::endl; }();
    // with params
    [](int a, int b){ std::cout << "a + b = " << a + b << std::endl; }(7, 3);
    auto add_func = [](int a, int b){ std::cout << "x + y = " << a + b << std::endl; };
    add_func(10, 25);
    // with return type
    auto add_lambda_with_return_type = [](int a, int b)->int{ return a + b; };
    int sum = add_lambda_with_return_type(420, 69);
    std::cout << sum << std::endl;
    // with capture
    int x = 77;
    int y = 23;
    [x, y](){ std::cout << "x + y = " << x + y << std::endl; }();
    // capture by value (default)
    int c = 42;
    auto func_by_val = [c](){std::cout << "Captured by value: " << c << std::endl; };

    for (int i = 0; i < 10; ++i) {
        std::cout << "Outer 'c' value: " << c << std::endl;
        func_by_val();
        c++;
    }
    // capture by ref
    int d = 24;
    auto func_by_ref = [&d](){std::cout << "Captured by ref: " << d << std::endl; };

    for (int i = 0; i < 10; ++i) {
        std::cout << "Outer 'd' value: " << d << std::endl;
        func_by_ref();
        d++;
    }
    // scoped capture
    int f = 199;
    int g = 1;
    auto func_scoped_val = [=](){std::cout<<"Captured f: " << f << "; captured g: " << g << std::endl;};

    for (int i = 0; i < 5; ++i) {
        std::cout << "Actual: f = " << f << "; g = " << g << std::endl;
        func_scoped_val();
        f++;
        g++;
    }
    // scoped by ref capture
    int k = 55;
    int l = 66;
    auto func_scoped_by_ref = [&](){std::cout<<"Captured by ref k: " << k << "; captured by ref l: " << l << std::endl;};

    for (int i = 0; i < 5; ++i) {
        std::cout << "Actual: k = " << k << "; l = " << l << std::endl;
        func_scoped_by_ref();
        k++;
        l++;
    }

    return 0;
}
