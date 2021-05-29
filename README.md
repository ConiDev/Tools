# Tools

# You can use the following instructions to manage your web server with docker

create an image:
docker build -t web .

to run the container:
docker run -p 80:80 -p 443:443 --name web web

to manage inside the container:
docker exec -it web /bin/bash
