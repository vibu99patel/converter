#include <iostream>
#include <string>
#include "Deque.hpp"
#include "NotationConverter.hpp"
#include "NotationConverter.cpp"

int main(){

  const std::string infix1 = "(A + B) ";
  const std::string infix2 = "((X + B) * (Y - D))";
  const std::string infix3 = "(((A + B) / (X + Y)) - R)";

  const std::string prefix1 = "+ / * x y g h";
  const std::string prefix2 = "-    /  x  y  g"; // Multiple Spaces Between Letters and Operators
  const std::string prefix3 = "- / x y * a b";

  // const std::string postfix1 = "X Y + A B + *";
  // const std::string postfix2 = "V C +";
  // const std::string postfix3 = "H W * R Q - /";

  NotationConverter nc;


  std::cout << std::endl;

  std::cout << "Infix notation should convert to prefix notation" << std::endl;
  std::cout << "program: " << nc.infixToPrefix(infix1) << "\t\t\t correct: " << "+ A B" << std::endl;
  std::cout << "program: " << nc.infixToPrefix(infix2) << "\t\t correct: " << "* + X B - Y D" << std::endl;
  std::cout << "program: " << nc.infixToPrefix(infix3) << "\t correct: " << "- / + A B + X Y R" << std::endl;
  std::cout << std::endl;

  // std::cout << "Infix notation should convert to postfix notation" << std::endl;
  // std::cout << "program: " << nc.infixToPostfix(infix1) << "\t\t\t correct: " << "A B +" << std::endl;
  // std::cout << "program: " << nc.infixToPostfix(infix2) << "\t\t correct: " << "X B + Y D - *" << std::endl;
  // std::cout << "program: " << nc.infixToPostfix(infix3) << "\t correct: " <<  "A B + X Y + / R -" << std::endl;
  // std::cout << std::endl;

  // std::cout << "Prefix notation should convert to postfix notation" << std::endl;
  // std::cout << "program: " << nc.prefixToPostfix(prefix1) << "\t\t correct: " << "x y * g / h +" << std::endl;
  // std::cout << "program: " << nc.prefixToPostfix(prefix2) << "\t\t correct: " << "x y / g -" << std::endl;
  // std::cout << "program: " << nc.prefixToPostfix(prefix3) << "\t\t correct: " << "x y / a b * -" << std::endl;
  // std::cout << std::endl;

  // std::cout << "Prefix notation should convert to infix notation" << std::endl;
  // std::cout << "program: " << nc.prefixToInfix(prefix1) << "\t correct: " << "(((x * y) / g) + h)" << std::endl;
  // std::cout << "program: " << nc.prefixToInfix(prefix2) << "\t\t correct: " << "((x / y) - g)" << std::endl;
  // std::cout << "program: " << nc.prefixToInfix(prefix3) << "\t correct: " << "((x / y) - (a * b))" << std::endl;
  // std::cout << std::endl;
  
  // std::cout << "Postfix notation should convert to infix notation" << std::endl;
  // std::cout << "program: " << nc.postfixToInfix(postfix1) << "\t correct: " << "((X + Y) * (A + B))" << std::endl;
  // std::cout << "program: " << nc.postfixToInfix(postfix2) << "\t\t correct: " << "(V + C)" << std::endl;
  // std::cout << "program: " << nc.postfixToInfix(postfix3) << "\t correct: " << "((H * W) / (R - Q))" << std::endl;
  // std::cout << std::endl;
  

  // std::cout << "Postfix notation should convert to prefix notation" << std::endl;
  // std::cout << "program: " << nc.postfixToPrefix(postfix1) << "\t\t correct: " << "* + X Y + A B" << std::endl;
  // std::cout << "program: " << nc.postfixToPrefix(postfix2) << "\t\t\t correct: " << "+ V C" << std::endl;
  // std::cout << "program: " << nc.postfixToPrefix(postfix3) << "\t\t correct: " << "/ * H W - R Q" << std::endl;
  // std::cout << std::endl;

  return 0;
}