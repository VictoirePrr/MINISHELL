# What concepts is the project trying to teach me ? 

#### The aim is to be able to recreate a small bash, so that we can learn about tokenizing and grouping commands with a syntax tree. Bash should no longer be witchcraft to us !

### How bash works ?
- It gives you a prompt.
- Let you input some commands in the STDIN.
- Parses inputs to find the different commands.
- Execute theses commands in the right order, creates children.
- Output its results in the STDOUT, Errors in the STDERR.

### Why bash ?
- Because only psychopaths talk in 0 and 1.
- To make life easier when you want to communicate with the computer (commands are close to the human language)
- Gives you infinite possibilites to adjust the terminal to your liking (alias...)


# What constraints are there ? 
- You have to get into the skin of a User, and think of every mistakes they can make while inputing commands.
- Multiple commands should be executed at the right time.
- Commands can be seperated by multiple spaces but it should still work.
- Depending on how the input is done a command can become a string.
- Depending on commands, like echo, a flag like "echo -n" can be written "echo -nnnnnnnnnnnnnnnnnnnnn" and it should still work as a flag.
- ....

# Design: structures and input

### 1. Tokenisation : 
- Words (echo, ls, file.txt)
- Operators (|, >, <, &&, ||)
- Quoted strings ("hello world", 'single quotes')
- Substitutions ($(command), `command`)
##### Key rules:
- Spaces separate tokens unless inside quotes.
- Special characters like |, <, >, & are recognized as operators.

### 2. Parsing :
- After tokenizing, Bash structures the command based on precedence and associativity rules.

##### For example:

```c
echo hello && ls | wc -l > output.txt
```

##### is parsed as:
```c
        &&
       /  \
    echo  |
         / \
       ls  >
          /  \
      wc -l output.txt
```

##### What happens here?

- '&&' has the lowest precedence, so it's evaluated last.
- '|' has higher precedence, meaning ls | wc -l is grouped first.
- '>' redirects the output only from wc -l.