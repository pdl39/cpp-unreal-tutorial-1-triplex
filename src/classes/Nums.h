// module;
// export module Nums;
#pragma once

class Nums {
   private:
    int Num1, Num2, Num3;

   public:
    Nums(int num1, int num2, int num3);
    Nums(int num1, int num2);
    Nums();

    int first();
    int second();
    int third();
};

Nums::Nums(int num1, int num2, int num3) : Num1{num1}, Num2{num2}, Num3{num3} {}
Nums::Nums(int num1, int num2) : Num1{num1}, Num2{num2} {}
Nums::Nums() : Num1{0}, Num2{0}, Num3{0} {}

int Nums::first() { return Num1; }
int Nums::second() { return Num2; }
int Nums::third() { return Num3; }