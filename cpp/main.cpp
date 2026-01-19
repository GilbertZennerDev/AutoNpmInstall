#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

vector<string> getDepCheckNames(vector<string> inTxt)
{
	int				i;
	vector<string>	depCheckNames;

	i = -1;	
	while (++i < inTxt.size())
	{
		if (inTxt[i][0] == '*')
			depCheckNames.push_back(inTxt[i].substr(2, inTxt[i].find(':') - 2));
	}
	return (depCheckNames);	
}

void runfork(vector<string> names)
{
	int		i;
	pid_t	pid;
	char	**cmds;

	cmds = (char **)malloc(sizeof(char *) * names.size() + 3);
	cmds[0] = strdup("npm");
	cmds[1] = strdup("install");
	i = -1;
	while (++i < names.size())
		cmds[i + 2] = strdup(names[i].c_str());
	cmds[names.size() + 2] = NULL;
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else
	{
		wait(NULL);
		i = -1;
		while (++i < names.size() + 3)
			free(cmds[i]);
		free(cmds);
	}
}

vector<string> getStdIn()
{
	vector<string>	content;
	string					input_line;
	while(getline(cin, input_line))
        content.push_back(input_line);
	return (content);
}

int	main(int ac, char **av)
{
	vector<string> inTxt;
	vector<string> names;

	inTxt = getStdIn();
	names = getDepCheckNames(inTxt);
	runfork(names);
	return (0);
}
