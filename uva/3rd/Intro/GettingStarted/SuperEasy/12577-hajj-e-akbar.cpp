#include<stdio.h>
#include<string.h>

int main() {
	int cn=1;
	char in[6];
	while(1) {
		scanf("%s", in);
		if(in[0] == '*') break;
		printf("Case %d: ", cn++);
		if(strcmp(in, "Hajj") == 0)
			printf("Hajj-e-Akbar\n");
		else if(strcmp(in, "Umrah") == 0)
			printf("Hajj-e-Asghar\n");
	}
	return 0;
}
