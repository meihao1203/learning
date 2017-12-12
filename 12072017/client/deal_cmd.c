#include"func.h"
void deal_cmd(char *cmd)
{
	int cur,index;
	for(cur=0,index=0;index<strlen(cmd);index++)
	{
		if(cmd[index]!=' '&&cmd[index]!='\n')
		{
			cmd[cur++] = cmd[index];
		}
		else
		{
			if(cur!=0&&cmd[cur-1]!=' ')
			{
				cmd[cur++] = ' ';
			}
		}
	}
	cmd[cur] = '\0';
}