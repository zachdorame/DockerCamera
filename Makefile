basic:
	docker buildx build -t program:latest -f docker/Dockerfile .
make run:
	docker run -p 127.0.0.1:8080:8080 program