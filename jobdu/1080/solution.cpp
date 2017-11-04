// https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=60&&tqId=29473&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include <cstdio>
#include <cstring>
using namespace std;

#define LENGTH 10010

struct bigInteger {
	char digit[LENGTH];
	int size;
	
	void init() {
		memset(digit, 0, sizeof(digit));
		size = 0;
	}
	
	void set(const char* str) {
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
	
	bigInteger multi(int x) {
		bigInteger ans;
		ans.init();
		int carry = 0;
		for (int i = 0; i < size; i++) {
			long int tmp = x * digit[i] + carry;
			carry  = tmp / 10;
			ans.digit[ans.size++] = tmp % 10;
		}
		while (carry) {
			ans.digit[ans.size++] = carry % 10;
			carry /= 10;
		} 
		return ans;
	}
	
	bigInteger add(const bigInteger &x) {
		bigInteger ans;
		ans.init();
		
		int carry = 0;
		int maxSize = size > x.size ? size : x.size;
		for (int i = 0; i < maxSize; i++) {
			int tmp = digit[i] + x.digit[i] + carry;
			carry = tmp / 10;
			ans.digit[ans.size++] = tmp % 10; 
		}
		
		if (carry) 
			ans.digit[ans.size++] = carry;
		return ans;
	}
	
	bigInteger div(int x) {
		bigInteger ans;
		ans.init();
		
		int remainer = 0;
		for (int i = size - 1; i >= 0; i--) {
			int tmp = remainer * 10 + digit[i];
			int t = tmp / x;
			int r = tmp % x;
			
			remainer = r;
			ans.digit[i] = t;
		}
		
		for (int i = size - 1; i >= 0; i--) {
			if (ans.digit[i] != 0)  {
				ans.size = i + 1;
				break;
			}
			ans.size = 1; // in case result = 0
		}
		return ans;
	}
	
	int mod(int x) {
		int remainer = 0;
		for (int i = size - 1; i >= 0; i--) {
			int tmp = remainer * 10 + digit[i];
			int t = tmp / x;
			int r = tmp % x;
			remainer = r;
		}
		return remainer;
	}
	
};

bigInteger a, b, c; 

char str[LENGTH];
char ans[LENGTH];

int M, N;

int main() {
	while(scanf("%d%d", &M, &N) != EOF) {
		scanf("%s", str);
		
		a.set("0");
		b.set("1");
		
		int len = strlen(str);
		for (int i = len - 1; i >= 0; i--) {
			char c  = str[i];
			int t;
			if (c >= '0' && c <= '9') 
				t = c - '0';
			else t = c - 'A' + 10;
			
			a = a.add(b.multi(t));
			b = b.multi(M);
		}
		
		int size  = 0;
		do {
			int p  = a.mod(N);
			a = a.div(N);
			
			if (p >= 0 && p <= 9)
				ans[size++] = '0' + p;
			else 
				ans[size++] = 'a' + p - 10;
			
		} while (!(a.size == 1 && a.digit[0] == 0));
		
		for (int i = size - 1; i >= 0; i--) 
			printf("%c", ans[i]);
		printf("\n");
		
	}
	return 0;
}
