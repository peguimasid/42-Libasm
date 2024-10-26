# Use the specified base image and platform
FROM --platform=linux/amd64 ubuntu:lunar

# Update and upgrade apt package lists
RUN apt update && apt upgrade -y

# Install vim, nasm, binutils, and gcc
RUN apt install -y binutils gcc nasm vim && apt clean 

# Set the default command to run an interactive shell
CMD ["bash"]
