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
"""
