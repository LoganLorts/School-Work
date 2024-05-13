# assignment02
Problems from the book:
 - 1.8a
 - 1.8b
 - 1.9a
 - 1.9b
 - 1.10a
 - 1.10b
 - 1.10c

# How to
Complete all work in `assignment02_main.py` this is the file that will be graded.

We are using the package `automata-lib` for DFAs in python. Install it using pip: `pip3 install automata-lib`

The basic format is `your_nfa = NFA(...)` and fill in parameters like in the last assignment.

Use `''` for the empty string (lambda), and if a state has two transitions with the same value leading to different states then enter a list of states where you would normally enter the destination. 

* Here is an example to illustrate both of these:
`'q0': {'': {'q1', 'q2'}}`

You must use the provided names for the FSMs.

If you are interested in the documentation: https://github.com/caleb531/automata/tree/main/docs

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
