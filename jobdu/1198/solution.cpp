// https://www.nowcoder.com/practice/4c39c984ea3848b48e111b8e71ec1dd4?tpId=69&&tqId=29656&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
#include <cstdio>
#include <cstring>

struct bigInteger {
public:
	int digit[1000];
	int size;
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	
	void set(char *str) {
		init();
		int L = strlen(str);
		for (int i = L - 1, c = 1, j = 0, t = 0; i >= 0; i--) {
			t += (str[i] - '0') * c;
			j++;
			c *= 10;
			if( j == 4 || i == 0) {
				digit[size++] = t;
				t = 0;
				j = 0;
				c =1;
			}
		}
	}
	
	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i != size -1) printf("%04d", digit[i]);
			else printf("%d", digit[i]);
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
			ret.digit[ret.size++] = tmp % 10000;
			carry = tmp / 10000;
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
