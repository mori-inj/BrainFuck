#include <stdio.h>
#include <stdlib.h>
#define fp(x) fprintf(fp2,x)

int main(int argc, char **argv)
{
	FILE *fp1,*fp2;
	char c,temp[20];

	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"w");

	fp("#include <stdio.h>\n\n");
	fp("int main(void)\n");
	fp("{\n");
	fp("\tchar a[8000000] = {0};\n");
	fp("\tchar *ptr=a;\n");

	while(fscanf(fp1,"%c",&c)!=EOF)
	{
		if(c=='<')
			fp("\t++ptr;\n");
		else if(c=='>')
			fp("\t--ptr;\n");
		else if(c=='+')
			fp("\t++*ptr;\n");
		else if(c=='-')
			fp("\t--*ptr;\n");
		else if(c=='.')
			fp("\tputchar(*ptr);\n");
		else if(c==',')
			fp("\t*ptr=getchar();\n");
		else if(c=='[')
			fp("\twhile(*ptr)\n\t{\n");
		else if(c==']')
			fp("\t}\n");
	}
	fp("\treturn 0;\n");
	fp("}\n");
	fclose(fp1);
	fclose(fp2);

	sprintf(temp,"gcc -o bf %s",argv[2]);
	system(temp);
	return 0;
}
