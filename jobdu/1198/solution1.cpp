#include <cstdio>
#include <cstring>

struct bigInteger {
public:
	char digit[1000];
	int size;
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	
	void set(char *str) {
		init();
		int L = strlen(str);
		for (int i = L - 1; i >= 0; i--) {
			digit[size++] = str[i] - '0';
		}
	}
	
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", (int)digit[i]);
		}
		printf("\n");
	}
	
	bigInteger add(const bigInteger& A) {
		bigInteger ret;
		ret.init();
		int carry = 0;
		int maxSize = A.size > size ? A.size : size;
		for (int i = 0; i < maxSize; i++) {
			int tmp = digit[i] + A.digit[i] + carry;
			ret.digit[ret.size++] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry) {
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}
};

bigInteger a, b, c;
char str1[1010];
char str2[1010];

int main() {
	while(scanf("%s%s", str1, str2) != EOF) {
		a.set(str1);
		b.set(str2);
		c = a.add(b);
		c.output();
	} 
	return 0;
}
