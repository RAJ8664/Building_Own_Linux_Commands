# How to Set Up and Use One of These Command Globally

Follow these steps to build and use one of these custom Linux command globally on your system.

---

## Step 1: Clone the Repository

Start by cloning this repository to your local machine:

```bash
git clone https://github.com/RAJ8664/Building_Own_Linux_Commands
cd Building_Own_Linux_Commands
```



## Step 2: Create a C File and Add Code
Create a new C file with the desired name. For example:

```bash
nano mycommand.c
```

Copy the provided C code from the repository, paste it into the file, and save it. Exit the editor after saving.

## Step 3: Compile the C Code
Compile the C file into an executable using the GCC compiler. Run the following command:

```bash
gcc mycommand.c -o mycommand
```
This will generate an executable file named mycommand.

## Step 4: Move the Executable to a Global Path
To make the command globally accessible, move the compiled executable to a directory included in your system's PATH. A common choice is /usr/bin

```bash
sudo mv mycommand /usr/bin/
```

## Step 5: Verify Installation
To confirm that your command works globally, run the following command:

```bash
mycommand
```
If the output matches your expectations, the installation was successful. The output will show you how to use the command.

## Step 6: (Optional) Clean Up
You can remove the source code and any temporary files if you no longer need them:

```bash
rm mycommand.c
```
This step is optional but helps keep your directories clean.

## Notes

Make sure you have the git and GCC compiler installed on your system. If not, you can install it using your package manager:

```bash
sudo apt install git      # For Ubuntu/Debian
sudo apt install gcc      # For Ubuntu/Debian
```
For Windows -- > why are you here ? 😀
