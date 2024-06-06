package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"io/ioutil"
	"net/http"
	"bytes"
)

func main() {
	// Define the port to listen on
	port := "8080"
	if len(os.Args) > 1 {
		port = os.Args[1]
	}

	// Start listening on the specified port
	listener, err := net.Listen("tcp", ":"+port)
	if err != nil {
		fmt.Println("Error starting the server:", err)
		os.Exit(1)
	}
	defer listener.Close()

	fmt.Println("Listening on port", port)

	for {
		// Accept a connection
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Error accepting connection:", err)
			continue
		}

		// Handle the connection in a new goroutine
		go handleConnection(conn)
	}
}

func handleConnection(conn net.Conn) {
	defer conn.Close()

	reader := bufio.NewReader(conn)
	message := make([]byte, 1024)

	//for {
	// Read the incoming message
	numBytesRead, err := reader.Read(message)
	fmt.Println(numBytesRead)
	if err != nil {
		fmt.Println("Error reading from connection:", err)
		return
	}

	// Print the received message to the console
	fmt.Print("Received message: ", string(message[:]))
	//}

	sendOk(conn)
}

func sendOk(conn net.Conn) {
		body := "Success" 
		t := &http.Response{
			Status:        "200 OK",
			StatusCode:    200,
			Proto:         "HTTP/1.1",
			ProtoMajor:    1,
			ProtoMinor:    1,
			Body:          ioutil.NopCloser(bytes.NewBufferString(body)),
			ContentLength: int64(len(body)),
			// Request:       req,
			Header:        make(http.Header, 0),
		}

		buff := bytes.NewBuffer(nil)
		t.Write(buff)

		conn.Write(buff.Bytes())
}
