// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char symbol) {
  switch (symbol) {
    case '(': return 0;
    case ')': return 1;
    case '+': case '-': return 2;
    case '*': case '/': return 3;
    case ' ': return 5;
    default: return 4;
  }
}

int calc(int x, int y, char oper) {
  switch (oper) {
    case '+': return (y + x);
    case '-': return (y - x);
    case '*': return (y * x);
    case '/':
      if (x != 0)
      return y / x;
    default: return 0;
  }
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stack;
  std::string res = "";
  for (int i = 0; i < inf.length(); i++) {
    char sym = inf[i];
      int PriorSym = priority(sym);
      if (PriorSym == 4) {
        res += sym;
        res += ' ';
      } else {
        bool empty = stack.isEmpty();
        int priorTop = priority(stack.get());
        if (PriorSym == 0 || PriorSym > priorTop || empty) {
          stack.push(sym);
        } else if (PriorSym == 1) {
          while (priority(stack.get()) != 0) {
            res += stack.get();
            res += ' ';
            stack.pop();
          }
            stack.pop();
        } else if (PriorSym <= priority(stack.get())) {
          if (PriorSym <= priority(stack.get())) {
            res += stack.get();
            res += ' ';
            stack.pop();
          }
          stack.push(sym);
        }
      }
  }
  if (!stack.isEmpty()) {
    while (!stack.isEmpty()) {
      res += stack.get();
      res += ' ';
      stack.pop();
    }
    res.pop_back();
  }
  return res;
}

int eval(std::string pref) {
  TStack <int, 100> stack1;
  int result = 0;
  for (int i = 0; i < pref.length(); i++) {
    char sym = pref[i];
    if (priority(sym) == 4) {
      stack1.push(sym - '0');
    } else if (priority(sym) < 4) {
      int temp1 = stack1.get();
      stack1.pop();
      int temp2 = stack1.get();
      stack1.pop();
      stack1.push(calc(temp1, temp2, sym));
    }
  }
  result = stack1.get();
  return result;
}
