#include <iostream>

class Figure {
    public:
        Figure() {
            this->name = "Фигура";
            this->sides = 0;
            this->dum = nullptr;
        }
        std::string get_name() {
            return name;
        }
        int count_sides() {
            return sides;
        }
        virtual int* get_side_values() {
            return dum;
        }
        virtual int* get_angle_values() {
            return dum;
        }
        virtual bool check() {
            if (sides == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        virtual void print_info() {
            std::string s = check() ? "Правильная" : "Неправильная";
            std::cout << s << "\n" << "Количество сторон: " << sides << "\n\n";
        }

    protected:
        std::string name;
        int sides;
        int* dum;
};

class Triangle : public Figure {
    public:
        Triangle() {
            this->name = "Треугольник";
            this->sides = 3;
            this->side_vals[0] = 1;
            this->side_vals[1] = 2;
            this->side_vals[2] = 3;
            this->angle_vals[0] = 40;
            this->angle_vals[1] = 60;            
            this->angle_vals[2] = 80;
        }
        Triangle(int a, int b, int c, int A, int B, int C) {
            this->name = "Треугольник";
            this->sides = 3;
            this->side_vals[0] = a;
            this->side_vals[1] = b;
            this->side_vals[2] = c;
            this->angle_vals[0] = A;
            this->angle_vals[1] = B;            
            this->angle_vals[2] = C;
        }
        int* get_side_values() {
            return side_vals;
        }
        int* get_angle_values() {
            return angle_vals;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 3; i++) {
                sum_angles += angle_vals[i];
            }
            if (sides == 3 && sum_angles == 180) {
                return true;
            }
            else {
                return false;
            }
        }
        void print_info() {
            std::string s = check() ? "Правильная" : "Неправильная";
            std::cout << s << "\n" << "Количество сторон: " << sides << "\n";
            std::cout << "Стороны: " << " a=" << side_vals[0] << " b=" << side_vals[1] << " c=" << side_vals[2] << "\n";
            std::cout << "Углы: " << " A=" << angle_vals[0] << " B=" << angle_vals[1] << " C=" << angle_vals[2] << "\n\n";
        }
    protected:
        int side_vals[3];
        int angle_vals[3];
};

class Quadrangle : public Figure {
    public:
        Quadrangle() {
            this->name = "Четырехугольник";
            this->sides = 4;
            this->side_vals[0] = 1;
            this->side_vals[1] = 2;
            this->side_vals[2] = 3;
            this->side_vals[3] = 4;
            this->angle_vals[0] = 20;
            this->angle_vals[1] = 40;            
            this->angle_vals[2] = 60;
            this->angle_vals[3] = 80;
        }
        Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
            this->name = "Четырехугольник";
            this->sides = 4;
            this->side_vals[0] = a;
            this->side_vals[1] = b;
            this->side_vals[2] = c;
            this->side_vals[3] = d;
            this->angle_vals[0] = A;
            this->angle_vals[1] = B;
            this->angle_vals[2] = C;
            this->angle_vals[3] = D;
        }
        int* get_side_values() {
            return side_vals;
        }
        int* get_angle_values() {
            return angle_vals;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 4; i++) {
                sum_angles += angle_vals[i];
            }
            if (sides == 4 && sum_angles == 360) {
                return true;
            }
            else {
                return false;
            }
        }
        void print_info() {
            std::string s = check() ? "Правильная" : "Неправильная";
            std::cout << s << "\n" << "Количество сторон: " << sides << "\n";
            std::cout << "Стороны: " << " a=" << side_vals[0] << " b=" << side_vals[1] << " c=" << side_vals[2] << " d=" << side_vals[3] << "\n";
            std::cout << "Углы: " << " A=" << angle_vals[0] << " B=" << angle_vals[1] << " C=" << angle_vals[2] << " D=" << angle_vals[3] << "\n\n";
        }

    protected:
        int side_vals[4];
        int angle_vals[4];
};

class RightTriangle : public Triangle {
    public:
        RightTriangle(int a, int b, int c, int A, int B) {
            this->name = "Прямоугольный треугольник";
            this->side_vals[0] = a;
            this->side_vals[1] = b;
            this->side_vals[2] = c;
            this->angle_vals[0] = A;
            this->angle_vals[1] = B;            
            this->angle_vals[2] = 90;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 3; i++) {
                sum_angles += angle_vals[i];
            }
            if (sides == 3 && sum_angles == 180 && angle_vals[2] == 90) {
                return true;
            }
            else {
                return false;
            }
        }
};

class IsoscelesTriangle : public Triangle {
    public:
        IsoscelesTriangle(int ac, int b, int AC, int B) {
            this->name = "Равнобедренный треугольник";
            this->side_vals[0] = ac;
            this->side_vals[1] = b;
            this->side_vals[2] = ac;
            this->angle_vals[0] = AC;
            this->angle_vals[1] = B;            
            this->angle_vals[2] = AC;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 3; i++) {
                sum_angles += angle_vals[i];
            }
            if (sides == 3 && sum_angles == 180 && side_vals[0] == side_vals[2] && angle_vals[0] == angle_vals[2]) {
                return true;
            }
            else {
                return false;
            }
        }
};

