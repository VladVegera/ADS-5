// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char symbol) {
  switch (symbol) {
    case '(': return 0;
    case ')': return 1;
    case '-': case '+': return 2;
    case '*': case '/': return 3;
    case ' ': return 4;
    default: return 4;
  }
}

int calc(int variable1, int variable2,cahr oper) {
  switch (oper){
    case '+': return variable1 + variable2;
    case '-': return variable1 - variable2;
    case '*': return variable1 * variable2;
    case '/': if (variable2 != 0) return variable1 / variable2;
    default:
    return 0;
    break;
  }
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stack;
  std::string res;
  int prior;
  for (int i = 0; i < inf.size(); i++) {
    prior = priority(inf[i]);
    if (prior == 4) {
      res.push_back(inf[i]);
      res.push_back(' ');
    } else {
      if (((prior == 0) || stack.isEmpty())) {
        stack.push(inf[i]);
      } else if ((prior > priority(stack.get()))) {
        stack.push(inf[i]);
      } else if (prior == 1) {
          while (stack.get() != '(') {
            res.push_back(stack.get());
            res.push_back(' ');
            stack.pop();
          }
          stack.pop();
      } else if (inf[i] != ' ') {
        int j = priority(stack.get());
        while ((j >= priority(inf[i])) && (!stack.isEmpty())) {
          res.push_back(stack.get());
          res.push_back(' ');
          stack.pop();
        }
        stack.push(inf[i]);
      }
    }
  }
  while (!stack.isEmpty()) {
    res.push_back(stack.get());
    res.push_back(' ');
    stack.pop();
  }
  return res;
}

int eval(std::string pref) {
  TStack <int, 100> stack;
  int x, y;
  for (int i = 0; i < post.size(); i++) {
    if (priority(post[i]) < 4) {
      y = stack.get();
      stack.pop();
      x = stack.get();
      stack.pop();
      stack.push(calk(post[i], x, y));
    } else if (priority(post[i]) == 4 && post[i] != ' ') {
      stack.push(post[i] - '0');
    }
  }
  return stack.get();
}
