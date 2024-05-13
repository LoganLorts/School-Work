# VM and Container
This repository offers an easy-to-use environment setup for programming assignments.
It can be used in conjunction with `assigner`, https://git-classes.mst.edu, and `grade.sh`.

## Full Fedora VM
For a full Fedora VM, then run this script to configure Fedora:
`./full_vm_config.sh`

## Install Docker/Podman/Singularity
If you want to run a lightweight container,
and are on Mac, or Windows, 
then see the instructions here:
https://docs.docker.com/get-docker/

If you are on Linux/Unix, 
then you don't really need Docker.
However if you want to use it,
you should probably use whatever docker is in the system repos.

Note: 
Depending on your shell, you may need to exclued `sudo` from the below commands.

## Test docker works
After installing docker, open a terminal, and then run:

`sudo docker run -it fedora`

Confirm that it worked, and you're in a Fedora container:

`cat /etc/os-release`

Then, to leave the container, type:

`exit`

## Running the remote pre-built image
If you are on an x86-64 architecture,
you can just pull a pre-built image.
Run the following command from the root directory of your Git repository,
where `<shell>` is your choice of shell (nu/fish/zsh/bash/etc.):

`sudo docker run --interactive --tty --rm --mount type=bind,source="$(pwd)"/,target=/your_code --workdir=/your_code git-docker-classes.mst.edu/containers/container <shell>`

I suggest the `fish` shell.

Your repository files are mounted inside the following directory:

`/your_code/`

## Building and running the image locally (optional)
If you are not on an x86-64 architecture,
or are curious, or are security-conscious,
you may want to build the image yourself.
From within the `container` repository directory 
(usually a Git submodule of your assignment), execute:

`sudo docker build --tag container .`

Then, you can run the image you built locally.
From the root directory of your assignment Git repository,
or any directory that you would like to mount in a container, execute,
where `<shell>` is your choice of shell (nu/fish/zsh/bash/etc.):

`sudo docker run --interactive --tty --rm --mount type=bind,source="$(pwd)"/,target=/your_code --workdir=/your_code container <shell>`

Your files will be mounted inside the container,
in the following directory:

`/your_code/`

## Campus Linux Machines (rootless docker)
If you use `ssh` (via putty or otherwise) to access the campus Linux machines,
then you will need to run a rootless container option.
First type `cd` to head to your home directory, then type:

`singularity shell docker://git-docker-classes.mst.edu/containers/container`

or:

`apptainer shell docker://git-docker-classes.mst.edu/containers/container`

After that, your entire home directory should be accessible from the container.

## Exposing ports
To expose a port, for example 80,
where `<shell>` is your choice of shell (nu/fish/zsh/bash/etc.):

`sudo docker run --interactive --tty --rm -p 80:80 --mount type=bind,source="$(pwd)"/,target=/your_code --workdir=/your_code container <shell>`

Or, more verbosely, when exposing port 6789

`sudo docker run --interactive --tty --publish target=6789,published=127.0.0.1:6789,protocol=tcp --mount type=bind,source="$(pwd)"/,target=/your_code --workdir=/your_code container <shell>`

Or, the pre-built version

`sudo docker run --interactive --tty --publish target=6789,published=127.0.0.1:6789,protocol=tcp --mount type=bind,source="$(pwd)"/,target=/your_code --workdir=/your_code git-docker-classes.mst.edu/containers/container <shell>`

This allows you to access network programs or services running within the container,
from your host.
For example, you could connect a web browser in the host,
to a web server in the container.

## Optional Docker Compose
If you would like to run with docker compose, 
then run `sudo docker compose run --rm programming` to enter a shell.
Note: on some systems, `docker compose` may be `docker-compose`.

If you would like the jupyter notebooks containerized for cs5700,
then run `sudo docker compose up -d jupyter`.
Then, connect to the notebook at `http://localhost:8888`.
Be sure to modify the compose file to point towards your *sequence-informatics* folder.

## Maintenance
If you maintain or update this container:

### Adding this submodule to your repo
If you, as an assignment developer or repository owner,
want to add this submodule to your repo, then:

`git submodule add https://git-classes.mst.edu/containers/container/`

### Adding software
Where <login> is your username,
and you have created a token in the gitlab web interface,
which will be required to copy-past via std-in:

```sh
sudo docker login git-docker-classes.mst.edu -u <login> --password-stdin
sudo docker build -t git-docker-classes.mst.edu/containers/container .
sudo docker push git-docker-classes.mst.edu/containers/container
```
