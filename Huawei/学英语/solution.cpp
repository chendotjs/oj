#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> aaa = {"", "billion","million","thousand","hundred"};
vector<string> bbb = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> ccc = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> ddd = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string read_3(int num) {
  string res;
  if (num >=0 && num <=9) {
    res = ddd[num].c_str();
    return res;
  } else if (num >=10 && num <=19) {
    res = ccc[num % 10].c_str();
    return res;
  } else if (num >=20 && num <=99) {
    res = bbb[num / 10].c_str();
    if (num % 10 != 0) {
      res += " ";
      res += ddd[num % 10].c_str();
    }
    return res;
  }

  res += ddd[num / 100];
  res += " hundred";
  num %= 100;
  if (num) {
    res += " and ";
    res += read_3(num);
  }
  return res;
}

int main() {

  long long int num;
  while (scanf("%lld", &num) != EOF) {
    if (num > 999999999) {
      printf("error\n");
      continue;
    }
    long int M = 1e9;
    string ans;
    //read_3(num);
#if 1
    for (int i = 1; i <=3; i++) {
      int d = num / M;

      if (d != 0) {
        ans += read_3(d);
        ans += " ";
        ans += aaa[i];
        ans += " ";
      }
      num %= M;
      M /= 1000;
    }
    ans += read_3(num);
    while (ans[ans.size() - 1] == ' ') {
      ans.erase(ans.end() - 1);
    }
    std::cout << ans << std::endl;
  #endif
  }
  return 0;
}

