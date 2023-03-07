FROM ubuntu:latest

# Install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gcc \
    g++ \
    gdb \
    make

# Create a working directory for the application
WORKDIR /app

COPY . .

WORKDIR ./src

CMD ["bash"]
