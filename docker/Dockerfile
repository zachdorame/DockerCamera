# Start with the official Golang image as a base
FROM golang:1.22

# Set the Current Working Directory inside the container
WORKDIR /src

# Copy the go.mod and go.sum files
COPY go.mod ./

# Download all dependencies. Dependencies will be cached if the go.mod and go.sum files are not changed
RUN go mod download

# Copy the source code into the container
COPY . .

# Build the Go app
RUN go build -o server .

# Expose port 8080 to the outside world
EXPOSE 8080

# Command to run the executable
CMD ["./server"]
