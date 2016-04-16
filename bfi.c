#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEOUT 100000

void end(void)
{
	exit(0);
}

int main(int argc, char **argv)
{
	char a[1000000] = {0};
	char ptr=0,c,loopcnt=0;
	FILE *fp1;
	clock_t start = clock();
	fp1 = fopen(argv[1],"r");

	while(fscanf(fp1,"%c",&c)!=EOF)
	{
		if(clock()-start>TIMEOUT)
			end();
		if(c=='<')
			++ptr;
		else if(c=='>')
			--ptr;
		else if(c=='+')
			++a[ptr];
		else if(c=='-')
			--a[ptr];
		else if(c=='.')
			putchar(a[ptr]);
		else if(c==',')
			a[ptr]=getchar();
		else if(c=='[')
		{
			loopcnt=1;
			if(!a[ptr])
				while(c!=']' || loopcnt>0)
				{
					if(clock()-start>TIMEOUT)
						end();

					fscanf(fp1,"%c",&c);
					if(c=='[')
						loopcnt++;
					else if(c==']')
						loopcnt--;
				}
		}

		else if(c==']')
		{
			loopcnt=0;
			while(c!='[' || loopcnt>0)
			{
				if(clock()-start>TIMEOUT)
					end();

				fseek(fp1,-1,SEEK_CUR);
				fscanf(fp1,"%c",&c);
				fseek(fp1,-1,SEEK_CUR);
				if(c==']')
					loopcnt++;
				else if(c=='[')
					loopcnt--;
			}
		}


	}

	return 0;
}

