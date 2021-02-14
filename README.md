SIMPLE SHELL
===================
This was a 15 days project that consisted of writing a simple UNIX command interpreter (a basic UNIX shell) in C language, using a limited number of standard library functions, which means that the functions were all rewritten in order to focus on learning and improve the coding skills.

> **INTRODUCTION**

**Kernel**
> - It's the heart of the operating system.
> - Interact with the hardware.
> - Management of the memory, task scheduling and file management.

**Simple Shell**

> - The simple_shell its a command interpretet that communicate with the operating system.
> - Translates commands typed and convert it into a computer lenguage.
> - Interface between a user and the operating system.

**Commands and Utilities**

> - Several commands as **ls, pwd, cd, etc** that come along with some options.

**Files and Directories**

> - Files organized into directories.

----------

> **OBJECTIVES**

> - Display a prompt and wait for the user to type a command. A command line always ends with a new line.
> - The prompt is displayed again each time a command has been executed.
> - The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
> - The command lines are made only of one word. No arguments will be passed to programs.
> - If an executable cannot be found, print an error message and display the prompt again.
> - You have to handle the “end of file” condition (Ctrl+D)
> - handle special characters : \", ', `, \, *, &, #.
> - Implement the exit built-in, that exits the shell.
> - Implement the env built-in, that prints the current environment.


-------------

#### INSTALL

clone

