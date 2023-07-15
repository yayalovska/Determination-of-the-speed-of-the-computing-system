#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const int OperationsCount = 40000;
double max_long_ops_per_sec = 0;

int main()
{
    cout << "Data type    " << "Operation     " << " Operations per second  " << "  Percentages   " << " Diagram" << endl;

    auto benchmark_long = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < OperationsCount; i++) {
            op_func();
        }
        auto t2 = high_resolution_clock::now();
        auto duration = static_cast<double>(duration_cast<microseconds>(t2 - t1).count());
        double ops_per_sec = OperationsCount * 8 / (duration / 1000);

        cout << fixed << setprecision(2);

        if (ops_per_sec > max_long_ops_per_sec) {
            max_long_ops_per_sec = ops_per_sec;
        }

        int percentage = static_cast<int>((ops_per_sec / max_long_ops_per_sec) * 100);


        cout << "long \t\t\t" << op_name << " \t\t\t\t" << ops_per_sec << "\t\t\t\t" << percentage << "% \t\t";

        int x_count = percentage / 2;
        for (int i = 0; i < x_count; i++) {
            cout << "X";
        }
        cout << endl;
    };

    long a2 = 221, b2 = 119, c2 = 101, d2 = 99, e2 = 81, f2 = 43, g2 = 21, h2 = 19;

    benchmark_long ("+", [&](){
        a2 = a2 + b2;
        b2 = b2 + c2;
        c2 = c2 + d2;
        d2 = d2 + e2;
        e2 = e2 + f2;
        f2 = f2 + g2;
        g2 = g2 + h2;
        h2 = h2 + a2;
        e2 = e2 + c2;
        f2 = f2 + g2;
        d2 = d2 + h2;
        h2 = h2 + a2;

    });


    benchmark_long ("-", [&](){
        a2 = a2 - b2;
        b2 = b2 - c2;
        c2 = c2 - d2;
        d2 = d2 - e2;
        e2 = e2 - f2;
        f2 = f2 - g2;
        g2 = g2 - h2;
        h2 = h2 - a2;
        e2 = e2 - g2;
        f2 = f2 - e2;
        g2 = g2 - d2;
        c2 = c2 - a2;
    });

    benchmark_long ("*", [&](){
        a2 = a2 * b2;
        b2 = b2 * c2;
        c2 = c2 * d2;
        d2 = d2 * e2;
        e2 = e2 * f2;
        f2 = f2 * g2;
        g2 = g2 * h2;
        h2 = h2 * a2;
        e2 = e2 * f2;
        f2 = f2 * g2;
        g2 = g2 * f2;
        g2 = g2 * a2;
    });

    benchmark_long ("/", [&](){                                                                                                       if (b2 != 0 && c2 != 0 && d2 != 0 && e2 != 0 && f2 != 0 && g2 != 0 && h2 != 0) {
        a2 = a2 / b2;
        b2 = b2 / c2;
        c2 = c2 / d2;
        d2 = d2 / e2;
        e2 = e2 / f2;
        f2 = f2 / g2;
        g2 = g2 / h2;
        h2 = h2 / a2;
    }
    });
    cout << endl;



    auto benchmark_int = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();

        for (int i = 0; i < OperationsCount; i++) {
            op_func();
        }

        auto t2 = high_resolution_clock::now();
        auto duration = static_cast<double>(duration_cast<microseconds>(t2 - t1).count());
        double ops_per_sec = OperationsCount * 8 / (duration / 1000);

        cout << fixed << setprecision(2);

        int percentage = static_cast<int>((ops_per_sec / max_long_ops_per_sec) * 100);
        if (percentage > 100) {
            percentage = 100;
        }

        cout << "int \t\t\t" << op_name << " \t\t\t\t" << ops_per_sec << "\t\t\t\t" << percentage << "% \t\t";

        int x_count = percentage / 2;
        for (int i = 0; i < x_count; i++) {
            cout << "X";
        }
        cout << endl;
    };

    int a = 33, b = 21, c = 19, d = 17, e = 15, f = 13, g = 9, h = 5;

    benchmark_int ("+", [&](){
        a = a + b;
        b = b + c;
        c = c + d;
        d = d + e;
        e = e + f;
        f = f + g;
        g = g + h;
        h = h + a;
        d = d + f;
        f = f + c;
        g = g + h;
        e = e + a;
    });

    benchmark_int ("-", [&](){
        a = a - b;
        b = b - c;
        c = c - d;
        d = d - e;
        e = e - f;
        f = f - g;
        g = g - h;
        h = h - a;
        e = e - g;
        f = f - e;
        g = g - d;
        c = c - a;
    });

    benchmark_int ("*", [&](){
        a = a * b;
        b = b * c;
        c = c * d;
        d = d * e;
        e = e * f;
        f = f * g;
        g = g * h;
        h = h * a;
        e = e * f;
        f = f * g;
        g = g * h;
        h = h * a;
    });

    benchmark_int ("/", [&](){                                                                                                       if (b2 != 0 && c2 != 0 && d2 != 0 && e2 != 0 && f2 != 0 && g2 != 0 && h2 != 0) {
        a2 = a2 / b2;
        b2 = b2 / c2;
        c2 = c2 / d2;
        d2 = d2 / e2;
        e2 = e2 / f2;
        f2 = f2 / g2;
        g2 = g2 / h2;
        h2 = h2 / a2;
        f2 = f2 / e2;
        g2 = g2 / f2;
        h2 = h2 / c2;
    }
    });
    cout << endl;


    auto benchmark_double = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < OperationsCount; i++) {
            op_func();
        }
        auto t2 = high_resolution_clock::now();
        auto duration = static_cast<double>(duration_cast<microseconds>(t2 - t1).count());
        double ops_per_sec = OperationsCount * 8 / (duration / 1000);

        cout << fixed << setprecision(2);

        int percentage = static_cast<int>((ops_per_sec / max_long_ops_per_sec) * 100);
        if (percentage > 100) {
            percentage = 100;
        }

        cout << "double \t\t\t" << op_name << " \t\t\t\t" << ops_per_sec << "\t\t\t\t" << percentage << "% \t\t";

        int x_count = percentage / 2;
        for (int i = 0; i < x_count; i++) {
            cout << "X";
        }
        cout << endl;
    };
    double a1 = 221.1, b1 = 211.2, c1 = 199.3, d1 = 167.0, e1 = 155.4, f1 = 117.5, g1 = 29.6, h1 = 9.7;

    benchmark_double ("+", [&](){
        a1 = a1 + b1;
        b1 = b1 + c1;
        c1 = c1 + d1;
        d1 = d1 + e1;
        e1 = e1 + f1;
        f1 = f1 + g1;
        g1 = g1 + h1;
        h1 = h1 + a1;
        d1 = d1 + f1;
        f1 = f1 + e1;
        g1 = g1 + c1;
        h1 = h1 + c1;
    });



    benchmark_double ("-", [&](){
        a1 = a1 - b1;
        b1 = b1 - c1;
        c1 = c1 - d1;
        d1 = d1 - e1;
        e1 = e1 - f1;
        f1 = f1 - g1;
        g1 = g1 - h1;
        h1 = h1 - a1;
        d1 = d1 - f1;
        f1 = f1 - e1;
        g1 = g1 - c1;
        h1 = h1 - c1;
    });



    benchmark_double ("*", [&](){
        a1 = a1 * b1;
        b1 = b1 * c1;
        c1 = c1 * d1;
        d1 = d1 * e1;
        e1 = e1 * f1;
        f1 = f1 * g1;
        g1 = g1 * h1;
        h1 = h1 * a1;
        d1 = d1 * f1;
        f1 = f1 * e1;
        g1 = g1 * c1;
        h1 = h1 * c1;
    });

    benchmark_double ("/", [&]()                                                                              { if (b1 != 0 && c1 != 0 && d1!= 0 && e1 != 0 && f1 != 0 && g1 != 0 && h1 != 0) {
        a1 = a1 / b1;
        b1 = b1 / c1;
        c1 = c1 / d1;
        d1 = d1 / e1;
        e1 = e1 / f1;
        f1 = f1 / g1;
        g1 = g1 / h1;
        h1 = h1 / a1;
    }
    });
    cout << endl;


    auto benchmark_float = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();

        for (int i = 0; i < OperationsCount; i++) {
            op_func();
        }


        auto t2 = high_resolution_clock::now();
        auto duration = static_cast<double>(duration_cast<microseconds>(t2 - t1).count());
        double ops_per_sec = OperationsCount * 8 / (duration / 1000);

        cout << fixed << setprecision(2);

        int percentage = static_cast<int>((ops_per_sec / max_long_ops_per_sec) * 100);
        if (percentage > 100) {
            percentage = 100;
        }

        cout << "float \t\t\t" << op_name << " \t\t\t\t" << ops_per_sec << "\t\t\t\t" << percentage << "% \t\t";

        int x_count = percentage / 2;
        for (int i = 0; i < x_count; i++) {
            cout << "X";
        }
        cout << endl;
    };

    float a5 = 333.56, b5 = 313.32, c5 = 294.11, d5 = 199.066, e5 = 153.475, f5 = 137.89, g5 = 121.322, h5 = 19.003;

    benchmark_float ("+", [&](){
        a5 = a5 + b5;
        b5 = b5 + c5;
        c5 = c5 + d5;
        d5 = d5 + e5;
        e5 = e5 + f5;
        f5 = f5 + g5;
        g5 = g5 + h5;
        h5 = h5 + a5;
        e5 = e5 + g5;
        f5 = f5 + h5;
        g5 = g5 + a5;
        h5 = h5 + b5;
    });

    benchmark_float ("-", [&](){
        a5 = a5 - b5;
        b5 = b5 - c5;
        c5 = c5 - d5;
        d5 = d5 - e5;
        e5 = e5 - f5;
        f5 = f5 - g5;
        g5 = g5 - h5;
        h5 = h5 - a5;
        e5 = e5 - g5;
        f5 = f5 - h5;
        g5 = g5 - a5;
        h5 = h5 - b5;
    });

    benchmark_float ("*", [&](){
        a5 = a5 * b5;
        b5 = b5 * c5;
        c5 = c5 * d5;
        d5 = d5 * e5;
        e5 = e5 * f5;
        f5 = f5 * g5;
        g5 = g5 * h5;
        h5 = h5 * a5;
        e5 = e5 * g5;
        f5 = f5 * h5;
        g5 = g5 * a5;
        h5 = h5 * b5;
    });


    benchmark_float ("/", [&](){                                                                                    if (b5 != 0 && c5 != 0 && d5 != 0 && e5 != 0 && f5 != 0 && g5 != 0 && h5 != 0) {
      a5 = a5 / b5;
      b5 = b5 / c5;
      c5 = c5 / d5;
      d5 = d5 / e5;
      e5 = e5 / f5;
      f5 = f5 / g5;
      g5 = g5 / h5;
      h5 = h5 / a5;
    }
    });
    cout << endl;

    auto benchmark_char = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();

        for (int i = 0; i < OperationsCount; i++) {
            op_func();
        }

        auto t2 = high_resolution_clock::now();
        auto duration = static_cast<double>(duration_cast<microseconds>(t2 - t1).count());
        double ops_per_sec = OperationsCount * 8 / (duration / 1000);

        cout << fixed << setprecision(2);

        int percentage = static_cast<int>((ops_per_sec / max_long_ops_per_sec) * 100);
        if (percentage > 100) {
            percentage = 100;
        }

        cout << "char \t\t\t" << op_name << " \t\t\t\t" << ops_per_sec << "\t\t\t\t" << percentage << "% \t\t";

        int x_count = percentage / 2;
        for (int i = 0; i < x_count; i++) {
            cout << "X";
        }
        cout << endl;
    };

    double a6 = 'a', b6 = 'b', c6 = 'c', d6 = 'd', e6 = 'e', f6 = 'f', g6 = 'g', h6 = 'h';

    benchmark_char ("+", [&](){
        a6 = a6 + b6;
        b6 = b6 + c6;
        c6 = c6 + d6;
        d6 = d6 + e6;
        e6 = e6 + f6;
        f6 = f6 + g6;
        g6 = g6 + h6;
        h6 = h6 + a6;
        e6 = e6 + f6;
        c6 = c6 + g6;
        g6 = g6 + e6;
        h6 = h6 + d6;
    });

    benchmark_char ("-", [&](){
        a6 = a6 - b6;
        b6 = b6 - c6;
        c6 = c6 - d6;
        d6 = d6 - e6;
        e6 = e6 - f6;
        f6 = f6 - g6;
        g6 = g6 - h6;
        h6 = h6 - a6;
        e6 = e6 - f6;
        c6 = c6 - g6;
        g6 = g6 - e6;
        h6 = h6 - d6;
    });

    benchmark_char ("*", [&](){
        a6 = a6 * b6;
        b6 = b6 * c6;
        c6 = c6 * d6;
        d6 = d6 * e6;
        e6 = e6 * f6;
        f6 = f6 * g6;
        g6 = g6 * h6;
        h6 = h6 * a6;
        e6 = e6 * f6;
        c6 = c6 * g6;
        g6 = g6 * e6;
        h6 = h6 * d6;
    });


    benchmark_char ("/", [&](){                                                                                                         if (b6 != 0 && c6 != 0 && d6 != 0 && e6 != 0 && f6 != 0 && g6 != 0 && h6 != 0) {
       a6 = a6 / b6;
       b6 = b6 / c6;
       c6 = c6 / d6;
       d6 = d6 / e6;
       e6 = e6 / f6;
       f6 = f6 / g6;
       g6 = g6 / h6;
       h6 = h6 / a6;
    }
    });
    cout << endl;



    auto benchmark_empty = [&](const char* op_name, auto op_func) {
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < OperationsCount; i++) {

        }
        auto t2 = high_resolution_clock::now();
    };

    benchmark_empty ("empty_1", [&](){

    });

    long a3, a4 = 3;
    benchmark_empty ("empty_2", [&](){
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
        a3 = a4;
    });

    return 0;
}