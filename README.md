# CSV Viewer in CLI with C

This project is a simple C application that reads a CSV (Comma-Separated Values) file and prints it to the terminal as a clean, aligned table.

## 🚀 Features

- Automatically detects the CSV delimiter: `,`, `;`, `\t`, or `|`
- Trims leading/trailing spaces in each field
- Dynamically adjusts column widths for alignment

## 🛠 Build and Installation

You can either compile the project using any standard C compiler yourself or use the already compiled executable file:

```bash
gcc -std=c99 -Wall -Werror csv-viewer.c -o csv
```

 ## [![My Skills](https://skillicons.dev/icons?i=windows)](https://skillicons.dev) Windows
Add the directory of the executable file to Enviroment Variables -> System Variables -> Path


## [![My Skills](https://skillicons.dev/icons?i=linux,apple)](https://skillicons.dev) Unix(Linux/Macos)
Add this line to the shell configuration file
```bash
export PATH="$PATH:/path/to/your/executable_directory" 
```
## 🚀 Usage

```bash
csv <file_name>
```

