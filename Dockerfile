# Use the specified base image and platform
FROM --platform=linux/amd64 debian:bookworm-slim

# Install vim, nasm, binutils, and gcc
RUN apt update && \
    apt upgrade -y && \
    apt install -y binutils gcc nasm vim && \
    apt clean

WORKDIR /libasm
