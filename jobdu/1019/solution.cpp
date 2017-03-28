#include <cstring>
#include <stack>
#include <stdio.h>
using namespace std;

char str[220];
int mat[][5] = {
    {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0},
};
stack<int> op;
stack<double> in;

void getOp(bool &reto, int &retn, int &i) {
  if (i == 0 && op.empty()) {
    reto = true;
    retn = 0;
    return;
  }

  if (str[i] == '\0') {
    reto = true;
    retn = 0;
    return;
  }

  if (str[i] >= '0' && str[i] <= '9') {
    // printf("detect number %c\n", str[i]);
    reto = false;
  } else {
    reto = true;
    switch (str[i]) {
    case '+':
      retn = 1;
      break;
    case '-':
      retn = 2;
      break;
    case '*':
      retn = 3;
      break;
    case '/':
      retn = 4;
      break;
    }
    i += 2;
    return;
  }
  retn = 0;
  for (; str[i] != ' ' && str[i] != '\0'; i++) {
    retn *= 10;
    retn += (str[i] - '0');
  }
  if (str[i] == ' ')
    i++;
  return;
}

int main() {
  while (fgets(str, 210, stdin)) {
    str[strlen(str) - 1] = '\0';
    // puts(str);
    if (str[0] == '0' && strlen(str) == 1)
      return 0;
    bool retop;
    int retnum;
    int idx = 0;
    while (!op.empty())
      op.pop();
    while (!in.empty())
      in.pop();
    while (true) {
      getOp(retop, retnum, idx);
      if (retop == false) {
        in.push((double)retnum);
        // printf("in push %d\n", retnum);
      } else {
        double tmp;
        if (op.empty() || mat[retnum][op.top()] == 1) {
          op.push(retnum);
        } else {
          while (mat[retnum][op.top()] == 0) {
            int ret = op.top();
            op.pop();
            double b = in.top();
            in.pop();
            double a = in.top();
            in.pop();
            if (ret == 1)
              tmp = a + b;
            if (ret == 2)
              tmp = a - b;
            if (ret == 3)
              tmp = a * b;
            if (ret == 4)
              tmp = a / b;
            in.push(tmp);
          }
          op.push(retnum);
        }
      }
      if (op.size() == 2 && op.top() == 0)
        break;
    }
    printf("%.2lf\n", in.top());
  }
  return 0;
}
