import sys
import subprocess as sp

def getStdIn():
	return [l for l in sys.stdin]

def getDepCheckNames(inTxt):
	names = [l for l in inTxt if l[0] == '*']
	names = [l[2:l.index(':')] for l in names if ':' in l]
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

