/*
am C ass et vill mei schwiereg
ech muss den stdin liesen, am beschten Zeil fir Zeit.
also getline googlen
getline kann ech vergiessen

ech muss also eng loop function benotzen:
emmer zum eischten *, an dann 1 weider: substring
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	getStdIn(char buffer[], char **content)
{
	int	bytes_read;

	bytes_read = read(0, buffer, 1023);
	buffer[bytes_read] = 0;
	printf("Debug buffer:%s", buffer);
	(*content)=strdup(buffer);
}

//void get

void	getCurrentLine(char *content)
{
	char	*line;
	char	*new_content;

	strncpy(new_content, strchr(content, '*') + 2, strlen(content));
	printf("debug new_content:%s.", new_content);
	strncpy(line, new_content, *new_content + *strchr(new_content, ' '));
	printf("debug line:%s.", line);
}

void	ft_runfork(char *name)
{
	printf("Running fork with %s\n", name);
}

void	useDepCheck()
{
	unsigned int	i;
	char			buffer[1024];
	char			**names;
	char			*content;

	i = 0;
	getStdIn(buffer, &content);
	getCurrentLine(content);
	names = malloc(sizeof(char *) * 11);
	while (i < 10)
		names[i++] = malloc(1024);
	names[i] = NULL;
	i = 0;
	while (names[i] != NULL)
		ft_runfork((names)[i++]);
	i = 0;
	while (names[i] != NULL)
		free(names[i++]);
	free(names[i++]);
	free(names);
}

int main(int ac, char **av)
{
	char  buffer[1024];

	//getStdIn(buffer);
	useDepCheck();
	return (0);
}
/*
import sys
import subprocess as sp

def getStdIn():
	return [l for l in sys.stdin]

def getDepCheckNames(inTxt):
	names = [l for l in inTxt if l[0] == '*']
	names = [l[2:l.index(':')] for l in names]
	return names

def useDepCheck():
	inTxt = getStdIn()
	return getDepCheckNames(inTxt)

def installPackages(names):
	if names == []: return
	print(names)
	for name in names:
		sp.run(f"npm install {name}", shell=True, check=True)

def installDepCheck():
	sp.run(f"npm install -g depcheck", shell=True, check=True)

def main():
	av = sys.argv
	ac = len(av)
	#installDepCheck()
	names = useDepCheck()
	installPackages(names)
if __name__ == "__main__":
	main()
	
"""
stash
#if ac == 2:
	#	if av[1] == "depcheck": names = useDepCheck()
		#elif av[1] == "errormsgs": names = useErrMsgs()
	#	else: print("First arg must be depcheck or errormsgs"); exit()
	#else: print("Usage: tsc | python app.py errormsgs"); exit()


def getModuleNames(inTxt):
	inTxt = [l for l in inTxt if "Cannot find module" in l]
	modNames = []
	for l in inTxt:
		parts = l.split(' ')
		name = parts[parts.index('module') + 1][1:-1]
		modNames.append(name)
	return modNames

def useErrMsgs():
	inTxt = getStdIn()
	return getModuleNames(inTxt)
"""*/
