# pa00_ps
Modify the `ps` command in Minix3.

## Environment setup
To distinguish between commands you execute in your host and Minix:

`$` prefaces commands executing in your host.

`#` prefaces commands executed in Minix.

### Step 0: 
Make sure you can run `qemu` virtual machines:

https://en.wikipedia.org/wiki/QEMU

https://gitlab.com/qemu-project/qemu

https://www.qemu.org/download/

If you can't (or don't want to) do this in Windows/Mac,
it's easy to just install a full virtual machine,
in which you can run `qemu`...
If so, I suggest this one,
which we use in networking and security courses later:

Either this:
https://fedoraproject.org/spins/xfce/download

Or this:
https://labs.fedoraproject.org/en/security/

After installing it, add some basic development software:
```
$ sudo dnf install -y ShellCheck bat cargo cgdb clang-tools-extra cmake cppcheck curl diffutils exa file fish gcc gcc-g++ gcovr gdb git gnupg2 graphviz httpd ltrace lynx make mc micro mtr nano nasm nc ncurses nmap octave pandoc poetry python3-black python3-devel python3-docopt python3-numpy python3-pip python3-scikit* qemu ranger rr rust-analysis rust-debugger-common rust-doc rust-gdb rust-lldb rust-src rustfmt shfmt strace tmux traceroute valgrind vim vim-X11 vim-enhanced vim-filesystem vim-fugitive vim-jedi vinagre vis wget whois zsh
$ sudo dnf install -y @virtualization
$ pip3 install python-Levenshtein mypy black py2cfg pudb assigner --user
$ fish -c "fish_add_path --prepend bin/ .local/bin/ .cargo/bin/"
```

### Step 1: 
Clone this repository:

`$ git clone <url>`

Clone the repository for Minix for this class:

`$ git clone: https://git-classes.mst.edu/containers/book_minix`

or

`$ git clone: git@git-classes.mst.edu:containers/book_minix.git`

### Step 2:
Mount the Minix image for editing in your host.
Copy the files in the repository into the book image.
Then, unmount.
```
$ cd book_minix/
$ ./mountminix3.sh

$ cd ../<your_pa01_repo>
$ cp -r goals/ your_outputs/ ps.c grade.sh -t ../book_minix/minix3bookmnt/usr/src/commands/ps/

$ cd ../book_minix/
$ ./umountminix3.sh
```

### Step 3:
Run Minix.
In your host, in `book_minix/`:
`$ ./qemuminix3.sh`

In Minix, navigate to the relevant folder:

`# cd /usr/src/commands/ps/`

### Step 4:
Read the man pages for `ps`,
explore its usage,
and actually read the source code.
```
# man ps
# ps
# ps -a
# ps -ax
# ps -al
# ps -axl
# vi ps.c
```

### Step 5:
Run, edit, and re-compile the `ps` program,
and run the autograder, `grade.sh`.
Do this repeatedly!
```
# ps
# ps -axl
# vi ps.c
# make && make install && make clean
# ps
# ps -axl
# ./grade.sh
```
You can either edit in Minix using `vi`,
or you can mount/umount to edit in the host.
To edit in your bare-metal OS host, 
make sure to follow the procedure outlined in the book Minix repo.

### Step 6:
Implement the actual requested features.
Add a `-c` option to the `ps` command.
The following should work:
```sh
# ps -ac
# ps -axc
```
It shoud have the columnar fields visible in the `goals/` folder.

To check your diffs:

```
# diff goals/ your_outputs/

$ diff -y goals/ your_outputs/

$ vimdiff goals/<file> your_outputs/<file>

$ meld goals/ your_outputs/
```

Some differences may be whitespace, formatting, or content.
These are the type you want to eliminate.
Some of the differences may be fluctuations in scheduling.
Those are not something you must eliminate.
`grade.sh` runs the command multiple times,
to makesure that such fluctations are ignored.
You may need to run the commands several times,
to identify which differences are which.

Continue to edit until the autograder passes your code.

### Step 7:
Shut down minix.
Mount the image file.
Copy the files out of the image,
back to your original repo.
Unmount the image file.

```
$ cd book_minix/
$ ./mountminix3.sh
$ cp minix3bookmnt/usr/src/commands/ps/ps.c <your_repo>
$ ./umountminix3.sh
```

### Step 8:
Git add, commit, push, verify.
```
$ git add ps.c
$ git commit -am "Time to git committed!"
$ git push
```
Lastly, verify your changes are actually up on the server.

P.S. Have fun!
