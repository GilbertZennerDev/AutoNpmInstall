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

void runfork(std::string name)
{
	//npm install x
	char	**cmds;
	unsigned int	i;
	pid_t	pid;

	cmds = (char **)malloc(sizeof(char *) * 4);
	cmds[0] = strdup("npm");
	cmds[1] = strdup("install");
	cmds[2] = strdup(name.c_str());
	cmds[3] = NULL;
	std::cout << "Installing " << name << "\n";
	pid = fork();
	if (pid == 0)
		execvp(cmds[0], cmds);
	else
	{
		wait(NULL);
		i = 0;
		while (i < 4)
			free(cmds[i++]);
		free(cmds);
	}
}

void installPackages(std::vector<std::string> names)
{
	unsigned int	i;

	i = 0;
	while (i < names.size())
	{
		runfork(names[i++]);
		sleep(10);
	}
}

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
	installPackages(names);
	return (0);
}