> -First of all, you should clone the repository of simple_shell from this link.
>- [**Clone**](https://github.com/Sergioq7777/simple_shell.git)

Compilation

> - Once you have the files of the simple_shell you must compile it with GCC.
> - gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Execute

> - Finally to execute the simple_shell you must to use "./hsh".
> - ./hsh


#### FUNCTIONS.

|  FUNCTION       |  FILE             |  DESCRIPTION      |
 -----------------| ------------------| ------------------
| - `main`        | - `bigshell.c`    | - 'Entry point of the program.' |
| - `checkinfo`   | - `checkstr.c`    | - 'Check the information enter by the user and look for commands' |
| - `new_command` | - `checkstr.c`    | - 'Create a duplicate process for the new command' |
| - `maintoken`   | - `checkstr.c`    | - 'Work with token functions allowing access in different parts of code' |
| - `divtokens`   | - `checkstr.c`    | - 'Split the string in an array of tokens' |
| - `numtoken`    | - `checkstr.c`    | - 'Counts tokens in the passed string.' |
| - `lookpath`    | - `directory.c`   | - 'looks for the path of the program' |
| - `lookenvpath` | - `directory.c`   | - 'Look for environmental variable' |
| - `divpath`     | - `directory.c`   | - 'Split the path string as array of path directories' |
| - `lookdir`     | - `directory.c`   | - 'Check in directories of pathtokens for the command' |
| - `strpath`     | - `directory.c`   | - 'Join path directory string with command string' |
| - `changedir`   | - `inc_funct.c`   | - 'Change CWD to the parameter in cd, no parameter change HOME' |
| - `varenv`      | - `inc_funct.c`   | - 'Print environment variables' |
| - `free_exit`   | - `inc_funct.c`   | - 'Exit after free allocated resources' |
| - `intfunct_exe`| - `inc_funct.c`   | - 'Lookup for function needed to execute' |
| - `intfunct`    | - `inc_funct.c`   | - 'Lookup for builtin functions' |
| - `wrtnum`      | - `aux_funct.c`   | - 'Write a number' |
| - `_strdup`     | - `aux_funct.c`   | - 'Copy a string' |
| - `printfun`    | - `aux_funct.c`   | - 'Print string by character' |
| - `_put_char`   | - `aux_funct.c`   | - 'Writes a character to stdout' |
| - `_strcmp`     | - `aux_funct.c`   | - 'Compare two strings' |
| - `freestr`     | - `aux_funct1.c`  | - 'Free pointers to a string' |
| - `freeptr`     | - `aux_funct1.c`  | - 'Free double pointer variables' |
| - `wrterrex`    | - `aux_funct1.c`  | - 'Write exec errors' |
| - `wrterror`    | - `aux_funct1.c`  | - 'Write message error when command is not found' |
| - `_strlen`     | - `aux_funct1.c`  | - 'Function that return the lenght of a string' |


#### USAGE examples:

![image](https://user-images.githubusercontent.com/55101797/69600852-28cf8100-0fe0-11ea-8f4e-54e47737e83f.png)

![image](https://user-images.githubusercontent.com/55101797/69600964-89f75480-0fe0-11ea-9ebb-fd06ccc6c4e1.png)

![image](https://user-images.githubusercontent.com/55101797/69602757-9e3e5000-0fe6-11ea-8845-0a4e6b5dfe85.png)

#### synopsis example:

> - ls [OPTION]... [FILE]...

> - pwd [OPTION]...

> - cat [OPTION]... [FILE]...

#### System call:

- The **Syscall** is the way in wich a computer request a service from the kernel,
of the operating system.


**PROCESS CONTROL**

|  SYSCALL       |  DESCRIPTION      |
 -----------------|------------------
| - `exit()`   | - 'terminates the calling process "immediately"' |
| - `fork()`   | - 'Create a process ' |
| - `wait()`   | - 'Wait for a single object ' |


**MANIPULATION**

|  SYSCALL       |  DESCRIPTION      |
 -----------------|------------------
| - `read()`   | - 'Read a file' |
| - `write()`   | - 'Write a file ' |
| - `close()`   | - 'Close handle ' |


**OTHERS**

|  SYSCALL       |  DESCRIPTION      |
-----------------|------------------
| - `chdir()`    | - 'Changes the current working directory to that specified in path.' |
| - `execve()`   | - 'Executes the program pointed to by filename' |
| - `signal()`   | - 'System call installs a new signal handler for the signal with number signum ' |
| - `getpit()`   | - 'Get the current process id ' |
| - `stat()`   | - 'These functions return information about a file.' |

----------

### BLOG LINK

**Medium:**


- What happens when you type ls -l in the shell.

>- [**Article**](https://medium.com/@sergioq.7777/what-happens-when-you-type-ls-l-in-the-shell-50bb95d5c5a?source=friends_link&sk=301544e6950294d24a8cd09441e249eb)
----------

### MAN-PAGE


|  MAN OPTION              |  	  DESCRIPTION                  |
 -----------------         | ----------------------------      |
| `./man_1_simple_shell` |  `Simple_shell is a command lenguage interpreter that execute commands read from the standar input or from a file .`|


----------

### FLOW CHART

![image](https://user-images.githubusercontent.com/55101797/69752030-5a4e6680-111e-11ea-9ad1-c03901134e84.png)
---
## CHALLENGES FACED AND FUTURE FEATURES
> This was a really challenging project to develop because of the use of the limited number of standard library functions additionally the huge of topics that had necessary study to can understand the correct way to develop this project.
>
> On the other hand, one of the team members had personal problems and had to travel to another country, so we were forced to anticipate the delivery date and the development and testing time was reduced.
>
> Nonetheless, the development was completed and it was really enriching, and the knowledge gained was definitely worth it.
>
> As possible future, improvements, it could be interesting to improve the implementation of handle the `PATH` and the `exit built-in` in a more effective way and with useful features.

## AUTHORS

> - **Alexander Urrego** - [mateo-a](https://github.com/mateo-a) - [@mateo_a](https://twitter.com/mateo_a)
> -  **Sergio Quiroga**   - [sergioq7777](https://github.com/sergioq7777) - [@SergioQ32400329](https://twitter.com/SergioQ32400329) 

---
## About myself
I am a Systems Engineer with emphasis in Software :man_technologist:, ITIL Foundation certificate, CompTia Network+ certificate, PMP project management training, SCRUM Foundation certificate, proficient in the use programing languages like `C, C++, Python, REACT, JavaScript, CSS, HTML, SQL`, as well `Flutter, Linux/Unix systems, bash, scripting, GIT, Windows Server, GCP, frameworks like Node.js` and `Flask, NGINX,` **currently going in-depth in Augmented and Virtual Reality (AR/VR)** using `C#` and `UNITY`, huge experience working and supporting infrastructure projects related to datacenters, WLAN, LAN and Networking.

## Where to find me
<a href="https://www.linkedin.com/in/john-alexander-urrego/">
  <img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />
</a>
<a href="https://twitter.com/mateo_a">
  <img src="https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white" />        
</a>
