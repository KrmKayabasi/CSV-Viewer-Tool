 CSV Tabulator in C

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

 ## For Windows ![windows_logo_icon_132880](https://github.com/user-attachments/assets/b944437b-47db-4f24-9ed3-b0d44da7b0f4)#



Add the directory of the executable file to Enviroment Variables -> System Variables -> Path

## For Unix(Linux/Macos) [![My Skills](https://skillicons.dev/icons?i=linux,apple)](https://skillicons.dev)
Add this line to the shell configuration file
```bash
export PATH="$PATH:/path/to/your/executable_directory" 
```
## 🚀 Usage

```bash
csv <file_name>
```

