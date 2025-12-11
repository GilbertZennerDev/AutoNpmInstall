# 🚀 AutoNpmInstall: Fix Your Missing Dependencies INSTANTLY\! 🛠️

**The only sane way to handle `depcheck` output and auto-install missing packages.**

## 🎯 Quick Links

| Link | Description |
| :--- | :--- |
| **GitHub Repo** | [git@github.com:GilbertZennerDev/AutoNpmInstall.git](https://github.com/GilbertZennerDev/AutoNpmInstall) |
| **Author** | **Gilbert Zenner Dev** |

-----

## ✨ The Problem (And The Brilliant Solution\!)

Have you ever run a tool like `depcheck` and gotten a massive list of missing dependencies? Copying and pasting each package name into an `npm install` command is tedious, slow, and prone to human error.

**Enter AutoNpmInstall\!** 🪄

This simple, laser-focused Python script takes the structured output from `depcheck` (or any tool that follows the same output format) and transforms it into a series of **automated `npm install` commands**.

**Stop manually fixing your dependencies. Automate it\!**

-----

## 💻 Installation

Since this is a simple Python script, no complex installation is needed\!

1.  **Clone the Repository:**
    ```bash
    git clone git@github.com:GilbertZennerDev/AutoNpmInstall.git
    cd AutoNpmInstall
    ```
2.  **Save the Script:**
    Save the code as `app.py` in a convenient location (or just keep it in the cloned repository).
3.  **Requirements:**
    You only need **Python 3** and the ability to run **`npm`** in your shell.

-----

## 🚀 Usage: The Magic Command

The script works by reading standard input (`stdin`). You simply **pipe** the output of `depcheck` directly into the Python script.

### Basic Usage

1.  Make sure you have `depcheck` installed (usually globally or in your project):

    ```bash
    npm install -g depcheck # if needed
    ```

2.  Run the ultimate one-liner:

    ```bash
    depcheck --missing | python app.py
    ```

### How it Works

| Command | Action |
| :--- | :--- |
| `depcheck --missing` | Runs the dependency checker and outputs the list of missing packages (starting with `*`). |
| `|` | **Pipes** that output to the next command. |
| `python app.py` | Reads the piped text, **parses** the package names, and **executes** `npm install <package-name>` for each one. |

-----

## 📝 The Code (AutoNpmInstall v1.0)

This script is intentionally minimalist and robust.

```python
import sys
import subprocess as sp

def getStdIn():
    # Read all input from the pipe
    return [l for l in sys.stdin]

def getDepCheckNames(inTxt):
    # Filter lines starting with '*' and slice the package name
    names = [l for l in inTxt if l[0] == '*']
    names = [l[2:l.index(':')] for l in names]
    return names

def useDepCheck():
    inTxt = getStdIn()
    return getDepCheckNames(inTxt)

def installPackages(names):
    if names == []: return
    print("✨ Installing the following packages:", names)
    for name in names:
        # Execute the npm install command
        # NOTE: Consider adding 'check=True' for robust error handling!
        sp.run(f"npm install {name}", shell=True)

def main():
    names = useDepCheck()
    installPackages(names)

if __name__ == "__main__":
    main()
```

-----

## 🤝 Contributing

Got an idea to make this even faster or more feature-rich (e.g., adding `check=True` for error handling, or supporting `npm install --save-dev` for development dependencies)?

We welcome pull requests\! Feel free to fork the repository and submit your improvements. Let's make dependency management painless\!
