# Use the specified base image and platform
FROM --platform=linux/amd64 ubuntu:lunar

# Install vim, nasm, binutils, and gcc
RUN apt update && apt upgrade -y && apt install -y binutils gcc nasm vim && apt clean

# Set the default command to run an interactive shell
CMD ["bash"]
