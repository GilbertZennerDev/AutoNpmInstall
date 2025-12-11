#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

std::vector<std::string> getDepCheckNames(std::vector<std::string> inTxt)
{
	unsigned int				i;
	std::vector<std::string>	depCheckNames;

	i = 0;	
	while (i < inTxt.size())
	{
		if (inTxt[i][0] == '*')
			depCheckNames.push_back(inTxt[i].substr(2, inTxt[i].find(':') - 2));
		++i;
	}
	return (depCheckNames);	
}

void runfork(std::vector<std::string> names)
{
	unsigned int	i;
	pid_t			pid;
	char			**cmds;

	cmds = (char **)malloc(sizeof(char *) * names.size() + 3);
	cmds[0] = strdup("npm");
	cmds[1] = strdup("install");
	i = 0;
	while (i < names.size())
	{
		cmds[i + 2] = strdup(names[i].c_str());
		++i;
	}
	cmds[names.size() + 2] = NULL;
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else
	{
		wait(NULL);
		i = 0;
		while (i < names.size() + 3)
			free(cmds[i++]);
		free(cmds);
	}
}

/*
void installPackages(std::vector<std::string> names)
{
	unsigned int	i;

	i = 0;
	while (i < names.size())
	{
		runfork(names[i++]);
		sleep(10);
	}
}*/

std::vector<std::string> getStdIn()
{
	std::vector<std::string>	content;
	std::string					input_line;
	while(std::cin) {
        getline(std::cin, input_line);
        content.push_back(input_line);
    };
	return (content);
}

int	main(int ac, char **av)
{
	std::vector<std::string> inTxt;
	std::vector<std::string> names;

	inTxt = getStdIn();
	names = getDepCheckNames(inTxt);
	runfork(names);
	return (0);
}
