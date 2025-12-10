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
	installPackages(useDepCheck())
if __name__ == "__main__":
	main()
*/

#include <string>
#include <iostream>


//wei geet daat am C++? wei kann ech am C++ den stdin liesen?
//ech schreiwen mir mol eng Zeil fake Content

void bla()
{
	std::string line = "fastify";
	std::cout << line << " will  be installed...\n";
}

void runfork()
{
	//npm install x
	std::string cmds_s[3];
	cmds_s[0] = "npm";
	cmds_s[1] = "install";
	cmds_s[2] = "fastify";
	execvp(cmds_s[0].c_str(), cmds_s.c_str())	
}

/*def getDepCheckNames(inTxt):
	names = [l for l in inTxt if l[0] == '*']
	names = [l[2:l.index(':')] for l in names]
	return names	
*/

int	main(int ac, char **av)
{
	if (0)
		return (1);
	std::cout << "C++ Time Now!\n";
	bla();
	return (0);
}
