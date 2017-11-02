// https://www.nowcoder.com/practice/b744af632ac4499aa485d7bb048bb0aa?tpId=69&&tqId=29671&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define LENGTH 1010

struct bigInteger {
	char digit[LENGTH];
	int size;
	
	void init() {
		memset(digit, 0 ,sizeof(digit));
		size = 0;
	}
	
	void set(const char *str) {
		init();
		int len = strlen(str);
		for (int i =  len - 1; i >=0; i--) {
			digit[size++] = (str[i] - '0');
		}
	}
	
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", (int)(digit[i]));
		}
		printf("\n");
	}
};

	bool ltr(const bigInteger &B, const bigInteger &A) {
		if (B.size < A.size)
			return true;
		else if (B.size > A.size) 
			return false;
		else {
			for (int i = B.size - 1; i >= 0; i--) {
				if (B.digit[i] < A.digit[i]) 
					return true;
				else if (B.digit[i] > A.digit[i])
					return false;
			}
		}
		return false;
	}


int N;
char str[LENGTH];

int main() {
	while (scanf("%d", &N) != EOF) {
		vector<bigInteger> v;
		for (int i = 0; i < N; i++) {
			scanf("%s", str);
			bigInteger b;
			b.set(str);
			v.push_back(b);
		}
		std::sort(v.begin(), v.end(), ltr);
		for (int i = 0; i < N; i++) {
			v[i].output();
		}
	}
}
