#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024 // # of individual life
#define M_max 2000 // max length of gene
#define M_min 30 //min length of gene

char bf[7]={'>','<','[',']','+','-','.'};
int f[23][N];
char ans[13]="Hello World!";

int main(void)
{
	int i,j;
	FILE *fp;

	srand((unsigned)time(NULL));

	for(i=0; i<N; i++)
	{
		char filename[40];
		sprintf(filename,"input%d%d%d%d",i/1000,(i/100)%10,(i/10)%10,i%10);
		fp = fopen(filename,"w");
		for(j=0; j< rand()%(M_max-M_min+1)+M_min; j++)
			fprintf(fp,"%c",bf[rand()%7]);
		fclose(fp);
		sprintf(filename,"./bfi input%d%d%d%d > output%d%d%d%d",i/1000,(i/100)%10,(i/10)%10,i%10,	i/1000,(i/100)%10,(i/10)%10,i%10);
		system(filename);
		
		sprintf(filename,"output%d%d%d%d",i/1000,(i/100)%10,(i/10)%10,i%10);
		fp = fopen(filename,"r");
		char c;
		int cnt = 0;
		for(j=0; j<12; j++)
		{
			fscanf(fp,"%c",&c);
			if(ans[cnt++]==c)
				f[0][i]++;
		}
		fclose(fp);
		fp = fopen(filename,"r");
		while(fscanf(fp,"%c",&c)!=EOF)
		{
			if(32<=c && c<=126)
				f[1][i]++;
			else
				f[2][i]++;
		}
		fclose(fp);
	}

	return 0;
}
