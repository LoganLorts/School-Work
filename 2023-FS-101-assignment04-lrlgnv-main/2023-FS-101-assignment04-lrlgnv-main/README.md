# assignment04

### Problems from the book:
- 1.21 a, b
- 1.28 a, b, c

### Instructions
- Complete all work in the main python file. This is the file that will be graded.
- You must use the provided names for the each problem.
- We are using the package `automata-lib` for DFAs in python. Install it using pip: `pip3 install automata-lib`. You do not need to manually install this if you use Docker or Singularity.

### Tips
- `*`: Kleene star operation, language repeated zero or more times. Ex: `a*`,`(ab)*`
- Concatenation. Ex: `abcd`
- `|`: Union. Ex: `a|b`
- Full syntax can be found here: https://github.com/caleb531/automata/blob/main/docs/regular-expressions.md
- The basic format is `your_nfa = NFA(...)` and fill in parameters.
- Use `''` for the empty string (lambda), and if a state has two transitions with the same value leading to different states then enter a list of states where you would normally enter the destination. Here is an example to illustrate both of these:
`'q0': {'': {'q1', 'q2'}}`
- If you are interested in the documentation: https://github.com/caleb531/automata/tree/main/docs

# Environments for Doing This Assignment

### Docker
1. Get Docker set up in your terminal.
2. Run `docker_build.sh` to build the Docker image.
3. Run `docker_run.sh` to enter the container.
4. Use `cd your_code/` to enter the repo directory.

### Singularity
1. Get on a campus machine or on PuTTY.
2. Clone the repo. Do not clone it in your SDRIVE. It will throw an error.
3. Run `singularity_run.sh` to enter an environment similar to a Docker container.

### GitLab Browser IDE
1. Go to the repo page on GitLab.
2. Press "." key. This should open a new tab with an IDE. You can edit your code here and push it, but you can not run the autograder. To see the autograder output you will have to go look at the GitLab job output.

### Linux
- If you are already running linux in some way then you can just install the dependencies for the autograder and run it locally.

# Information regarding this repository

## Auto-grader
### How to run the auto-grader on your machine?
Run the following in the root directory of your repository:
`./grade.sh`

### How to run the auto-grader on Gitlab-CI?
Make sure all your files are added, committed, and pushed.
Navigate to the Gitlab web interface to confirm these changes exist on the server.

## How to make sure I'm getting points?
* Click on Build -> Jobs -> the latest job.
* Is it passing, green, etc? 
* What grade does it say you have?
* Whatever grade the latest job says, is what we think you have!

## When is this due?
See Canvas!