class EquilateralTriangle : public Triangle {
    public:
        EquilateralTriangle(int abc) {
            this->name = "Равносторонний  треугольник";
            this->side_vals[0] = abc;
            this->side_vals[1] = abc;
            this->side_vals[2] = abc;
            this->angle_vals[0] = 60;
            this->angle_vals[1] = 60;            
            this->angle_vals[2] = 60;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 3; i++) {
                sum_angles += angle_vals[i];
            }
            bool check_sides = (side_vals[1] == side_vals[0] && side_vals[2] == side_vals[0]);
            bool check_angles = (angle_vals[0] == 60 && angle_vals[0] == 60 && angle_vals[0] == 60);
            if (sides == 3 && sum_angles == 180 && check_sides && check_angles) {
                return true;
            }
            else {
                return false;
            }
        }
};

class Rectangle : public Quadrangle {
    public:
        Rectangle(int ac, int bd) {
            this->name = "Прямоугольник";
            this->side_vals[0] = ac;
            this->side_vals[1] = bd;
            this->side_vals[2] = ac;
            this->side_vals[3] = bd;
            this->angle_vals[0] = 90;
            this->angle_vals[1] = 90;
            this->angle_vals[2] = 90;
            this->angle_vals[3] = 90;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 4; i++) {
                sum_angles += angle_vals[i];
            }
            bool check_sides = (side_vals[0] == side_vals[2] && side_vals[1] == side_vals[3]);
            bool check_angles = (angle_vals[0] == 90 && angle_vals[1] == 90 && angle_vals[2] == 90 && angle_vals[3] == 90);
            if (sides == 4 && sum_angles == 360 && check_sides && check_angles) {
                return true;
            }
            else {
                return false;
            }
        }
};

class Square : public Quadrangle {
    public:
        Square(int a) {
            this->name = "Квадрат";
            this->side_vals[0] = a;
            this->side_vals[1] = a;
            this->side_vals[2] = a;
            this->side_vals[3] = a;
            this->angle_vals[0] = 90;
            this->angle_vals[1] = 90;
            this->angle_vals[2] = 90;
            this->angle_vals[3] = 90;        
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 4; i++) {
                sum_angles += angle_vals[i];
            }
            bool check_sides = (side_vals[1] == side_vals[0] && side_vals[2] == side_vals[0] && side_vals[3] == side_vals[0]);
            bool check_angles = (angle_vals[0] == 90 && angle_vals[1] == 90 && angle_vals[2] == 90 && angle_vals[3] == 90);
            if (sides == 4 && sum_angles == 360 && check_sides && check_angles) {
                return true;
            }
            else {
                return false;
            }
        }
};

class Parallelogram : public Quadrangle {
    public:
        Parallelogram(int ac, int bd, int AC, int BD) {
            this->name = "Параллелограмм";
            this->side_vals[0] = ac;
            this->side_vals[1] = bd;
            this->side_vals[2] = ac;
            this->side_vals[3] = bd;
            this->angle_vals[0] = AC;
            this->angle_vals[1] = BD;
            this->angle_vals[2] = AC;
            this->angle_vals[3] = BD;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 4; i++) {
                sum_angles += angle_vals[i];
            }
            bool check_sides = (side_vals[0] == side_vals[2] && side_vals[1] == side_vals[3]);
            bool check_angles = (angle_vals[0] == angle_vals[2] && angle_vals[1] == angle_vals[3]);
            if (sides == 4 && sum_angles == 360 && check_sides && check_angles) {
                return true;
            }
            else {
                return false;
            }
        }
};

class Rhombus : public Quadrangle {
    public:
        Rhombus(int a, int AC, int BD) {
            this->name = "Ромб";
            this->side_vals[0] = a;
            this->side_vals[1] = a;
            this->side_vals[2] = a;
            this->side_vals[3] = a;
            this->angle_vals[0] = AC;
            this->angle_vals[1] = BD;
            this->angle_vals[2] = AC;
            this->angle_vals[3] = BD;
        }
        bool check() {
            int sum_angles = 0;
            for (int i = 0; i < 4; i++) {
                sum_angles += angle_vals[i];
            }
            bool check_sides = (side_vals[1] == side_vals[0] && side_vals[2] == side_vals[0] && side_vals[3] == side_vals[0]);
            bool check_angles = (angle_vals[0] == angle_vals[2] && angle_vals[1] == angle_vals[3]);
            if (sides == 4 && sum_angles == 360 && check_sides && check_angles) {
                return true;
            }
            else {
                return false;
            }
        }
};

void polymorf(Figure &figure) {
    figure.print_info();
}

int main() {
    Figure f0;
    Triangle t0;
    Quadrangle q0;

    RightTriangle t1(1, 2, 3, 30, 60);
    IsoscelesTriangle t2(2, 1, 30, 90);
    EquilateralTriangle t3(3);

    Rectangle q1(1, 4);
    Square q2(4);
    Parallelogram q3(1, 4, 60, 120);
    Rhombus q4(4, 60, 40);

    polymorf(f0);
    polymorf(t0);
    polymorf(q0);
    polymorf(t1);
    polymorf(t2);
    polymorf(t3);
    polymorf(q1);
    polymorf(q2);
    polymorf(q3);
    polymorf(q4);

    return 0;
}