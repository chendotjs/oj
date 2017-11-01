// https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=60&&tqId=29496&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include <cstdio>
#include <cstring>

#define LENGTH 10100

struct bigInteger {
	char digit[LENGTH];
	int size;
	
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	
	void set(char *str) {
		init();
		int len = strlen(str);
		for (int i = len - 1; i >= 0; i--) {
			digit[size++] = str[i] - '0';
		}
	}
	
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", digit[i]);
		}
		printf("\n");
	}
	
	bigInteger multi(int m) {
		bigInteger ans;
		ans.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			long long int tmp = digit[i] * m + carry;
			carry = tmp / 10;
			ans.digit[ans.size++] = tmp % 10;
		}
		if (carry) {
			while (carry) {
				int c = carry % 10;
				carry /= 10;
				ans.digit[ans.size++] = c;
			}
		}
		return ans;
	}
};

int N;

int main() {
	while (scanf("%d", &N) != EOF) {
		bigInteger ans;
		ans.set("1");
		for (int i = 1; i <= N; i++) {
			ans = ans.multi(i);
		}
		ans.output();
	}
	return 0;
}
