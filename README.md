# CSV Tabulator in C

This project is a simple C application that reads a CSV (Comma-Separated Values) file and prints it to the terminal as a clean, aligned table.

## 🚀 Features

- Automatically detects the CSV delimiter: `,`, `;`, `\t`, or `|`
- Trims leading/trailing spaces in each field
- Dynamically adjusts column widths for alignment

## 🛠 Build

You can either compile the project using any standard C compiler yourself or use the already compiled executable file:

```bash
gcc -std=c99 -Wall -Werror csv-viewer.c -o csv


