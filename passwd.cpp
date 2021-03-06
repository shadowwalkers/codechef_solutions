#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define max 1000005
#define sd(a) fastInt(&a)
#define GC getchar_unlocked

inline void fastInt(int *a)
{
    register char c=0;
    register int neg = 1;
    while (c<33) c=GC();
    if(c == '-'){
        neg = -1;
        c=GC();
    }
    *a=0;
    while (c>33)
    {
        *a=(*a<<1)+(*a<<3)+c-'0';
        c=GC();
    }
    *a *= neg;
}

int main() {
	int tc;
//	sd(tc);
	scanf("%d", &tc);	
	while (tc--) {
		int n,o;
//		sd(n);
		scanf("%d",&n);
		o = n;
		int i = 0;
		char a[n][2];
		char b[max];
		while (n--) {
			scanf(" %c",&a[i][0]);
			scanf(" %c",&a[i][1]);
			i++;
		}
		i = 0;
		char c;
		int t;
		int flag = 0;
		int count = 0;
		while (1) {
//			c = GC();
			scanf("%c",&c);
			while(c == '\n' && count == 0)
//				c = GC();
				scanf("%c",&c);
				b[i] = c;
			for (t = 0; t < o; t++) {
				if (b[i] == a[t][0]) {
					b[i] = a[t][1];
					break;
				}		
			}
			count++;
			if (b[i] == '.') {
				flag = 1;
			}
			if (b[i] == '\n') {
				b[i] = '\0';
				break;
			} 
			i++;
		}
		
		int k = 0;
		if (flag == 0) {
			while(b[k] != '\0') {
				if (b[k] == '0')
					k++;
				else 
					break;
			}
		
			if (k == count - 1) {
				printf("0\n");
				break;
			}
			strcpy(b,b+k);
			printf("%s\n",b);	
		}
		else {
			int j = count - 2;
//			cout << b <<"end"; 
			while (b[j] == '0') {
				j--;
			}
			if (b[j] == '.')
				j--;

			b[j+1] = '\0';

			while (b[k] == '0') {
				k++;
			}

			strcpy(b, b + k);
			if (b[0] == '.' && b[1] == '\0'){
				printf("0\n");
				break;
			}

			if (strcmp(b,"\0") == 0) {
				printf("0\n");
				break;
			}
			printf("%s\n",b);
		}	
			
	}
	
	return 0;
}
